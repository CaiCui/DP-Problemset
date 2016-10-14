//嵌套矩形 把问题转换为：DAG有向无环图上的动态规划，它是学习DP的基础,本题是图上的一维dp
/**Problem Describe
  *有n个矩形，每个矩形用两个整数a,b描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)，当且仅当a<c,b<d或a<d,b<c,
  *选出尽量多的矩形排成一列使得每一个都可以嵌套在后面那个矩形中。
  examples:
  10
  1 2
  2 4
  5 8
  6 10
  7 9
  3 1
  5 8
  12 10
  9 7
  2 2
  *二元关系，用图来建模，转换成了求DAG上的最长路径，并且是没有确定路径起点，终点的问题。
  *我在做这题的时候先想到，贪心+暴力，因为要最长，肯定要从最小的开始选到最大的，所以从最小的开始每一步都贪心一次，后面再选的时候也不会超过前面选的。
  *首先按a<c的情况排序，然后暴力整个序列，依次枚举比较，得到一个最长的序列；然后按b<d的情形排序，暴力整个序列，依次枚举比较，
  *将2次结果再比较得出最长的。但是这里却无法证明是否能涵盖了a<d,b<c的情形，并且如果再按a<d,b<c来排序基本无法进行下去(事实上这种情况排不了序)，所以贪心法失败(至少我是这么想的。。)
  *时间复杂度O(nlogn+n^2)
  *经过手写发现了，该模型具有最优子结构，即最长序列一定包含建立过程中形成的较长序列，并且是在其基础上+1，依次增长起来的。所以使用DP来解决。
  *构造一个图，若X可以嵌套在Y ,就建立一条X->Y的有向边。然后找到一条最长的有向路径，到这里我就想到了，同样可以用图论的DFS解答，依次dfs每个矩阵，搜索出最长相连的矩阵就行了。
  *不过从上个数字三角形的题目就可以看出，能用dp的，尽量用dp。
  *
  *状态转移方程：d(i)=max{d(j)+1|(i,j)属于E,即j矩形可以嵌套在i中} ：从节点i出发的最长路长度，E表示边集，最终结果就是max{d(i)}
  */
  //0ms	 236kb的DP思路：按边长降序排序，用类似LIS的方法求解，只是比较元素大小的方法变成了比较长和宽
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 1000
int G[maxn][maxn];//图
int a[maxn];
int b[maxn];
int d[maxn];
int n;
int answer;
int dp(int i){
 int &ans=d[i];//技巧
 if(ans>0)return ans;
 ans=1;
 for(int j=1;j<=n;j++)
    if(G[i][j]==1)ans=std::max(ans,dp(j)+1);
 return ans;
}
void print_ans(int i)
{
    printf("%d ",i);
    for(int j=1;j<=n;j++)
        if(G[i][j]==1&&d[i]==d[j]+1)
    {
        print_ans(j);
        break;
    }

}
int main()
{
    freopen("9-2.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i);//读入输入
    memset(G,0,sizeof(G));//初始化为0，表示默认都不连通
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
         if((a[i]>a[j]&&b[i]>b[j])||(a[i]>b[j]&&b[i]>a[j]))
          G[i][j]=1; //表示矩阵i可以包含矩阵j
    memset(d,0,sizeof(d));
    answer=-1;
    int t;
    int s;//记录最大的矩形链首
    for(int i=1;i<=n;i++){
        t=dp(i);
        if(t>answer)
        { answer=t; s=i;}
    }
    printf("%d\n", answer);
    print_ans(s);
    return 0;
}
/*
//输出所有符合条件的路径
void print_all(int i){

  path[++cnt] = i;
  if(cnt == answer) {
    for(int j = 1; j <= cnt; ++j) printf("%d(%d, %d) ", path[j], a[path[j]], b[path[j]]);
    printf("\n");
  }
  else for(int j = 1; j <= n; ++j) if(G[i][j] && d[j]+1 == d[i]){
    print_all(j);
  }
  --cnt;
}
*/
