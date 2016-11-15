//01背包详解，无限背包点拨
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
int main(void)
{
    int V[20],W[20],C;
    int f[20][20];
    int v,w;
    C=10;
    //f[i,j]=max{f[i+1,j],f[i+1,j-V[i]]+W[i]} 表示把第i,i+1...n个物品在容量为j的背包里的最大价值,逆推
    for(int i=n;i>0;n--)
        for(int j=0;j<=C;j++)//C枚举顺序无所谓
    {
        f[i][j]=(i==n?0:f[i+1][j]);
        if(j-V[i]>=0)
            f[i][j]=max(f[i][j],f[i+1][j-V[i]]+W[i]);
    }
    cout<<f[1][C];
    //f[i,j]=max{f[i-1,j],f[i-1,j-V[i]]+W[i]} 表示把前i个物品装在容量为j的背包里的最大价值,顺推
    for(int i=1;i<=n;i++)
        for(int j=0;j<=C;j++)//C枚举顺序无所谓
    {
        f[i][j]=(i==1?0:f[i-1][j]);
        if(j-V[i]>=0)
            f[i][j]=max(f[i][j],f[i-1][j-V[i]]+W[i]);
    }
    cout<<f[n][C];

    //第二种状态下，可以边读入，边计算而不必保留V[],W[]数组,因为是顺推，后面的计算都建立在前面的基础上
    for(int i=1;i<=n;i++)
    {
       cin>>w>>v;
       for(int j=0;j<=C;j++)//C枚举顺序无所谓
       {
        f[i][j]=(i==1?0:f[i-1][j]);
        if(j-v>=0)
            f[i][j]=max(f[i][j],f[i-1][j-v]+w);
        }
    }
    cout<<f[n][C];

    //一维滚动数组优化,计算过程是从右向左，从上到下执行的
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
    {
       cin>>w>>v;
       for(int j=C;j>=0;j--)
        {
        //f[i][j]=(i==1?0:f[i-1][j]);
        if(j-v>=0)
            f[j]=max(f[j],f[j-v]+w);
        }
    }
    cout<<f[C];

    //物品无限价值最大的背包问题
    /**求解思路:
      *就是硬币问题的变形，S面值变为C体积，增加了物品重量这一参数，将原来的无权图改为了带权图。
      *转化成以C为起点，终点任意！的边权之和最大的路径。
      *只需要把硬币中的maxres[j]=max(maxres[j],maxres[j-V[i]]+1);，变为maxres[j]=max(maxres[j],maxres[j-V[i]]+W[i]);即可。
      */
    return 0;
}

