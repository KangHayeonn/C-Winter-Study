#include <stdio.h>

//1,2,3 말고는 상 가능 1470 말고는 좌 가능 %3 !=1 %3!=0말고는 우 가능 (0은예외) 7890말고는 하 가능.

int setDp(int dp[1000][10], int depth, int N, int mode)
{
    if (dp[depth][mode] != 0)       //이미 계산한 결과
    {
        return dp[depth][mode];
    }
    if (depth == 0)     //1자리는 무조건 1
    {
        return 1;
    }
    if (mode == 0)      //0은 특별케이스
    {
        return dp[depth][mode] = setDp(dp, depth - 1, N, 7);
    }
    else
    {
        if (mode % 3 != 1)
        {
            dp[depth][mode] += setDp(dp, depth - 1, N, mode - 1);
        }
        if (mode > 3)
        {
            dp[depth][mode] += setDp(dp, depth - 1, N, mode - 3);
        }
        if (mode % 3 != 0)
        {
            dp[depth][mode] += setDp(dp, depth - 1, N, mode + 1);
        }
        if (mode < 7)
        {
            dp[depth][mode] += setDp(dp, depth - 1, N, mode + 3);
        }
        else if (mode == 7)     //7도 특별케이스
        {
            dp[depth][mode] += setDp(dp, depth - 1, N, 0);
        }
        return dp[depth][mode] %= 1234567;      //미리 1234567을 나눠준다
    }
}

int main()
{
    int testNum;
    int N;
    int sum, temp;
    int dp[1000][10];
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dp[i][j] = 0;
        }
    }
    scanf("%d", &testNum);

    for (int i = 0; i < testNum; i++)
    {
        scanf("%d", &N);
        sum = 0;

        for (int i = 0; i < 10; i++)
        {
            temp = setDp(dp, N - 1, N, i);
            sum += temp;
            sum %= 1234567;
        }
        printf("%d\n", sum);
    }
}
