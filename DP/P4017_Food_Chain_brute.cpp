#include "../model.hpp"
#define MOD 80112002
#define N_MAX 5005
#define int ll
/*1-n-5*10^3 1-m-5*10^5*/
struct Animal{
    int index;
    struct Animal* next = 0;
};
Animal animals[N_MAX];
bool hunted[N_MAX];
int n,m,num,init,ans,start[N_MAX],dp[N_MAX];

void insert_prey(int prey,int hunter)
{
    if(!animals[hunter].next){
        animals[hunter].next = new Animal();
        animals[hunter].next->index = prey;
        animals[hunter].next->next = 0;
    }else{
        Animal* p = new Animal();
        p->next = animals[hunter].next;
        animals[hunter].next = p;
        p->index = prey;
    }
}

void calculate_dp(int hunter)
{
    Animal* p = animals[hunter].next;
    while(p){
        if(dp[p->index] == 0)
            calculate_dp(p->index);
        dp[hunter] = (dp[hunter] + dp[p->index]) % MOD;
        p = p->next;
    }
    num ++;
}

signed main()
{
    int k = 0;
    n = fastRead(); m = fastRead();
    for(int i = 0;i < m;i ++){
        int prey = fastRead(), hunter = fastRead();
        hunted[prey] = 1;
        insert_prey(prey,hunter);
    }
    //  找到没有prey的动物作为最低级
    for(int i = 1;i <= n;i ++){
        if(animals[i].next == 0){
            init = i;
            dp[init] = 1;
            num ++;
        }
        if(!hunted[i]){
            start[k++] = i;
        }
    }
    /*要注意结果要将所有最高级消费者的dp加起来，不要输出dp[n]*/
    for(int i = 0;i < k;i ++){
        calculate_dp(start[i]);
        ans += dp[start[i]];
        ans %= MOD;
        if(num >= n)     break;
    }

    printf("%lld",ans);
    return 0;
}