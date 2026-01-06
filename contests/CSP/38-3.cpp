#include<bits/stdc++.h>
#define int long long
#define ll long long 
#define MAX 20
#define HASH_MULTI 47055833459
using namespace std;

string code;
vector<int> code11,code6;
string dec11,dec6;
map<int, string> record25;  
map<int, string> record12; //记录已经出现过的代号

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

//将二进制转化为数字
void tranNum(string s,int &num){
    num = 0;
    for(int i = 0;i < s.size();i++){
    	char x = s[i];
        if(x == '1' || x == '0'){
            num = num * 2 + (x - '0');
        }else {
            printf("二进制数错误\n");
            return ;
        }
    }
//    printf("二进制转化为数字为%lld\n", num);
    return ;
}
//将11编码转化为数字
int encode11(){
    if(code11.size() != 11) {
        printf("error,code11长度不为11\n");
        return -1;
    }  
    int ret = 0,power = 1;
    for(int i = 10; i >= 0; i --){
        int t = dec11[i];
        if(t >= '0' && t <= '9')   t = t - '0' + 1;
        else if(t >= 'A' && t <= 'Z') t = t - 'A' + 11;
        else if(t == '_')    t = 37;
        else if(t == 0)     t = 0;
        else  printf("error,不存在编码所对应的数\n");
        ret += t * power;
        power *= 38;
    }
    return ret;
}
//将数字转化为原始编码
void decode11(int num){
    int power = (int)pow(38, 10);
    int index = 0;
    while(power){
        code11[index++] = num/power;
        num = num % power;
        power /= 38;
    }
    if(index != 11 || power )  printf("error\n");
    for(index = 0; index < 11; index++){
        int t = code11[index];
        if(t > 0 && t <= 10)    dec11[index] = t-1+'0';
        else if(t >= 11 && t <= 36) dec11[index] = t - 11 + 'A';
        else if(t == 37)    dec11[index] = '_';
        else if(t == 0)     ;
        else    printf("error,不存在编码所对应的数\n");
    }
    printf("code11解码为%s\n", dec11.c_str());
    return;
}
void decode6(int num){
    int power = (int)pow(26, 3) *36 *10;
    int index = 0;
    while(power){
    	index ++; 
        code6.push_back(num/power) ;
        num = num % power;
        if(index == 1)  power /= 36;
        else if(index == 2) power /= 10;
        else    power /= 26;
    }
    if(index != 6 || power )  printf("error\n");
    for(index = 0; index < 6; index++){
        int t = code6[index];
        if(!index){
            if(t > 0 && t <= 10)    dec6[index] = t-1+'0';
            else if(t >= 11 && t <= 36) dec6[index] = t - 11 + 'A';
            else if(t == 0)   dec6[index] = '*'  ;
            else    printf("error,不存在编码所对应的数\n");            
        }else if(index == 1){
            if(t >= 0 && t <= 9)    dec6[index] = t + '0';
            else if(t >= 10 && t <= 35) dec6[index] = t - 10 + 'A';
            else  printf("error,不存在编码所对应的数\n");           
        }else if(index == 2){  
            if(t >= 0 && t <= 9)    dec6[index] = t + '0';
            else  printf("error,不存在编码所对应的数\n");
        }else{
            if(t >= 0 && t <= 25) dec6[index] = t + 'A';
            else  printf("error,不存在编码所对应的数\n");
        }
    }
    if(dec6[0] == '*'){
	 dec6.erase(0,1); //去掉前导0
	 if(dec6[0] == '*')	printf("去除0失败\n");
}
    printf("code6解码为%s\n", dec6.c_str());   
    return ;
}
//计算编码的散列值
int calcHash(int num,int digit){
    int mod = (int)pow(2,digit),divide = (int)pow(2,64-digit),ret = 0;

    ret = (num * HASH_MULTI) / divide % mod;
 
//    printf("hash值为%lld\n", ret);
    return ret;
}


signed main(){
    int total;
    fr(total);

    while(total --){
        cin>>code;
        if(code[0] == '0'){
            string t1 = code.substr(1, 28),t2 = code.substr(29,28),t3 = code.substr(57, 15);
            printf("t1.size()=%d, t2.size()=%d, t3.size()=%d\n", (int)t1.size(), (int)t2.size(), (int)t3.size());
            int num[2],num3,mod = (int)pow(2, 25);
            tranNum(t1, num[0]);
            tranNum(t2, num[1]);
            tranNum(t3, num3);

            for(int i = 0;i < 2;i++){
                if(num[i] >= mod){  //短数字表示
                    num[i] -= mod;
                    decode6(num[i]);
                    if(dec6[0] == 0) printf("666");
                    record25[calcHash(num[i],25)] = dec6;
                    record12[calcHash(num[i],12)] = dec6;                
                }else{                          //hash值表示
                    if(record25.find(num[i]) != record25.end()){  //找到了对应的hash值（但没有解决找最后一个的目的
                    printf("#%s",record25[num[i]].c_str());
                    }else{                          //无法确定
                        printf("###");
                    }                
                }

                if(i == 0)  printf(" ");
                else {
                    if(num3 != 0)   printf(" %lld\n", num3);
                    else    printf("\n");
                }
            }

        }else if(code[0] == '1'){
            string t1 = code.substr(1, 58), t2 = code.substr(59, 12);
            char t3 = code[71];         //t3先不管
            int num1, num2; tranNum(t1, num1); tranNum(t2, num2);

            decode11(num1);
            printf("%s ", dec11.c_str());
            record25[calcHash(num1,25)] = dec6;
            record12[calcHash(num1,12)] = dec6;  
            
            if(record12.find(num2) != record12.end()){
                printf("#%s\n",record12[num2].c_str());
            }else printf("###\n");              //  找不到对象


        }else{
            printf("error,编码不合法\n");
            break;
        }
    }


    return 0;
}
/*
000000111011010010001111000110010000110101101010001111011000000001111011
#ABCD200_3 A0BCD 123
100111111001001101000001000100101001010001000000011011110000011100011010
ABCD200_3 #A0BCD
*/
