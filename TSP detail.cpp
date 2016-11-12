/**
TSP-DP�ⷨ��
��F[i,s]��ʾ��ǰ�ڵ�Ϊi��δ���ʵĽڵ㼯��Ϊs�����·�̡�����Ϊѡ����һ���ڵ�k������״̬ת�Ʒ���Ϊ��
F[i,s]= min��(k in S)?��{F[k,s-{k}+d[i][k]}����d[i][k]��ʾi��k�ľ���
DP��ʵ���ʺ���������⡣��ʱ��ռ临�Ӷȹ����ˣ�O(2^n*n^2)
���DP���ѣ������롣����
**/
#include<iostream>
using namespace std;
const int n = 6;
const int size = 1 << ( n - 1 );
const int infinite = 10000;
int D[n][n] = {
		{0, 10, 20, 30, 40, 50},//0��
		{12, 0, 18, 30, 25, 21},
		{23, 19, 0, 5, 10, 15},
		{34, 32, 4, 0, 8, 16},
		{45, 27, 11, 10, 0, 18},
		{56, 22, 16, 20, 12, 0}//5��
};

int printPath( int path[size][n - 1], int final, int s, int step )
{
	//�ݹ��ӡ·��
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
	//��̬�滮�������ͼ��TSP���⣬����minDis[][]Ϊ�������ƹ�ϵʽ�е�dp[][],path[][]���ڴ��·��
	int minDis[size][n - 1];
	int path[size][n - 1];
	for( int set = 1; set != size; ++ set)
	{
		for( int city = 2; city != n + 1; ++ city )
			minDis[set][city - 2] = infinite;
	}
	for( int city = 2; city != n + 1; ++ city )
		//��0�б������0~31���ϱ仯��city2��ÿ�θ��¼�¼��1����city3�ı仯��¼������������������	
		minDis[1 << ( n - city )][city - 2] = D[0][city - 1];//���Ｋ�����ͨ��λ�����D[0]�е�Ԫ�طֱ��Ƶ��������ڵ�minDis�е�λ���ˣ����Ծ�����ᣬ����city=2,��1<<4��size���Ͼ���010000��ʾ2ѡ�뼯�ϣ���ʱ����ֵ����misDict[16][0]=D[0][1];
	for( int set = 1; set != size-1; ++ set ) //��1~30ö�ټ�������������������000001 000010 000011 ������������һλ��1����ʾ�ó��б�ѡ�뼯�ϣ������ұ��Ϊ2,3,4,5,6������Ϊ011111=31���ͱ�ʾȫ��ѡ���ˣ�����Ҫѭ����011110��size-1��Ȼ��ѡ�����һ���������ĸ����Ժ�1������̡�
	{  //��ʵ��set���Ƕ�����2,3,4,5,6��������ļ��ϵ�ö�٣�Ȼ������1��ʼ���м侭���ü���S������Ԫ�أ����ε�2,3,4,5,6�����ž���ĸ���
		for( int next = 2; next != n + 1; ++ next )//2~6 ѡ��һ������
		{
			if( ! ( ( 1 << ( n - next ) ) & set ) )//������next���ڼ���set��
			{
				int min = infinite;
				int set1 = set + ( 1 << ( n - next ) );//���뼯��
				for( int city = 2; city != n+1; ++ city )
				{
					//��ӳ���1��������set�����г��и�һ���ҽ��ٵ������next�����·��
					if( ( 1 << ( n - city ) ) & set )//������city�ڼ���set�У�����1��set=1,ֻ��city 6�ڼ����У����Ծ�1,6,2����С·��
					{
						int tmp = minDis[set][city - 2] + D[city - 1][next - 1];//������������1:mindDis[1][4](1��6�ľ���)+D[5][1](6��2�ľ���)
						if( tmp < min )
						{
							min = tmp;
							path[set1][next - 2] = city;//������������1����ʾ1����һ����6��2·����С����¼6
						}
					}
				}
				minDis[set1][next - 2] = min;//������������1������2�����е���С����
			}
		}
	}
	//�������ٻص�����1������г̣���31,011111�ļ������
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
	//��ӡ���·��
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