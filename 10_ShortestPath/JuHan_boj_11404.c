

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 101
#define INF 987654321

int i, j;
int graph[MAX][MAX];

/*
ex)
int before[MAX][MAX];		: 가중치 뿐만이 아닌 경로까지 알기 위해, 직전의 정점을 저장하는 행렬 선언

1부터 2까지의 경로 : 1 5 4 3 2
1부터 3까지의 경로 : 1 5 4 3
*/

void floyd(int n) {		//	n : 정점의 갯수
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				if (graph[start][mid] != INF && graph[mid][end] != INF)
					graph[start][end] = min(graph[start][end], graph[start][mid] + graph[mid][end]);
			}
		}
	}
}

int main() {
	int n, m;
	int from, to, fee;

	// n: 정점의 수, m: 간선의 수
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {        // graph 초기화
		for (j = 1; j <= n; j++) {
			graph[i][j] = INF;
		}
	}

	for (i = 0; i < m; i++) {		//	가중치 입력
		scanf("%d %d %d", &from, &to, &fee);
		graph[from][to] = min(graph[from][to], fee);		
	}

	floyd(n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j || graph[i][j] == INF) {
				printf("0 ");
			}
			else {
				printf("%d ", graph[i][j]);
			}			
		}
		printf("\n");
	}
}
