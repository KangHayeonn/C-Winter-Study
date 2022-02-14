#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, A, B, C;
    long long **map;

    long long INF = 800000000000L;
    int sussess = 1;
    scanf("%d %d", &N, &M);
    long long *distance = (long long *)malloc(sizeof(long long) * N);
    map = (long long **)malloc(sizeof(long long *) * N);
    for (int i = 0; i < N; i++)
    {
        map[i] = (long long *)malloc(sizeof(long long) * N);
        for (int j = 0; j < N; j++)
        {
            map[i][j] = INF;
        }

        distance[i] = INF;
    }
    distance[0] = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &A, &B, &C);
        if (map[A - 1][B - 1] > C)
            map[A - 1][B - 1] = C;
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (map[j][k] == INF)
                    continue;
                if (distance[j] == INF)
                    continue;
                if (distance[k] > distance[j] + map[j][k])
                    distance[k] = distance[j] + map[j][k];
            }
        }
    }

    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < N; k++)
        {
            if (map[j][k] == INF)
                continue;
            if (distance[j] == INF)
                continue;
            if (distance[k] > distance[j] + map[j][k])
                sussess = 0;
        }
    }

    if (!sussess)
    {
        printf("-1");
    }
    else
        for (int i = 1; i < N; i++)
        {
            if (distance[i] == INF)
                printf("-1\n");
            else
                printf("%d\n", distance[i]);
        }
}
