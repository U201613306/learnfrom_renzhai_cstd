#define _USE_MATH_DEFINES  //math�����һ���汾(defineҪд��include��ǰ��)

#include<stdio.h>
#include<math.h>



int main()
{
	//����ת�Ƕ�
	//1����= 180/pi���Ƕȣ�
	//1�Ƕ� =pi/180�����ȣ�

	float A = 40.f;
	sin(A* (M_PI /180.f));//sin���뻡��



	//���Ǻ���
	//sin();
	//cos();
	//tan();
	//hypot();


   //�����Ǻ���

	//asin()     ���ػ���
	//acos()
	//atan()

	//˫������

	//   sinhx = ��e ^ x - e ^ -x�� / 2;


	//sinh();
	//cosh();
	//tanh();    (-oo,+oo)  (-1,1)

	//��˫��
	//acosh();         [1,+oo��  ��-��+��
	//atanh();         [-1,+1]     (-,+)

	//ָ����

	//   frexp();   x = β�� x  2^ָ��   frexp�� β��
   //               β��= frexp(x,ָ��)

	//����
	//log();
	//log10();

	//ƽ����
	//sqrt����;
	//fmod(A,B);  A����Bȡ��
	//modf(A,&B);  A=3.1415   B=��������  ���  С������  
	//���� A ����С������ output    �������� B(��ַ����)
	
	//����ֵ
	//fabs()��

	

	//ceil();����ȡ��

	//floor();����ȡ�� 

	//round();��������
	return 0;
}