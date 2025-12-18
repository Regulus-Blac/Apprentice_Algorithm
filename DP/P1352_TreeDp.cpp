#include "../model.hpp"
const int MAXN = 6005;
/* 1 ≤ n ≤ 6000 −128 ≤ ri ≤127  1 ≤ l,k ≤ n，且给出的关系一定是一棵树*/

int n,num[MAXN],dp[MAXN][2];
/*DFS*/
vector <int> father[MAXN];
bool isChild[MAXN];
/*TOPO*/
int outDegree[MAXN],firstFather[MAXN];
queue<int> q_stack;

void dfs(int root)
{
    dp[root][1] += num[root];
    for(int t:father[root]){
        dfs(t);
        dp[root][0] += max(dp[t][0],dp[t][1]);
        dp[root][1] += dp[t][0];
    }
}

void solution_dfs()
{
    int son,fath,root;
    for(int i = 1;i < n;++i ){
        son = fastRead();
        fath = fastRead();
        father[fath].push_back(son);
        isChild[son] = 1;
    }
    for(int i = 1;i <= n; ++i){
        if(!isChild[i]){
            root = i;
            break;
        }
    }
    dfs(root);
    printf("%d",max(dp[root][0],dp[root][1]));
    return ;
}
void solution_topo()
//  避免栈溢出
{
    int son,fath;
    for(int i = 1;i < n;i ++){
        son = fastRead();
        fath = fastRead();
        firstFather[son] = fath;
        outDegree[fath] ++;
    }
    for(int i = 1;i <= n;i ++){
        //  把子节点全部入队
        if(outDegree[i] == 0){
            q_stack.push(i);
        }
    }

    while(!q_stack.empty()){
        son = q_stack.front(),fath = firstFather[son];
        q_stack.pop();
        dp[son][1] += num[son];
        if(fath){
            --outDegree[fath];
            //  父节点依赖项全部结束后将父节点入队
            if(outDegree[fath] == 0)    q_stack.push(fath);  
        }
        else{
            printf("%d",max(dp[son][0],dp[son][1]));
            return ;
        }

        dp[fath][0] += max(dp[son][0],dp[son][1]);
        dp[fath][1] += dp[son][0];
    }

}
int main()
{
    n = fastRead();
    for(int i = 1;i <= n; ++i){
        num[i] = fastRead();
    }
    // solution_dfs();
    solution_topo();
    return 0;
}















