#define _USE_MATH_DEFINES  //math库的另一个版本(define要写在include的前面)

#include<stdio.h>
#include<math.h>



int main()
{
	//弧度转角度
	//1弧度= 180/pi（角度）
	//1角度 =pi/180（弧度）

	float A = 40.f;
	sin(A* (M_PI /180.f));//sin输入弧度



	//三角函数
	//sin();
	//cos();
	//tan();
	//hypot();


   //反三角函数

	//asin()     返回弧度
	//acos()
	//atan()

	//双曲函数

	//   sinhx = （e ^ x - e ^ -x） / 2;


	//sinh();
	//cosh();
	//tanh();    (-oo,+oo)  (-1,1)

	//反双曲
	//acosh();         [1,+oo）  （-，+）
	//atanh();         [-1,+1]     (-,+)

	//指数幂

	//   frexp();   x = 尾数 x  2^指数   frexp求 尾数
   //               尾数= frexp(x,指数)

	//对数
	//log();
	//log10();

	//平方根
	//sqrt（）;
	//fmod(A,B);  A除以B取余
	//modf(A,&B);  A=3.1415   B=整数部分  结果  小数部分  
	//输入 A 返回小数部分 output    整数部分 B(地址返回)
	
	//绝对值
	//fabs()；

	

	//ceil();向上取整

	//floor();向下取整 

	//round();四舍五入
	return 0;
}