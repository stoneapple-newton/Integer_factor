
#include<cstdio>
using namespace std;

int facsum(int n)
{
    int sum=0;
    for(int i=1;i*i<=n;i++)
    {
        if(i*i==n)
        {
            sum+=i;
        }
        else if(n%i==0)
        {
            sum+=i+n/i;
        }
    }
    return sum-n;
}
int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        if (facsum(facsum(i))==i&&facsum(i)!=i) {
            printf("%d\n",i);
            cnt++;
        }
    }
    printf("cnt=%d\n",cnt/2);
    return 0;
}
