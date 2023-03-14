#include<stdio.h>
#include<stdarg.h>

//arg�����ڴ��ݿɱ��������char,int,float,double
//va_arg ��va_start(ptr,int) ���ǽ�����ָ�루va_list��ָ��ָ�����͵ĺ�һλ (int֮��)
//�������ݲ���˳��
//5��
//4��
//3��
//2��
//1��
//����ַ�ӵ͵���
//**************����C����*****************
//�ɱ�����ں����䴫��ʱ������û��ָ�����ݺͽ��ܷ��Ĳ������ͣ�C�����б����������ƣ����float������Ϊdouble,short int ����Ϊint,����ʵ��û��float�ʹ��ݣ�û��va_arg(ptr,float)��д����
//va_arg������ȡ���ṹ��

const int INT_TYPE = 100000;
const int STR_TYPE = 100001;
const int CHAR_TYPE = 100002;
const int LONG_TYPE = 100003;
const int FLOAT_TYPE = 100004;
const int DOUBLE_TYPE = 100005;
//��һ�����������ѡ��������,����ѭ��ȡ����������  
//�ɱ��������arg_type,arg_value...����ʽ����,�Դ���ͬ�Ŀɱ��������  
void arg_type(int cnt, ...);
//��һ�����������ѡ��������,����ѭ��ȡ����������  
void arg_cnt(int cnt, ...);
//����va_start,va_arg��ʹ�÷���,���������ڶ�ջ�еĵ�ַ�ֲ����  
void arg_test(int i, ...);
int main(int argc, char *argv[])
{
	int int_size = _INTSIZEOF(int);
	printf("int_size=%d\n", int_size);
	arg_test(0, 4);


	arg_cnt(4, 1, 2, 3, 4);
	arg_type(5, INT_TYPE, 222, STR_TYPE, "ok,hello world!",FLOAT_TYPE,2.345,CHAR_TYPE,'E',INT_TYPE,233);
	return 0;
}


void arg_test(int i, ...)
{
	int j = 0;
	va_list arg_ptr;


	va_start(arg_ptr, i);
	printf("&i = %p\n", &i);//��ӡ����i�ڶ�ջ�еĵ�ַ  
	printf("arg_ptr = %p\n", arg_ptr);
	//��ӡva_start֮��arg_ptr��ַ,  
	//Ӧ�ñȲ���i�ĵ�ַ��sizeof(int)���ֽ�  
	//��ʱarg_ptrָ����һ�������ĵ�ַ  


	j = *((int *)arg_ptr);
	printf("%d %d\n", i, j);
	j = va_arg(arg_ptr, int);
	printf("arg_ptr = %p\n", arg_ptr);
	//��ӡva_arg��arg_ptr�ĵ�ַ  
	//Ӧ�ñȵ���va_argǰ��sizeof(int)���ֽ�  
	//��ʱarg_ptrָ����һ�������ĵ�ַ  
	va_end(arg_ptr);                   //���һ����Ҫ�����ͷŲ���ָ��
	printf("%d %d\n", i, j);
}
void arg_cnt(int cnt, ...)
{
	int value = 0;
	int i = 0;
	int arg_cnt = cnt;
	va_list arg_ptr;
	va_start(arg_ptr, cnt);
	for (i = 0; i < cnt; i++)
	{
		value = va_arg(arg_ptr, int);
		printf("value%d=%d\n", i + 1, value);
	}
}
void arg_type(int cnt, ...)
{
	int arg_type = 0;
	int int_value = 0;
	int i = 0;
	float float_value = 0.0;
	int arg_cnt = cnt;
	char char_value = NULL;
	char *str_value = NULL;
	va_list arg_ptr;
	va_start(arg_ptr, cnt);
	for (i = 0; i < cnt; i++)
	{
		arg_type = va_arg(arg_ptr, int);   //ȡ����ǰ����������ָ������һλ��ָ��value��
		switch (arg_type)
		{
		case INT_TYPE:
			int_value = va_arg(arg_ptr, int);   //��ȡ��valueָ����һ��type��
			printf("value%d=%d\n", i , int_value);
			break;
		case STR_TYPE:
			str_value = va_arg(arg_ptr, char*);
			printf("value%d=%s\n", i , str_value);
			break;
		case CHAR_TYPE:
			char_value = va_arg(arg_ptr,int);
			printf("value%d=%c\n", i, char_value);
			break;
		case FLOAT_TYPE:
		    float_value = (float)va_arg(arg_ptr, double);  //double�Ŷ�
			printf("value%d = %f \n",i,float_value);
			break;
		default:
			break;
		}
	}
}