#include<bits/stdc++.h>
using namespace std;

class doubling{
    public:
        vector<int> former;
        vector<vector<int>> dp;
        doubling(int length){
            this->former=vector<int>(length,0);
            for(int i=0;i<length;i++){
                cin>>this->former.at(i);
            }
            this->dp=vector<vector<int>>(60,vector<int>(length,0));
            for(int i=0;i<length;i++){
                this->dp.at(0).at(i)=this->former.at(i);
            }
            for(int i=1;i<60;i++){
                for(int j=0;j<length;j++){
                    this->dp.at(i).at(j)=this->dp.at(i-1).at(this->dp.at(i-1).at(j)-1);
                }
            }
        }

        int prod(int state,long long int y){
            for(int i=0;i<60;i++){
                if((y>>i)%2==1){
                    state=this->dp.at(i).at(state-1);
                }
            }
            return state;
        }
};

int main(){
    int n,q;
    cin>>n>>q;
    class doubling dp(n);
    int x;
    long long int y;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        cout<<dp.prod(x,y)<<endl;
    }
}