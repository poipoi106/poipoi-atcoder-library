#include<bits/stdc++.h>
using namespace std;
#define int long long

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

void write(map<int,int> &mp,int n){
    cout<<n<<": ";
    vector<int> ans(0,0);
    for(pair<int,int> pp:mp){
        for(int i=0;i<pp.second;i++){
            ans.push_back(pp.first);
        }
    }
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<ans.at(ans.size()-1)<<endl;
}

signed main(){
    int n;
    cin>>n;
    map<int,int> mp=factrization(n);
    write(mp,n);
}