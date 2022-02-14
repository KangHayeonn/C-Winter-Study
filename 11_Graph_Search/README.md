## 📌그래프와 탐색(Graph_Search)
##### 담당자 : 박주한
<br>

### 📌그래프란?
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcjbjPd%2FbtqKgF6OzSD%2FU0a7BKCpfJlhx1iJzwsEy1%2Fimg.png) 
<br>
그래프는 정점과 간선으로 이루어진 자료구조입니다. 정확히는 정점(Vertex)간의 관계를 표현하는 조직도라고 볼수도 있겠습니다. 그런면에서 트리는 그래프의 일종인 셈입니다. 다만 트리와는 달리 그래프는 정점마다 간선이 없을수도 있고 있을수도 있으며 루트 노드, 부모와 자식이라는 개념이 존재하지 않습니다. 또한 그래프는 네트워크 모델 즉, 객체와 이에 대한 관계를 나타내는 유연한 방식으로 이해할 수 있습니다. 실생활에서 다양한 예를 그래프로 표현할 수 있습니다. 대표적으로 지하철 노선도, 도심의 도로등이 있습니다. 이런식으로 활용할 수 있는 방법이 많기에 문제도 다양하게 출제를 할 수 있습니다. 그래프는 알고리즘에서 굉장히 많이 사용됩니다. 특히 그래프를 순회하는 방식인 DFS와 BFS를 잘 알아두어야 합니다. <br>
<br>


### 📌그래프에서 사용하는 용어
<br>
정점(vertice) : 노드(node)라고도 하며 정점에는 데이터가 저장됩니다. (0, 1, 2, 3)<br>
간선(edge): 링크(arcs)라고도 하며 노드간의 관계를 나타냅니다.<br>
인접 정점(adjacent vertex) : 간선에 의해 연결된 정점으로 위에서 (정점0과 정점1은 인접 정점)<br>
단순 경로(simple-path): 경로 중 반복되는 정점이 없는것, 같은 간선을 자나가지 않는 경로<br>
차수(degree): 무방향 그래프에서 하나의 정점에 인접한 정점의 수 (정점 0의 차수는 3)<br>
진출 차수(out-degree) : 방향그래프에서 사용되는 용어로 한 노드에서 외부로 향하는 간선의 수를 뜻합니다.<br>
진입차수(in-degree) : 방향그래프에서 사용되는 용어로 외부 노드에서 들어오는 간선의 수를 뜻합니다.<br>
<br>

### 📌그래프 구현 방법 
<br>
그래프를 구현하는 방법에는 1.인접행렬(Adjacency Materix)와 2.인접리스트(Adjacency List)방식이 있습니다. <br>
두개의 구현 방식은 각각의 상반된 장단점을 가지고 있는데 대부분 인접리스트 형식을 많이들 사용합니다.<br>
<br>
<br>
<br>

### 1.인접행렬 방식 
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F7RFhy%2FbtqKkOhoYiE%2FSE3IQP2q0g3xd34EQZkjM1%2Fimg.png)
<br>
인접행렬은 그래프의 노드를 2차원 배열로 만든 것입니다. 완성된 배열의 모양은 1, 2, 3, 4, 5, 6의 정점을 연결하는 노드에 다른 노드들이 인접 정점이라면 1, 아니면 0을 넣어줍니다.<br>
<br>
<br>

#### 인접행렬 장점
1. 2차원 배열 안에 모든 정점들의 간선 정보를 담기 때문에 배열의 위치를 확인하면 두 점에 대한 연결 정보를 조회할 때 O(1) 의 시간 복잡도면 가능합니다. <br>
2. 구현이 비교적 간편합니다.<br>
<br>

#### 인접행렬 단점
1. 모든 정점에 대해 간선 정보를 대입해야 하므로 O(n²) 의 시간복잡도가 소요됩니다.<br>
2. 무조건 2차원 배열이 필요하기에 필요 이상의 공간이 낭비됩니다.<br>
<br>
<br>
<br>

#### 2.인접리스트 방식 
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FNlh1G%2FbtqKicb2Wub%2FsHWVSS6bn2FZdijEJVR2r1%2Fimg.png)
<br>
인접리스트란 그래프의 노드들을 리스트로 표현한것입니다. 주로 정점의 리스트 배열을 만들어 관계를 설정해줌으로써 구현합니다. 
<br>
<br>

#### 인접리스트 장점
1. 정점들의 연결 정보를 탐색할 때 O(n) 의 시간이면 가능합니다. (n: 간선의 갯수)
2. 필요한 만큼의 공간만 사용하기때문에 공간의 낭비가 적습니다.
<br>

#### 인접리스트 단점
1. 특정 두 점이 연결되었는지 확인하려면 인접행렬에 비해 시간이 오래 걸립니다. (배열보다 search 속도느림)
2. 구현이 비교적 어렵습니다.
<br>
<br>
<br>

### 📌다양한 그래프의 종류 
그래프는 구현되어진 특성에 따라 여러가지 종류로 나누어집니다. 대표적인 그래프의 유형은 아래와 같습니다.
<br>
<br>
<br>

#### 1.무방향그래프
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F0ZsjG%2FbtqKjcbPzFp%2FEmai2Mc2IWMIAENKHr4Is1%2Fimg.png)
<br>
무방향 그래프는 두 정점을 연결하는 간선에 방향이 없는 그래프입니다.
<br>
<br>

#### 2.방향그래프 
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbvvxel%2FbtqKkPUXTtY%2FpsdErjeixg2KkpZWHc9NqK%2Fimg.png)
<br>
방향 그래프는 두 정점을 연결하는 간선에 방향이 존재하는 그래프입니다. 간선의 방향으로만 이동할 수 있습니다. 
<br>
<br>

#### 3.가중치그래프 
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FBVFRy%2FbtqKopgFBy3%2FSlXKIsNr2avTAKIyLnwuvk%2Fimg.png)
<br>
가중치 그래프는 두 정점을 이동할때 비용이 드는 그래프입니다.
<br>
<br>

#### 4.완전그래프
![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FmPtuW%2FbtqKqyqTexj%2FUDBayShMmL3p8LGDl25uR1%2Fimg.png)
<br>
완전 그래프는 모든 정점이 간선으로 연결되어 있는 그래프입니다.
<br>
<br>

### 📌그래프의 탐색 
![image](https://blog.kakaocdn.net/dn/cFgEJ6/btqKmoJkq5a/pwm3O8T4rERuL4wSTrkgnK/img.gif)
<br>
첫 정점에서부터 그래프에 존재하는 모든 정점들을 모두 한번씩 방문하는 것을 그래프 탐색이라고 합니다. 그래프 탐색의 방법은 깊이 우성 탐색(DFS) 방식과 너비 우선 탐색(BFS)방식이 있습니다.
<br>
<br>
<br>

#### 1.깊이 우선탐색(DFS)
깊이 우선탐색 DFS는 갈 수 있는 만큼 최대한 깊이 가고, 더 이상 갈 곳이 없다면 이전 정점으로 돌아가는 방식으로 그래프를 순회하는 방식입니다. 간단히 재귀호출을 사용하여 구현하거나 스택을 사용하여 구현합니다. 
<br>
<br>

#### 2.넓이 우선탐색(BFS)
넓이 우선탐색 BFS는 시작정점을 방문한 후 시작 정점에 인접한 모든 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선방문하는 방법입니다. 일반적으로 QUEUE를 사용해서 지금 위치에서 갈 수 있는 것들을 모두 큐에 넣는 방식으로 구현합니다.
<br>
<br>
<br>


### 📌C로 구현한 인접행렬 그래프 코드
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;


// 그래프 초기화
void init(GraphType* g){
    int r,c;
    g->n=0;
    for(r=0;r<MAX_VERTICES;r++)
        for(c=0;c<MAX_VERTICES;c++)
           g->adj_mat[r][c]=0;
}


//정점 삽입
void insert_vertex(GraphType* g,int v){
    if (((g->n)+1)>MAX_VERTICES){
        fprintf(stderr,"overflow");
        return;
    }
    g->n++;
}

//간선 삽입
void insert_edge(GraphType* g,int start,int end){
    if(start>=g->n||end>=g->n){
        fprintf(stderr,"vertex key error");
        return;
    }
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g){
    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            printf("%2d",g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    GraphType *g;
    g=(GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
       insert_vertex(g,i);
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);
    print_adj_mat(g);
    
    free(g);
}
```
<br>
<br>

### 📌C로 구현한 인접리스트 그래프 코드
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType{
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType* g){
    int v;
    g->n=0;
    for(v=0;v<MAX_VERTICES;v++)
        g->adj_list[v]=NULL;
}

void insert_vertex(GraphType* g,int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr,"overflow");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g,int u,int v){
    GraphNode* node;
    if(u>=g->n||v>=g->n){
        fprintf(stderr,"vertex index error");
        return;
    }
    node= (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex=v;
    node->link=g->adj_list[u];
    g->adj_list[u]=node;
}

void print_adj_list(GraphType* g){
    for(int i=0;i<g->n;i++){
        GraphNode* p=g->adj_list[i];
        printf("정점 %d의 인접 리스트",i);
        while(p!=NULL){
            printf("->%d",p->vertex);
            p=p->link;
        }
        printf("\n");
    }
}

int main()
{
    GraphType *g;
    g=(GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
        insert_vertex(g,i);
    insert_edge(g,0,1);
    insert_edge(g,1,0);
    insert_edge(g,0,2);
    insert_edge(g,2,0);
    insert_edge(g,0,3);
    insert_edge(g,3,0);
    insert_edge(g,1,2);
    insert_edge(g,2,1);
    insert_edge(g,2,3);
    insert_edge(g,3,2);
    print_adj_list(g);

    free(g);

    return 0;
}
```
<br>
<br>
이론 출처 : https://coding-factory.tistory.com/610
<br>
코드 출처 : https://velog.io/@kysung95/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-C%EB%A1%9C-%EA%B7%B8%EB%9E%98%ED%94%84%EB%A5%BC-%EB%A7%8C%EB%93%A4%EC%9E%90
