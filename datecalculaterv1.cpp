
#include<cstdio>
#include<iostream>
using namespace std;
bool isleap(int y){
    if (y%4==0&&y%100!=0) {
        return 1;
    }
    return 0;
}
int monthday(int y,int m){
    switch (m) {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;break;
        case 4:case 6:case 9:case 11:return 30;break;
        case 2:return 28+int(isleap(y));break;
        default:return 0;break;
    }
}

int difday(int ys,int ms,int ds,int y,int m,int d){
    int cnt=-1;
    cnt+=365*(y-ys);
    for (int i=ys+1; i<=y-1; i++) {
        cnt+=int(isleap(i));
    }
    while (ms<=12) {
        ds++;
        if (ds>monthday(ys, ms)) {
            ds=1;
            ms++;
        }
        cnt++;
    }
    ms=1;
    ds=1;
    while (ms<m) {
        ds++;
        if (ds>monthday(ys, ms)) {
            ds=1;
            ms++;
        }
        cnt++;
    }
    cnt+=d;
    return cnt;
}

int main(){
    int ys,ms,ds,y,m,d,ans;
    cin>>ys>>ms>>ds>>y>>m>>d;
    ans=difday(ys, ms, ds, y, m, d);
    printf("the diffrence of %d . %d . %d and %d . %d . %d is %d days\n",ys,ms,ds,y,m,d,ans);
    return 0;
}
