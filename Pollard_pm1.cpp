#include<ctime>
#include<random>
#include<iostream>
#include<algorithm>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
typedef __int128_t lll;
typedef long double ld;
ll gcd(ll a,ll b){
    if(b>a)swap(a,b);
    if(b==0)return a;
    return gcd(b, a%b);
}
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
ll Pollard_pm1(ll n,ll b){
    if(is_prime(n))return n;
    if(n % 2 == 0)return 2;
    int i = 1;
    while (1){
        i++;
        b = qpow(b, i, n);
        ll g = gcd(b - 1, n);
        if(g != 1 && g != n)return g;
    }
}
int main(){
    ll n;
    cin >> n;
    clock_t t1 = clock();
    cout << Pollard_pm1(n, 2);
    clock_t t2 = clock();
    cout << "\ntime used:" << t2-t1 << "ms\n";
    return 0;
}
