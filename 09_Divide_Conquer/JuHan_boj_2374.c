#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
	5  1 10 2 5 3  -> 9 + 3 + 2 + 5 = 19
	1  10 2 5 3
	10 10 2 5 3
	10 10 5 5 3
	10 10 5 5 5
	10 10 10 10 10
	인접한 수끼리 같은 숫자가 되면 그룹화
	그룹을 하나의 수로 생각하고 인접한 수랑 같도록
	같아지면 또 그룹화
	-> 재귀

  미완성
*/

int* arr;
int i, cnt, same = 0;

int solve(int* a, int len) {
	for (i = 0; i < len - 1; i++) {
		if (a[i] != a[i + 1]) {
			same = 1;
		}
	}

	if (same == 0)
		return cnt;
	else {
		for (i = 0; i < len; i++) {
			if (i == 0) {
				if (a[i] < a[i + 1]) {
					cnt += (a[i + 1] - a[i]);
					a[i] = a[i + 1];
				}
			}
			else if (1 <= i && i <= len - 2) {		//주요
				if (a[i] < a[i + 1]) {
					cnt += (a[i + 1] - a[i]);
					a[i] = a[i + 1];
				}
			}
			else if (i == len - 1) {
				if (a[i] < a[i - 1]) {
					cnt += (a[i - 1] - a[i]);
					a[i] = a[i - 1];
				}
			}
		}
		return cnt;
	}
}


int main() {
	int n;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d\n", solve(arr, n));
}
