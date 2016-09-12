///dp 动态规划hdu 1584
/**
状态方程:
f[x][y]=min{f[x][y-1]+abs(a[y]-a[y-1]),min{f[x][t-1]+f[t][y]+abs(a[y]-a[t-1])} }
*/
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int weizhi[20];
int dp[15][15];
int main()
{
 int T,i,j,len;
 while(cin>>T)
 {
     int a;
   for(int k=0;k<T;k++)
   {
       for(i=1;i<=10;i++)
        {
            cin>>a;
            weizhi[a]=i;
        }
      memset(dp,0,sizeof(dp));
      for(len=1;len<=9;len++)
      {
          for(i=1;i+len<=10;i++)
          {
              dp[i][i+len]=dp[i][i+len-1]+abs(weizhi[i+len]-weizhi[i+len-1]);
              for(j=i+1;j<=i+len;j++)///<和<=一个效果
              {
                  dp[i][i+len]=min(dp[j][i+len]+dp[i][j-1]+abs(weizhi[i+len]-weizhi[j-1]),dp[i][i+len]);
              }
          }
      }

      cout<<dp[1][10]<<endl;

 }

   }

}
