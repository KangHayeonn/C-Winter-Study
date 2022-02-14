// 도시 건설 (백준 21924번)

// 크루스칼 알고리즘 - MST (사이클 체크 : Union-Find 이용)
// C언어일 경우 HeapSize 주의

/* [ 추가 알고리즘 ]
 * 1. 모든 노드를 연결한 간선의 개수 = 노드의 개수 - 1 인지 확인
 * 2. 전체 비용에서 - 최소 비용 = 절약하는 비용
 * 3. 조건이 int형을 넘어갈 수 있으므로 long 타입으로 선언해줘야 정답!
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 500001

int* parents;

typedef struct value
{
    int from;
    int to;
    int weight;

}values;

struct heap_element // 정수 값을 저장하는 힙의 노드 구조체로 우선 순위를 지정할 수 있다.
{
    int priority;
    values data;
};
typedef struct heap_element heap_element;

struct heap
{
    int count;
    heap_element heap_arr[HEAP_LEN]; // 힙은 배열 구조를 기반으로 구현된다.
};
typedef struct heap heap;

void HeapInit(heap* h);
int HIsEmpty(heap* h);
void HInsert(heap* h, values data, int priority);
values HDelete(heap* h);
void ShowHeap(heap* h);

int GetParentIndex(int child_index);
int GetLeftChildIndex(int parent_index);
int GetRightChildIndex(int parent_index);
int GetChildIndex(heap* h, int parent_index);

// Union-Find 부분
int findParent(int x);
void unionParent(int x, int y);
bool isCycle(int x, int y);

int main() {
    int N, M; // N: 컴퓨터(노드)의 수, M: 연결할 수 있는 선(간선)의 수
    scanf("%d %d", &N, &M);

    long total = 0; // 전체 비용
    long minTotal = 0; // 사용하는 최소 비용
    int count = 0; // 연결된 간선의 개수를 카운트 (최소 비용일 때)

    // 우선순위 큐
    heap h;
    HeapInit(&h);
    parents = (int*)malloc(sizeof(int) * (N + 3));

    for (int i = 0; i < M; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);

        values p;
        p.from = from;
        p.to = to;
        p.weight = weight;
        HInsert(&h, p, p.weight);
        
        total += weight;
    }

    // 부모 = 자신 으로 처음 초기화
    for (int i = 1; i <= N; i++) {
        parents[i] = i;
    }

    while (!HIsEmpty(&h)) {
        values t = HDelete(&h);
        int rx = findParent(t.from);
        int ry = findParent(t.to);

        // 사이클이 발생하지 않는 경우에만 집합에 포함
        if (!isCycle(rx, ry)) {
            minTotal += t.weight;
            unionParent(t.from, t.to);
            count++;
        }
    }

    if (count == N - 1) {
        printf("%ld", total - minTotal);
    }
    else {
        printf("%d",  - 1);
    }
}

// 자신이 연결된 노드의 끝을 찾아 본질의 부모를 찾아주기
int findParent(int x) {
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = findParent(parents[x]);
}

// 더 작은 값을 부모로 선정 (부모 노드를 합침)
void unionParent(int x, int y) {
    x = findParent(x);
    y = findParent(y);

    if (x < y) {
        parents[y] = x;
    }
    else {
        parents[x] = y;
    }
}

// 사이클인지 판단 (같은 부모인지 체크)
bool isCycle(int x, int y) {
    if (x == y) return true;
    return false;
}


void HeapInit(heap* h)
{
    int i = 0;
    h->count = 0;
    for (i = 0; i < HEAP_LEN; i++)
    {
        h->heap_arr[i].data.from = 0;
        h->heap_arr[i].data.to = 0;
        h->heap_arr[i].data.weight = 0;
        h->heap_arr[i].priority = -1;
    }
    return;
}
int HIsEmpty(heap* h)
{
    return (h->count == 0) ? TRUE : FALSE;
}

void HInsert(heap* h, values data, int priority)
{
    int insert_index = h->count + 1;
    int parent_index = 0;
    heap_element new_element = { priority, data };

    while (insert_index != 1) // 처음 삽입되는 위치가 루트 노드가 아니면 혹은 갱신된 추가 인덱스가 루트 노드가 아니면
    {
        parent_index = GetParentIndex(insert_index);
        if (new_element.priority >= h->heap_arr[parent_index].priority) // 우선 순위가 부모가 높다면 구조 재조정이 필요 없다.
            break;
        else // 추가할 노드가 우선 순위가 높은 경우, 계속 구조 재조정이 필요함.
        {
            h->heap_arr[insert_index] = h->heap_arr[parent_index];
            insert_index = parent_index;
        }
    }
    h->heap_arr[insert_index] = new_element;
    h->count++;
    return;
}

values HDelete(heap* h)
{
    values r_data;
    r_data.from = h->heap_arr[1].data.from; // 삭제할 데이터(Pop 할 데이터와 같은 의미
    r_data.to = h->heap_arr[1].data.to; // 삭제할 데이터(Pop 할 데이터와 같은 의미)
    r_data.weight = h->heap_arr[1].data.weight; // 삭제할 데이터(Pop 할 데이터와 같은 의미)
    heap_element last_element = h->heap_arr[h->count]; // 비교 대상인 마지막 노드 지정( 마지막 노드를 루트 자리로 올려 비교하기 때문 )
    // 최종 결정된 인덱스
    int parent_index = 1; // 루트 노드 부터 시작한다.
    int child_index = 0;

    while (child_index = GetChildIndex(h, parent_index))
    {
        if (last_element.priority <= h->heap_arr[child_index].priority) // 자식 노드보다 우선 순위가 높다면 현재 구한 인덱스로의 변경만 하면 된다.
            break;
        else // 계속해서 구조의 재조정이 필요한 경우
        {
            h->heap_arr[parent_index] = h->heap_arr[child_index];
            parent_index = child_index;
        }
    }
    h->heap_arr[parent_index] = last_element;
    h->count--;
    return r_data;
}
// Heap의 내용을 트리의 계층(레벨) 별로 보여준다.
void ShowHeap(heap* h)
{
    int begin = 1, end = 1, index = 1;
    int i = 0;

    if (h->count == 0)
    {
        printf("heap이 비었습니다!\n");
        return;
    }

    printf("%d, %d, %d(%d), \n", h->heap_arr[1].data.from, h->heap_arr[1].data.to, h->heap_arr[1].data.weight, h->heap_arr[1].priority);

    while (index <= h->count)
    {
        begin = GetLeftChildIndex(begin), end = GetRightChildIndex(end); // 각 레벨 층의 시작과 끝 인덱스 설정 후 출력한다
        if (end > h->count)    end = h->count; // end가 마지막 노드보다 넓은 범위에 있다면 end를 마지막 노드의 인덱스로 설정

        index = end + 1; // 위에서 지정한 end 다음 값으로 변경한다.

        for (i = begin; i <= end; i++)
            printf("%d, %d, %d(%d), ", h->heap_arr[1].data.from, h->heap_arr[1].data.to, h->heap_arr[i].data.weight, h->heap_arr[i].priority);
        fputc('\n', stdout);
    }
    return;
}

// 부모 노드의 인덱스를 구한다.
int GetParentIndex(int child_index)
{
    return child_index / 2;
}
// 왼쪽 자식 노드의 인덱스를 구한다.
int GetLeftChildIndex(int parent_index)
{
    return parent_index * 2;
}
// 오른쪽 자식 노드의 인덱스를 구한다.
int GetRightChildIndex(int parent_index)
{
    return (parent_index * 2) + 1;
}
// 두 자식 노드 중 우선 순위에 따라 반환한다.
int GetChildIndex(heap* h, int parent_index)
{
    if (GetLeftChildIndex(parent_index) > h->count) // 자식 노드가 없으면 0 반환
        return 0;
    else if (GetLeftChildIndex(parent_index) == h->count) // 자식 노드가 하나인 경우에는 해당 인덱스 반환
        return GetLeftChildIndex(parent_index);
    else // 두 자식 노드 중 우선 순위가 높은 것의 인덱스 반환
    {
        int left_child_index = GetLeftChildIndex(parent_index), right_child_index = GetRightChildIndex(parent_index);
        if (h->heap_arr[left_child_index].priority > h->heap_arr[right_child_index].priority) // 오른쪽 자식 노드가 더 우선 순위가 높다면
            return right_child_index; // 오른쪽 자식 노드의 인덱스 반환
        else // 왼쪽 자식 노드가 더 우선 순위가 높거나 양쪽 노드의 우선 순위가 같다면
            return left_child_index; // 왼쪽 자식 노드의 인덱스 반환
    }
}