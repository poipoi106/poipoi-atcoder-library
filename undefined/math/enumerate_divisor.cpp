#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> enumerate_divisor(int n){
    set<int> st;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            st.insert(i);
            st.insert(n/i);
        }
    }
    vector<int> ans(0,0);
    for(int t:st){
        ans.push_back(t);
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    cout<<(1LL<<30)<<endl;
    vector<int> ans=enumerate_divisor((1LL<<30));
    cout<<ans.size()<<endl;
    /*
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<ans.at(ans.size()-1)<<endl;
    */
}