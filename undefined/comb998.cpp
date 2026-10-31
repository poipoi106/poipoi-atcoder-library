#include<bits/stdc++.h>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
#define int long long

using mint=modint998244353;

vector<mint> frac(10000001,1);

void calcfrac(){
    for(int i=1;i<(int)frac.size();i++){
        frac.at(i)=frac.at(i-1)*i;
    }
}

int comb(int a,int b){
    if(a<b){
        return 0;
    }
    mint ans=frac.at(a)/frac.at(b)/frac.at(a-b);
    return ans.val();
}

int comb_gred(int a,int b){
    if(a<b){
        return 0;
    }
    mint ans=1;
    for(int i=a,cnt=0;cnt<b;i--,cnt++){
        ans*=i;
    }
    for(int i=b;i>=1;i--){
        ans/=i;
    }
    return ans.val();
}

signed main(){
    int m,t;
    cin>>t>>m;
    calcfrac();
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        cout<<comb(a,b)<<endl;
    }
}