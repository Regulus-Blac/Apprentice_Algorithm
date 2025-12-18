#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAX 101
// #define int long long
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
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

bool visitarr[MAX][MAX] = {false};
int constarr1[2] ={1,-1};
int constarr2[2] = {2,-2};
int Size = 0;

void jump(int x, int y, int step)
{
    if(step == 0)   return ;
    int xx,yy;

    for(int i = 0; i < 2 ;i ++){
        for(int j = 0;j < 2;j ++){
            xx = x + constarr1[i];
            yy = y + constarr2[j];
            if(xx < 0 || yy < 0 || xx >= Size || yy >= Size)   continue;

            if(visitarr[xx][yy] == false){
                visitarr[xx][yy] = true;
                jump(xx, yy, step - 1);
            }
        }
    }
    for(int i = 0; i < 2 ;i ++){
        for(int j = 0;j < 2;j ++){
            xx = x + constarr2[i];
            yy = y + constarr1[j];
            if(xx < 0 || yy < 0 || xx >= Size || yy >= Size)   continue;

            if(visitarr[xx][yy] == false){
                visitarr[xx][yy] = true;
                jump(xx, yy, step - 1);
            }
        }
    }
}
/*<bits/stdc++.h> 把 整个 标准库都拉进来了，其中 <string> 里有一个同名函数模板于是编译器在看到 size 这个名字时，既匹配到
全局变量 int size，又匹配到 std::size() 函数模板，产生二义性，报错*/
int main(){
    ios::sync_with_stdio(false);
    int step,x,y, cnt = 0;
    fr(Size);fr(step);fr(x);fr(y);
    x -= 1; y -= 1;
    visitarr[x][y] = true;
    jump(x,y,  step);

    for(int i = 0;i < Size; i++){
        for(int j = 0;j < Size; j++){
            if(visitarr[i][j]) cnt ++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}