#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> sieve(int n){
    vector<int> isprime(n,1); //0-indexed.
    isprime.at(0)=0;
    for(int i=2;i<=n;i++){
        if(isprime.at(i-1)==1){
            for(int j=i+i;j<=n;j+=i){
                isprime.at(j-1)=0;
            }
        }
    }
    return isprime;
}

vector<int> enum_prime(vector<int> &isprime){
    vector<int> ans(0);
    for(int i=0;i<(int)isprime.size();i++){
        if(isprime.at(i)==1){
            ans.push_back(i+1);
        }
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<int> isprime=sieve(n);
    vector<int> ans(0,0);
    for(int i=1;i<=n;i++){
        if(isprime.at(i-1)==1){
            ans.push_back(i);
        }
    }
    int flag=1;
    int cnt=0;
    while(1){
        flag*=2;
        cnt+=1;
        if(flag>1e15){
            break;
        }
    }
    cout<<cnt<<endl;
    /*
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<endl;
    }
    */
}
