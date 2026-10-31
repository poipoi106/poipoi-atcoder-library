#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
構文解析ライブラリ.
JAG2011のD問題のACコード.
*/

int all_digit(string s){ //負の数も含め、それが整数かどうか判定.
    if(!(s!="-" && (isdigit(s.at(0)) || s.at(0)=='-'))){
        return 0;
    }
    for(int i=1;i<s.size();i++){
        if(isdigit(s.at(i))==0){
            return 0;
        }
    }
    return 1;
}

vector<string> tokenizer(string s){ //文字列を数字や記号のトークンごとに分ける.
    vector<string> token(0);
    int isnum=0;
    string t="";
    for(int i=0;i<s.size();i++){
        if('0'<=s.at(i) && s.at(i)<='9'){
            t.push_back(s.at(i));
            isnum=1;
        }
        else{
            if(isnum==1){
                token.push_back(t);
                t="";
                isnum=0;
            }
            string u="";
                u.push_back(s.at(i));
                token.push_back(u);
        }
    }
    if(t!=""){
        token.push_back(t);
    }
    int flag=1;
    vector<string> newtoken(0);
    while(flag==1){ //((6))みたいに()が連続する場合に注意.
        flag=0;
        for(int i=1;i<token.size();i++){
            if(token.at(i-1)=="(" && all_digit(token.at(i))==1 && token.at(i+1)==")"){
                token.at(i-1)=".";
                token.at(i+1)=".";
                flag=1;
            }
        }
        newtoken=vector<string>(0);
        for(int i=0;i<token.size();i++){
            if(token.at(i)!="."){
                newtoken.push_back(token.at(i));
            }
        }
        token=newtoken;
    }
    return newtoken;
}

set<int> ans;

void calc(vector<string> token,int id){
    if(!(all_digit(token.at(id-1))==1 && all_digit(token.at(id+1))==1)){
        return;
    }
    int left=stoll(token.at(id-1)),right=stoll(token.at(id+1));
    string t;
    if(token.at(id)=="+"){
        t=to_string(left+right);
    }
    else if(token.at(id)=="-"){
        t=to_string(left-right);
    }
    else if(token.at(id)=="*"){
        t=to_string(left*right);
    }
    else{
        if(right==0){
            return;
        }
        t=to_string(left/right);
    }
    vector<string> newtoken(0);
    for(int i=0;i<id-1;i++){
        newtoken.push_back(token.at(i));
    }
    newtoken.push_back(t);
    for(int i=id+2;i<token.size();i++){
        newtoken.push_back(token.at(i));
    }
    id-=1;
    token=newtoken;
    newtoken=vector<string>(0);
    int flag=1;
    while(flag==1){
        flag=0;
        if(id!=0 && token.at(id-1)=="(" && token.at(id+1)==")"){
            newtoken=vector<string>(0);
            flag=1;
            for(int i=0;i<id-1;i++){
                newtoken.push_back(token.at(i));
            }
            newtoken.push_back(token.at(id));
            for(int i=id+2;i<token.size();i++){
                newtoken.push_back(token.at(i));
            }
            token=newtoken;
            id-=1;
        }
    }
    if(token.size()==1){
        ans.insert(stoll(token.at(0)));
        return;
    }
    for(int i=0;i<token.size();i++){
        if(token.at(i)=="+" || token.at(i)=="-" || token.at(i)=="*" || token.at(i)=="/"){
            calc(token,i);
        }
    }
    return;
}

void solve(string s){
    ans.clear();
    vector<string> token=tokenizer(s);
    int one=1;
    for(int i=0;i<token.size();i++){
        if(token.at(i)=="+" || token.at(i)=="-" || token.at(i)=="*" || token.at(i)=="/"){
            one=0;
            calc(token,i);
        }
    }
    if(one){
        cout<<1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    return;
}

signed main(){
    string s;
    while(1){
        cin>>s;
        if(s=="#"){
            break;
        }
        solve(s);
    }
}