#include<bits/stdc++.h>
using namespace std;

int comp(vector<int> &array,int a,int target){
    long long int t=0;
    for(int i=0;i<array.size();i++){
        t+=(long long int)a/array.at(i);
    }
    if(target<=t){
        return 1;
    }
    return 0;
}

int answersearch(vector<int> &array,int minans,int maxans,int k,int comp(vector<int> &array,int a,int target)){
    int left=minans,right=maxans,mid;
    while(right-left>1){
        mid=(left+right)/2;
        if(comp(array,mid,k)){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    return right;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> alist(n,0);
    for(int i=0;i<n;i++){
        cin>>alist.at(i);
    }
    int minans=0,maxans=1500000000;
    int ans=answersearch(alist,minans,maxans,k,comp);
    cout<<ans<<endl;
}