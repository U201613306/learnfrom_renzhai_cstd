#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void plus(int n, int   *sum,int i)
{

	if (i < n)
	{
		*sum = *sum + i;

		i++;

		plus(n,sum,i);
	}

	

}


int main()
{
	//时间复杂度  T(n) = O(f(n))
	//空间复杂度  如 递归  牺牲内存换可读性
	//渐进时间复杂度
	//正确性
	//可读性
	//容错性


	//递归法  必须有边界条件（决定是否调用自己（出口））

	int sum = 0;
	int N = 8;
	int i = 0;
	plus(N,&sum, i);

	//贪心算法
	//个人最优解  

	//分治法  二分法 冒泡排序
	//二分查找  


	//都太简单，略
	return 0;
}