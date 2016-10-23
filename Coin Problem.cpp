//固定起点和终点的DAG最长路最短路问题
/**Problem Describe
  *给你n种硬币，每种无限多价值分别为V[i](i=0,1...)，给定一个值S
  *问如何选择可以恰好凑够S，求需要的硬币最大数量和最小数量
  *分析：这道题和嵌套不同的地方就是，有了状态限定。从S->0，即每取一枚V[i],状态就变为S-V[i],目标是使S-V[i]->0的情况下找出max和min
  *最长路：f(i)=max{-max,f(i-V[j])+1)| i>=V[j]} V[j]是硬币的不同价值，i是当前的S值
  *最短路：g(i)=min{max,g(i-V[j])+1)| i>=V[j]} V[j]是硬币的不同价值，i是当前的S值
  *边界f(0)=g(0)=0;表示选择数值S=0时，需要0个，且最大最小均为0
  */

#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
#define maxn 10000
int n;
int ans;
int V[maxn];
int d[maxn];

//递归方式DP
int dpmax(int S)
{
   int &ans=d[S];//ans代表d[i]
   if(ans!=-1) //ans==-1表示还未计算过 也可以用vis[S]=1 or 0来标记访问与否 复杂情况选择STL map函数，判断S时只需d.count(S)即可，就是Hash
    return ans;
   ans=-1<<30; //如果最终返回这个数值，就表示无解，和-1表示没有算过区分开来 可以想象以下S=7 n=1 V=3 就发现这个设计十分巧妙了
   for(int j=0;j<n;j++)
    if(S>=V[j])
       ans=max(ans,dpmax(S-V[j])+1);//核心 状态转移
    return ans;
}
int dpmin(int S)
{
   int &ans=d[S];
   if(ans!=-1)
    return ans;
   ans=1<<30;
   for(int j=0;j<n;j++)
    if(S>=V[j])
       ans=min(ans,dpmin(S-V[j])+1);//核心 状态转移
    return ans;
}
int main()
{
     int i,j,S;
     int a[maxn],b[maxn];
     cin>>n>>S;
     memset(d,-1,sizeof(d));//
     d[0]=0;
     for(i=0;i<n;i++)
        cin>>V[i];
     dpmax(S);
     cout<<d[S]<<endl;

    return 0;
}

//递归方式DP化为递推形式 首先肯定能想到边界f[0]=0(?其他元素初始化为多少呢),然后能想到用for来处理每次的S-V[i]的选择，那么怎么枚举S的状态变化呢？
//由于硬币价值都是整数，也就是S是离散变化的，所以可以直接枚举S从0-S 或 1-S，注意这里0,1没有区别是因为判断了一次V[i]与i的关系。
//若是别的DP就要考虑清楚是0还是1
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
#define maxn 1000
int V[maxn];
int maxres[maxn];
int minres[maxn];
int main(){

    int n,S,j,i;
    cin>>n>>S;
    for(int i=0;i<n;i++)
        cin>>V[i];
    maxres[0]=minres[0]=0;
    for(i=1;i<=S;i++){minres[i]=maxn;maxres[i]=-maxn;} //非常重要的地方，如果没有就会出错,想一想,举个例子就明白了
    for(j=0;j<=S;j++)
        for(i=0;i<n;i++)
    {
        if(j-V[i]>=0)
        {
            maxres[j]=max(maxres[j],maxres[j-V[i]]+1);
            minres[j]=min(minres[j],minres[j-V[i]]+1);
        }
    }
    cout<<maxres[S]<<endl;
    cout<<minres[S]<<endl;
    return 0;

}

