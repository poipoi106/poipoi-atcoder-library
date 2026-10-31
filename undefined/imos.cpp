#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
imos法ライブラリ.
1次元, 2次元, 1次以上の関数を表す際に使える.

(現状,2次元の方はcompress.cppを参照.)
*/

struct rect{
    int x1;
    int y1;
    int x2;
    int y2;
};

signed main(){
    int n;
    cin>>n;
    int x1,y1,x2,y2;
    set<int> xst,yst; //{マスの座標,左上なら1,右下なら-1}.
    vector<rect> rectlist(n);
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        rectlist.at(i)=rect{x1,y1,x2,y2};
        xst.insert(x1);
        xst.insert(x2);
        yst.insert(y1);
        yst.insert(y2);
    }
    vector<int> x(0,0),y(0,0);
    for(int t:xst){
        x.push_back(t);
    }
    for(int t:yst){
        y.push_back(t);
    }
    vector<vector<int>> board((int)x.size(),vector<int>(y.size(),0));
    for(int i=0;i<n;i++){
        rect cur=rectlist.at(i);
        //左上を足す操作.
        board.at(lower_bound(x.begin(),x.end(),cur.x1)-x.begin()).at(lower_bound(y.begin(),y.end(),cur.y1)-y.begin())+=1;
        //右下を引く操作.
        board.at(lower_bound(x.begin(),x.end(),cur.x2)-x.begin()).at(lower_bound(y.begin(),y.end(),cur.y2)-y.begin())-=1;
    }
    for(int i=0;i<(int)x.size();i++){
        for(int j=1;j<(int)y.size();j++){
            board.at(i).at(j)+=board.at(i).at(j-1);
        }
    }
    for(int j=0;j<(int)y.size();j++){
        for(int i=1;i<(int)x.size();i++){
            board.at(i).at(j)+=board.at(i-1).at(j);
        }
    }
    int ans=0;
    for(int i=0;i<(int)x.size()-1;i++){
        for(int j=0;j<(int)y.size()-1;j++){
            if(board.at(i).at(j)>=1){
                ans+=(x.at(i+1)-x.at(i))*(y.at(i+1)-y.at(i));
            }
        }
    }
    cout<<ans<<endl;
}