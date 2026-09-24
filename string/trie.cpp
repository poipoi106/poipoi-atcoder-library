#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
基本的にはcurのその先をいじるような感じ.
競技プログラミングでならクエリ途中でのメモリ操作はいらないかも?(空間計算量が大きくならない)
*/

class trie{
    private:
    struct vertex{
        char c;
        int id; //0-indexed.
        int cnt; //文字列がその頂点を通る回数.
        int endstr; //文字列がそこで終わる回数.
        vector<vertex*> nextvertex;
    };
    int n,strsize; //strsizeでの参照は1-indexed.
    vertex* root;

    int del_rec(string &s,int id,vertex* cur){ //再帰的に消去.
        int flag=0;
        if(cur->nextvertex.size()==0){
            return 0;
        }
        auto itr=cur->nextvertex.begin();
        while(itr!=cur->nextvertex.end()){
            if(s.at(id)==(*itr)->c){ //文字が見つかったら.
                if(id==(int)s.size()-1){
                    (*itr)->endstr-=1;
                    (*itr)->cnt-=1;
                    if((*itr)->cnt==0){
                        delete *itr;
                        cur->nextvertex.erase(itr);
                    }
                    cur->cnt-=1;
                    return 1;
                }
                flag=del_rec(s,id+1,*itr);
                if(flag && (*itr)->cnt==0){ //再帰先で消すことができたら.
                    delete *itr;
                    cur->nextvertex.erase(itr);
                    cur->cnt-=1;
                    return 1;
                }
                else if(flag){
                    cur->cnt-=1;
                    return 1;
                }
                else{
                    return 0;
                }
            }  
            itr=next(itr);
        }
        return 0;
    }

    void del_p(vertex* cur){ //デストラクタ用.
        if(cur->nextvertex.size()==0){
            delete cur;
            return;
        }
        auto itr=cur->nextvertex.begin();
        while(itr!=cur->nextvertex.end()){
            del_p(*itr);
            itr=next(itr);
        }
        delete cur;
        return;
    }

    public:
    trie(){
        root=new vertex;
        *root=vertex{'-',0,0,0,{}};
        n=0;
        strsize=0;
    }

    int add_string(string s){
        vertex *cur=root;
        strsize+=1;
        int flag=0;
        for(int i=0;i<s.size();i++){
            flag=0;
            if(cur->nextvertex.size()==0){
                n+=1;
                vertex *nex=new vertex;
                *nex=vertex{s.at(i),n,0,0,{}};
                cur->nextvertex.push_back(nex);
                cur->cnt+=1;
                cur=nex;
                continue;
            }
            for(int j=0;j<cur->nextvertex.size();j++){
                if((cur->nextvertex.at(j))->c==s.at(i)){
                    cur->cnt+=1;
                    cur=(cur->nextvertex.at(j));
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                n+=1; //文字が見つからなかった場合.
                vertex *nex=new vertex;
                *nex=vertex{s.at(i),n,0,0,{}};
                (cur->nextvertex).push_back(nex);
                cur->cnt+=1;
                cur=nex;
            }
            
        }
        cur->cnt+=1;
        cur->endstr+=1;
        return strsize;
    }

    int del_string(string s){ //sがtrie木に存在しない場合は0を返す. 成功した場合は1を返す.
        if(del_rec(s,0,root)){
            strsize-=1;
            return 1;
        }
        return 0;
    }

    int count_string(string &s){ //sを加えた時、sが辞書順で何番目にあるかカウントする(1-indexed). 同じ文字列があるなら大きい方になる.
        vertex *cur=root,*nex;
        nex=nullptr;
        int ans=0;
        for(int i=0;i<s.size();i++){
            auto itr=cur->nextvertex.begin();
            nex=nullptr;
            if(itr==cur->nextvertex.end()){ //trie木の葉にいる. 葉にいる場合は葉のcntを加える必要がある(前の行で足した).
                break;
            }
            while(itr!=cur->nextvertex.end()){
                if(((*itr)->c)<s.at(i)){ //この時点で辞書順で早い文字があるなら確定させる.
                    ans+=(*itr)->cnt;
                }
                else{
                    if(s.at(i)==((*itr)->c)){ //同じ文字がなければ次に行く必要がない.
                        ans+=(*itr)->endstr;
                        nex=*itr;
                    }
                }
                itr=next(itr);
            }
            if(nex==nullptr){ //nexがない. すなわち同じ文字がない. 同じ文字がない場合はこれ以上ansが増えない.
                break;
            }
            cur=nex;
        }
        return ans+1;
    }

    ~trie(){
        del_p(root);
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    trie tree;
    int n,m,k;
    cin>>n>>m>>k;
    string t;
    cin>>t;
    vector<string> pat(n),cor(n);
    for(int i=0;i<n;i++){
        cin>>pat.at(i);
        for(int j=0;j<k;j++){
            if(pat.at(i).at(j)==t.at(j)){
                cor.at(i).push_back('0');
            }
            else{
                cor.at(i).push_back('1');
            }
        }
    }
    for(int i=0;i<n;i++){
        tree.add_string(cor.at(i));
    }
    int q;
    cin>>q;
    int a,b;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        tree.del_string(cor.at(a-1));
        cor.at(a-1).at(b-1)=((cor.at(a-1).at(b-1)-'0')^1)+'0';
        tree.add_string(cor.at(a-1));
        //cout<<tree.count_string(cor.at(a-1))<<'\n';
        if(n==m){
            int flag=1;
            for(int j=0;j<k;j++){
                if(cor.at(a-1).at(j)=='0'){
                    flag=0;
                }
            }
            if(flag){
                cout<<"No"<<'\n';
            }
            else{
                cout<<"Yes"<<'\n';
            }
        }
        else{
            if(tree.count_string(cor.at(a-1))-1<=m){
                cout<<"Yes"<<'\n';
            }
            else{
                cout<<"No"<<'\n';
            }
        }
    }
}