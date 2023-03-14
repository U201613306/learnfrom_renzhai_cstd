//locale库定义了日期，时区等本地化设置

#define _CRT_SECURE_NO_WARNINGS
#include<windows.system.h>
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

namespace flocale 
{
	const  char af[] = "af";  //南非荷兰语
	const  char af_ZA[] = "af-ZA";//南非荷兰语（南非）
	const char sq[] = "sq";       //阿尔巴尼亚语
	const char sq_AL[] = "sq-AL"; //阿尔巴尼亚语（阿尔巴尼亚）
	char* get_locale(char*in_buffer, const char * in_locale, const char * in_encoding)
	{
		memset(in_buffer, 0, strlen(in_buffer));//初始化字符数组
		strcat(in_buffer, in_locale);   //连接字符函数
		strcat(in_buffer, ".");
		strcat(in_buffer, in_encoding);

		return in_buffer;  //返回数组in_buffer头地址
	}
}

using namespace flocale;
int main()

{
	//strcoll();
	//strxfrm();
	//strftime();
	//struct lconv* lv = nullptr;



	//setlocale(LC_MONETARY,"");//setlocale 函数讲解
	//LC_COLLATE 影响字符串比较（中文环境按拼音排序）(strcoll,strxfrm)（string.h） 
	//LC_CTYPE 影响不同操作系统的字符比较(ctpye.h wctype.h)  （字母的范围会受语言环境，locale本地设置的影响）
	//LC_MONETARY影响不同地区的货币符号等（￥） 
	// LC_NUMERIC影响不同地区数字表示（中文区25.6 打印25.6 法语区打印25,6） 
	// LC_TIME不同地区的时间格式(strftime())（中文 年月日  美国 月日年）
	//setlocale 参数1 默认的影响范围   参数2  默认的地域名称（“”则为当前计算机语言地区，NULL为  不修改区域设置   ）
	//执行成功返回 char*(包含地域信息)  失败返回NULL


	//localeconv();返回Locale convention structure，包含一些有用的信息

	//lconv结构体参数讲解

	//char*    decimal_point;    非货币千分位小数点   
	//char*    thousands_sep;       非货币千分符
	//char*    grouping;            非货币每组数字大小的字符串
	//char*    int_curr_symbol;        货币字符
	//char*    currency_symbol;         货币本地符号
	//char*    mon_decimal_point;       货币小数点    
	//char*    mon_thousands_sep;       
	//char*    mon_grouping;
	//char*    positive_sign;       正货币+
	//char*    negative_sign;       
	//char     int_frac_digits;
	//char     frac_digits;             小数点后部分
	//char     p_cs_precedes;
	//char     p_sep_by_space;        货币空格符
	//char     n_cs_precedes;
	//char     n_sep_by_space;
	//char     p_sign_posn;             正货币 正号位置       
	//char     n_sign_posn;
	//wchar_t* _W_decimal_point;          同上  宽字符支持
	//wchar_t* _W_thousands_sep;
	//wchar_t* _W_int_curr_symbol;
	//wchar_t* _W_currency_symbol;
	//wchar_t* _W_mon_decimal_point;
	//wchar_t* _W_mon_thousands_sep;
	//wchar_t* _W_positive_sign;
	//wchar_t* _W_negative_sign;

	// 使用lconv结构体的本地化实战

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

	time(&currenttime);   //输入 time_t类的指针（地址） 返回 time_t变量  （功能为初始化time_t）
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

	
	timer = localtime(&currenttime);  //得到结构体tm(指针)，包含当前时间 

	strftime(buffer, 128, "%c", timer);// 将时间结构体tm转化为对应格式（字符）
	printf("buffer = %s\n", buffer);      //打印时间结构体tm*(转换后)


	char* p = flocale::get_locale(in_buffer,flocale::af,"UTF-8"); 
	//调用namespace中的函数返回 拼接好的 地点(用的flocale空间中的 af[]  )
	char* content = setlocale(LC_ALL, p); //设置地点 ，并保存    可选ja.UTF8 en_GB.UTF-8
	printf("time = %s\n", content);





	return 0;
}