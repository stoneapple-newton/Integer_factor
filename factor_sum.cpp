#include <cstdio>
using namespace std;

int factor_sum(int n)
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
	return sum;
}
int main() 
{
	int n;
	scanf("%d", &n);
    printf("%d\n", factor_sum(n));
    return 0;
}
