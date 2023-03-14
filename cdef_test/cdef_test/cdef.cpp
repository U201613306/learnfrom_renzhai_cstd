#include<stdio.h>
#include<stddef.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
//ptrdiff_t是C/C++标准库中定义的一个与机器相关的数据类型。ptrdiff_t类型变量通常用来保存两个指针减法操作的结果
//标准库类型(library type)ptrdiff_t 与 size_t 类型一样,ptrdiff_t 也是一种与机器相关的类型,在 cstddef 头文件中定义。
//size_t 是unsigned 类型,而 ptrdiff_t 则是 signed 整型
//size_t 类型用于指明数组长度,它必须是一个正数;ptrdiff_t 类型则应保证足以存放同一数组中两个指针之间的差距,它有可能是负数

int main()
{

	//ptrdiff_t  //计算指针长度（尾减首）

	char str[] = "hello";
	char* start_ptr = str;
	char* end_ptr = strlen(str) + start_ptr;  
	ptrdiff_t diff = end_ptr - start_ptr;       //为什么要用关键字？而不是直接相减保存为int?   因为不同系统中基本的长度单位不同，保存为关键字ptrdiff_t可以支持跨平台转换
	printf("dif = %d",diff);
	//size_t同理，也是为跨平台设计的，为了防止内存偏移操作出现问题，其实类似于int
	size_t in = sizeof(int);   //unsigned int类型
	for (size_t i = 0; i < 5; i++)
	{

	}

	//unicode 编码(UTF-8 UTF-16)一般是以宽字符wchar_t储存
	//因为char 只有8位，而wchar_t有16-32位

	  /*    宏	  未定义_UNICODE(ANSI字符)	 定义了_UNICODE(Unicode字符)
		_tcschr	 strchr	                      wcschr
		_tcscmp	 strcmp	                      wcscmp
		_tcslen	 strlen	                      wcslen*/





	//宽字符定义及打印
#define TEXT(S)  L#S          //宏定义 TEXT(S)  表示 L“S”(宽字符串类型) #为连接符  编译前会按字面意思替换宏
	wchar_t name[] = TEXT(人宅);   //等于 L"人宅"
	setlocale(LC_ALL, "zh_CN.UTF-8");  // 必须进行本地化设置，否则TEXT打不出中文字符
	wprintf(TEXT(\n %s ), name);

        //等价于
	/*wchar_t name[] = L"人宅";
	setlocale(LC_ALL, "zh_CN.UTF-8");  // 必须进行本地化设置，否则TEXT打不出中文字符
	wprintf(L"%s", name);*/




	//指针保护（防止空指针的崩溃）
	//if (ptr)
	//{

	//}
	
	
	//堆和栈

	//char* ptr =NULL;  //指针地址保存在栈中
	//char*p = malloc();                //指针分配的空间保存在堆中
	//free(p);                          //释放指针只释放了堆中分配的空间（必须及时释放，不然会爆内存），并没有清除掉栈中保存的指针地址








	//内存偏移，计算当前结构体的内存偏移量


	typedef struct 
	{
		int index[100];
		char name[128];
		float h;
	}fhello;


	fhello  hello;

	



	//memset作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行为清零操作的一种最快方法
	//不可用memset给成员赋值，如令整型数组的index成员值都为1，因为他是以字节为单位赋值的，int型数组四字节一分，赋值完毕是0x01010101
	//字符型数组一字节一分，可以用memset直接覆盖
	//所赋的值应为0~255（8位宽），即-1与511相同

	//memset(hello.index, 1, 400);
	for(int i = 0; i < 400;i++)
	{
			hello.index[i] = 1;

	}
	memset(hello.name,'A',128);
	hello.h = 3.14f;


	size_t index_offset = offsetof(fhello, index);  //用size_t表示偏移大小而不是直接unsign int ；为了多平台移植
	size_t name_offset = offsetof(fhello, name);  //offsetof(A,B)计算地址A,与地址B的偏差
	size_t h_offset = offsetof(fhello, h);
	//以上可以看出  ***结构体地址就是结构体中第一个成员的地址  ***int 4字节  char1字节  




	unsigned char* ptr_he = (unsigned char*)&hello;  //******将结构体指针（hello.index,hello.name）转换为 字符指针(hello+strlen(index))
	int * show = (int*)(ptr_he);   
	//*****C语言中A强制转换为B,实际就是用A的内存组成B
	//ptr_he 字符指针 一个字节一分  转为整型指针 四字节一分  （恰好还原index【100】整型数组）
	ptr_he += name_offset;  //加上整型数组偏移，则指向字符数组name的第一位

	char* show2 = (char*)(ptr_he);//ptr也为char指针，其实可以不转

	ptr_he += (h_offset - name_offset);

	float *show3 = (float*)(ptr_he);//float也是四字节一分

	
	
	return 0;
}