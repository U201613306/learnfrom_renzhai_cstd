//locale�ⶨ�������ڣ�ʱ���ȱ��ػ�����

#define _CRT_SECURE_NO_WARNINGS
#include<windows.system.h>
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

namespace flocale 
{
	const  char af[] = "af";  //�ϷǺ�����
	const  char af_ZA[] = "af-ZA";//�ϷǺ�����Ϸǣ�
	const char sq[] = "sq";       //������������
	const char sq_AL[] = "sq-AL"; //��������������������ǣ�
	char* get_locale(char*in_buffer, const char * in_locale, const char * in_encoding)
	{
		memset(in_buffer, 0, strlen(in_buffer));//��ʼ���ַ�����
		strcat(in_buffer, in_locale);   //�����ַ�����
		strcat(in_buffer, ".");
		strcat(in_buffer, in_encoding);

		return in_buffer;  //��������in_bufferͷ��ַ
	}
}

using namespace flocale;
int main()

{
	//strcoll();
	//strxfrm();
	//strftime();
	//struct lconv* lv = nullptr;



	//setlocale(LC_MONETARY,"");//setlocale ��������
	//LC_COLLATE Ӱ���ַ����Ƚϣ����Ļ�����ƴ������(strcoll,strxfrm)��string.h�� 
	//LC_CTYPE Ӱ�첻ͬ����ϵͳ���ַ��Ƚ�(ctpye.h wctype.h)  ����ĸ�ķ�Χ�������Ի�����locale�������õ�Ӱ�죩
	//LC_MONETARYӰ�첻ͬ�����Ļ��ҷ��ŵȣ����� 
	// LC_NUMERICӰ�첻ͬ�������ֱ�ʾ��������25.6 ��ӡ25.6 ��������ӡ25,6�� 
	// LC_TIME��ͬ������ʱ���ʽ(strftime())������ ������  ���� �����꣩
	//setlocale ����1 Ĭ�ϵ�Ӱ�췶Χ   ����2  Ĭ�ϵĵ������ƣ�������Ϊ��ǰ��������Ե�����NULLΪ  ���޸���������   ��
	//ִ�гɹ����� char*(����������Ϣ)  ʧ�ܷ���NULL


	//localeconv();����Locale convention structure������һЩ���õ���Ϣ

	//lconv�ṹ���������

	//char*    decimal_point;    �ǻ���ǧ��λС����   
	//char*    thousands_sep;       �ǻ���ǧ�ַ�
	//char*    grouping;            �ǻ���ÿ�����ִ�С���ַ���
	//char*    int_curr_symbol;        �����ַ�
	//char*    currency_symbol;         ���ұ��ط���
	//char*    mon_decimal_point;       ����С����    
	//char*    mon_thousands_sep;       
	//char*    mon_grouping;
	//char*    positive_sign;       ������+
	//char*    negative_sign;       
	//char     int_frac_digits;
	//char     frac_digits;             С����󲿷�
	//char     p_cs_precedes;
	//char     p_sep_by_space;        ���ҿո��
	//char     n_cs_precedes;
	//char     n_sep_by_space;
	//char     p_sign_posn;             ������ ����λ��       
	//char     n_sign_posn;
	//wchar_t* _W_decimal_point;          ͬ��  ���ַ�֧��
	//wchar_t* _W_thousands_sep;
	//wchar_t* _W_int_curr_symbol;
	//wchar_t* _W_currency_symbol;
	//wchar_t* _W_mon_decimal_point;
	//wchar_t* _W_mon_thousands_sep;
	//wchar_t* _W_positive_sign;
	//wchar_t* _W_negative_sign;

	// ʹ��lconv�ṹ��ı��ػ�ʵս

	time_t currenttime;
	struct tm* timer;

	char buffer[128] = { 0 };
	char in_buffer[128] = {0};
	//struct tm
	//{
	//	int tm_sec;   // seconds after the minute - [0, 60] including leap second
	//	int tm_min;   // minutes after the hour - [0, 59]
	//	int tm_hour;  // hours since midnight - [0, 23]
	//	int tm_mday;  // day of the month - [1, 31]
	//	int tm_mon;   // months since January - [0, 11]
	//	int tm_year;  // years since 1900
	//	int tm_wday;  // days since Sunday - [0, 6]
	//	int tm_yday;  // days since January 1 - [0, 365]
	//	int tm_isdst; // daylight savings time flag
	//};

	time(&currenttime);   //���� time_t���ָ�루��ַ�� ���� time_t����  ������Ϊ��ʼ��time_t��
	//static __inline time_t __CRTDECL time(
	//	_Out_opt_ time_t* const _Time
	//)
	//{
	//	return _time64(_Time);
	//}

	//_CRT_INSECURE_DEPRECATE(localtime_s)
	//	static __inline struct tm* __CRTDECL localtime(
	//		_In_ time_t const* const _Time
	//	)
	//{
	//	return _localtime64(_Time);
	//}

	
	timer = localtime(&currenttime);  //�õ��ṹ��tm(ָ��)��������ǰʱ�� 

	strftime(buffer, 128, "%c", timer);// ��ʱ��ṹ��tmת��Ϊ��Ӧ��ʽ���ַ���
	printf("buffer = %s\n", buffer);      //��ӡʱ��ṹ��tm*(ת����)


	char* p = flocale::get_locale(in_buffer,flocale::af,"UTF-8"); 
	//����namespace�еĺ������� ƴ�Ӻõ� �ص�(�õ�flocale�ռ��е� af[]  )
	char* content = setlocale(LC_ALL, p); //���õص� ��������    ��ѡja.UTF8 en_GB.UTF-8
	printf("time = %s\n", content);





	return 0;
}