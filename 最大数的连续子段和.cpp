//nod51 1049��������Ӷκ� ����DP ע�Ȿ�����壺a[i]��Χ�ܴ���������ĺͿ��ܻᳬ��int ,����Ҫ�� long long
#include<iostream>
using namespace std;
//-2 11 -4 13 -5 -2
/**
��B[K]>0ʱ������B[K]Ϊ��ֵ��B[K]=B[K-1]+A[K]
��B[K]<0ʱ��Ҳ����B[K]��¼��һ��A[J]�Ǹ��ģ����԰�B[K]��ɸ��ģ���ôB[J]��¼����һ��Ӧ�ýص���ӦΪ���ۺ����A[K]��󣬼��ϸ������ܲ������������Ӷκͣ���˽�B[K]=A[K]�����¿�ʼ��¼��
�ʶ�̬ת�Ʒ��̱�ɵó�
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
            if(b>0)b+=a[i];//̰�ģ�ֻҪ����>0�ͼ���Ԫ�أ����Ҹ���һ��sum����
            else b=a[i];//b<=0������
            if(b>sum)
                sum=b;
            }
    cout<<sum<<endl;
    return 0;
}
