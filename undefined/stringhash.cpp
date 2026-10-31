#include<bits/stdc++.h>
using namespace std;
#define int long long

class stringhash{
    public:
        vector<int> pow2=vector<int>(100,0);
        vector<int> hashlist;
        int mod;
        int b;
        int length;
        string s;

        stringhash(string st,int u,int t){
            this->s=st;
            this->length=st.size();
            this->mod=t;
            this->hashlist=vector<int>(length+1,0);
            this->hashlist.at(1)=this->s.at(0)-'a';
            this->b=u;
            for(int i=1;i<this->length;i++){
                this->hashlist.at(i+1)=this->hashlist.at(i)*this->b+(this->s.at(i)-'a');
                this->hashlist.at(i+1)%=this->mod;
            }
            this->pow2.at(0)=b;
            for(int i=1;i<100;i++){
                this->pow2.at(i)=this->pow2.at(i-1)*this->pow2.at(i-1);
                this->pow2.at(i)%=this->mod;
            }
        }

        int sub(int a,int b,int mod){
            if(a<b){
                return this->mod+(a-b);
            }
            return a-b;
        }

        int power(int n){
            int ans=1;
            for(int i=0;i<64;i++){
                if((n>>i)%2==1){
                    ans*=this->pow2.at(i);
                    ans%=this->mod;
                }
            }
            return ans;
        }

        int prod(int left,int right){
            return sub(hashlist.at(right),power(right-left+1)*hashlist.at(left-1)%mod,mod);
        }
};

signed main(){
    int n,q;
    string s;
    cin>>n>>q>>s;
    int a,b,c,d;
    class stringhash hash(s,100,998244353);
    for(int i=0;i<q;i++){
        cin>>a>>b>>c>>d;
        if(hash.prod(a,b)==hash.prod(c,d)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}