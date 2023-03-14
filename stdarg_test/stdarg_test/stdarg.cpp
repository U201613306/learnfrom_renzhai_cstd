#include<stdio.h>
#include<stdarg.h>

//arg库用于传递可变参数，如char,int,float,double
//va_arg 和va_start(ptr,int) 都是将参数指针（va_list）指向指定类型的后一位 (int之后)
//函数传递参数顺序：
//5参
//4参
//3参
//2参
//1参
//即地址从低到高
//**************常见C陷阱*****************
//可变参数在函数间传递时，由于没有指定传递和接受方的参数类型，C语言有变量提升机制，会把float型提升为double,short int 提升为int,所以实际没有float型传递，没有va_arg(ptr,float)的写法。
//va_arg还可以取出结构体

const int INT_TYPE = 100000;
const int STR_TYPE = 100001;
const int CHAR_TYPE = 100002;
const int LONG_TYPE = 100003;
const int FLOAT_TYPE = 100004;
const int DOUBLE_TYPE = 100005;
//第一个参数定义可选参数个数,用于循环取初参数内容  
//可变参数采用arg_type,arg_value...的形式传递,以处理不同的可变参数类型  
void arg_type(int cnt, ...);
//第一个参数定义可选参数个数,用于循环取初参数内容  
void arg_cnt(int cnt, ...);
//测试va_start,va_arg的使用方法,函数参数在堆栈中的地址分布情况  
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
	printf("&i = %p\n", &i);//打印参数i在堆栈中的地址  
	printf("arg_ptr = %p\n", arg_ptr);
	//打印va_start之后arg_ptr地址,  
	//应该比参数i的地址高sizeof(int)个字节  
	//这时arg_ptr指向下一个参数的地址  


	j = *((int *)arg_ptr);
	printf("%d %d\n", i, j);
	j = va_arg(arg_ptr, int);
	printf("arg_ptr = %p\n", arg_ptr);
	//打印va_arg后arg_ptr的地址  
	//应该比调用va_arg前高sizeof(int)个字节  
	//这时arg_ptr指向下一个参数的地址  
	va_end(arg_ptr);                   //最后一定不要忘记释放参数指针
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
		arg_type = va_arg(arg_ptr, int);   //取出当前参数，并把指针下移一位（指向value）
		switch (arg_type)
		{
		case INT_TYPE:
			int_value = va_arg(arg_ptr, int);   //（取出value指向下一个type）
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
		    float_value = (float)va_arg(arg_ptr, double);  //double才对
			printf("value%d = %f \n",i,float_value);
			break;
		default:
			break;
		}
	}
}