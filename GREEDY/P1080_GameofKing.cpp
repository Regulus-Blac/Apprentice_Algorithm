#include "../model.hpp"

/*左、右手上面分别写下一个整数,n 位大臣排成一排，国王站在队伍的最前面
每位大臣获得的金币数是：排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数，然后向下取整
要求：使获奖赏最多的大臣，所获奖赏尽可能的少
 1≤n≤1000,0<a,b<10000*/
 /*按照左右手乘积大的*/
const int MAX_LEN = 1005;
int n;

struct person{
    int l,r,ret;
};
person num[MAX_LEN];
bool cmp(person a,person b)
{
    return a.ret < b.ret;
}
signed main()
{
    /*需要高精度计算*/
    highP max_now = 0,t,curr;
    n = fastRead();
    
    for(int i = 0;i <= n;++i){
        num[i].l = fastRead();
        num[i].r = fastRead();
        num[i].ret = num[i].l * num[i].r;
    }
    curr = num[0].l;
    sort(num + 1,num + 1 + n,cmp);

    for(int i = 1;i <= n;++i){
        t = curr / num[i].r;
        if(t > max_now) max_now = t;
        curr *= num[i].l;
    }
    max_now.output(0);
    return 0;
}
