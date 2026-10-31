#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> lis_fig(vector<int> &alist){ //dpには配列の長さごとの、その配列を構成する最小値が入る.
    vector<int> dp_min(alist.size(),9e18);
    for(int i=0;i<alist.size();i++){
        int itr=lower_bound(dp_min.begin(),dp_min.end(),alist.at(i))-dp_min.begin();
        dp_min.at(itr)=min(alist.at(i),dp_min.at(itr));
    }
    return dp_min;
}

vector<int> lis_id(vector<int> &alist){ //dpにはidをlisの右端にした時のlisの長さが入る.
    vector<int> dp_min(0,0);
    vector<int> dp_len(alist.size(),0);
    for(int i=0;i<alist.size();i++){
        int itr=lower_bound(dp_min.begin(),dp_min.end(),alist.at(i))-dp_min.begin();
        if(itr==dp_min.size()){
            dp_min.push_back(alist.at(i));
        }
        else{
            dp_min.at(itr)=min(dp_min.at(itr),alist.at(i));
        }
        dp_len.at(i)=itr+1;
    }
    return dp_len;
}

vector<int> lis_construct(vector<int> &alist){ //構築、リストにはlisを構成するインデックス(1-indexed)が入る.
    vector<int> dp_min(0,0);
    vector<int> dp_len(alist.size(),0);
    for(int i=0;i<alist.size();i++){
        int itr=lower_bound(dp_min.begin(),dp_min.end(),alist.at(i))-dp_min.begin();
        if(itr==dp_min.size()){
            dp_min.push_back(alist.at(i));
        }
        else{
            dp_min.at(itr)=min(dp_min.at(itr),alist.at(i));
        }
        dp_len.at(i)=itr+1;
    }
    int lislen=1;
    for(int i=0;i<dp_len.size();i++){
        lislen=max(lislen,dp_len.at(i));
    }
    vector<int> ans(0,0);
    for(int i=alist.size()-1;i>-1;i--){
        if(dp_len.at(i)==lislen && (ans.size()==0 || alist.at(ans.at(ans.size()-1)-1)>alist.at(i))){
            ans.push_back(i+1);
            lislen-=1;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void print(vector<int> &array){
    cout<<array.size()<<endl;
    if(array.size()==0){
        return;
    }
    for(int i=0;i<array.size()-1;i++){
        cout<<array.at(i)<<" ";
    }
    cout<<array.at(array.size()-1)<<endl;
}

signed main(){
    int n;
    cin>>n;
    vector<int> alist(n,0);
    for(int i=0;i<n;i++){
        cin>>alist.at(i);
    }
    vector<int> ans=lis_construct(alist);
    for(int i=0;i<ans.size();i++){
        ans.at(i)-=1;
    }
    print(ans);
}