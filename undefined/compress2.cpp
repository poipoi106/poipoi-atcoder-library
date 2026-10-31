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

/*
i,j版. x,yで聞かれているならxをiに, yをjに言い換えることが必要.
*/

struct rect{
    int i1;
    int j1;
    int i2;
    int j2;
};

signed main(){
    int n;
    cin>>n;
    int i1,j1,i2,j2;
    set<int> ist,jst; //マスの座標 左上なら1,右下なら-1.
    vector<rect> rectlist(n);
    for(int i=0;i<n;i++){
        cin>>i1>>j1>>i2>>j2;
        rectlist.at(i)=rect{i1,j1,i2,j2};
        ist.insert(i1);
        ist.insert(i2);
        jst.insert(j1);
        jst.insert(j2);
    }
    vector<int> ivec(0,0),jvec(0,0);
    for(int t:ist){
        ivec.push_back(t);
    }
    for(int t:jst){
        jvec.push_back(t);
    }
    vector<vector<int>> board((int)ivec.size(),vector<int>(jvec.size(),0));
    for(int i=0;i<n;i++){
        rect cur=rectlist.at(i);
        //足す操作.
        board.at(lower_bound(ivec.begin(),ivec.end(),cur.i1)-ivec.begin()).at(lower_bound(jvec.begin(),jvec.end(),cur.j1)-jvec.begin())+=1;
        board.at(lower_bound(ivec.begin(),ivec.end(),cur.i2)-ivec.begin()).at(lower_bound(jvec.begin(),jvec.end(),cur.j2)-jvec.begin())+=1;

        //引く操作.
        board.at(lower_bound(ivec.begin(),ivec.end(),cur.i2)-ivec.begin()).at(lower_bound(jvec.begin(),jvec.end(),cur.j1)-jvec.begin())-=1;
        board.at(lower_bound(ivec.begin(),ivec.end(),cur.i1)-ivec.begin()).at(lower_bound(jvec.begin(),jvec.end(),cur.j2)-jvec.begin())-=1;

    }
    for(int i=0;i<(int)ivec.size();i++){
        for(int j=1;j<(int)jvec.size();j++){
            board.at(i).at(j)+=board.at(i).at(j-1);
        }
    }
    for(int j=0;j<(int)jvec.size();j++){
        for(int i=1;i<(int)ivec.size();i++){
            board.at(i).at(j)+=board.at(i-1).at(j);
        }
    }
    int ans=0;
    for(int i=0;i<(int)ivec.size()-1;i++){
        for(int j=0;j<(int)jvec.size()-1;j++){
            if(board.at(i).at(j)>=1){
                ans+=(ivec.at(i+1)-ivec.at(i))*(jvec.at(j+1)-jvec.at(j));
            }
        }
    }
    cout<<ans<<endl;
}