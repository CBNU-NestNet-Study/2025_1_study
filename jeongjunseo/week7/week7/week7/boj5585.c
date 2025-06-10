#include <stdio.h>
void Change()
{
    int Coin[6] = { 500,100,50,10,5,1 };
    int cnt = 0;
    int N;
    int i = 0;
    scanf("%d", &N);
    N = 1000 - N;
    while (N > 0)
    {
        if (N >= Coin[i])
        {
            N -= Coin[i];
            cnt++;
        }
        else
            i++;
    }
    printf("%d", cnt);
}
int main()
{
    Change();
}
