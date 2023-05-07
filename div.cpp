
#include<cstdio>
using namespace std;

int main(){
    int a,b,n,sh = 0 ,yu,i;
    scanf("%d%d%d",&a,&b,&n);
    printf("%d",a/b);
    printf(".");
    yu=a%b;
    for(int i=1;i<=n;i+=1)
    
    {
        sh=yu*10/b;
        yu=yu*10%b;
        printf("%d",sh);
    }
    printf("\n");
    return 0;
}
