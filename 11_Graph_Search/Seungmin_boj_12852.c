#include <stdio.h>

int answer[1000000];
int pick[1000000];
int min = 1000002;

void setDp(int mode, int depth, int N, int num)
{

    if (depth > min)
    {
        return;
    }
    if (num == 1)
    {
        if (min > depth)
        { //정답의 갱신일경우
            min = depth;
            pick[depth] = 1;
            for (int i = depth; i >= 0; i--)
            {
                answer[i] = pick[i];
            }
        }
        return;
    }
    if (mode == 0)
    {
        if (num % 3 == 0)
        {
            pick[depth] = num;
            setDp(0, depth + 1, N, num / 3);
            setDp(1, depth + 1, N, num / 3);
            setDp(2, depth + 1, N, num / 3);
        }
    }
    else if (mode == 1)
    {
        if (num % 2 == 0)
        {
            pick[depth] = num;
            setDp(0, depth + 1, N, num / 2);
            setDp(1, depth + 1, N, num / 2);
            setDp(2, depth + 1, N, num / 2);
        }
    }
    else
    {
        pick[depth] = num;
        setDp(0, depth + 1, N, num - 1);
        setDp(1, depth + 1, N, num - 1);
        setDp(2, depth + 1, N, num - 1);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    pick[0] = N;

    setDp(0, 0, N, N);
    setDp(1, 0, N, N);
    setDp(2, 0, N, N);

    printf("%d\n", min);

    for (int i = 0; i <= min; i++)
    {
        printf("%d ", answer[i]);
    }
}
