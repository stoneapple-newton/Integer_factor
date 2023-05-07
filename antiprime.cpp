
#include <iostream>
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
int main(int argc, const char * argv[]) {
    // insert code here...
    int maxn=0,maxfac=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if (factor_num(i)>maxfac) {
            maxn=i;
            maxfac=factor_num(i);
            printf("%d is an antiprime,with %d factors in it.\n",maxn,maxfac);//find anti-prime
            printf("%d 是一个反质数,它有 %d 个因子.\n",maxn,maxfac);
        }
    }
    return 0;
}
