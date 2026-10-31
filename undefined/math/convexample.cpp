#include<bits/stdc++.h>
#include<atcoder/modint>
#include<atcoder/convolution>
using namespace std;
using namespace atcoder;
#define int long long

using mint=modint998244353;

/*
ACLの畳み込みライブラリの使用例.
問題はJAG2023のD問題.
D問題は[x^N](\Sigma_{i=0}^{255} ix^i mod m)を求める.
1回の畳み込みは配列の長さn=a+b-1に対してO(nlogn).
*/

void solve(int k,int n){
    vector<vector<mint>> ans(11);
    ans.at(0)=vector<mint>(min(256LL,n+1),0);
    for(int i=0;i<min(256LL,n+1);i++){
        ans.at(0).at(i)=i;
    }
    for(int i=1;i<11;i++){
        ans.at(i)=convolution(ans.at(i-1),ans.at(i-1));
    }
    vector<mint> fans(0);
    for(int i=0;i<11;i++){
        if(((k>>i)&1)==1){
            if(fans.size()==0){
                fans=ans.at(i);
            }
            else{
                fans=convolution(fans,ans.at(i));
            }
        }
    }
    cout<<fans.at(n).val()<<endl;
}

signed main(){
    int k,n;
    while(1){
        cin>>k>>n;
        if(k+n==0){
            break;
        }
        else{
            solve(k,n);
        }
    }
}