// 플로이드 (백준 11404번)

// 플로이드 와샬 이용

#include <stdio.h>
#include <stdlib.h>

int** graph;

void floyd_warshall(int** graph, int n);

int main() {
	int n; // 도시(정점)의 개수
	int m; // 버스(간선)의 개수
	scanf("%d %d", &n, &m);

	graph = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		graph[i] = (int*)malloc(sizeof(int) * (n + 1));
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else {
				graph[i][j] = 10000000;
				graph[j][i] = 10000000;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		if (graph[from - 1][to - 1] > weight) graph[from - 1][to - 1] = weight; // 노선이 하나가 아닐 경우 더 작은 값을 weight로 설정
	}

	floyd_warshall(graph, n);
}

void floyd_warshall(int** graph, int V) {
	for (int i = 0; i < V; i++) { // i : 경유지 설정
		for (int j = 0; j < V; j++) { // j : 시작 정점, k : 도착 정점
			for (int k = 0; k < V; k++) {
				if (graph[j][k] > graph[j][i] + graph[i][k]) {
					graph[j][k] = graph[j][i] + graph[i][k];
				}
			}
		}
	}

	for (int i = 0; i<V; i++) {
		for (int j = 0; j < V; j++) {
			if (graph[i][j] == 10000000) printf("%d ", 0);
			else printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}