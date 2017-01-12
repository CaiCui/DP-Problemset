//LIS 51Nod 1134
/*
直接进行一般DP会TLE 50000*50000数量太大 O(n^2)
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 50010;
int s[N];
int f[N];
const int Max=-1000000009;
//一般DP: f[i]=max{f[i],f[j]+1} j=i~n, 表示从i出发的最长递增子序列长度
int main(){
    int n,i,j,Max;
    cin>>n;
    for(i=0;i<n;i++)
    {
     cin>>s[i];
    }
    memset(f,0,sizeof(f));
    for(i=n-1;i>=0;i--)
    {
       for(j=i;j<n;j++)
       {

         if(s[j]>=s[i])
         {

             f[i]=max(f[i],f[j]+1);
             if(f[i]>Max)
                Max=f[i];
         }
       }
    }
    cout<<Max<<endl;
    return 0;
}
*/
/*
另外一个想法是，对于一个未排序的数组，可以用LCS算法来求最长递增子序列。那么求的过程是这样的：

将原数组A排序。排序之后的数组记为B，求A和B的最长公共子序列，就是这里要的结果了。但是这样的时间复杂度和空间复杂度就非常高了。
*/

//LIS 二分求解 适合n很大的情况 O(nlogn)求解 
/** 下面这种方法极其巧妙，充分利用二分搜索的技巧、DP思想、贪心思想
目的：我们期望在前i个元素中的所有长度为len的递增子序列中找到这样一个序列，它的最大元素比a[i+1]小，而且长度要尽量的长，
如此，我们只需记录len长度的递增子序列中最大元素的最小值(贪心)就能使得将来的递增子序列尽量地长。
方法：维护一个一维滚动数组f[i]，记录长度为i的递增子序列中最大元素的最小值，并对于输入中的每个元素（可把当前某个序列最大元素替换掉的）考察其是哪个子序列的新的最大元素，
通过二分完成f数组的最终最优序列的更新，最终i的值便是最长递增子序列的长度。
测试：可通过手工计算一部分5 1 6 8 2 4 5 10值加深对方法的理解。
**/
#include<iostream>
using namespace std;
int f[50010];
int Binarysearch(int st,int ed, int k)
{
  while(st<=ed)
  {
    int mid = (st+ed)/2;
    if(f[mid]==k)
        return mid;
    if(f[mid]<k)
        st= mid + 1; //向右走，用于在序列中添加新的队尾元素，增加序列长度
    else
        ed= mid - 1; //向左走，用于为更新当前序列的最大元素做准备，使其尽可能小
  }
  return st;//返回的是st 因为st这里才会发生真正的更新，增加操作
}
int main(){

 int n,i,j,a;
 cin>>n;
 int Max=0;//记录最终结果,表示当前子序列最大长度
 for(i=0;i<n;i++)
 {
   cin>>a;
   j=Binarysearch(1,Max,a);
   f[j]=a;//更新当前序列的最大元素,这里用到了贪心思想，比如5,1,6,7,8 可以找到5 6 7 8 和1 6 7 8两种，即用小的1更新5，一定不会比从5开始获得的长度小，因为比5大的一定比1大，所以而且1和5都不能加到对方的子序列中，所以两种序列获得的长度只能是1>=5。
   if(Max<j)
   {
       Max = j;//更新最大长度
   }
 }
 cout<<Max<<endl;
 return 0;
}
///f[]就相当与一个滚动数组，当LIS变长时，就会在尾部加入元素，当LIS的某个子序列最大元素要更新时，就会在相应位置更新，
///仿佛是一种隐形的DP在执行，快在了不是n^2枚举而是二分来更新最优解元素的位置，在搜索到位置同时也就完成了更新，而不需要一个个枚举比较找到下一个最优元素的位置。
