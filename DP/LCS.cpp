/*最长公共子序列*/
#include "../model.hpp"
const int MAX = 3005;
int dp[MAX][MAX];
/*dp[i][j]代表ai和bj的LCS长度*/
// int prer[MAX][MAX],prec[MAX][MAX];
// vector<char>path;
char record[MAX][MAX];
char ans[MAX];
/*1代表上箭头-1代表左箭头2代表对角线*/
int main()
{
    string a,b;
    cin>>a>>b;
    int m = a.length(),n = b.length();
    for(int i = 1;i <= m;++i){
        for(int j = 1;j <= n;++j){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                // prer[i][j] = i - 1;
                // prec[i][j] = j - 1;
                record[i][j] = 2;
            }else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                // prer[i][j] = i - 1;
                // prec[i][j] = j;
                record[i][j] = 1;
            }else{
                dp[i][j] = dp[i][j-1];
                // prer[i][j] = i;
                // prec[i][j] = j - 1;
                record[i][j] = -1;
            }            
        }
    }
    printf("%d\n",dp[m][n]);
    int i = m,j = n;
    while(dp[i][j]){
        if(record[i][j] == 2){
            ans[dp[i][j]] = a[i-1];
            --i;--j;
        }else if(record[i][j] == 1){
            --i;
        }else{
            --j;
        }
    }
    for(int t = 1;t <= dp[m][n];++t)    printf("%c",ans[t]);
    // while(m > 0 && n > 0){
    //     int tm = prer[m][n],tn = prec[m][n];
    //     if(tm != m && tn != n)  path.push_back(a[tm]);
    //     m = tm,n = tn;
    // }
    // reverse(path.begin(),path.end());
    // for(char c:path)   cout<<c;

    return 0;
}