#include <iostream>
#include <ctime>
#define ll long long 
using namespace std;


ll gcd1(int a,int b){return b?gcd1(b,a%b):a;}    //辗转相除       log(max(a,b)),1次取模
ll gcd2(int a,int b){                            //更相减损       max(a,b)
    if(a == b)  return b;
    else if(a > b)  return gcd2(a-b, b);
    else return gcd2(a, b-a);
}
ll gcd3(int a,int b)                             //改进的更相减损 log(max(a,b)),0次取模
{
    if(a == b)  return a;

    if(not (a & 1) and not (b & 1)){
        return gcd3(a >> 1, b >> 1) << 1;
    }
    else if(not (a & 1) & (b & 1)){
        return gcd3(a >> 1, b);
    }
    else if(not (b & 1) & (a & 1)){
        return gcd3(a, b >> 1);
    }
    else{
        if(a > b)   return gcd3(a-b, b);
        else        return gcd3(a, b-a);
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int a,b;
    a = 1 + rand()%500;
    b = 1 + rand()%502;
    cout<<"a = "<<a<<" b = "<<b<<"\ngcd1 = "<<gcd1(a,b)<<"\ngcd2 = "<<gcd2(a,b)<<"\ngcd3 = "<<gcd3(a,b)<<endl;
    return 0;
}