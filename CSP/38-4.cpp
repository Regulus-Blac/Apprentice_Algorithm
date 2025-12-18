#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAX 16
#define int long long
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void fr(int &num){
    bool minus = false;
    num = 0;
    char c = getchar();
    while(c != EOF && (c < '0' || c > '9')){
        if(c == '-') minus = true;
        c = getchar();
    }
    while(c != EOF && c >= '0' && c <= '9'){
        num = num * 10 + (c - '0');
        c = getchar();
    }
    if(minus)   num = -num;
}
   
vector <int> sharpPos;  //记录#号位置
bool isValid(){


    return true;
}



signed main(){
    ios::sync_with_stdio(false);
    int len, num, t;
    fr(len);fr(num);
    sharpPos[0] = num;
    for(int i = 1;i <= num; i ++){
        fr(t);
        sharpPos[i] = t;
    }

    return 0;
}