//�̶������յ��DAG�·���·����
/**Problem Describe
  *����n��Ӳ�ң�ÿ�����޶��ֵ�ֱ�ΪV[i](i=0,1...)������һ��ֵS
  *�����ѡ�����ǡ�ôչ�S������Ҫ��Ӳ�������������С����
  *������������Ƕ�ײ�ͬ�ĵط����ǣ�����״̬�޶�����S->0����ÿȡһöV[i],״̬�ͱ�ΪS-V[i],Ŀ����ʹS-V[i]->0��������ҳ�max��min
  *�·��f(i)=max{-max,f(i-V[j])+1)| i>=V[j]} V[j]��Ӳ�ҵĲ�ͬ��ֵ��i�ǵ�ǰ��Sֵ
  *���·��g(i)=min{max,g(i-V[j])+1)| i>=V[j]} V[j]��Ӳ�ҵĲ�ͬ��ֵ��i�ǵ�ǰ��Sֵ
  *�߽�f(0)=g(0)=0;��ʾѡ����ֵS=0ʱ����Ҫ0�����������С��Ϊ0
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

//�ݹ鷽ʽDP
int dpmax(int S)
{
   int &ans=d[S];//ans����d[i]
   if(ans!=-1) //ans==-1��ʾ��δ����� Ҳ������vis[S]=1 or 0����Ƿ������ �������ѡ��STL map�������ж�Sʱֻ��d.count(S)���ɣ�����Hash
    return ans;
   ans=-1<<30; //������շ��������ֵ���ͱ�ʾ�޽⣬��-1��ʾû��������ֿ��� ������������S=7 n=1 V=3 �ͷ���������ʮ��������
   for(int j=0;j<n;j++)
    if(S>=V[j])
       ans=max(ans,dpmax(S-V[j])+1);//���� ״̬ת��
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
       ans=min(ans,dpmin(S-V[j])+1);//���� ״̬ת��
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

//�ݹ鷽ʽDP��Ϊ������ʽ ���ȿ϶����뵽�߽�f[0]=0(?����Ԫ�س�ʼ��Ϊ������),Ȼ�����뵽��for������ÿ�ε�S-V[i]��ѡ����ô��ôö��S��״̬�仯�أ�
//����Ӳ�Ҽ�ֵ����������Ҳ����S����ɢ�仯�ģ����Կ���ֱ��ö��S��0-S �� 1-S��ע������0,1û����������Ϊ�ж���һ��V[i]��i�Ĺ�ϵ��
//���Ǳ��DP��Ҫ���������0����1
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
    for(i=1;i<=S;i++){minres[i]=maxn;maxres[i]=-maxn;} //�ǳ���Ҫ�ĵط������û�оͻ����,��һ��,�ٸ����Ӿ�������
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

