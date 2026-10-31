#include<bits/stdc++.h>
using namespace std;

/*
union-find
uniteは結合する2つのノードのうち1つを変える
findrootは再帰関数を用いる
printtreeはfindrootを用いて2次元の配列を作っていき、それを出力する
*/

class unionfind{
    public:
        vector<int> tree;
        vector<int> sizeoftree;

        unionfind(int n){
            this->tree=vector<int>(n,0);
            this->sizeoftree=vector<int>(n,1);
            for(int i=0;i<n;i++){
                this->tree.at(i)=i+1;
            }
        }

        vector<vector<int>> printtree(){
            vector<vector<int>> output(this->tree.size(),vector<int>(0,0));
            for(int i=0;i<this->tree.size();i++){
                output.at(findroot(this->tree.at(i))-1).push_back(i+1);
            }
            return output;
        }

        int findroot(int a){
            if(this->tree.at(a-1)!=a){
                a=findroot(this->tree.at(a-1));
            }
            return a;
        }

        void unite(int x,int y){ 
            int xroot=findroot(x),yroot=findroot(y);
            if(xroot==yroot){}
            else if(xroot!=x || yroot!=y){
                unite(xroot,yroot);
            }
            else{
                if(xroot<yroot){
                    this->tree.at(y-1)=xroot;
                    this->sizeoftree.at(x-1)+=this->sizeoftree.at(y-1);
                }
                else{
                    this->tree.at(x-1)=yroot;
                    this->sizeoftree.at(y-1)+=this->sizeoftree.at(x-1);
                }
            }
        }

        int findsame(int x,int y){
            return findroot(x)==findroot(y);
        }

        int findsize(int a){
            return sizeoftree.at(findroot(a)-1);
        }
};

int main(){
    int n,q;
    cin>>n>>q;
    int t,b,c;
    unionfind tree(n);
    for(int i=0;i<q;i++){
        cin>>t>>b>>c;
        if(t==0){
            tree.unite(b+1,c+1);
        }
        if(t==1){
            cout<<tree.findsame(b+1,c+1)<<endl;
        }
    }
    return 0;
}