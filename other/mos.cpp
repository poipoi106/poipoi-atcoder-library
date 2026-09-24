#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
range set query(ABC174F)への解答.
計算量解析はちゃんとすること(相加相乗平均を使うとよい).
*/

class mos{
    private:
    vector<tuple<int,int,int>> kukan; //元のクエリと順番.
    int haba; //区間の最大幅.
    const int minihaba=(int)sqrt(500000); //平方分割の幅. 調整すること!

    public:
    mos(vector<pair<int,int>> k,int h){
        haba=h;
        kukan=vector<tuple<int,int,int>>(k.size());
        for(int i=0;i<k.size();i++){
            kukan.at(i)={k.at(i).first,k.at(i).second,i+1};
        }
        sort(kukan.begin(),kukan.end(),
            [this](tuple<int,int,int> a,tuple<int,int,int> b){ //区間のソートの核心の部分.
                int biga=get<0>(a)/minihaba,bigb=get<0>(b)/minihaba;
                if(biga==bigb){
                    if(biga%2==0){
                        return get<1>(a)<get<1>(b);
                    }
                    else{
                        return get<1>(a)>get<1>(b);
                    }
                }
                return biga<bigb;
            }
        );
    }

    pair<vector<pair<int,int>>,vector<int>> getkukan(){
        vector<pair<int,int>> kukanpp(kukan.size());
        vector<int> junban(kukan.size());
        for(int i=0;i<kukan.size();i++){
            tuple<int,int,int> t=kukan.at(i);
            kukanpp.at(i)={get<0>(t),get<1>(t)};
            junban.at(i)=get<2>(t);
        }
        return {kukanpp,junban};
    }
};

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,q; //入力の受け取りからクエリのソートまで.
    cin>>n>>q;
    vector<int> clist(n,0);
    for(int i=0;i<n;i++){
        cin>>clist.at(i);
    }
    vector<pair<int,int>> kukan(q);
    for(int i=0;i<q;i++){
        cin>>kukan.at(i).first>>kukan.at(i).second;
    }
    mos mosquery(kukan,n);
    vector<pair<int,int>> query;
    vector<int> junban;
    tie(query,junban)=mosquery.getkukan();

    vector<int> color(n,0); //クエリを処理する. colorは現在の集合, ansはクエリの区間に答えを対応させたもの.
    int minians=0;
    vector<int> ans(q,0);
    pair<int,int> curkukan={-1,-1}; //閉区間.

    for(int j=query.at(0).first;j<=query.at(0).second;j++){ //最初のクエリに愚直に答える.
        if(color.at(clist.at(j-1)-1)==0){
            minians+=1;
        }
        color.at(clist.at(j-1)-1)+=1;
    }
    curkukan={query.at(0).first,query.at(0).second}; //現在の区間.
    ans.at(junban.at(0)-1)=minians;

    for(int i=1;i<q;i++){ //区間を変化させながら残りのクエリに答える.
        while(curkukan.second<query.at(i).second){
            if(color.at(clist.at(curkukan.second)-1)==0){
                minians+=1;
            }
            color.at(clist.at(curkukan.second)-1)+=1;
            curkukan.second+=1;
        }
        while(curkukan.first<query.at(i).first){
            if(color.at(clist.at(curkukan.first-1)-1)==1){
                minians-=1;
            }
            color.at(clist.at(curkukan.first-1)-1)-=1;
            curkukan.first+=1;
        }

        while(curkukan.first>query.at(i).first){
            if(color.at(clist.at(curkukan.first-2)-1)==0){
                minians+=1;
            }
            color.at(clist.at(curkukan.first-2)-1)+=1;
            curkukan.first-=1;
        }
        while(curkukan.second>query.at(i).second){
            if(color.at(clist.at(curkukan.second-1)-1)==1){
                minians-=1;
            }
            color.at(clist.at(curkukan.second-1)-1)-=1;
            curkukan.second-=1;
        }

        ans.at(junban.at(i)-1)=minians;
    }

    for(int i=0;i<q;i++){ //出力.
        cout<<ans.at(i)<<'\n';
    }
}