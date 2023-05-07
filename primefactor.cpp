
#include<iostream>
using namespace std;


void factornum(int n)
{
    cout<<n<<" = ";
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            cout<<i;
            n/=i;
            if(n!=1){
                cout<<" * ";
            }
        }
    }
    if(n!=1){
        cout<<n;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    for (int i=2; i<=n; i++) {
        factornum(i);
    }
    return 0;
}
