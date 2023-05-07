#include <cstdio>
using namespace std;
int factor_num(int n)
{	int cnt=0;
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
	int n;
	scanf("%d", &n);
    printf("%d\n", factor_num(n));
    return 0;
}
