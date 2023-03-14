#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "simple_library/public/simple_library.h"

int main()
{
//	clock_t s = get_clock();
////	struct tm * t = get_local_time_tm();
////	char * p = asctime(t);
//
//	time_t t = get_time_t();
//	char *ccc = time_t_to_string(LOCAL_TIME,&t);
//	struct tm * t1 = time_t_to_tm(GM, &t);
//	char *ccc1 = time_t_to_string(GM, &t);
//	time_t tc  = tm_to_time_t(t1);
//	time_t www = tc - t; // 8 Сʱ
//	//char*p = tm_to_string(t1);
//
//	//char buffer[128] = { 0 };
//	//get_local_time_string(buffer);
//
//	//	struct tm * t = get_g_m_time_tm();
//	//	char * p = asctime(t);
//
//	//printf("%s \n", p);
//	clock_t e = get_clock();
//	double www1 = get_clock_diff(s, e);

	wchar_t c[1024] = L"Hello World CC DDD WSFASF  SD SAD ASD SA FASF SA";
	wremove_string_start(c,L"He");

	wremove_wchar_start(c,L'o');

	wremove_wchar_end(c, L'r');

	wremove_all_wchar_end(c, L'l');

	wreplace_wchar_inline(c, L'D',L'?');
	wchar_t buffer[1024] = { 0 };
	wget_printf(buffer,L"%s %i",c,6);
	wchar_t buffer1[1024] = { 0 };
	wget_printf_s_s(sizeof(buffer1),buffer1,L"%s", buffer);
	wchar_t buffer2[1024] = { 0 };

	wprintf(L"%s \n", wstring_mid(buffer1, buffer2, 2, 5));
	wprintf(L"%s \n", c);
	system("pause");
	return 0;
}