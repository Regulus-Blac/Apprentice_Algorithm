#include <cstdio>
using namespace std;

//快读
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
/*字符串只用到前k个小写字母，当x|（j - i）时，s[i]要与s[j]不同*/
int cnt,k,x;

int main()
{
  cnt = fastRead();
  while(cnt --){
    k = fastRead(),x = fastRead();
    printf("%d\n",k * x + 1);
  }
  return 0;
}
