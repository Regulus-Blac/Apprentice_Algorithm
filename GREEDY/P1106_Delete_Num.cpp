#include "../model.hpp"
/*输入一个大数删去其中k位，得到的最小数*/
const int MAX_LEN = 255;
vector <int>record;
int n;
/*way1*/
int num[MAX_LEN],min_period[MAX_LEN][MAX_LEN];
//上三角矩阵min_period[i][j]代表到i-j的最小值
/*way2*/
//并不需要知道每一对的最小值，只需在往右推进时寻找即可
void test_min_period()
{
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n; ++j){
            printf("%d%c",min_period[i][j],j == n ? '\n':' ');
        }
    }
}
void way1();
void way2();
int main()
{
    // way1();
    way2();

    return 0;
}
void way1()
{
    int k,i = 0,cnt,min_now = 10,c = getchar();
    while(c >= '0' && c <= '9'){
        //  记录数据同时算出以首位开始的各项区间最小值
        num[++i] = c - '0';
        if(num[i] < min_now){
            min_now = num[i];
            min_period[1][i] = i;
        }else{
            min_period[1][i] = min_period[1][i-1];
        }
        c = getchar();
    }
    num[0] = i,n = i;
    //  完成min_period
    for(i = 2;i <= n; ++i){
        min_now = 10;
        for(int j = i;j <= n;++j){
            if(num[j] < min_now){
                min_now = num[j];
                min_period[i][j] = j;
            }else{
                min_period[i][j] = min_period[i][j - 1];
            }
        }
    }   //O(n^2)
    // test_min_period();

    k = fastRead();
    cnt = n - k;    i = 0;
    while(cnt){
        min_now = min_period[i+1][n-cnt+1];
        record.push_back(num[min_now]);
        i = min_now;
        --cnt;
    }
    i = 0;
    for(int t : record){
        if(t){
            if(!i)  i = 1;
            printf("%d",t);
        }
        else if(i){
            printf("0");
        } 
    }
    if(!i)  printf("0");
}
void way2()
{
    string s;
    int k,cnt,min_pos,min_now,t = 0;
    cin >> s;
    k = fastRead();
    n = s.length();
    for(int i = 0;i < n;++i){
        num[i+1] = s[i] - '0';
    }

    cnt = n - k;    min_now = 10;
    while(cnt){
        for(int i = t + 1;i <= n - cnt + 1;++i){
            if(num[i] < min_now){
                min_now = num[i];
                min_pos = i;
            }
        }

        t = min_pos;
        min_now = 10;
        record.push_back(num[min_pos]);
        --cnt;
    }
    for(int t : record){
        if(t){
            if(!cnt)  cnt = 1;
            printf("%d",t);
        }
        else if(cnt){
            printf("0");
        } 
    }
    if(!cnt)  printf("0");
}