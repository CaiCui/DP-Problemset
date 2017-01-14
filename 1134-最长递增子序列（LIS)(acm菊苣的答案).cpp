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
//    //d[i] 以i为结尾的 最长的长度
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

//TLE 的方法
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
    //因为子序列的长度若相同，则结尾元素越小越有优势。
    //d[i] 长度为i的子序列的最小结尾元素
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
//    //因为子序列的长度若相同，则结尾元素越小越有优势。
//    //d[i] 长度为i的子序列的最小结尾元素
//    //因为单调性 可以使用二分搜索 优化成nlogn的复杂度
//    memset(d, INF, sizeof(d));
//    for(int i = 1; i <= n; i++)
//    {
//        *lower_bound(d, d + n, a[i]) = a[i];//STL的二分查找
//    }
//    int ans = lower_bound(d, d + n, INF) - d;
//
//    printf("%d\n", ans);
//    return 0;
//}

