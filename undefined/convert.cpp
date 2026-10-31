#include<bits/stdc++.h>
using namespace std;
#include<atcoder/scc>
using namespace atcoder;
#define int long long

vector<vector<int>> convert32_64(vector<vector<int32_t>> a){
    vector<vector<int>> ans(a.size(),vector<int>(0,0));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.at(i).size();i++){
            ans.at(i).push_back((int)a.at(i).at(j));
        }
    }
    return ans;
}

signed main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    scc_graph graph(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph.add_edge(a-1,b-1);
    }
    int ans=0;
    vector<vector<int32_t>> tlist=graph.scc();
    vector<vector<int>> scclist=convert32_64(tlist);
}
