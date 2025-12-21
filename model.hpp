#include <bits/stdc++.h>
using ll = long long;
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
//自写最大最小
int fastMax(int a,int b){
    return a > b? a : b;
}
int fastMin(int a,int b){
    return a < b ? a : b;
}
//正数高精度计算
//实现更大可以令BASE = 10000使得数组中每一位存储0-9999
const int MAX_HIGHPRECISION_LEN = 5000;
const int HIGHPRECISION_BASE = 10;
class highP{
public:
    int a[MAX_HIGHPRECISION_LEN];
public:
    highP(){memset(a,0,sizeof(a));}
    void clear(){memset(a,0,sizeof(a));}
    highP(int x){
        clear();
        while(x){
            a[++a[0]] = x % HIGHPRECISION_BASE;
            x /= HIGHPRECISION_BASE;
        }
        while(a[a[0]] == 0 && a[0]) --a[0];
    }
    void output(const char *separator){
        if(a[0] == 0){
            putchar('0');
            if(separator)   printf("%s",separator);
            return;
        }
        //  BASE大于10时输出时需要补0
        int width = 1;
        for (int t = HIGHPRECISION_BASE - 1; t >= 10; t /= 10) ++width;
        printf("%d",a[a[0]]);   //最高位不用补0
        for(int i = a[0]-1; i >= 1; --i){
            if (HIGHPRECISION_BASE == 10) {
                printf("%d", a[i]);
            } else {
                printf("%0*d", width, a[i]);
            }
        }
        if(separator)   printf("%s",separator);
    }
    highP& operator=(int x){
        clear();
        while(x){
            a[++a[0]] = x % HIGHPRECISION_BASE;
            x /= HIGHPRECISION_BASE;
        }
        while(a[a[0]] == 0 && a[0]) --a[0];
        return *this;
    }
    char cmp_greater(const highP& x){
        if(a[0] > x.a[0])   return 1;
        else if(a[0] < x.a[0])  return -1;
        for(int i = a[0];i > 0; --i){
            if(a[i] > x.a[i])   return 1;
            else if(a[i] < x.a[i])  return -1;
        }
        return 0;
    }
    bool operator>(const highP& x){
        return cmp_greater(x) == 1;
    }
    bool operator<(const highP& x){
        return cmp_greater(x) == -1;
    }
    bool operator==(const highP& x){
        return cmp_greater(x) == 0;
    }
    bool operator>=(const highP& x){
        return !(*this < x);
    }    
    bool operator<=(const highP& x){
        return !(*this > x);
    }
    highP operator+(const highP& x){
        highP ret;
        ret.a[0] = a[0] > x.a[0] ? a[0] + 1 : x.a[0] + 1;
        for(int i = 1;i <= ret.a[0]; ++i){
            ret.a[i] = a[i] + x.a[i];
            if(ret.a[i] >= HIGHPRECISION_BASE){
                ret.a[i] -= HIGHPRECISION_BASE;
                ++ ret.a[i+1];
            }
        }
        while(ret.a[ret.a[0]] == 0 && ret.a[0]) --ret.a[0];
        return ret;
    }
    highP& operator+=(const highP& x){
        *this = *this + x;
        return *this;
    }
    highP operator-(const highP& x){
        highP ret;
        ret.a[0] = a[0] > x.a[0] ? a[0] : x.a[0];
        for(int i = 1;i <= ret.a[0];++i){
            ret.a[i] += a[i] - x.a[i];
            if(ret.a[i] < 0){
                ret.a[i] += HIGHPRECISION_BASE;
                -- ret.a[i+1];
            }
        }
        while(ret.a[ret.a[0]] == 0 && ret.a[0]) --ret.a[0];
//实现存疑
        if(ret.a[a[0] + 1] < 0){
            highP remin = ret,highestBit;
            remin.a[a[0]+1] = 0;
            highestBit.a[0] = a[0] + 1;
            highestBit.a[a[0] + 1] = -ret.a[a[0] + 1];
            return highestBit - remin;

        }
        return ret;
    }
    highP& operator-=(const highP& x){
        *this = *this - x;
        return *this;
    }
    highP operator*(const highP& x)const{
        highP ret;
        ret.a[0] = a[0] + x.a[0];
        for(int i = 1;i <= a[0]; ++i){
            for(int j = 1;j <= x.a[0]; ++j){
                ret.a[i+j-1] += a[i] * x.a[j];
            }
        }
        for(int i = 1;i <= ret.a[0]; ++i){
            if(ret.a[i] >= HIGHPRECISION_BASE){
                ret.a[i+1] += ret.a[i] / HIGHPRECISION_BASE;
                ret.a[i] %= HIGHPRECISION_BASE;
            }
        }
        while(ret.a[ret.a[0]] == 0 && ret.a[0]) --ret.a[0];
        return ret;
    }
    highP& operator*=(const highP& x){
        *this = *this * x;
        return *this;
    }
    highP operator*(const int x){
        highP ret;
        ret.a[0] = a[0];
        for(int i = 1;i <= a[0];++i){
            ret.a[i] += a[i] * x;
        }
        for(int i = 1;i <= ret.a[0]; ++i){
            if(ret.a[i] >= HIGHPRECISION_BASE){
                ret.a[i+1] += ret.a[i] / HIGHPRECISION_BASE;
                ret.a[i] %= HIGHPRECISION_BASE;
            }
        }
        int i = ret.a[0] + 1;
        while(ret.a[i]){
            ++ ret.a[0];
            if(ret.a[i] >= HIGHPRECISION_BASE){
                ret.a[i+1] += ret.a[i] / HIGHPRECISION_BASE;
                ret.a[i] %= HIGHPRECISION_BASE;
            }
            ++ i;
        }
        return ret;
    }
    highP& operator*=(const int x){
        *this = *this * x;
        return *this;
    }
    highP operator/(const int x){
        if (x == 0) return *this;
        highP ret;
        ret.a[0] = a[0];
        int now = 0;
        for(int i = a[0];i > 0; --i){
            now = now * HIGHPRECISION_BASE + a[i];
            ret.a[i] = now / x;
            now %= x;
        }
        while(ret.a[ret.a[0]] == 0 && ret.a[0]) --ret.a[0];
        return ret;
    }
    highP& operator/=(const int x){
        if (x == 0) return *this;
        *this = *this / x;
        return *this;
    }
};
