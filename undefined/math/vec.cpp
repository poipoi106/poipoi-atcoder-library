#include<bits/stdc++.h>
using namespace std;
#define int long long

struct vec{
    double x;
    double y;
};

vec kaiten(vec a,double angle){
    return vec{a.x*cos(angle/180.0*acos(-1))-a.y*sin(angle/180.0*acos(-1)),a.x*sin(angle/180.0*acos(-1))+a.y*cos(angle/180.0*acos(-1))};
}

signed main(){
}