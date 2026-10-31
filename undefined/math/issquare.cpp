#include<bits/stdc++.h>
using namespace std;
#define int long long

int issquare(int n){ //n<=10^18. nが何かの数の2乗か確かめる.
    int ok=0,ng=1000000001,mid;
    while(ng-ok>1){
        mid=(ng+ok)/2;
        if(mid*mid<=n){
            ok=mid;
        }
        else{
            ng=mid;
        }
    }
    if(ok*ok==n){
        return ok;
    }
    return -1;
}

signed main(){
    int n;
    cin>>n;
    if(issquare(n)!=-1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
