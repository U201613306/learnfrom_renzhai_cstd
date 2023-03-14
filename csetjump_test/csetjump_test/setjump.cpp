#include<stdio.h>
#include<setjmp.h>
#include<process.h>

static jmp_buf j_buf;   //jmp_buf为int[16] ,_JUMP_BUFFER是setjump中的一种结构体

//GOTO会打乱代码结构， 跳跃可能内存泄漏，慎用 
//GOTO只能由于同一函数内


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


//setjump用于实现函数与函数间的跳跃


void kkk()
{

	longjmp(j_buf,0);   //jump_buf类型的数组（跳跃变量），int型 表示跳跃返回值

	printf("这里不会执行");
}

void  ssss()

{
	kkk();

}

//第一次执行时，setjump返回为假(未通过longjump跳跃)  ，第二次通过longjump跳跃，返回值为设置值；（如果返回值设为0，实际返回1）
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