#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
偏角を比べるには外積が使えたりする. aから見たbの外積はa_x*b_y-a_y*b_xであり, それが0より大きいならaの方がbより時計の方向にいる. 0なら180度か0度.
a*b>0ならa<bとなる. 
*/
int comp(pair<int,int> a,pair<int,int> b){
    return a.second*b.first<b.second*a.first;
}

vector<pair<int,int>> angle_sort(vector<pair<int,int>> arr){
    vector<pair<int,int>> firstarr(0),secondarr(0);
    for(int i=0;i<arr.size();i++){
        pair<int,int> pp=arr.at(i);
        if(pp.second>=0 && pp.first>=0){
            firstarr.push_back(pp);
        }
        else if(pp.second<0 && pp.first>0){
            firstarr.push_back(pp);
        }
        else{
            secondarr.push_back(pp);
        }
    }
    sort(firstarr.begin(),firstarr.end(),comp);
    sort(secondarr.begin(),secondarr.end(),comp);
    for(int i=0;i<secondarr.size();i++){
        firstarr.push_back(secondarr.at(i));
    }
    return firstarr;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> temp(n);
    for(int i=0;i<n;i++){
        cin>>temp.at(i).first>>temp.at(i).second;
    }
    temp=angle_sort(temp);
    vector<pair<int,int>> board(0);
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            board.push_back(temp.at(j));
        }
    }
    int ans=0,id=1;
    for(int i=0;i<n;i++){
        pair<int,int> cur=board.at(i);
        while(id!=2*n){
            id=max(id,i+1);
            pair<int,int> pp=board.at(id),curinv={-board.at(i).first,-board.at(i).second};
            if(curinv.first*pp.second-curinv.second*pp.first>=0){
                break;
            }
            else{
                id+=1;
                continue;
            }
        }
        ans=max(ans,id-i);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int query=0;query<t;query++){
        solve();
    }
}