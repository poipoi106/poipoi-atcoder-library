#include<bits/stdc++.h>
using namespace std;

int comp(vector<int> &array,int a,int target){
    return array.at(a)<=target;
}

pair<int,int> binarysearch(vector<int> &array,int target,int comp(vector<int> &array,int a,int target)){
    int left=0,right=array.size(),mid;
    while(right-left>1){
        mid=(left+right)/2;
        if(comp(array,mid,target)){
            left=mid;
        }
        else{
            right=mid;
        }
    }
    return {left,array.at(left)};
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> alist(n,0);
    for(int i=0;i<n;i++){
        cin>>alist.at(i);
    }
    sort(alist.begin(),alist.end());
    pair<int,int> ans=binarysearch(alist,target,comp);
    cout<<ans.first+1<<" "<<ans.second<<endl;
}