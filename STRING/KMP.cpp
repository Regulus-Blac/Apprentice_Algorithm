/*P3375*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int substr_next[MAX];
void make_next(string &s2);
void KMP(string &s1,string &s2);


int main()
{
    string s1,s2;
    int num_s2;
    cin>>s1>>s2;
    num_s2 = s2.size();

    make_next(s2);
    KMP(s1,s2);

    for(int i = 0;i < num_s2; i++){
        cout<< substr_next[i] << " ";
    }

    return 0;
}

void KMP(string &s1,string &s2)
{
    int i = 0,j = 0,len1 = s1.length(), len2 = s2.length();
    if(len2 > 1){
        while(i < len1){
            if(s1[i] == s2[j]){
                i ++;
                j ++;
                if(j == len2){
                    //  输出起始匹配位置
                    cout<< i - j + 1 <<endl;
                    //  开始新一轮的匹配
                    j = substr_next[j - 1];
                }
            }else if(j > 0){    
            //  没匹配上，j退回
                j = substr_next[j - 1];
            }else{  
            //  j已经退无可退了
                i ++;
            }
        }
    }else{
        for(int k = 0;k < len1; k++){
            if(s1[k] == s2[0]){
                cout<< k + 1 <<endl;
            }  
        }
    }
}

void make_next(string &s2)
{
    int i = 0,j = 1, len = s2.length();

    while(j < len){
        if(s2[j] == s2[i]){
            i ++;
            substr_next[j] = i;
            j ++;
        }else{
            if(i){
                i = substr_next[i - 1];
            }else{
                substr_next[j] = 0;
                j ++;
            }
            
        }
    }
}