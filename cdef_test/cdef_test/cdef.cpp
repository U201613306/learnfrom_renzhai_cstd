#include<stdio.h>
#include<stddef.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
//ptrdiff_t��C/C++��׼���ж����һ���������ص��������͡�ptrdiff_t���ͱ���ͨ��������������ָ����������Ľ��
//��׼������(library type)ptrdiff_t �� size_t ����һ��,ptrdiff_t Ҳ��һ���������ص�����,�� cstddef ͷ�ļ��ж��塣
//size_t ��unsigned ����,�� ptrdiff_t ���� signed ����
//size_t ��������ָ�����鳤��,��������һ������;ptrdiff_t ������Ӧ��֤���Դ��ͬһ����������ָ��֮��Ĳ��,���п����Ǹ���

int main()
{

	//ptrdiff_t  //����ָ�볤�ȣ�β���ף�

	char str[] = "hello";
	char* start_ptr = str;
	char* end_ptr = strlen(str) + start_ptr;  
	ptrdiff_t diff = end_ptr - start_ptr;       //ΪʲôҪ�ùؼ��֣�������ֱ���������Ϊint?   ��Ϊ��ͬϵͳ�л����ĳ��ȵ�λ��ͬ������Ϊ�ؼ���ptrdiff_t����֧�ֿ�ƽ̨ת��
	printf("dif = %d",diff);
	//size_tͬ��Ҳ��Ϊ��ƽ̨��Ƶģ�Ϊ�˷�ֹ�ڴ�ƫ�Ʋ����������⣬��ʵ������int
	size_t in = sizeof(int);   //unsigned int����
	for (size_t i = 0; i < 5; i++)
	{

	}

	//unicode ����(UTF-8 UTF-16)һ�����Կ��ַ�wchar_t����
	//��Ϊchar ֻ��8λ����wchar_t��16-32λ

	  /*    ��	  δ����_UNICODE(ANSI�ַ�)	 ������_UNICODE(Unicode�ַ�)
		_tcschr	 strchr	                      wcschr
		_tcscmp	 strcmp	                      wcscmp
		_tcslen	 strlen	                      wcslen*/





	//���ַ����弰��ӡ
#define TEXT(S)  L#S          //�궨�� TEXT(S)  ��ʾ L��S��(���ַ�������) #Ϊ���ӷ�  ����ǰ�ᰴ������˼�滻��
	wchar_t name[] = TEXT(��լ);   //���� L"��լ"
	setlocale(LC_ALL, "zh_CN.UTF-8");  // ������б��ػ����ã�����TEXT�򲻳������ַ�
	wprintf(TEXT(\n %s ), name);

        //�ȼ���
	/*wchar_t name[] = L"��լ";
	setlocale(LC_ALL, "zh_CN.UTF-8");  // ������б��ػ����ã�����TEXT�򲻳������ַ�
	wprintf(L"%s", name);*/




	//ָ�뱣������ֹ��ָ��ı�����
	//if (ptr)
	//{

	//}
	
	
	//�Ѻ�ջ

	//char* ptr =NULL;  //ָ���ַ������ջ��
	//char*p = malloc();                //ָ�����Ŀռ䱣���ڶ���
	//free(p);                          //�ͷ�ָ��ֻ�ͷ��˶��з���Ŀռ䣨���뼰ʱ�ͷţ���Ȼ�ᱬ�ڴ棩����û�������ջ�б����ָ���ַ








	//�ڴ�ƫ�ƣ����㵱ǰ�ṹ����ڴ�ƫ����


	typedef struct 
	{
		int index[100];
		char name[128];
		float h;
	}fhello;


	fhello  hello;

	



	//memset��������һ���ڴ�������ĳ��������ֵ�����ǶԽϴ�Ľṹ����������Ϊ���������һ����췽��
	//������memset����Ա��ֵ���������������index��Աֵ��Ϊ1����Ϊ�������ֽ�Ϊ��λ��ֵ�ģ�int���������ֽ�һ�֣���ֵ�����0x01010101
	//�ַ�������һ�ֽ�һ�֣�������memsetֱ�Ӹ���
	//������ֵӦΪ0~255��8λ������-1��511��ͬ

	//memset(hello.index, 1, 400);
	for(int i = 0; i < 400;i++)
	{
			hello.index[i] = 1;

	}
	memset(hello.name,'A',128);
	hello.h = 3.14f;


	size_t index_offset = offsetof(fhello, index);  //��size_t��ʾƫ�ƴ�С������ֱ��unsign int ��Ϊ�˶�ƽ̨��ֲ
	size_t name_offset = offsetof(fhello, name);  //offsetof(A,B)�����ַA,���ַB��ƫ��
	size_t h_offset = offsetof(fhello, h);
	//���Ͽ��Կ���  ***�ṹ���ַ���ǽṹ���е�һ����Ա�ĵ�ַ  ***int 4�ֽ�  char1�ֽ�  




	unsigned char* ptr_he = (unsigned char*)&hello;  //******���ṹ��ָ�루hello.index,hello.name��ת��Ϊ �ַ�ָ��(hello+strlen(index))
	int * show = (int*)(ptr_he);   
	//*****C������Aǿ��ת��ΪB,ʵ�ʾ�����A���ڴ����B
	//ptr_he �ַ�ָ�� һ���ֽ�һ��  תΪ����ָ�� ���ֽ�һ��  ��ǡ�û�ԭindex��100���������飩
	ptr_he += name_offset;  //������������ƫ�ƣ���ָ���ַ�����name�ĵ�һλ

	char* show2 = (char*)(ptr_he);//ptrҲΪcharָ�룬��ʵ���Բ�ת

	ptr_he += (h_offset - name_offset);

	float *show3 = (float*)(ptr_he);//floatҲ�����ֽ�һ��

	
	
	return 0;
}