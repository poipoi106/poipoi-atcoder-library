#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> bellmanford(vector<vector<int>> &graph,vector<vector<int>> &weight,int start){
    int n=graph.size();
    if(n==1){
        return {0};
    }
    vector<int> ans(n,9e18);
    ans.at(start-1)=0;
    int v,w;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<graph.at(j).size();k++){
                v=graph.at(j).at(k);
                w=weight.at(j).at(k);
                if(ans.at(v-1)>ans.at(j)+w){
                    ans.at(v-1)=ans.at(j)+w;
                }
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<graph.at(j).size();k++){
            v=graph.at(j).at(k);
            w=weight.at(j).at(k);
            if(ans.at(v-1)>ans.at(j)+w){
                return vector<int>(n,-1);
            }
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(0,0));
    vector<vector<int>> weight(n,vector<int>(0,0));
    int u,v;
    int w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        graph.at(u-1).push_back(v);
        weight.at(u-1).push_back(w);
    }
    vector<int> ans=bellmanford(graph,weight,1);
    return 0;
}