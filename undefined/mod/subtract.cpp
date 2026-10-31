#include<bits/stdc++.h>
using namespace std;

long long int sub(long long int a,long long int b,long long int mod){
    if(a<b){
        return mod+(a-b);
    }
    return a-b;
}

int main(){
    long long int a,b;
    cin>>a>>b;
    cout<<sub(a,b,998244353)<<endl;
}