#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<process.h>
#include<windows.h>
void  fun(void);
int main()
{
	//CLOCKS_PER_SEC
	//clock_t s = 1000;  //clock_t��C�洢ϵͳʱ������ͣ���λ���룬CLOCKS_PER_SEC 1000ms��һ��

	//time_t  ʱ�������һ��Ϊlong int ��
	
	//��������ʱ��  1970�꿪ʼ   
		//32λint ��ֻ������2038��
		//һ����long int 64λ
		//����ԭ��ʱ��  (UT2)  GMT����������ʱ�䣩
		//����Э��ʱ  UTC������ԭ��ʱȡƽ���������ʱ��� )

		//GPSʱ��  UTC������Э��ʱ��  LT ���ط�ʱ��   
	//���ص�ʱ�̶��в�ͬ�����Ǵ�ҵ�UTC(1970��������)����ͬ��
		//GMT  =  UTC  (time_t)
	
		
	//	timeval;(΢��)
	//  tm   ʱ��ṹ��
	struct tm t;
	t.tm_hour = 4;
	t.tm_isdst = 0;
	t.tm_mday = 1;
	t.tm_min = 59;
	t.tm_mon = 11;
	t.tm_sec = 24;
	t.tm_wday = 3;
	t.tm_yday = 24;
	t.tm_year = 12;//��1970��ʼ�ĸ�������ʱ��





	//�� ʱ��ṹ��tm ����ת�� �ܴ�ӡ���ַ���ʽ
	//char *time = asctime(&t);
	//printf("%s", time);


	//ʹ��asctime_s�Ǹ��Ӱ�ȫ������

	char buffer[256] = {0};

	//һ��������÷�   errno_t time_safe = asctime_s(buffer,256,&t);
	//***********asctime_s����ֵ�Ǵ���������ͣ�errno_t��,����0��ʾ�ɹ�����
	if ( !asctime_s(buffer, 256, &t) )
	{
		printf("%s",buffer);
	}
	



	//**********time(NULL)���ظ�������ʱ��1970��������,()��Ҳ�����
	time_t time_second = time(NULL);
	time_t time_hour = time_second / 3600;


	//localtime����������ʱ��ת��Ϊtm�ṹ��

	time_t newt=NULL;
	time(&newt);
	//Out_opt_ time_t* const _Time   ******C�İ�ȫ���******
	//const int*p  (�㶨����int)ָ��ĵ�ַ�ɸģ���ָ��ָ���ֵ���ܸ�
	//int *const p(�㶨����*)ָ���ַ���ɸģ���ָ��ָ���ֵ�ɸ�
	//�ص㣺���У�int��*const �Ĳ�����˼��ָ���ַ���䣬���Բ��ܳ�ʼ��һ��ָ��ȥ�ӣ�Ӧ�ó�ʼ��һ��������&i��ȥ��
	 struct tm *time_local =localtime(&newt);
	 char buffer_new[256] = { 0 };
	 if (!asctime_s(buffer_new, 256, time_local))
	 {
		 printf("buffer_new=%s", buffer_new);
	 }



	 //clock()   ���ڼ�¼����������ʹ�õ�ʱ�� (���������е�����)

	 {
		 //��ʼ��
		clock_t time_run= clock();



		 //��Ⱦ
		 for (size_t j = 0; j < 10000000; j++)
		 {
			 fun();  //��⺯����ʱ
		 }

		 clock_t time_end = clock();


		 double time_total = (double)(time_end - time_run) / CLOCKS_PER_SEC; //clock�������ص�λ�Ǻ���
		 printf("%f",time_total);

		 //���� �ͷ�





	 }





	 //ctime   ����������ʱ��ת��Ϊ  �ַ���������ʱ

	 time_t ti =time(NULL);

	 char *  result = ctime(&ti);








	 //difftime()  ʱ����


	 time_t t_start;
	 time(&t_start);
	 Sleep(50);
	 time_t t_end;
	 time(&t_end);

	 double dif = difftime(t_end,t_start);
	 printf("time diff is %lf",dif);





	 //gmtime()   ��localtime һ�� ��������������ת��Ϊ TMʱ��ṹ�壨������ localtime�Ǳ���ʱ��,�籱��ʱ��  gmtime�Ǳ�׼ʱ�䣩
	 time_t tm;
	 time(&tm);
	 
	 struct tm * gm_time= gmtime(&tm);

	 char* gm_output=asctime(gm_time);
	 printf("\n��������ʱ����%s\n",gm_output);
	 printf("����ʱ����%02d:%02d\n",(gm_time->tm_hour+8)%24,(gm_time->tm_min));


	 //mktime ��tmʱ��ṹ��ת��Ϊ  ������������

	 //��

	 //strftime    *****   ��tmʱ��תΪ�ض�ʱ���ʽ���

	 char buffer2[256] = {};
	 strftime(buffer2,256,"%y-%m-%d %H:%M:%S",gm_time);
	 printf("strftime�Զ���ʱ���ʽ���Ϊ��%s\n",buffer2);


	 //  ����ʱ���ʽ Format��ѡ��

	 //_ACRTIMP size_t __cdecl strftime(
		// _Out_writes_z_(_SizeInBytes)  char*            _Buffer,
		// _In_                          size_t           _SizeInBytes,
		// _In_z_ _Printf_format_string_ char const*      _Format,
		// _In_                          struct tm const* _Tm
	 //);

	 //%a  ��д���ڼ�
	 //%A  ���������ڼ�
	 //%b  ��д�·�
	 //%B  �����·�
	 //%c  ���ں�ʱ��ı�����
	 //%d  ����
	 //%D   �� �� �� ���ڱ�ʾ��
	 //%T   ʱ����
	 //%H   24Сʱʱ��
	 //%I   12Сʱʱ��
	 //%j    һ���еĵڼ���
	 //%m    �·�
	 //%M    ����
	 //%p    ���硢����
	 //%S    ��
	 //%U    һ���еĵڼ���
	 //%w    ���ڼ�(���ֱ�ʾ��
	 //%W    һ���еĵڼ���
	 //%x     ���ڱ�ʾ��
	 //%X     ʱ���ʾ��
	 //%y     ��ݣ������λ��
	 //%Y     ��ݣ�������
	 //%Z     ʱ�����ƣ���


	 //timespec_get  �߾��ȵĻ��UTC������Э��ʱ���ĸ���������������ȷ�����룩
	 struct timespec tm2 = {0};  //timespec �� xx��xx���� 
	 timespec_get(&tm2,TIME_UTC);
	 struct tm* timspec_ = gmtime(&tm2.tv_sec);
	 strftime(buffer2, 128, "%D  %T", timspec_);
	 enum lan {

		 STD,
	     DST,
		 

	 };


	 //_get_tzname ��ȡ����ʱ������
	 size_t tzname_get=NULL;
	 char buffer3[128] = {0};
	 _get_tzname(&tzname_get,buffer3,128,STD);  //���һ������Ϊ����,���㶨��ö�٣���ǿ����Ŀɶ��ԣ�Ҳ����ֱ�Ӹ�0,1(ѡ���׼ʱ������ʱ)


	system("pause");
	return 0;
}



void  fun(void)
{

	

}