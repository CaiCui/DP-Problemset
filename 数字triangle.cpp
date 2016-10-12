/**动态规划01数字三角形
  *test.in
  *4
  *1
  *3 2
  *4 10 1
  *4 3 2 20
  *求从这个三角形顶端走到底端最大的一条路的和
  */
//方法0：递归
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 100
using namespace std;
int n, a[maxn][maxn];
int f(int i, int j){
    if(i == n) return a[i][j];
    return max(f(i+1, j), f(i+1, j+1)) + a[i][j]; //max() is included in <algorithm>
}
int d(int i, int j){
    return a[i][j] + (i == n ? 0 : max(d(i+1, j), d(i+1, j+1)));
}
int main(){
    freopen("test.in", "r", stdin);
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= i; j++) scanf("%d", &a[i][j]);
    int ans;
    ans = d(1, 1);
    printf("%d\n", ans);
    return 0;
}

//方法一:dfs回溯
/*
#include<cstdio>
#include<cstdlib>
#define maxn 1000
int a[maxn][maxn];
int ans,n,cnt;
void dfs(int x,int y,int s)
{
    if(x==n)
    {
        if(s>ans)
            ans=s;
        cnt++;
        return;
    }
    else{
        dfs(x+1,y,s+a[x+1][y]);
        dfs(x+1,y+1,s+a[x+1][y+1]);
    }
}
int main()
{
    freopen("test.in","r",stdin);//读入
    ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
         scanf("%d",&a[i][j]);
    cnt=0;
    dfs(1,1,a[1][1]);
    printf("result: %d",ans);
    return 0;
}

//方法二:记忆化搜索,空间换时间
#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define maxn 1000
int a[maxn][maxn],b[maxn][maxn];
int n;

int fmem(int i,int j)
{
    if(b[i][j]>=0)return b[i][j];
    return b[i][j]=a[i][j]+(i==n?0:max(fmem(i+1,j),fmem(i+1,j+1)));
}
int main()
{
    freopen("test.in","r",stdin);//读入
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
         scanf("%d",&a[i][j]);
    memset(b,-1,sizeof(b));
    printf("result: %d",fmem(1,1));
    return 0;
}
*/
//方法三：动态规划 递推式d(i,j)=a(i,j)+max{d(i+1,j),d(i+1,j+1)} d(i,j):第i行j列的当前的累加值
#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define maxn 1000
int a[maxn][maxn],d[maxn][maxn];
int n;
int main()
{
    freopen("test.in","r",stdin);//读入
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        for(int j=1;j<=i;j++)
         scanf("%d",&a[i][j]);
    memset(d,-1,sizeof(d));
    for(int i=1;i<=n;i++)//初始化第四行，从第四行到第一行倒着递推
    {
         scanf("%d",&a[n][i]);
         d[n][i]=a[n][i];
    }
     for(int i=n-1;i>0;i--)
        for(int j=1;j<=i;j++)
        {
            d[i][j]=a[i][j]+max(d[i+1][j],d[i+1][j+1]);
        }
    printf("result is : %d",d[1][1]);
    return 0;
}
进阶:优化dp
 ///dp方法二一维滚动数组，空间优化
    int *sum;
    sum=D[n];//第n行复制过来
    for(i=10-1;i>=1;i--)
        for(j=1;j<=i;j++)
        {
            sum[j]=max(sum[j],sum[j+1])+D[i][j];
        }
    cout<<sum[1]<<endl;
