#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,s;
    cin>>n>>s;
    vector<int> alist(n,0);
    for(int i=0;i<n;i++){
        cin>>alist.at(i);
    }
    int ans=9e18,right=1,t=alist.at(0);
    for(int left=0;left<n;left++){
        if(left!=0){
            t-=alist.at(left-1);
        }
        while(right<n){
            if(t<s){
                t+=alist.at(right);
                right+=1;
            }
            else{
                break;
            }
        }
        if(t>=s){
            ans=min(ans,right-left);
        }
    }
    if(ans==9e18){
        cout<<0<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}