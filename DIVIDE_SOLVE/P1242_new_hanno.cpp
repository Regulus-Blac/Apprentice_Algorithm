#include "../model.hpp"
#define MAX 50

bool output = false;
int temp,num,mode,cnt[2];
char pole[3] = {'A','B','C'};
int src[MAX],des[MAX],current[MAX];  //分别存储每个盘子应该在哪个柱子上,第0位空出来

void init()
{
    num = fastRead();
    int t;

    for(int i = 0; i < 3;i ++){
        t = fastRead();
        for(int j = 1;j <= t;j ++){
            src[fastRead()] = i;
        }
    }

    for(int i = 0; i < 3;i ++){
        t = fastRead();
        for(int j = 1;j <= t;j ++){
            des[fastRead()] = i;
        }
    }
}
void hanno(int n, int from, int to)
{
    //  先把上面的小盘子移动到helper上
    for(int i = n - 1;i > 0;i --){
        if(current[i] != 3 - from - to)    hanno(i,current[i],3 - from - to);
    }
    //  再把最大的移动到目标盘上
    current[n] = to;
    if(output)  printf("move %d from %c to %c\n",n,pole[from],pole[to]);
    else cnt[mode] ++;
}
void executor(int code)
{
    memcpy(current,src,sizeof(src));
    switch(code){
        case 0:{
        //  模式1：将上面的都放在help柱，然后从from到to
            mode = 0;
            for(int i = temp; i > 0;i--){
                if(current[i] != des[i]){
                    hanno(i, current[i], des[i]);
                }
            }    
            break;    
        }
        case 1:{
        //  模式2: 对于第一个盘子，上面的放在to，然后大的放在helper,上面的再转移到from,大的再放到to
            mode = 1;
            for(int i = temp - 1;i > 0;i --){
                if(current[i] != des[temp]){
                    hanno(i,current[i],des[temp]);
                }
            }
            hanno(temp,current[temp],3-src[temp]-des[temp]);

            for(int i = temp - 1;i > 0; i--){
                if(current[i] != src[temp]){
                    hanno(i,current[i],src[temp]);
                }
            }
            hanno(temp,current[temp],des[temp]);
        //  之后和模式1一样
            for(int i = temp - 1;i > 0;i --){
                if(current[i] != des[i]){
                    hanno(i,current[i],des[i]);
                }
            }
            break;
        }
    }

}   


int main()
{
    init();
    temp = num;
    //  找到第一个需要移动的地方
    while(src[temp] == des[temp] && temp > 0)    temp --;
    executor(0);
    executor(1);

    mode = (cnt[0] < cnt[1]) ? 0 : 1;
    output = true;
    executor(mode);
    printf("%d",cnt[mode]);

    return 0;
}