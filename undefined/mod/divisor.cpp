#include<bits/stdc++.h>
using namespace std;

long long int power(long long int x,long long int n,long long int mod){
    long long int ans=1;
    vector<long long int> anslist(64,0);
    anslist.at(0)=x;
    for(int i=1;i<64;i++){
        anslist.at(i)=anslist.at(i-1)*anslist.at(i-1);
        anslist.at(i)%=mod;
    }
    for(int i=0;i<64;i++){
        if((n>>i)%2==1){
            ans*=anslist.at(i);
            ans%=mod;
        }
    }
    return ans;
}

long long int divisor(long long int x,long long int div,long long int mod){ //divはpで割り切れないようにする(割り切れる場合は答えが0になる)
    x%=mod;
    if(mod==1){
        return x;
    }
    long long int multiply=power(div,mod-2,mod);
    return x*multiply%mod;
}

int main(){
    long long int n,div,mod=998244353;
    cin>>n>>div;
    cout<<divisor(n,div,mod)<<endl;
}

