//
//  main.c
//  MakingInto1
//
//  Created by rabbi on 2022/02/14.
//

// No. 12852

int* d; // 연산 횟수 저장, dynamic programming
int* before; // 그 전의 수를 저장하는 배열

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solve(int n) {
    for(int i = 2; i <= n; i++) {
        d[i] = d[i-1] + 1;
        before[i] = i-1;
        
        // 2의 배수이고 i/2번째 횟수에서 1을 추가하는 것이 더 낫다면
        if(i % 2 == 0 && d[i] > d[i/2] + 1) {
            d[i] = d[i/2] + 1; // i/2 인덱스에서 횟수 1 추가
            before[i] = i/2; // 그 전 수 저장
        }
        
        // 3의 배수이고 i/3번째 횟수에서 1을 추가하는 것이 더 낫다면
        if(i % 3 == 0 && d[i] > d[i/3] + 1) {
            d[i] = d[i/3] + 1; // i/2 인덱스에서 횟수 1 추가
            before[i] = i/3; // 그 전 수 저장
        }
    }
    
    return d[n];
}

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    d = (int*)malloc(sizeof(int) * n + 1);
    before = (int*)malloc(sizeof(int) * n + 1);
    
    d[1] = 0;
    
    printf("%d\n", solve(n));
    
    while(true) {
        printf("%d ", n);
        n = before[n];
        if(n==0) break;
    }
    
    
    return 0;
}
