#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
#define int long long

//グリッド問題の例.

vector<int> di={0,-1,0,1},dj={1,0,-1,0};

pair<int,int> idtozahyo(int a,int w){
    a-=1;
    return {a/w,a%w};
}

int zahyotoid(pair<int,int> pp,int w){
    return pp.first*w+pp.second+1;
}

signed main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> board(h,vector<char>(w,'0'));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>board.at(i).at(j);
        }
    }
    vector<vector<int>> graph(h*w,vector<int>(0,0));
    vector<int> mobile(h*w,1);
    int clear=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            clear=1;
            for(int k=0;k<4;k++){
                if(0<=i+di.at(k) && i+di.at(k)<=h-1 && 0<=j+dj.at(k) && j+dj.at(k)<=w-1){
                    if(board.at(i+di.at(k)).at(j+dj.at(k))=='#'){
                        clear=0;
                    }
                }
            }
            if(board.at(i).at(j)=='#'){
                clear=0;
            }
            mobile.at(zahyotoid({i,j},w)-1)=clear;
            if(clear){
                for(int k=0;k<4;k++){
                    if(0<=i+di.at(k) && i+di.at(k)<=h-1 && 0<=j+dj.at(k) && j+dj.at(k)<=w-1){
                        graph.at(zahyotoid({i,j},w)-1).push_back(zahyotoid({i+di.at(k),j+dj.at(k)},w));
                    }
                }
            }
        }
    }
    vector<int> usedlist(h*w,0);
    int ans=1;
    for(int i=0;i<h*w;i++){
        if(mobile.at(i)==0){
            continue;
        }
        if(usedlist.at(i)==1){
            continue;
        }
        int state;
        deque<int> qu;
        set<int> st;
        usedlist.at(i)=1;
        st.insert(i+1);
        qu.push_back(i+1);
        while(qu.size()){
            state=qu.front();
            qu.pop_front();
            for(int j=0;j<graph.at(state-1).size();j++){
                int nextv=graph.at(state-1).at(j);
                if(st.count(nextv)){
                    continue;
                }
                else if(mobile.at(nextv-1)==0){
                    st.insert(nextv);
                }
                else{
                    usedlist.at(nextv-1)=1;
                    st.insert(nextv);
                    qu.push_back(nextv);
                }
            }
        }
        ans=max(ans,(int)st.size());
    }
    cout<<ans<<endl;
}