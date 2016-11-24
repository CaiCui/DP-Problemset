//递归中的DP ---表达式上的DP，最优矩阵连乘问题，关键点：N个矩阵连乘，确定括号的位置，减少计算次数
/**可以分析出来：
  *该问题具有最优子结构特征
  *设A=P x Q 第i个矩阵Ai是(pi-1*pi)
  *P=A1xA2....xAk  Q=Ak+1 x Ak+2 x Ak+3.....xAn
  *很明显，为了计算最优P，还要继续枚举P=A1xA2....xAk的最优情况,依次类推
  *状态方程：i,j作为起点和终点
  *f(i,j)=min{f(i,k)+f(k+1,j)+pi-1*pk*pj} 表示把Ai..Aj乘起来的次数，枚举“最后一次乘法”是第k个乘号，就是最后一次合并两边的位置(P)x(Q)，时间复杂度O(n^3)
  *边界f(i,i)=0
  */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<climits>
#include<deque>
#include<stack>
#include<vector>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<functional>
#include<cstring>
#include<cctype>
#include<bits/stdc++.h>
typedef long long ll;
const int MOD=10e9+7;
const int INF=0x7fffffff;
const double ESP=10e-7;
const double Pi=acos(-1.0);
const int dr[]= {0,0,1,-1,1,1,-1,-1};
const int dc[]= {-1,1,0,0,-1,1,-1,1};
#define maxn INF
#define min -INF
using namespace std;
//记忆化搜索,比较好写
int n,p[205],d[205][205];
int f(int i,int j){//(1,3)
    if(d[i][j]>=0)return d[i][j];
    int ans,t;
    ans = maxn;
    for(int k=i;k<j;k++)//枚举k,从[i,j)
    {
        t = f(i,k)+f(k+1,j)+p[i-1]*p[k]*p[j];//(0,1,2,3)
        if(t<ans) ans=t;
    }
    return ans;
}
int main(void)
{
    int i;
    scanf("%d",&n);//3 A B C 2x3 3x4 4x5
    for(i=0;i<=n;i++)
        scanf("%d",p+i);//2 3 4 5
    memset(d,-1,sizeof(d));
    for(i=0;i<=n;i++)
        d[i][i]=0;
    printf("%d\n",f(1,n));

    //递推O(n^3),有点难
    for(int seq=0;seq<n;seq++)//按照区间长度从0到n的方式递推,设seq=j-i，要以seq递增即j-i递增也即区间长度递增的顺序DP
      for(int i=1;i+seq <= n;i++){
        int j=i+seq;
        f[i][j]=i==j?0:maxn;
        for(int k=i;k<j;k++)
        {
            int t = f[i][k] + f[k+1][j] + p[i-1]*p[k]*p[j];
            if(t < f[i][j]) f[i][j] = t;
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}










