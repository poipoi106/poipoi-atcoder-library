#include<bits/stdc++.h>
using namespace std;
#define int long long

struct distbox{
    int dist;
    int id;
};

bool operator<(distbox a,distbox b){
    return a.dist<b.dist;
}

vector<distbox> calcdist(vector<vector<int>> &graph){ //頂点startからのdistを出し, ソート. {dist}
    int start=1;
    int n=graph.size();
    vector<distbox> dist(n,distbox{-1,-1});
    for(int i=0;i<n;i++){
        dist.at(i).id=i+1;
    }
    deque<int> qu;
    int state;
    qu.push_back(start);
    dist.at(start-1).dist=0;
    while(qu.size()){
        state=qu.front();
        qu.pop_front();
        for(int i=0;i<graph.at(state-1).size();i++){
            int nextv=graph.at(state-1).at(i);
            if(dist.at(nextv-1).dist==-1){
                dist.at(nextv-1).dist=dist.at(state-1).dist+1;
                qu.push_back(nextv);
            }
        }
    }
    sort(dist.begin(),dist.end());
    reverse(dist.begin(),dist.end());
    return dist;
}

signed main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n,vector<int>(0,0));
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        graph.at(u-1).push_back(v);
        graph.at(v-1).push_back(u);
    }
    vector<distbox> dist=calcdist(graph);
}