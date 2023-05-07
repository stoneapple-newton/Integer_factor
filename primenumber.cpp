
#include <cstdio>
#include<algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    if(n==1){
    	printf("NO");
    	return 0;
    }
    else{
    for(int i=2;i*i<=n;i++)
    {
    	if(n%i==0)
    	{
    		printf("NO");
    		return 0;
    	}
    }
    printf("YES");
    return 0;
    }
}
