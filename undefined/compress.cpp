#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
2次元の座標圧縮. 

X1,X2 と Y1,Y2 で分けて、一次元での座標圧縮を行う(以下 X1,X2 について考える)
X1,X2 の要素と、その一つ隣の要素を全てまとめて、ソートした結果を vals とする
vals の重複した値を削除する
X1,X2 のそれぞれの要素について、vals の中の何番目に出現するかを二分探索などで調べる
(アルゴリズムロジックより)

以下の問題では,
点のx座標とy座標をそれぞれ記録しておく.
座標圧縮をする. 
imos法をする. 
imos法で1以上となったマスに対してその多重度を答えに足す.
*/

/*
n本の線分は平面を最大(n^2+n+2)/2個に
n枚の平面は空間を最大(n^3+5n+6)/6個に分割する.
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
        //足す操作.
        board.at(lower_bound(x.begin(),x.end(),cur.x1)-x.begin()).at(lower_bound(y.begin(),y.end(),cur.y1)-y.begin())+=1;
        board.at(lower_bound(x.begin(),x.end(),cur.x2)-x.begin()).at(lower_bound(y.begin(),y.end(),cur.y2)-y.begin())+=1;

        //引く操作.
        board.at(lower_bound(x.begin(),x.end(),cur.x2)-x.begin()).at(lower_bound(y.begin(),y.end(),cur.y1)-y.begin())-=1;
        board.at(lower_bound(x.begin(),x.end(),cur.x1)-x.begin()).at(lower_bound(y.begin(),y.end(),cur.y2)-y.begin())-=1;

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
                ans+=(x.at(i+1)-x.at(i))*(y.at(j+1)-y.at(j));
            }
        }
    }
    cout<<ans<<endl;
}