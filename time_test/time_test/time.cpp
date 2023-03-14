#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<process.h>
#include<windows.h>
void  fun(void);
int main()
{
	//CLOCKS_PER_SEC
	//clock_t s = 1000;  //clock_t是C存储系统时间的类型，单位毫秒，CLOCKS_PER_SEC 1000ms即一秒

	//time_t  时间变量（一般为long int ）
	
	//格林威致时间  1970年开始   
		//32位int 则只能用至2038年
		//一般用long int 64位
		//现用原子时标  (UT2)  GMT（格林威治时间）
		//世界协调时  UTC（无数原子时取平均，是秒的时间戳 )

		//GPS时间  UTC（世界协调时）  LT （地方时）   
	//各地的时刻都有不同，但是大家的UTC(1970格林威治)是相同的
		//GMT  =  UTC  (time_t)
	
		
	//	timeval;(微秒)
	//  tm   时间结构体
	struct tm t;
	t.tm_hour = 4;
	t.tm_isdst = 0;
	t.tm_mday = 1;
	t.tm_min = 59;
	t.tm_mon = 11;
	t.tm_sec = 24;
	t.tm_wday = 3;
	t.tm_yday = 24;
	t.tm_year = 12;//从1970开始的格林威治时间





	//将 时间结构体tm 快速转成 能打印的字符形式
	//char *time = asctime(&t);
	//printf("%s", time);


	//使用asctime_s是更加安全的做法

	char buffer[256] = {0};

	//一个错误的用法   errno_t time_safe = asctime_s(buffer,256,&t);
	//***********asctime_s返回值是错误代码类型（errno_t）,返回0表示成功运行
	if ( !asctime_s(buffer, 256, &t) )
	{
		printf("%s",buffer);
	}
	



	//**********time(NULL)返回格林威治时（1970）的秒数,()内也是输出
	time_t time_second = time(NULL);
	time_t time_hour = time_second / 3600;


	//localtime将格林威治时间转换为tm结构体

	time_t newt=NULL;
	time(&newt);
	//Out_opt_ time_t* const _Time   ******C的安全编程******
	//const int*p  (恒定的是int)指针的地址可改，但指针指向的值不能改
	//int *const p(恒定的是*)指针地址不可改，但指针指向的值可改
	//重点：含有（int）*const 的参数意思是指针地址不变，所以不能初始化一个指针去接，应该初始化一个变量（&i）去接
	 struct tm *time_local =localtime(&newt);
	 char buffer_new[256] = { 0 };
	 if (!asctime_s(buffer_new, 256, time_local))
	 {
		 printf("buffer_new=%s", buffer_new);
	 }



	 //clock()   用于记录程序运行所使用的时间 (检测程序运行的消耗)

	 {
		 //初始化
		clock_t time_run= clock();



		 //渲染
		 for (size_t j = 0; j < 10000000; j++)
		 {
			 fun();  //检测函数耗时
		 }

		 clock_t time_end = clock();


		 double time_total = (double)(time_end - time_run) / CLOCKS_PER_SEC; //clock（）返回单位是毫秒
		 printf("%f",time_total);

		 //结束 释放





	 }





	 //ctime   将格林威治时间转换为  字符的年月日时

	 time_t ti =time(NULL);

	 char *  result = ctime(&ti);








	 //difftime()  时间差函数


	 time_t t_start;
	 time(&t_start);
	 Sleep(50);
	 time_t t_end;
	 time(&t_end);

	 double dif = difftime(t_end,t_start);
	 printf("time diff is %lf",dif);





	 //gmtime()   和localtime 一样 将格林威治秒数转换为 TM时间结构体（区别是 localtime是本地时间,如北京时间  gmtime是标准时间）
	 time_t tm;
	 time(&tm);
	 
	 struct tm * gm_time= gmtime(&tm);

	 char* gm_output=asctime(gm_time);
	 printf("\n格林威治时间是%s\n",gm_output);
	 printf("北京时间是%02d:%02d\n",(gm_time->tm_hour+8)%24,(gm_time->tm_min));


	 //mktime 将tm时间结构体转换为  格林威至秒数

	 //略

	 //strftime    *****   将tm时间转为特定时间格式输出

	 char buffer2[256] = {};
	 strftime(buffer2,256,"%y-%m-%d %H:%M:%S",gm_time);
	 printf("strftime自定义时间格式输出为：%s\n",buffer2);


	 //  关于时间格式 Format的选择

	 //_ACRTIMP size_t __cdecl strftime(
		// _Out_writes_z_(_SizeInBytes)  char*            _Buffer,
		// _In_                          size_t           _SizeInBytes,
		// _In_z_ _Printf_format_string_ char const*      _Format,
		// _In_                          struct tm const* _Tm
	 //);

	 //%a  缩写星期几
	 //%A  完整的星期几
	 //%b  缩写月份
	 //%B  完整月份
	 //%c  日期和时间的表述法
	 //%d  日期
	 //%D   月 日 年 日期表示法
	 //%T   时分秒
	 //%H   24小时时间
	 //%I   12小时时间
	 //%j    一年中的第几天
	 //%m    月份
	 //%M    分钟
	 //%p    上午、下午
	 //%S    秒
	 //%U    一年中的第几周
	 //%w    星期几(数字表示）
	 //%W    一年中的第几周
	 //%x     日期表示法
	 //%X     时间表示法
	 //%y     年份（最后两位）
	 //%Y     年份（完整）
	 //%Z     时区名称（）


	 //timespec_get  高精度的获得UTC（世界协调时）的格林威治秒数（精确到纳秒）
	 struct timespec tm2 = {0};  //timespec 含 xx秒xx纳秒 
	 timespec_get(&tm2,TIME_UTC);
	 struct tm* timspec_ = gmtime(&tm2.tv_sec);
	 strftime(buffer2, 128, "%D  %T", timspec_);
	 enum lan {

		 STD,
	     DST,
		 

	 };


	 //_get_tzname 获取本地时区名称
	 size_t tzname_get=NULL;
	 char buffer3[128] = {0};
	 _get_tzname(&tzname_get,buffer3,128,STD);  //最后一个参数为索引,方便定义枚举，增强代码的可读性，也可以直接给0,1(选择标准时、夏令时)


	system("pause");
	return 0;
}



void  fun(void)
{

	

}