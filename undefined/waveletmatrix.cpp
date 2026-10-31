#include<bits/stdc++.h>
using namespace std;
#define int long long

class binarytrie{ //整数が何個あるか数えるbinarytrie.
    public:
    vector<vector<int>> tree;
    int h;
    binarytrie(int maxa,vector<int> vec){ //O(n).
        int clear=0;
        for(int i=0;i<61;i++){
            if(maxa<=(1<<i)){
                this->h=i;
                clear=1;
                break;
            }
        }
        if(clear==0){
            throw("maxa is too big");
        }
        tree=vector<vector<int>>(h+1);
        for(int i=1;i<h+1;i++){
            tree.at(i)=vector<int>((1LL<<i),0);
        }
        int id=0;
        for(int i=0;i<vec.size();i++){
            id=0;
            for(int j=h-1,k=1;j>-1;j--,k++){
                if((vec.at(i)>>j)&1==1){
                    tree.at(k).at(id+1)+=1;
                    id+=(1<<k);
                }
                else{
                    tree.at(k).at(id)+=1;
                }
            }
        }
    }
};

class waveletmatrix{
    public:
    vector<vector<int>> tree,treeid;
    int h;
    waveletmatrix(int maxa,vector<int> vec){ //O(n). 配列のサイズは事前に決めておく.
        int clear=0;
        for(int i=0;i<61;i++){
            if(maxa<=(1<<i)){
                this->h=i;
                clear=1;
                break;
            }
        }
        if(clear==0){
            throw("maxa is too big");
        }
        tree=vector<vector<int>>(h); //idが大きい方が下ビット.
        treeid=vector<vector<int>>(h);
        for(int i=0;i<h;i++){
            tree.at(i)=vector<int>(vec.size(),0);
            treeid.at(i)=vector<int>(vec.size(),0);
        }
        for(int i=0;i<vec.size();i++){
            treeid.at(h-1).at(i)=i+1;
        }
        int id=0;
        for(int i=h-1;i>-1;i--){ //waveletmatrixを作る.
            int zero=0,one=0;
            for(int j=0;j<vec.size();j++){
                if((vec.at(treeid.at(i).at(j)-1)>>i)==1){
                    tree.at(i).at(j)=1;
                    one+=1;
                }
                else{
                    tree.at(i).at(j)=0;
                }
            }
            if(i!=0){
                for(int j=0;j<vec.size();j++){
                    if(tree.at(i).at(j)==0){
                        treeid.at(i-1).at(zero)=treeid.at(i).at(j);
                        zero+=1;
                    }
                    else{
                        treeid.at(i-1).at(one)=treeid.at(i).at(j);
                        one+=1;
                    }
                }
            }
        }
    }
};

signed main(){
}