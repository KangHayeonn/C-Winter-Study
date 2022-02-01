/*
https://www.acmicpc.net/problem/1780

만약 종이 내의 모든 숫자들이 같은 수라면, 분할하지 않습니다.

하지만, 종이 내에 다른 숫자가 하나라도 포함된다면, 9개의 종이로 자르고, 
잘린 종이마다 숫자가 모두 같은지 아닌지를 반복하여 판단합니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int res[3];
int map[2200][2200];	//입력의 최대값이 2143

// 종이 내 모든 칸들이 모두 같은지 판단
bool check(int row, int col, int num) {

	// 시작점
	int start = map[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != map[i][j])	//start와 원소가 다를때 return false 하면서 종료(탈출)
				return false;
		}
	}
	return true;
}

// 재귀: 9분할로 나눠주고 res를 갱신하는 함수
void divide(int row, int col, int num) {
	
	if (check(row, col, num)) {		// 단위 종이 내 모든 칸들의 값이 같다면
		res[map[row][col]]++;
	}
	else {		// 모든 칸들의 값이 같지 않다면 -> 새로운 단위 사이즈를 만든다.		
		int size = num / 3; 

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(row + size * i, col + size * j, size);	//시작점과 num이 변경됨
			}
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			int input;
			scanf("%d", &input);
			input++; // -1,0,1 을 0,1,2로 저장 : res의 index와 맞추려고
			map[i][j] = input;
		}
	}

	divide(0, 0, N);
	printf("%d\n%d\n%d\n", res[0], res[1], res[2]);
	
}
