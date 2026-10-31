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

signed main(){
    binarytrie a((1LL<<62));
}