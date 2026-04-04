/*
做完3道，第4道还在调
*/
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define fr =fastRead()
#define fl =fastRead(1)
int fastRead()
{
    bool minus = 0;
    int ret = 0;    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')    minus = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return minus? -ret : ret;   
}
ll fastRead(int)
{
    bool minus = 0;
    ll ret = 0;    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')    minus = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return minus? -ret : ret;   
}
inline int fastMax(int a,int b){
    return a > b? a : b;
}
inline int fastMin(int a,int b){
    return a < b ? a : b;
}
ll fastpow(ll a,ll b,ll mod)
{
    ll ret = 1;
    while(b){
        if(b & 1)    ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

void funA();
void funB();
void funC();
void funD();
void funE();

void(*func[5])()={funA,funB,funC,funD,funE};
signed main()
{
    void(*funp)() = func['D'-'A'];
    funp();
    return 0;
}

void funA()
{
    // int a fr,b;
    // b fr;
    // switch(a){
    //     case 1:{
    //         if(b == 7){
    //             printf("Yes\n");
    //         }else{
    //             printf("No\n");
    //         }
    //         break;
    //     }
    //     case 3:{
    //         if(b == 3){
    //             printf("Yes\n");
    //         }else{
    //             printf("No\n");
    //         }
    //         break;
    //     }
    //     case 5:{
    //         if(b == 5){
    //             printf("Yes\n");
    //         }else{
    //             printf("No\n");
    //         }
    //         break;
    //     }
    //     case 7:{
    //         if(b == 7){
    //             printf("Yes\n");
    //         }else{
    //             printf("No\n");
    //         }
    //         break;
    //     }
    //     case 9:{
    //         if(b == 9){
    //             printf("Yes\n");
    //         }else{
    //             printf("No\n");
    //         }
    //         break;
    //     }
    //     default:{
    //         printf("No\n");
    //         break;
    //     }
    // }
}

void funB()
{
    // int row,col;row fr;col fr;
    // for(int i = 0;i < row;++i){
    //     if(i == 0 || i == row - 1){
    //         for(int j = 0;j < col;++j){
    //             putchar('#');
    //         }
    //         putchar('\n');
    //     }else{
    //         putchar('#');
    //         for(int j = 1;j < col - 1;++j){
    //             putchar('.');
    //         }
    //         putchar('#');putchar('\n');
    //     }
    // }
}

void funC()
{
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // string s,sno;
    // sno.push_back('A');
    // int n,m,t1,t2; cin >> n;
    // vector<string>poss_ret;
    // vector<pair<int,int>>order(n);
    // vector<unordered_set<char>>cdd(n);
    // for(int i = 0;i < n;++i){
    //     cin >> t1 >> t2;
    //     order[i] = {t1,t2};
    // }
    // cin >> m;
    // for(int i = 0;i < m;++i){
    //     cin >> s;
    //     int length = s.length();
    //     if(length == n) poss_ret.push_back(s);
    //     else poss_ret.push_back(sno);
    //     for(int j = 0;j < n;++j){
    //         int len = order[j].first,pos = order[j].second - 1;
    //         if(len != length) continue;
    //         else{
    //             cdd[j].insert(s[pos]);
    //         }
    //     }
    // }
    // for(string pr : poss_ret){
    //     if(pr[0] == 'A'){
    //         cout << "No\n";
    //         continue;
    //     }
    //     bool flag = 1;
    //     for(int i = 0;i < n;++i){
    //         if(cdd[i].find(pr[i]) == cdd[i].end()){
    //             flag = 0;
    //             break;
    //         }
    //     }
    //     if(flag) cout << "Yes\n";
    //     else cout << "No\n";
    // }
    // return;
}

/*
在S的非空子串(连续)中，找不含T作为子序列(可以不连续)的数目
非空子串

6-3+45-3+6*/
void funD()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s,t;
    int sl,tl,i,j,back_pos,back,advent[55]={0},max_bit = 1; ll ret = 0;
    cin >> s >> t; sl = s.length();tl = t.length();
    auto calc = [](int len)->ll{ll ret = (1+(ll)len)*(ll)len/2;return ret;};
    i = j = 0;
    if(tl == 1){
        while(j < sl){
            for(j;j < sl && s[j] != t[0];++j);
            ret += calc(j-i);
            ++ j;i = j;
        }
        cout << ret;
        return ;
    }

    back_pos = tl - 2; // 回退到的索引
    while(j < sl){
        // 进行字符串匹配
        for(int k = 0;k < max_bit;++k){
            if(s[j] == t[k]){
                if(s[j] == t[back_pos]){
                    back = j;
                }
                advent[k] += (k == 0)?1:advent[k-1];
            }
        }
        if(advent[max_bit-1])  ++ max_bit;
        
        if(advent[tl-1]){
            ret += calc(j - i);
            // cout << "after calc" << j-i+1 << " ret = "<<ret<<endl;
            i = back;
            ret -= calc(j - i);

            if(j + 1 == sl){
                ret += calc(j - i + 1);
                break;
            }
            max_bit = 1;
            for(int i = 0;i < tl;++i) advent[i] = 0;
            // cout << "after calc"<< j-i<< "ret = "<<ret<<endl;
        }
        
        ++ j;
    }
    cout << ret;

}
void funE()
{

}