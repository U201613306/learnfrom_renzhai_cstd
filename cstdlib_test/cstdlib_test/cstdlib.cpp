#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void stop()
{

	printf("注册终止函数激活");
	
}

int main()
{
	//srand(2);设置随机种子 srand(time(NULL))
	//rand();伪随机

	atexit(stop);//注册终止函数（关闭程序后运行，用于热更新，或游戏状态自动保存）




	//各种类型转字符串   ***to string

	//itoa();  ltoa(); ultoa();无符长整型
	//类似：
	//(    _ACRTIMP char* __cdecl itoa(
	//_In_                   int   _Value,
	//	_Pre_notnull_ _Post_z_ char* _Buffer,
	//	_In_                   int   _Radix    使用的进制（2,4,10等） 
	//atoi();atoi (表示 ascii to integer)是把字符串转换成整型数的一个函数，
	//应用在计算机程序和办公软件中。
	//int atoi(const char *nptr) 函数会扫描参数 nptr字符串，会跳过前面的空白字符（例如空格，tab缩进）等。
	//如果 nptr不能转换成 int 或者 nptr为空字符串，那么将返回 0。特别注意，该函数要求被转换的字符串是按十进制数理解的。atoi输入的字符串对应数字存在大小限制（与int类型大小有关），若其过大可能报错-1
	
	
	//_gcvt()  float浮点转字符串
	//_In_                   double _Value,      浮点值
	//_In_                   int    _DigitCount, 有效数字
	//_Pre_notnull_ _Post_z_ char*  _DstBuf      结果字符串






	//ecvt      double浮点转字符串(结果不包含小数点，且作四舍五入)
	//fcvt      double to char   (结果不做四舍五入)  (参数为小数点后位数)

	//_ACRTIMP char* __cdecl ecvt(
	//	_In_  double _Value,               浮点
	//	_In_  int    _DigitCount,          有效数字
	//	_Out_ int*   _PtDec,              小数点位置
	//	_Out_ int*   _PtSign               结果正负
	//);

	double f = 3.1415926;
	int a, b;
	printf("%s\n",ecvt(f,5,&a,&b));

	printf("%s\n", fcvt(f, 5, &a, &b)); //小数点后五位
	





	//strtod();  ******string to double 
	//strtod 
	//	_In_z_                   char const* _String,   待转换字符串
	//	_Out_opt_ _Deref_post_z_ char**      _EndPtr   不合条件而终止的nptr中的字符指针由endptr传回
	//同理  strtof strtoll
	
	//div（） 整除  (int)
	div_t re = div(13,4); 
	re.quot;  //商
	re.rem;   //余数


	//swab(A,B,sizeof(A) )  将A的奇数位字符与偶数位交换，并存储与B中（B的大小为sizeof(A)）,如果A总字符为奇数，则交换n-1位
	char A[] = "hello world";
	char B[128] = { 0 };    // 
	swab(A,B,sizeof(A));    //末尾有\0 提前终止字符，所以结果为   ehll oowlr(\0d）
	swab(B, B, sizeof(B));
	printf("%s\n%d",B,sizeof(A)); 

	//at_quick_exit 退出执行  同 exit
	at_quick_exit(stop);

	//左移函数 ——rotl()大类   移动的是bit码

	//右移函数    略








	//创建路径
	//_makepath_s 创建路径文件，并保存路径于buffer中,返回错误日志errno_t
	_ACRTIMP errno_t __cdecl _makepath_s(
		_Out_writes_z_(_BufferCount) char*       _Buffer,      //保存路径的字符数组
		_In_                         size_t      _BufferCount,  //数组大小
		_In_opt_z_                   char const* _Drive,       // 盘符 c d e
		_In_opt_z_                   char const* _Dir,         //不含盘符的路径 \\Appdata\\local\\Roaming\\
		_In_opt_z_                   char const* _Filename,    // 文件名（不含格式）  hello
		_In_opt_z_                   char const* _Ext          // 文件格式  .txt
	);

	wchar_t buffeer4[_MAX_PATH] = {0};

	_wmakepath_s(buffeer4,_MAX_PATH,L"c",L"\\Appdata\\local\\Roaming\\",L"hello",L".txt");






	//拆分路径    _wsplitpath()
	wchar_t  drive[_MAX_PATH] = { 0 };
	wchar_t  dir[_MAX_PATH] = {0};
	wchar_t  filepath[_MAX_PATH] = {0};
	wchar_t  ext[_MAX_PATH] = { 0 };


	
	_wsplitpath(buffeer4,drive,dir,filepath,ext);






	//fullpath  相对路径转换为 全路径
	wchar_t buffer5[_MAX_PATH] = { 0 };

	_wfullpath(buffer5,L"..\\Debug\\cstdlib_test.exe",_MAX_PATH);

	return 0;
}