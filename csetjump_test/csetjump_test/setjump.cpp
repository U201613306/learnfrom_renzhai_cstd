#include<stdio.h>
#include<setjmp.h>
#include<process.h>

static jmp_buf j_buf;   //jmp_bufΪint[16] ,_JUMP_BUFFER��setjump�е�һ�ֽṹ��

//GOTO����Ҵ���ṹ�� ��Ծ�����ڴ�й©������ 
//GOTOֻ������ͬһ������


//int main()
//{
//
//
////TCG:
////	printf("holl");
////
////
////	goto TCG;
////
////
////
//
//
//	return 0;
//}


//setjump����ʵ�ֺ����뺯�������Ծ


void kkk()
{

	longjmp(j_buf,0);   //jump_buf���͵����飨��Ծ��������int�� ��ʾ��Ծ����ֵ

	printf("���ﲻ��ִ��");
}

void  ssss()

{
	kkk();

}

//��һ��ִ��ʱ��setjump����Ϊ��(δͨ��longjump��Ծ)  ���ڶ���ͨ��longjump��Ծ������ֵΪ����ֵ�����������ֵ��Ϊ0��ʵ�ʷ���1��
int main()
{
	int i=0;
	i = setjmp(j_buf);
	if (i)
	{
		printf("%d", i);

	}
	else
	{
		ssss();
	}

	system("pause");

}