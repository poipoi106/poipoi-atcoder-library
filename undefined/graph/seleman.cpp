#include<bits/stdc++.h>
using namespace std;
#define int long long

int powint(int x,int n){
    int ans=1;
    for(int i=0;i<n;i++){
        ans*=x;
    }
    return ans;
}

int selesman(vector<vector<int>> &graph,vector<vector<int>> &weight){
    int n=graph.size();
    int inf=1e9; //適宜変える.
    vector<vector<int>> edgelist(n,vector<int>(n,inf));
    for(int i=0;i<n;i++){
        for(int j=0;j<graph.at(i).size();j++){
            int u=i+1,v=graph.at(i).at(j);
            edgelist.at(i).at(v-1)=weight.at(i).at(j);
        }
    }
    
}

signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(0,0)),weight(n,vector<int>(0,0));
    int s,t,d;
}