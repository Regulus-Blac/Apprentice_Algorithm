#include <bits/stdc++.h>
/*如果字符串中没有连续子串2025或者有连续子串2026即为符合条件，每次操作可以把某一位的值改为2或0或5或6，求将字符串修改为符合条件字符串最少需要几次操作*/
using ll = long long;
using namespace std;
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
int cnt;
int s[30];
int main()
{
    cnt = fastRead();
    int len,flag = 0,a5 = 0,a6 = 0;
    string s;
    while(cnt --){
        len = fastRead();
        flag = a5 = a6 = 0;
        cin>>s;
        for(int i = 0;i < len;++i){
            s[i] -= '0';
                if(s[i] == 2){
                    if(flag == 2){
                        ++flag;
                    }else{
                        flag = 1;
                    }
                }else if(s[i] == 0){
                    if(flag == 1)   ++flag;
                    else flag = 0;
                }else if(s[i] == 5){
                    if(flag == 3)
                        ++a5; 
                    flag = 0;
                }else if(s[i] == 6){
                    if(flag == 3){
                        ++a6;
                        break;
                    }    
                    flag = 0;
                }
        }
        if(!a6 && a5)  printf("1\n");//有2025只需修改一个5为6
        else printf("0\n");//没有2025,直接符合条件

    }
    return 0;
}