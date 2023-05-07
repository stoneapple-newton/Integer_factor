
#include<cstdio>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    bool a[n+1];
    memset(a, 1, sizeof(a));
    a[0]=a[1]=0;
    for (int i=2; i<=n; i++) {
        if (a[i]==0) {
            continue;
        }
        else{
            for (int j=2; i*j<=n; j++) {
                a[i*j]=0;
            }
        }
    }
    /*print the value of prime numbers*/
    for (int k=0; k<=n; k++) {
        if (a[k]==1) {
            printf("%d\n",k);
        }
    }
    return 0;
}
