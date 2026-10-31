#include<bits/stdc++.h>
#include<atcoder/math>
using namespace std;
using namespace atcoder;
#define int long long
//正の整数nについて、1からnまでの自然数のうちnと互いに素なものの個数を求める. nは10^9以下. 計算量O((logn)^2)くらい.

map<int,int> factrization(int n){
    map<int,int> mp;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]=mp[i]+1;
            n/=i;
        }
    }
    if(n!=1){
        mp[n]=mp[n]+1;
    }
    return mp;
}

int powint(int x,int n,int mod){
    return pow_mod(x,n,mod);
}

int euler_phi(map<int,int> &mp){
    int ans=1;
    int mod=2e9;
    for(pair<int,int> pp:mp){
        ans*=powint(pp.first,pp.second,mod)-powint(pp.first,pp.second-1,mod);
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    map<int,int> f=factrization(n);
    cout<<euler_phi(f)<<endl;
}