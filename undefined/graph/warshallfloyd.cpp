#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> warshallfloyd(vector<vector<int>> &graph,vector<vector<int>> &weight){
    int n=graph.size();
    vector<vector<int>> ans(n,vector<int>(n,1e17));
    for(int i=0;i<n;i++){
        ans.at(i).at(i)=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<graph.at(i).size();j++){
            ans.at(i).at(graph.at(i).at(j)-1)=weight.at(i).at(j);
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans.at(i).at(k)!=1e17 && ans.at(k).at(j)!=1e17){
                    ans.at(i).at(j)=min(ans.at(i).at(j),ans.at(i).at(k)+ans.at(k).at(j));
                }
            }
        }
    }
    int minans=0;
    for(int i=0;i<n;i++){
        minans=min(minans,ans.at(i).at(i));
    }
    if(minans<0){
        return {};
    }
    return ans;
}

signed main(){
    int n,m;
    cin>>n>>m;
    int u,v,w;
    vector<vector<int>> graph(n,vector<int>(0,0)),weight(n,vector<int>(0,0));
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        u+=1;
        v+=1;
        graph.at(u-1).push_back(v);
        weight.at(u-1).push_back(w);
    }
    vector<vector<int>> dist=warshallfloyd(graph,weight);
    if(dist==vector<vector<int>>(0)){
        cout<<"NEGATIVE CYCLE"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(dist.at(i).at(j)==1e17){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dist.at(i).at(j)<<" ";
            }
        }
        if(dist.at(i).at(n-1)==1e17){
            cout<<"INF"<<endl;
        }
        else{
            cout<<dist.at(i).at(n-1)<<endl;
        }
    }
}