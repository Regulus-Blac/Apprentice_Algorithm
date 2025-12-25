#include "../model.hpp"
const int MAX = 12;
int board[MAX][MAX],temp[MAX][MAX];
bool row_judge[MAX][MAX],col_judge[MAX][MAX],box_judge[MAX][MAX];
bool judge(int i,int j)
{
    int t = temp[i][j],index = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
    //行列检查
    if(row_judge[i][t]) return 0;
    if(col_judge[j][t]) return 0;
    if(box_judge[index][t]) return 0;
    return 1;
}
void init()
{
    int t,index;
    for(int i = 1;i <= 9;++ i){
        for(int j = 1;j <=9;++j){
            index = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
            t = fastRead();
            board[i][j] = t;
            if(t){
                row_judge[i][t] = 1;
                col_judge[j][t] = 1;
                box_judge[index][t] = 1;
            }
        }
    }
    memcpy(temp,board,sizeof(board));

}
void output(int arr[MAX][MAX])
{
    for(int i = 1;i <=9; ++i){
        for(int j = 1;j <= 9; ++j){
            printf("%d%c",arr[i][j],(j == 9)?'\n':' ');
        }
    }
}
void dfs(int r,int c)
{
    int i,j;
    bool flag = 0;
//  找到第一个空位
    for(i = r;i <=9;++i){
        for(j = (i == r)?c:1;j <=9;++j){
            if(!temp[i][j]){
                flag = 1;
                break;
            }  
        }
        if(flag)    break;
    }
    //已经没有空位,找到一个解,直接退出dfs
    if(!flag){
        output(temp);
        exit(0);
    }
    int index = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
    //对空位，如果该空位为最后一格则直接判断
    for(int k = 1;k <= 9;++k){
        temp[i][j] = k;
        
        if(judge(i,j)){
            row_judge[i][k] = 1;
            col_judge[j][k] = 1;
            box_judge[index][k] = 1;
            if(i == 9 && j == 9){
                output(temp);
                exit(0);
            }
            //不是最后一格就要继续递归,若没有成功退出dfs就要回溯
            dfs(i+(j+1)/10,j+1>9?1:j+1);
            temp[i][j] = 0;
            row_judge[i][k] = col_judge[j][k] = box_judge[index][k] = 0;           
        }else
            temp[i][j] = 0;
    }
}
int main()
{
    init();
    dfs(1,1);

    return 0;
}
/*也可用dacing links,题解如下：*/
/*把每一个点对应到一个集合（行，列，宫，值），然后进行精确覆盖*/
/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define mx 100100//其实不用这么大只要大于729*324即可 
int sum=0;
int a[10][10];//每个点的数
inline int Read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}//快读好习惯 
struct DLX{
	int n,m,cnt;//矩阵的长，宽，点的数量
	int l[mx],r[mx],u[mx],d[mx],row[mx],col[mx];//每个点的左，右，上下，行，列信息 
	int h[mx];//每行的头结点 
	int s[mx];//每列的结点数 
	int ansk[mx];//ansk[] 装答案（选了哪几行）
	void init(int _n,int _m){
		n=_n,m=_m;
		int i;
		for(i=0;i<=m;i++){
			r[i]=i+1;l[i]=i-1;u[i]=d[i]=i;
		}
		r[m]=0;//m右边是0 
		l[0]=m;//0左边是m 
		memset(h,-1,sizeof(h));
		memset(s,0,sizeof(s));
		cnt=m+1;//开始时有m个结点（0结点和各列头结点） 
	}//初始化，生成每列的头
	void link(int R,int C){
		s[C]++;
		row[cnt]=R;
		col[cnt]=C;
		u[cnt]=C;
		d[cnt]=d[C];
		u[d[C]]=cnt;
		d[C]=cnt;
		if(h[R]<0)h[R]=r[cnt]=l[cnt]=cnt;//该行没有别的点,把第一个加入的点作为该行的行头结点 
		else{
			r[cnt]=h[R];
			l[cnt]=l[h[R]];
			r[l[h[R]]]=cnt;
			l[h[R]]=cnt;
		}
		cnt++;
	}//在r行c列插入点
	void remove(int c){
		r[l[c]]=r[c],l[r[c]]=l[c];
		for(int i=d[c];i!=c;i=d[i]){
			for(int j=r[i];j!=i;j=r[j]){
				u[d[j]]=u[j];
				d[u[j]]=d[j];
				s[col[j]]--;
			}
		}
	}//删除c列和c列上有点的行
	void resume(int c){
		for(int i=u[c];i!=c;i=u[i]){
			for(int j=l[i];j!=i;j=l[j]){
				u[d[j]]=j;
				d[u[j]]=j;
				s[col[j]]++;
			}
		}
		r[l[c]]=c;
		l[r[c]]=c;
	}//恢复c列和c列上有点的行
	bool dance(int deep){
		if(r[0]==0){
			int x,y,v;
			for(int i=0;i<deep;i++){
			x=(ansk[i]-1)/9/9;
			y=(ansk[i]-1)/9%9;
			v=(ansk[i])%9;//把行信息转换成对应的点的值 
			if(v==0)v=9;//防止9的倍数%9==0 
			a[x][y]=v;
			}
			return 1;//只要找一组解 
		}
		int c=r[0];
		for(int i=r[0];i!=0;i=r[i])if(s[i]<s[c])c=i;//找到点最少的列
		remove(c);
		for(int i=d[c];i!=c;i=d[i]){
			ansk[deep]=row[i];
			for(int j=r[i];j!=i;j=r[j]) remove(col[j]);
			if(dance(deep+1)==1)return 1;//只要找一组解 
			for(int j=l[i];j!=i;j=l[j]) resume(col[j]);
		}
		resume(c); 
		return false;
	}
}dlx;
int main(){
	dlx.init(729,324);
	//729:
	//9^4种情况对应9^4行;
	//324:
	//对应数独的规则:每个格子，每行，每列，每个九宫只能填1~9各一次 
	//对于第m列：
	//若m在[1,81]表示在(m/9，m%9)填数 
	//若m在[81*1,81*2]在第1+（m-81）/9行填1+（m-81）%9 
	//若m在[81*2,81*3]在第1+（m-81*2）/9列填1+（m-81*2）%9 
	//若m在[81*3,81*4]在第1+（m-81*3）/9宫填1+（m-81*3）%9
	int x;
	int o;
	for(int i=0;i<=8;i++){
	 	for(int j=0;j<=8;j++){
	 	a[i][j]=x=Read();
		 for(int k=1;k<=9;k++){
		 	if(x!=k&&x!=0)continue;//已经填好的点就不用考虑了 
		 	o=i*9*9+j*9+k;
		 	dlx.link(o,i*9+j+1);
		 	dlx.link(o,i*9+81+k);
		 	dlx.link(o,j*9+81*2+k);
		 	dlx.link(o,81*3+(i/3*3+j/3)*9+k);//把点对应成行（集合） 
		 }
		 }
	 }
	 dlx.dance(0);
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++)printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
*/