#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
ビットシフトで括弧を付けるのを忘れない.
((2>>0)&1)==0みたいに.
*/

int powint(int x,int n){
    int ans=1;
    for(int i=0;i<n;i++){
        ans*=x;
    }
    return ans;
}

int comp(int a,int b){
    return __builtin_popcount(a)<__builtin_popcount(b);
}

void solve(int n){
    vector<int> nosoubi(n,0);
    vector<vector<int>> soubi(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        cin>>nosoubi.at(i);
        for(int j=0;j<n;j++){
            cin>>soubi.at(i).at(j);
        }
    }
    vector<int> order(powint(2,n),0); //dpを配る順番.
    for(int i=0;i<powint(2,n);i++){
        order.at(i)=i;
    }
    sort(order.begin(),order.end(),comp);
    vector<int> dp(powint(2,n),9e18);
    dp.at(0)=0;
    for(int i=0;i<powint(2,n)-1;i++){
        for(int j=0;j<n;j++){
            if(((i>>j)&1)==0){
                int t=nosoubi.at(j);
                for(int k=0;k<n;k++){
                    if(((i>>k)&1)==1){
                        t=min(t,soubi.at(j).at(k));
                    }
                }
                dp.at(i+powint(2,j))=min(dp.at(i+powint(2,j)),dp.at(i)+t);
            }
        }
    }
    cout<<dp.at(powint(2,n)-1)<<endl;
}

signed main(){
    int n;
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        solve(n);
    }
}