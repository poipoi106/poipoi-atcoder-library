#include<bits/stdc++.h>
#include<atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
#define int long long

struct box{
    int len; //区間長.
    int sum; //区間の総和.
};

box op(box a,box b){
    return box{a.len+b.len,a.sum+b.sum};
}

box e(){
    return box{0,0};
}

box mapping(box e,box a){ //fはeを作用させること、f_e(a)みたいな感じ.
    return box{a.len,a.sum+a.len*e.sum};
}

box composition(box a,box b){
    return box{a.len+b.len,a.sum+b.sum};
}

box id(){
    return {0,0};
}

signed main(){
    int n,q;
    cin>>n>>q;
    lazy_segtree<box,op,e,box,mapping,composition,id> tree(vector<box>(n,box{1,0}));
    int f,s,t,x;
    for(int i=0;i<q;i++){
        cin>>f>>s>>t;
        if(f==0){
            cin>>x;
            tree.apply(s-1,t,box{0,x});
        }
        if(f==1){
            cout<<tree.prod(s-1,t).sum<<endl;
        }
    }
}