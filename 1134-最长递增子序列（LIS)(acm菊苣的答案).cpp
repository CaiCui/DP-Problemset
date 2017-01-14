//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 50000 + 5;
//int d[maxn], a[maxn];
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for(int i = 1; i <= n; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    //d[i] ��iΪ��β�� ��ĳ���
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 0; j < i; j++)
//        {
//            if(a[i] > a[j])
//            {
//                d[i] = max(d[i], d[j] + 1);
//            }
//        }
//    }
//    printf("%d\n", d[n]);
//    return 0;
//}
//

//TLE �ķ���
#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 5;
const int INF = 0x3f3f3f3f;
int d[maxn], a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    //��Ϊ�����еĳ�������ͬ�����βԪ��ԽСԽ�����ơ�
    //d[i] ����Ϊi�������е���С��βԪ��
    memset(d, INF, sizeof(d));

    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i == 1 || a[j] > d[i - 1])
                d[i] = min(d[i], a[j]);
        }

    }
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] < INF) ans = i;
    }
    printf("%d\n", ans);
    return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 50000 + 5;
//const int INF = 0x3f3f3f3f;
//int d[maxn], a[maxn];
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for(int i = 1; i <= n; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    //��Ϊ�����еĳ�������ͬ�����βԪ��ԽСԽ�����ơ�
//    //d[i] ����Ϊi�������е���С��βԪ��
//    //��Ϊ������ ����ʹ�ö������� �Ż���nlogn�ĸ��Ӷ�
//    memset(d, INF, sizeof(d));
//    for(int i = 1; i <= n; i++)
//    {
//        *lower_bound(d, d + n, a[i]) = a[i];//STL�Ķ��ֲ���
//    }
//    int ans = lower_bound(d, d + n, INF) - d;
//
//    printf("%d\n", ans);
//    return 0;
//}

