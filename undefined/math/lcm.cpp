#include<bits/stdc++.h>
using namespace std;
#define int long long

int lcm_arr(vector<int> &arr){
    int ans=arr.at(0);
    for(int i=1;i<arr.size();i++){
        ans=lcm(ans,arr.at(i));
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<int> alist(n,0);
    for(int i=0;i<n;i++){
        cin>>alist.at(i);
    }
    cout<<lcm_arr(alist)<<endl;
}