#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void stop()
{

	printf("ע����ֹ��������");
	
}

int main()
{
	//srand(2);����������� srand(time(NULL))
	//rand();α���

	atexit(stop);//ע����ֹ�������رճ�������У������ȸ��£�����Ϸ״̬�Զ����棩




	//��������ת�ַ���   ***to string

	//itoa();  ltoa(); ultoa();�޷�������
	//���ƣ�
	//(    _ACRTIMP char* __cdecl itoa(
	//_In_                   int   _Value,
	//	_Pre_notnull_ _Post_z_ char* _Buffer,
	//	_In_                   int   _Radix    ʹ�õĽ��ƣ�2,4,10�ȣ� 
	//atoi();atoi (��ʾ ascii to integer)�ǰ��ַ���ת������������һ��������
	//Ӧ���ڼ��������Ͱ칫����С�
	//int atoi(const char *nptr) ������ɨ����� nptr�ַ�����������ǰ��Ŀհ��ַ�������ո�tab�������ȡ�
	//��� nptr����ת���� int ���� nptrΪ���ַ�������ô������ 0���ر�ע�⣬�ú���Ҫ��ת�����ַ����ǰ�ʮ���������ġ�atoi������ַ�����Ӧ���ִ��ڴ�С���ƣ���int���ʹ�С�йأ������������ܱ���-1
	
	
	//_gcvt()  float����ת�ַ���
	//_In_                   double _Value,      ����ֵ
	//_In_                   int    _DigitCount, ��Ч����
	//_Pre_notnull_ _Post_z_ char*  _DstBuf      ����ַ���






	//ecvt      double����ת�ַ���(���������С���㣬������������)
	//fcvt      double to char   (���������������)  (����ΪС�����λ��)

	//_ACRTIMP char* __cdecl ecvt(
	//	_In_  double _Value,               ����
	//	_In_  int    _DigitCount,          ��Ч����
	//	_Out_ int*   _PtDec,              С����λ��
	//	_Out_ int*   _PtSign               �������
	//);

	double f = 3.1415926;
	int a, b;
	printf("%s\n",ecvt(f,5,&a,&b));

	printf("%s\n", fcvt(f, 5, &a, &b)); //С�������λ
	





	//strtod();  ******string to double 
	//strtod 
	//	_In_z_                   char const* _String,   ��ת���ַ���
	//	_Out_opt_ _Deref_post_z_ char**      _EndPtr   ������������ֹ��nptr�е��ַ�ָ����endptr����
	//ͬ��  strtof strtoll
	
	//div���� ����  (int)
	div_t re = div(13,4); 
	re.quot;  //��
	re.rem;   //����


	//swab(A,B,sizeof(A) )  ��A������λ�ַ���ż��λ���������洢��B�У�B�Ĵ�СΪsizeof(A)��,���A���ַ�Ϊ�������򽻻�n-1λ
	char A[] = "hello world";
	char B[128] = { 0 };    // 
	swab(A,B,sizeof(A));    //ĩβ��\0 ��ǰ��ֹ�ַ������Խ��Ϊ   ehll oowlr(\0d��
	swab(B, B, sizeof(B));
	printf("%s\n%d",B,sizeof(A)); 

	//at_quick_exit �˳�ִ��  ͬ exit
	at_quick_exit(stop);

	//���ƺ��� ����rotl()����   �ƶ�����bit��

	//���ƺ���    ��








	//����·��
	//_makepath_s ����·���ļ���������·����buffer��,���ش�����־errno_t
	_ACRTIMP errno_t __cdecl _makepath_s(
		_Out_writes_z_(_BufferCount) char*       _Buffer,      //����·�����ַ�����
		_In_                         size_t      _BufferCount,  //�����С
		_In_opt_z_                   char const* _Drive,       // �̷� c d e
		_In_opt_z_                   char const* _Dir,         //�����̷���·�� \\Appdata\\local\\Roaming\\
		_In_opt_z_                   char const* _Filename,    // �ļ�����������ʽ��  hello
		_In_opt_z_                   char const* _Ext          // �ļ���ʽ  .txt
	);

	wchar_t buffeer4[_MAX_PATH] = {0};

	_wmakepath_s(buffeer4,_MAX_PATH,L"c",L"\\Appdata\\local\\Roaming\\",L"hello",L".txt");






	//���·��    _wsplitpath()
	wchar_t  drive[_MAX_PATH] = { 0 };
	wchar_t  dir[_MAX_PATH] = {0};
	wchar_t  filepath[_MAX_PATH] = {0};
	wchar_t  ext[_MAX_PATH] = { 0 };


	
	_wsplitpath(buffeer4,drive,dir,filepath,ext);






	//fullpath  ���·��ת��Ϊ ȫ·��
	wchar_t buffer5[_MAX_PATH] = { 0 };

	_wfullpath(buffer5,L"..\\Debug\\cstdlib_test.exe",_MAX_PATH);

	return 0;
}