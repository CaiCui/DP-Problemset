//nod51 1049最大连续子段和 经典DP 注意本题陷阱：a[i]范围很大，所以求出的和可能会超出int ,所以要用 long long
#include<iostream>
using namespace std;
//-2 11 -4 13 -5 -2
/**
当B[K]>0时，无论B[K]为何值，B[K]=B[K-1]+A[K]
当B[K]<0时，也就是B[K]记录到一个A[J]是负的，可以把B[K]变成负的，那么B[J]记录的这一段应该截掉，应为无论后面的A[K]多大，加上个负数总不可能是最大的子段和，因此将B[K]=A[K]，重新开始记录。
故动态转移方程便可得出
B[K] = MAX(B[K-1]+A[K] , A[K])
**/
int a[50010];
int main(){
    int n,i;
    long long sum=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    long long b=0;
    for(i=1;i<=n;i++){
            if(b>0)b+=a[i];//贪心，只要和是>0就加入元素，并且更新一下sum最大和
            else b=a[i];//b<=0，重来
            if(b>sum)
                sum=b;
            }
    cout<<sum<<endl;
    return 0;
}
