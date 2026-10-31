#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
#define int long long

/*
dsuにいろいろ載せる.(DSL_1_B)

a_y-a_x=(a_y-a_l)-(a_x-a_l)=z.

コンストラクタ->すべてのfigを0に初期化.
relate(x,y,z)
xとyが非連結の場合:
新しいleaderをxとする.
もしgroups.at(x-1).size()<groups.at(y-1).size()であればswapを行い、情報を書き換える
leaderの判定はサイズが大きい方に固定されるため、高速に解ける.
*/

signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> fig(n,0); //a_x-a_leaderの値.
    vector<vector<int>> groups(n,vector<int>(0,0)); //連結成分に属するグループ. leaderのみ定義. 
    dsu tree(n);
    for(int i=0;i<n;i++){
        groups.at(i).push_back(i+1);
    }
    int t,x,y,z;
    for(int i=0;i<q;i++){
        cin>>t;
        if(t==0){
            cin>>x>>y>>z;
            if(tree.same(x,y)){
                continue;
            }
            int leader1=tree.leader(x)+1,leader2=tree.leader(y)+1;
            tree.merge(x,y);
            int newleader=tree.leader(x)+1,oldleader;
            if(newleader==leader1){
                oldleader=leader2;
                int p=fig.at(x)+z-fig.at(y);
                for(int j=0;j<groups.at(oldleader-1).size();j++){
                    int tp=p;
                    if(groups.at(oldleader-1).at(j)!=oldleader){
                        tp+=fig.at(groups.at(oldleader-1).at(j)-1);
                    }
                    fig.at(groups.at(oldleader-1).at(j)-1)=tp;
                    groups.at(newleader-1).push_back(groups.at(oldleader-1).at(j));
                }
            }
            else{
                oldleader=leader1;
                int p=fig.at(y)-z-fig.at(x);
                for(int j=0;j<groups.at(oldleader-1).size();j++){
                    int tp=p;
                    if(groups.at(oldleader-1).at(j)!=oldleader){
                        tp+=fig.at(groups.at(oldleader-1).at(j)-1);
                    }
                    fig.at(groups.at(oldleader-1).at(j)-1)=tp;
                    groups.at(newleader-1).push_back(groups.at(oldleader-1).at(j));
                }
            }
        }
        if(t==1){
            cin>>x>>y;
            if(tree.same(x,y)==0){
                cout<<"?"<<endl;
                continue;
            }
            cout<<fig.at(y)-fig.at(x)<<endl;
        }
    }
}