#include<ctime>
#include<random>
#include<iostream>
#include<algorithm>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
typedef __int128_t lll;
typedef long double ld;

ll qmul(ll a,ll b,ll mod)
{
    ll c=(ld)a/mod*b;
    ll res=(ull)a*b-(ull)c*mod;
    return (res+mod)%mod;
}
ll qpow(ll a,ll n,ll mod)
{
    ll res=1;
    while(n)
    {
        if(n&1) res=qmul(res,a,mod);
        a=qmul(a,a,mod);
        n>>=1;
    }
    return res;
}
bool is_prime(ll n)
{
    if(n<3||n%2==0) return n==2;
    ll u=n-1,t=0;
    while(u%2==0) u/=2,++t;
    ll ud[]={2,325,9375,28178,450775,9780504,1795265022};
    for(ll a:ud)
    {
        ll v=qpow(a,u,n);
        if(v==1||v==n-1||v==0) continue;
        for(int j=1;j<=t;j++)
        {
            v=qmul(v,v,n);
            if(v==n-1&&j!=t){v=1;break;}
            if(v==1) return 0;
        }
        if(v!=1) return 0;
    }
    return 1;
}
ll randint(ll r){
    uint32_t a = (uint32_t)time(nullptr);
    srand(a);
    ll h = (ll)rand() << 32;
    return (h + rand()) % r;
}

void fermat(ll n)
{
    if(is_prime(n))
    {
        cout << n;
        return;
    }
 
    // check if n is a even number
    if((n & 1) == 0)
    {
        cout << 2;
        return;
    }
         
    ll a = ceil(sqrt(n)) ;
 
    // if n is a perfect root,
    // then both its square roots are its factors
    if(a * a == n)
    {
        cout << a;
        return;
    }
    int b;
    while(true)
    {
        ll b1 = a * a - n ;
        b = (int)sqrt(b1) ;
         
        if(b * b == b1)
            break;
        else
            a += 1;
    }
    cout << (a - b);
    return;
}
     
int main(){
    ll n;
    cin >> n;
    clock_t t1 = clock();
    fermat(n);
    clock_t t2 = clock();
    cout << "\ntime used:" << t2-t1 << "ms\n";
    return 0;
}
