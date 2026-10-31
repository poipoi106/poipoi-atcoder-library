#include<bits/stdc++.h>
using namespace std;
#define int long long

int bfs(vector<vector<int>> &graph){
    int n=(int)graph.size();
    vector<int> anslist(n,1);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<graph.at(i).size();j++){
            anslist.at(graph.at(i).at(j)-1)=max(anslist.at(graph.at(i).at(j)-1),anslist.at(i)+1);
            ans=max(ans,anslist.at(graph.at(i).at(j)-1));
        }
    }
    return ans;
}

int comp(int mid,vector<pair<int,int>> &cloth,vector<pair<int,int>> &clothreturn,int k){
    int n=(int)cloth.size();
    vector<vector<int>> graph(n,vector<int>(0,0));
    for(int i=0;i<n-1;i++){
        pair<int,int> state=cloth.at(i);
        int nextstart=state.second+mid;
        int itr=lower_bound(cloth.begin(),cloth.end(),make_pair(nextstart,nextstart+1))-cloth.begin();
        if(itr==n){
            continue;
        }
        graph.at(i).push_back(clothreturn.at(itr).second);
    }
    if(bfs(graph)>=k){
        return 1;
    }
    return 0;
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> cloth(n);
    for(int i=0;i<n;i++){
        cin>>cloth.at(i).first>>cloth.at(i).second;
    }
    sort(cloth.begin(),cloth.end());
    vector<pair<int,int>> clothreturn(n); //{end,id}.
    clothreturn.at(n-1)={cloth.at(n-1).second,n-1};
    for(int i=n-2;i>-1;i--){
        if(cloth.at(i).second<=clothreturn.at(i+1).first){
            clothreturn.at(i)={cloth.at(i).second,i+1};
        }
        else{
            clothreturn.at(i)=clothreturn.at(i+1);
        }
    }
    int ok=0,ng=1000000000-1,mid;
    while(ng-ok>1){
        mid=(ng+ok)/2;
        if(comp(mid,cloth,clothreturn,k)){
            ok=mid;
        }
        else{
            ng=mid;
        }
    }
    if(ok==0){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ok<<endl;
}