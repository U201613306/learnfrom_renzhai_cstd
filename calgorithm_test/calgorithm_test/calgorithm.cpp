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
	//ʱ�临�Ӷ�  T(n) = O(f(n))
	//�ռ临�Ӷ�  �� �ݹ�  �����ڴ滻�ɶ���
	//����ʱ�临�Ӷ�
	//��ȷ��
	//�ɶ���
	//�ݴ���


	//�ݹ鷨  �����б߽������������Ƿ�����Լ������ڣ���

	int sum = 0;
	int N = 8;
	int i = 0;
	plus(N,&sum, i);

	//̰���㷨
	//�������Ž�  

	//���η�  ���ַ� ð������
	//���ֲ���  


	//��̫�򵥣���
	return 0;
}