#include<bits/stdc++.h>
using namespace std;
#define int long long

double angletopi(double angle){ //度数法->弧度法.
    return acos(-1)/180.0*angle;
}

double pitoangle(double pi){ //弧度法->度数法.
    return pi*180.0/acos(-1);
}

double prod_angle(double a,double b,double c,double d){ //(a,b)から見た時の(c,d)の偏角を0<=ans<360で求める.
    double x=c-a,y=d-b;
    if(x==0 && y==0){
        return -1.0;
    }
    if(x==0 && y>0){
        return 90.0;
    }
    if(x==0 && y<0){
        return 270.0;
    }
    double ans=pitoangle(atan(y/x));
    if(x>0 && y<0){
        ans=360.0+ans;
    }
    else if(x<0){
        ans=180.0+ans;
    }
    return ans;
}

double prod_angle0(double x,double y){ //原点から見た時の偏角を求める.
    double ans=pitoangle(atan(y/x));
    if(x>0 && y<0){
        ans=360.0+ans;
    }
    else if(x<0){
        ans=180.0+ans;
    }
    return ans;
}

signed main(){
    cout<<prod_angle0(sqrt(3),1)<<endl;
}