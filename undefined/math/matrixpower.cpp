#include<bits/stdc++.h>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
#define int long long

using mint=modint1000000007;

/*
行列積を用いるにはopが半環であることが必要.(https://qiita.com/lotz/items/094bffd77b24e37bf20e)またはABC009Dを参照.
半環であるためには, 集合Rと二項演算(+,*)が

(R,+)は単位元0を持ち,
(a+b)+c=a+(b+c)
0+a=a+0=a
a+b=b+a

(R,*)は単位元1を持ち,
(a*b)*c=a*(b*c)
1*a=a*1=a

乗法は加法の上に分配的で,
a*(b+c)=(a*b)+(a*c)
(a+b)*c=(a*c)+(b*c)

0-倍はRを零化する
0*a=a*0=0

を満たす必要がある.
*/

template<typename T>
class matrix_power{ //n行n列の行列累乗. atcoder/modintが必要. A^0は単位行列を返す.
    public:
    int n;
    vector<vector<T>> mat;

    private:
    vector<vector<vector<T>>> matpower;

    private:
    vector<vector<T>> matrix_mul(vector<vector<T>> &a,vector<vector<T>> &b){
        vector<vector<T>> ans(this->n,vector<T>(this->n,0));
        for(int i=0;i<this->n;i++){
            for(int j=0;j<this->n;j++){
                for(int k=0;k<this->n;k++){
                    ans.at(i).at(j)+=a.at(i).at(k)*b.at(k).at(j);
                }
            }
        }
        return ans;
    }

    public:
    matrix_power(vector<vector<T>> &inputmat){
        this->n=inputmat.size();
        for(int i=0;i<this->n;i++){
            assert(inputmat.at(i).size()==n);
        }
        this->mat=vector<vector<T>>(n,vector<T>(n,0));
        for(int i=0;i<this->n;i++){
            for(int j=0;j<this->n;j++){
                this->mat.at(i).at(j)=inputmat.at(i).at(j);
            }
        }
        this->matpower=vector<vector<vector<T>>>(62,mat);
        for(int i=1;i<=61;i++){
            matpower.at(i)=matrix_mul(matpower.at(i-1),matpower.at(i-1));
        }
    }

    public:
    vector<vector<T>> prod(int a){
        vector<vector<T>> ans(this->n,vector<T>(this->n,0));
        for(int i=0;i<this->n;i++){
            ans.at(i).at(i)=1;
        }
        for(int i=0;i<=61;i++){
            if((a>>i)&1==1){
                ans=matrix_mul(this->matpower.at(i),ans);
            }
        }
        return ans;
    }
};

signed main(){
    int n;
    cin>>n;
    vector<vector<mint>> mat(n,vector<mint>(n,0));
    int a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            mat.at(i).at(j)=a;
        }
    }
    matrix_power<mint> matpower(mat);
    vector<vector<mint>> ans=matpower.prod(4);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cout<<ans.at(i).at(j).val()<<" ";
        }
        cout<<ans.at(i).at(n-1).val()<<endl;
    }
}