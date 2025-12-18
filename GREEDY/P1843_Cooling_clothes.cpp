/*P1843*/
/*
优先队列
它的第一个元素总是它所包含的元素中最大的，只能检索最大堆元素，包含头文件<queue>
template <class T, class Container = vector<T>,  class Compare = less<typename Container::value_type> > class priority_queue;
默认用vector盛放，且降序排列，升序改为greater，less greater前提为C++基本类型
*/
// #include <queue>
#include <bits/stdc++.h>
using namespace std;
int a,b,n;
int main()
{
    int temp, cnt = 0;
    cin>>n>>a>>b;
    priority_queue <int> pq;
    while(n--){
        cin>>temp;
        pq.push(temp);
    }

    while(pq.size()){

        int t = pq.top();
        pq.pop();
        //  上一次就已经吹干了，不需要此次操作
        if(t <= cnt * a)    break;
    
        cnt ++;

        //  把烘干之后的再放回去
        if(t > b + cnt * a){
            t -= b;
            pq.push(t);
        }
        //  已经干的就不必再放回去了
    }

    cout<<cnt;

    return 0;
}