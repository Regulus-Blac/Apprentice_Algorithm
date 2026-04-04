#include <bits/stdc++.h>
using namespace std;
union{
    char c[4];
    float f;
    int i;
}t1,t2,t3;
void showBit(float x)
{
    int s[32];
    for(int i = 0;i < 32;++i){
        s[31-i] = ((*(int*)&x >> i) & 1);
    }
    printf("float: %f\n",x);
    printf("bit: ");
    for(int i = 0;i < 32;++i){
        if(i == 1 || i == 9) printf(" ");
        printf("%d",s[i]);
    }
    return;
}
int main()
{
    float a = 1.25;
    showBit(a);
    return 0;
}