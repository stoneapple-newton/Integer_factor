
#include<cstdio>
using namespace std;

int isp(int n){
    if(n==1){
        return 0;
    }
    else{
        for (int i=2; i*i<=n; i++) {
            if (n%i==0) {
                return 0;
            }
        }
        return 1;
    }
}
int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        if(isp(i)){
            printf("%d\n",i);
            cnt++;
        }
    }
    printf("cnt=%d\n",cnt);
    return 0;
}
