#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
制約に注意!
N=200程度ならワーシャルフロイド法を使う方がよい.
*/

vector<int> dijkstra(vector<vector<int>> &graph,vector<vector<int>> &weight,int start){ //1-indexed.
    int n=graph.size();
    vector<int> ans(n,9e18);
    set<int> used;
    ans.at(start-1)=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
    qu.push({0,start});
    pair<int,int> state;
    while(qu.size()){
        state=qu.top();
        qu.pop();
        if(used.count(state.second)){
            continue;
        }
        used.insert(state.second);
        for(int i=0;i<graph.at(state.second-1).size();i++){
            if(used.count(graph.at(state.second-1).at(i))==0 && ans.at(state.second-1)+weight.at(state.second-1).at(i)<ans.at(graph.at(state.second-1).at(i)-1)){
                ans.at(graph.at(state.second-1).at(i)-1)=ans.at(state.second-1)+weight.at(state.second-1).at(i);
                qu.push({ans.at(graph.at(state.second-1).at(i)-1),graph.at(state.second-1).at(i)});
            }
        }
    }
    return ans;
}

signed main(){
    int n,m,r;
    cin>>n>>m>>r;
    vector<vector<int>> graph(n,vector<int>(0,0)),weight(n,vector<int>(0,0));
    int a,b,c;
    for(int i=0;i<m;i++){ //有向グラフの場合.
        cin>>a>>b>>c;
        a+=1,b+=1;
        graph.at(a-1).push_back(b);
        weight.at(a-1).push_back(c);
    }
    vector<int> ans=dijkstra(graph,weight,r+1);
    for(int i=0;i<n;i++){
        if(ans.at(i)==9e18){
            cout<<"INF"<<endl;
        }
        else{
            cout<<ans.at(i)<<endl;
        }
    }
}
