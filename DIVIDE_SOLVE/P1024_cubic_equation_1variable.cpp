/*根的范围在 −100 至 100 之间,由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后 2 位*/
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double a,b,c,d;
bool lef;
void binary_judge(double l,double r)
{
    double mid = (l + r) / 2;
    double val = a * mid * mid * mid + b * mid * mid + c * mid + d;
    //x精确两位，对应的y误差不超过1e-8
    if(fabs(val) < 1e-8){
        cout << fixed << setprecision(2) << mid << ' ';
        // printf("%.2lf ", mid);
        return;
    }
    if(!lef){
        if(val > 0)    binary_judge(l,mid);
        else    binary_judge(mid,r);
    }else{
        if(val < 0)    binary_judge(l,mid);
        else    binary_judge(mid,r);       
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double l,r,delta;
    cin >> a >> b >> c >> d;
    if(a < 0){
        a = -a; b = -b; c = -c; d = -d;
    }
    delta = 4*b*b-12*a*c;
    assert(delta >= 0);

    l = (-2*b-sqrt(delta))/(6*a);
    r = (-2*b+sqrt(delta))/(6*a);
    lef = 0;
    binary_judge(-100.0,l);
    lef = 1;
    binary_judge(l,r);
    lef = 0;
    binary_judge(r,100.0);

    return 0;
}