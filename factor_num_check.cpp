
#include<cstdio>
using namespace std;
int factor_num(int n)
{    int cnt=0;
    for(int i=1;i*i<=n;i++)
    {
        if(i*i==n)
        {
            cnt++;
        }
        else if(n%i==0)
        {
            cnt++;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int s,n,k,cnt=0;
    scanf("%d%d%d", &s ,&n ,&k);
    for (int i=s; i<=n; i++) {
        if (factor_num(i) == k) {
            printf("%d\n",i);
            cnt++;
        }
    }
    printf("cnt=%d\n",cnt);
    return 0;
}
