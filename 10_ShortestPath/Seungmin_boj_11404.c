#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, **shortestMap, start, destination, cost;
    scanf("%d %d", &N, &M);
    shortestMap = (int **)malloc(sizeof(int *) * N);

    for (int i = 0; i < N; i++)
    {
        shortestMap[i] = (int *)malloc(sizeof(int) * N);

        for (int j = 0; j < N; j++)
        {
            if (i != j)
                shortestMap[i][j] = 1000000001;
            else
                shortestMap[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &start, &destination, &cost);

        if (shortestMap[start - 1][destination - 1] > cost)
            shortestMap[start - 1][destination - 1] = cost;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (shortestMap[j][k] > shortestMap[i][k] + shortestMap[j][i])
                    shortestMap[j][k] = shortestMap[i][k] + shortestMap[j][i];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (shortestMap[i][j] == 1000000001)
                printf("0 ");
            else
                printf("%d ", shortestMap[i][j]);
        }
        printf("\n");
    }
}
