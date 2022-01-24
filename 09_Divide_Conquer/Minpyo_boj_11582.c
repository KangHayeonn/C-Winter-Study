//
//  main.c
//  ChickenTopN
//
//  Created by rabbi on 2022/01/22.
//

// No. 11582

#include <stdio.h>
#include <stdlib.h>

int n; // 치킨집 개수
int k; // 현재 정렬을 진행중인 회원들의 수
int* temp; // 정렬한 데이터를 저장할 temp 배열

void Merge(int data[], int start, int mid, int end) {
    if(end - start > n / k) return; // k명 조건의 다음 단계가 될 경우 data 배열을 변경해주지 않는다
    int s = start; int m = mid+1;
    int index = start;
    
    // 한 구역을 다 옮길 때까지 크기 순으로 temp 배열에 정렬
    while(s <= mid && m <= end) {
        temp[index++] = (data[s] >= data[m])? data[m++] : data[s++];
    }
    
    // 다 옮기지 못한 나머지도 옮겨준다
    while(s<=mid) temp[index++] = data[s++];
    while(m<=end) temp[index++] = data[m++];
    
    // temp 배열을 원본 배열에 복사한다
    for(int i = start; i <= end; i++) data[i] = temp[i];
}

void MergeSort(int data[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        MergeSort(data, start, mid);
        MergeSort(data, mid+1, end);
        Merge(data, start, mid, end);
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    
    int *TasteList = (int*)malloc(sizeof(int) * n); // 치킨집의 맛 수치 배열
    
    for(int i = 0; i < n; i++) scanf("%d", &TasteList[i]);
    
    scanf("%d", &k);
    
    temp = (int*)malloc(sizeof(int) * n);
    
    MergeSort(TasteList, 0, n-1);
    
    for(int i = 0; i < n; i++) printf("%d ", TasteList[i]);
    
    return 0;
}
