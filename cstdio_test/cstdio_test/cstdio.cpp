#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//��װ���ֽڶ�д����
void read_print_file(const char * filename)
{
	FILE* fp2 = NULL;
	fp2 = fopen(filename, "rb");
	if (ferror(fp2))
	{
		printf("�ļ�û�гɹ���");
		clearerr(fp2);

	}
	else
	{
		while (1)
		{
			char c = fgetc(fp2);  //���ֽڶ�д����,һ�㲻�ã�Ч��̫�ͣ���fgets()  **�������з����ڶ�ȡ���������һ�δ���һ�п�ʼ ����ʱʵ�ʶ�ȡΪn-2  \n \0��
			if (feof(fp2))
			{
				break;
			}
			printf("%c", c);
		}
	}


	fclose(fp2);

}


int main()
{
	
	//�ļ�������д��
	FILE* fp = NULL;
	FILE* fp2 = NULL;

	fp =fopen("file.txt","w");//û�еĻ������ڵ�ǰ·���´���
	fp2 = fopen("file.txt","r");//��ͬ������Ҫ���岻ͬ���ļ���
	    
		/*r  ��ֻ����ʽ���ļ������ļ�������ڡ�
		r+  �Զ� / д��ʽ���ļ������ļ�������ڡ�
		a	�Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���ᴴ�����ļ�������ļ����ڣ���д������ݻᱻ�ӵ��ļ�β�󣬼��ļ�ԭ�ȵ����ݻᱻ����
		w	��ֻд�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������򴴽����ļ���
		w+  ��r/w�ļ���ÿ�δ�֮ǰ����������ݣ������ڿ����ȴ���
			
			��������̬�ַ����������ټ�һ�� b �ַ����� rb��w + b �� ab + ����ϣ����� b �ַ��������ߺ������Զ�����ģʽ���ļ���
			������� b����ʾĬ�ϼ��� t���� rt��wt������ t ��ʾ���ı�ģʽ���ļ���
			
			������ģʽ���ı�ģʽ�����𣺹̶����Ų�ͬ��windows�£��ı�ģʽ���з�Ϊ\r\n�������ʱΪ\n(fputs���Զ������ַ�)��linux�£��ı��Ͷ�����ģʽҲ��ͬ����������ģʽ����ȫ��ͬ
*/



	if (ferror(fp)) //ʧ�ܷ���1
	{

		printf("�ļ���������");
		clearerr(fp);  //��д��������ִ��clearerr ������ļ���

	}
	else
	{
		fprintf(fp, "%s", "I see you####");
	}
	

	

	fclose(fp); //***fclose ����Ҫ�ӣ�fclose�����ڱ����ļ���д��Ĳ���ֻ����ִ��fclose�����Żᱣ����Ч

	//�ļ����ֽڶ�ȡ
	if (ferror(fp2))
	{
		printf("�ļ�û�гɹ���");
		clearerr(fp2);
		
	}
	else
	{
		while (1)
		{
			char c = fgetc(fp2);  //���ֽڶ�д����,һ�㲻�ã�Ч��̫�ͣ���fgets()  **�������з����ڶ�ȡ���������һ�δ���һ�п�ʼ ����ʱʵ�ʶ�ȡΪn-2  \n \0��
			if (feof(fp2))
			{
				break;
			}
			printf("%c", c);
		}
	}
	
	
	fclose(fp2);


	








	//�ļ���д�ǳ�������
	//setvbuf()���Զ��建�����
	//(������ָ�ȱ��棬�ȵ�һ����������д�������������Դ������Ч��

	char buff[10240] = { 0 };  

	fprintf(stdout, "%s", "�޻��������\n");//stdout��C�ı�׼��������������Ļ����Ҳ���Բ����Զ�����ļ���FILE*
	setvbuf(stdout,buff,_IOFBF,10240);  //����������  ***���أ����ö����е�printf�ຯ����Ч
	 //#define _IOFBF 0x0000    ȫ����
     //#define _IOLBF 0x0040    �л���
     //#define _IONBF 0x0004    �޻���
	fprintf(stdout, "%s", "���������1\n");
	fprintf(stdout, "%s", "���������2\n");
	fprintf(stdout, "%s", "���������3\n");
	fprintf(stdout, "%s", "���������4\n");
	fprintf(stdout, "%s", "���������5\n");
	//���Կ��������ݱ�����������buff������û��д����Ļ


	fflush(stdout); //��ջ���������ʼд��(���������ֻ�е����̽���ʱ���Ż᳢��out)





	//fputs ���ַ���������

	FILE* fp3 = NULL;
	char buffer3[448] = "he was lay me 233";
	fp3 = fopen("file_puts.txt","w+");

	if (ferror(fp3)) {

		printf("�������ļ�ʧ��");
		clearerr(fp3);
	}
	else
	{
		fputs(buffer3,fp3);
		fputs("ffh",fp3);
	}


	fclose(fp3);

	read_print_file("file_puts.txt"); 
	//��ʱstdio����׼�����Ϊȫ����ģʽ��setvbuf() //���������壩����printf_file�����е��õ�printf���Ȼ�����buff���������buff��С�����ᱬ���棬������
	


	//fgetpos fsetpos  �õ��������ļ�ָ���λ�ã����fputs  ��fseek������ʵ�������������ɸ�ʽ����txt�ı���
	
	FILE* fp4 = NULL;
	fpos_t pos1=0, pos2=0, pos3=0;
	fp4=fopen("file_getpos.txt", "w+");
	fgetpos(fp4,&pos1);
	pos1++;
	fsetpos(fp4,&pos1);
	fputs("hello",fp4);
	fgetpos(fp4, &pos2);
	pos2++;           //ͨ��ָ��++ ���ļ����ʼ����ո�
	fsetpos(fp4, &pos2);
	fputs("world",fp4);
	fputs("\n",fp4);
	fgetpos(fp4,&pos3);
	fseek(fp4,pos3+3,SEEK_SET); 
	fputs("this is", fp4);
	
	





	//fseek()  �����α�ƫ��
	
		//_Inout_ FILE* _Stream,  
		//_In_    long  _Offset,     ƫ����
		//_In_    int   _Origin      ƫ�Ƽ���λ�� 
		//SEEK_CUR   ��ǰ
		//SEEK_END   ����
		//SEEK_SET   ��ͷ

	//��


	//freopen �ض����ļ���   ��д���ļ��������ݱ������½����ļ�����
	
	//һ�����ڷ�����������־�ı��ر���


	//_ACRTIMP FILE* __cdecl freopen(  �����ض������ļ�ָ��
	//	_In_z_  char const* _FileName,
	//	_In_z_  char const* _Mode,  �򿪷�ʽ
	//	_Inout_ FILE*       _Stream
	//);

	freopen("file_reopen.txt", "w+",stdout);  //����׼������������µ��ļ���file_reopen��

	printf("%s","�ļ����������������");

	//*********reopen�����ָ�   
	freopen("CON","w",stdout); 
	
	//CON  windows�������ļ���
	//  /dev/tty    ��unix������

	printf("%s","\n��׼������ѻָ�");




	//�ض���������   
	//��ʾΪ�ض����׼���������������룩


	//char buffer4[128] = { 0 };

	////fscanf(stdin,"%s",buffer3);
	////scanf("%s",buffer3);       ͨ���������뵽buffer[]   ��ȫ��Ч


	//scanf("%s",buffer4);  //���̶�ȡ
	//freopen("file_scanf.txt","r",stdin);  //���̶�ȡ��Ϊ�����ļ���ȡ

	//scanf("%s",buffer4);    //*****�ض���󣬴��ļ�����Ҳ��һ��һ�����루������gets��,buffer4�ᱻ���ϵĸ���

	//scanf("%s", buffer4);



	//reopen ��׼�������ָ�     C��û�У�C++��ר�ŵķ���








	//�ض�����������
	//fprintf(stderr)��ȫ�����ض��������fprinf(stdout)





	//fwrite fread ���fseekʵ��  �ļ��Ķ�д�����ݱ���


	char bufer1[128] = "Cpp is so easy";
	char buff_copy[128] = { 0 };

	FILE* fp5 = NULL;
	fp5 = fopen("file_re_wr.txt","w+");
	if (ferror(fp5))
	{

		clearerr(fp5);
	}
	else
	{
		fwrite(bufer1,strlen(bufer1)+1,1,fp5); //���ַ�д���ļ� 
		// �״�㣺sizeof(bufer1)�����鶨���С(128)��strlen��ʵ��ʹ�ô�С��+1��Ϊfwrite ������fgets��ָ��Nλʵ��д��N-1λ�����һλ\0��
		fseek(fp5,0,SEEK_SET);//���������λ
		fread(buff_copy,sizeof(buff_copy),1,fp5);
	}

	fclose(fp5);

	//ftell��ȡ��ǰ�α��λ�ã����fseek �����ڻ�ȡ�ļ����ȣ�



	FILE*fp6 =fopen("file_re_wr.txt","r");

	fseek(fp6, 0, SEEK_END);

	long length =ftell(fp6);   //���Ȱ���\0



	fclose(fp6);





	//frewind(fp)  �ļ��α��ƶ�����ͷ���� fseek( ...,SEEK_SET)
	//��





	//puts ��fputs  ������ printf ��fprintf ��  ��׼����������

	//putc putwc  putchar(ֱ�������stdout)   
	//perror ������־��ӡ��stderr�����fprintf(stderr)�ض��򣬿��Դ�ӡ������־������
    //�򵥣���


	//setbuf  ���û����� ,ָ��ȫ����  ��ȫ��ͬ��setvbuf��...��_IOFBUF��(����һ�����建��ģʽ)

	



	//tmpfile()   ������ʱ�ļ������ļ��������ڲ���ϵͳ�У�ֻ���ڴ���  ������дһЩ��Կ�ļ����������Զ�ɾ����

	FILE* fp8 = NULL;
	char buffer4[128] = { 0 };
	fp8 = tmpfile();

	fputs("this is a tmp file",fp8);
	rewind(fp8);   //ָ���λ
	fgets(buffer4,128,fp8);
	long dis =ftell(fp8);

	fclose(fp8); //��ʱ�ļ����ڹر�ʱɾ��


	





	//tmpnam����  ������ʱ���ļ��� ������ȫ��Ψһ�� 
	//Ĭ�Ϲ��򣺴�Ҷ���ѻ��ڸ��ļ������ļ���������C\\xue\\Appdata\\local\\Roaming\\Tmp��  �����û�ɾ��








	//getsϵ��


	//gets_s();  ��ȡ�����������buffer
	char buffer5[128] = { 0 };    
	gets_s(buffer5,sizeof(buffer5));   //ʵ������ȡλ��Ϊ127�����һλ��Ϊ\0


	// д  fputs fputc  fwrite fprintf
	// ��  fgets fgetc  fread  fscanf

	//getchar  �Ӽ��̶�ȡ �����ֽ�  ����getwchar
	//getc  ���ֽڶ�ȡ

	
	return 0;
}