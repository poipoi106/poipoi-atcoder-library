#include<bits/stdc++.h>
#include<atcoder/math>
using namespace std;
using namespace atcoder;
#define int long long

int powint(int x,int n,int mod){
    return pow_mod(x,n,mod);
}

signed main(){
    int n,m;
    cin>>n>>m;
    int mod=1000000007;
    cout<<pow_mod(n,m,mod)<<endl;
}