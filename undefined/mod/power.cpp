#include<bits/stdc++.h>
using namespace std;

long long int power(long long int x,long long int n,long long int mod){
    long long int ans=1;
    vector<long long int> pow2(100,0);
    pow2.at(0)=x;
    for(int i=1;i<100;i++){
        pow2.at(i)=pow2.at(i-1)*pow2.at(i-1);
        pow2.at(i)%=mod;
    }
    for(int i=0;i<64;i++){
        if((n>>i)%2==1){
            ans*=pow2.at(i);
            ans%=mod;
        }
    }
    return ans;
}

int main(){
    long long int a,b;
    cin>>a>>b;
    long long int ans=power(a,b,1000000007);
    cout<<ans<<endl;
}

