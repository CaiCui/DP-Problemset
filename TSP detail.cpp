/**
TSP-DP解法：
设F[i,s]表示当前节点为i，未访问的节点集合为s的最短路程。决策为选出下一个节点k，所以状态转移方程为：
F[i,s]= min┬(k in S)?〖{F[k,s-{k}+d[i][k]}〗，d[i][k]表示i到k的距离
DP其实不适合求这个问题。。时间空间复杂度过高了，O(2^n*n^2)
这个DP略难，多想想。。。
**/
#include<iostream>
using namespace std;
const int n = 6;
const int size = 1 << ( n - 1 );
const int infinite = 10000;
int D[n][n] = {
		{0, 10, 20, 30, 40, 50},//0行
		{12, 0, 18, 30, 25, 21},
		{23, 19, 0, 5, 10, 15},
		{34, 32, 4, 0, 8, 16},
		{45, 27, 11, 10, 0, 18},
		{56, 22, 16, 20, 12, 0}//5行
};

int printPath( int path[size][n - 1], int final, int s, int step )
{
	//递归打印路径
	if( step == 1)
		cout << "step 1: " << final << endl;
	else
	{
		printPath( path, path[s][final - 2], s - ( 1 << ( 6 - final ) ), step - 1 );
		cout << "step " << step << ": " << final << endl;
	}
	return 0;
}

void tsp()
{
	//动态规划求解有向图的TSP问题，其中minDis[][]为上述递推关系式中的dp[][],path[][]用于存放路径
	int minDis[size][n - 1];
	int path[size][n - 1];
	for( int set = 1; set != size; ++ set)
	{
		for( int city = 2; city != n + 1; ++ city )
			minDis[set][city - 2] = infinite;
	}
	for( int city = 2; city != n + 1; ++ city )
		//第0列保存的是0~31集合变化中city2的每次更新记录，1列是city3的变化记录，。。。。依次类推	
		minDis[1 << ( n - city )][city - 2] = D[0][city - 1];//这里极其巧妙，通过位运算把D[0]行的元素分别复制到它们所在的minDis中的位置了，可以举例体会，比如city=2,则1<<4，size集合就是010000表示2选入集合，此时它的值就是misDict[16][0]=D[0][1];
	for( int set = 1; set != size-1; ++ set ) //从1~30枚举集合所有情形来构造结果000001 000010 000011 。。。。。哪一位有1，表示该城市被选入集合，从左到右编号为2,3,4,5,6，当变为011111=31，就表示全都选中了，所以要循环到011110即size-1，然后选择最后一个城市是哪个可以和1相连最短。
	{  //其实，set就是对所有2,3,4,5,6存在情况的集合的枚举，然后做从1开始，中间经过该集合S中所有元素，依次到2,3,4,5,6的最优距离的更新
		for( int next = 2; next != n + 1; ++ next )//2~6 选择一个城市
		{
			if( ! ( ( 1 << ( n - next ) ) & set ) )//若城市next不在集合set中
			{
				int min = infinite;
				int set1 = set + ( 1 << ( n - next ) );//加入集合
				for( int city = 2; city != n+1; ++ city )
				{
					//求从城市1出发经过set中所有城市各一次且仅再到达城市next的最短路径
					if( ( 1 << ( n - city ) ) & set )//若城市city在集合set中，例如1：set=1,只有city 6在集合中，所以就1,6,2求最小路径
					{
						int tmp = minDis[set][city - 2] + D[city - 1][next - 1];//接着上面例如1:mindDis[1][4](1到6的距离)+D[5][1](6到2的距离)
						if( tmp < min )
						{
							min = tmp;
							path[set1][next - 2] = city;//接着上面例如1：表示1经过一个点6到2路径更小，记录6
						}
					}
				}
				minDis[set1][next - 2] = min;//接着上面例如1：更新2所在列的最小距离
			}
		}
	}
	//求最终再回到城市1的最短行程，即31,011111的集合情况
	int minDis_all = infinite;
	int final;
	for( int k = 2; k != n + 1; ++ k )
	{
		if( minDis[size - 1][k - 2] + D[k - 1][0] < minDis_all )
		{
			final = k;
			minDis_all = minDis[size - 1][k - 2] + D[k - 1][0];
		}
	}
	//打印最短路径
	cout << "The minimun distance is: " << minDis_all << endl;
	cout << "The path is:" << endl;
	printPath( path, final, size - 1, n - 1 );
	cout << "step 6: back to 1" << endl;
}

int main()
{
	tsp();
	return 0;
}