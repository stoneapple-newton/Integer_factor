
#include<cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	if(n<3)
	{
		printf("1");
	}
	else
	{
		long long l1=1,l2=1;
		long long now;
		for(int i=3;i<=n;i++)
		{
			now=l1+l2;
			l2=l1;
			l1=now;
		}
		printf("%lld",now);
	}
}
