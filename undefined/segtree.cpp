#include<bits/stdc++.h>
using namespace std;

class segtree{
    public:
    vector<vector<long long int>> seg;
    long long int length;
    long long int depth=1;
    long long int ans;

    long long int op(long long int a,long long int b){
        return a+b;
    }
    
    long long int e(){
        return 0;
    }

    segtree(long long int t){
        this->length=t;
        long long int s=1;
        long long int u=1;
        while(1){
            if(u<this->length){
                u*=2;
            }
            else{ 
                break;
            }
        }
        this->length=u;
        while(1){
            if(s<this->length){
                this->depth+=1;
                s*=2;
            }
            else{
                break;
            }
        }
        this->seg=vector<vector<long long int>>(this->depth,vector<long long int>());
        s=1;
        for(int i=0;i<this->depth-1;i++){
            this->seg.at(i)=vector<long long int>(s,this->e());
            s*=2;
        }
        this->seg.at(this->depth-1)=vector<long long int>(this->length,this->e());
    }
    
    void set(long long int fig,int id){
        this->seg.at(this->depth-1).at(id)=fig;
        if(this->depth==1){
            return;
        }
        id/=2;
        for(int i=this->depth-2;i>-1;i--){
            this->seg.at(i).at(id)=this->op(this->seg.at(i+1).at(id*2),this->seg.at(i+1).at(id*2+1));
            id/=2;
        }
    }

    void sep(int maxleft,int maxright,int left,int right,int state1,int state2){
        if(state2>=length){}
        else if(maxleft<=left && right<=maxright){
            this->ans=op(ans,this->seg.at(state1).at(state2));
        }
        else if(right<=maxleft || left>=maxright){}
        else{
            sep(maxleft,maxright,left,(left+right)/2,state1+1,state2*2);
            sep(maxleft,maxright,(left+right)/2,right,state1+1,state2*2+1);
        }
    }

    long long int prod(int left,int right){
        this->ans=this->e();
        sep(left,right,0,this->length,0,0);
        return this->ans;
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    segtree tree(n);
    int t,x,y;
    for(int i=0;i<q;i++){
        cin>>t>>x>>y;
        if(t==1){
            tree.set(y,x-1);
        }
        else{
            cout<<tree.prod(x-1,y-1)<<endl;
        }
    }
}