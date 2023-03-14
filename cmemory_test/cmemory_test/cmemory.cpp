#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdarg.h>
#include<malloc.h>
#include<string.h>

//project :�Զ������ݸ�ʽ��д���Զ�����ļ����ͣ����ɹ���ȡ

typedef struct 
{
	unsigned int w;
	unsigned int h;
	unsigned int d;
	unsigned int buf_size;  //�������ݰ����ֵĴ�С
	char bisf : 1;//λ��
	unsigned char m; //���ܷ�ʽ
}fjpg_h;


typedef struct  {

	unsigned char r;
	unsigned char g;
	unsigned char b;


} fjpg_buff;  //jpg�����ݲ��ֽṹ
int main()
{
	//�Զ��������ļ��Ĵ����ʽ���Զ���ͼƬ�Ĵ����ʽ
	//  filename.asset
	//  jpg  h   buf= r(char)g b
	//  png      buf = R G B A(Alphaͨ��)


	//�Զ�����Դ��ʽ��Ҫ�㣨ͼƬ  ��  ������������ZB��̵ķ���ͼƬ��normal���ȣ�
	//1. �ڴ����Ҫ����
	//2. ͷ   1024*1024 r���λ��  aͨ��λ��   ���ܷ�ʽ�ȵ� 
	//3. �������� RGB RGB RGB RGB(1����) ��A��


	



	fjpg_h jpeg_h;    //ͷ
	fjpg_buff  buff[32 * 32];  //���ݰ�   ��ȱ�㣺��ʵ�ٷ������ jpeg_h ��buff�ڴ��ϲ��������ģ����Բ��������İ���




	//jpgͷ �ĳ�ʼ��
	jpeg_h.h = 32;
	jpeg_h.w = 32;
	jpeg_h.d = 0;
	jpeg_h.bisf = 0;
	jpeg_h.buf_size = sizeof(buff);
	jpeg_h.m = 2;                      //���ܷ�ʽ


	//���������ݳ�ʼ��
	
	for (int i=0;i<sizeof(buff)/3;i++)
	{
		int index =0;
		if (i > 255)
		{
			index = i - 256*(i/256);   //0~255
		}
		else
		{
			index = i;
		}

		buff[i].r= (unsigned char)index;
		buff[i].b = (unsigned char)index;
		buff[i].g= (unsigned char)index;
	}


//����ͷ�����ݲ��ִ�����������

	//����һ  ��  �Զ��������ķ�ʽ���� �Զ����ʽ������

	FILE*  fp = fopen("hello.myasset","w+"); //�����Զ����ʽ���ʲ�

	if (!ferror(fp))
	{
		// ****�ʲ�д�룬������Զ�����������ʽ��fputs fprintf ���ַ�ʽ������"\0"��ֹͣд�룬������fwrite

		fwrite((char *)&jpeg_h,sizeof(jpeg_h),1,fp);   //��ͷ�ṹתΪcharʽ�з�

		fwrite((char*)&buff,sizeof(buff),1,fp);    
		fclose(fp);

	}


	//�Զ��������ķ�ʽ��ȡ�Զ����ʽ�ļ�
	//����ѡ��freadһ������ȡ

	char buf[128 * 128] = {0};

	FILE* fp2 = fopen("hello.myasset","r");
	if (!ferror(fp2))
	{
		while (1)
		{ 
			int test = 0;
			test = fread(buf, sizeof(buf), sizeof(char), fp2);   //����ʧ�ܷ��ظ�ֵ

			if (feof(fp2)|| (test<0))
			{
				break;
			}
		}
	}
	fclose(fp2);

	//��ȡ���������󣬰��ն���ĸ�ʽ�и��ڴ�
	//��ȡͷ
	char *p = buf;
	fjpg_h* out_h = (fjpg_h*)p;  //ǿת�и��ڴ棨��B*��A  A�洢�Ŀռ���B�Ķ����С�и
	p += sizeof(fjpg_h);    //ָ��ƫ��һ��ͷ��С��ָ�����ݲ��ֵ��׵�ַ
	fjpg_buff * out_buf = (fjpg_buff*)p; //ʣ��ռ䰴�ն���������ڴ滮��

	for (int k=0;k<(out_h->buf_size/3);k++)  //ͷ�а������ݲ��ֵĽṹ��Ϣ
	{
		printf("��ԭ   ��%d ������    r=%d  g=%d b=%d\n", k+1,out_buf[k].r, out_buf[k].g,out_buf[k].b);

	}





	//���ȱ�� ��Ϊ��ʵ���ڴ��ϵ�������   �Լ�����һ���ڴ棬Ȼ��ͷ�����ݵ�����д���Ӧ�ڴ�

	//�ڴ�����
	int space = jpeg_h.buf_size + sizeof(jpeg_h);
	char* u = (char*)malloc(space); //�����ڴ棬����ָ���ڴ��ָ��
	memset(u,0,space);//���ֽ�Ϊ��λ���

	//// �ڴ��д��  ����һ��(��֪ͷ�ĸ�ʽ��ֱ����һ��ͷ��Ȼ��ǿת���ڴ濽������)
	//fjpg_h * out_h2 = (fjpg_h*)u;
	////   ����  memcpy(u, (char*)&jpeg_h, sizeof(jpeg_h));  //ֱ�Ӱ�ͷ���ڴ濽����
	//*out_h2 = jpeg_h;   //  *out_h2   ��ʾ ��ַ��Ӧ�����ݣ�������ͬ���͵�A struct ��ʼ��B

	//char * p2 = u;//��Ҫ��ԭʼָ��ƫ�ƣ��Ժ��ַ���ˣ�
	//p2 += sizeof(fjpg_h);
	//memcpy(p2,(char*)buff,out_h2->buf_size);        //memcpy�ڴ濽������   ���Ѿ���ʼ�������ݰ�buff����charΪ��λ������ u��Ӧ���ڴ��
	//



	//�ڴ��д��  ��������(�и��ڴ涹��)����������ң�
	//*****ǰ�᣺���ǲ�֪������ͷ�Ķ��壨��֪�� fjpeg_hͷ ��,��������֪��������������ͣ���int char float�� ��
	//ʹ�þ�������������ƫ��
	//�и�ͷ�����ڴ涹��
	char * pp = u;

	 *( int *)pp = jpeg_h.w;   

	 pp += sizeof( int);

	 *( int *)pp = jpeg_h.h;

	 pp += sizeof(int);

	 *( int *)pp = jpeg_h.d;

	 pp += sizeof(int);

	 *(int *)pp =( int) jpeg_h.buf_size;
	
	 pp += sizeof( int );
	 *(char *)pp = jpeg_h.bisf;
	 pp += sizeof(char);
	 *( char *)pp = jpeg_h.m;

	 //���ݲ���
	 pp += sizeof( char);

	pp += 0x2; //λ��

	 fjpg_h * out_pp = (fjpg_h*)u; //u���ڴ��Ѿ�������ϣ�������ȫƥ��fjpeg_h�Ľṹ
	 memcpy(pp, (char*)buff, out_pp->buf_size);












	FILE*  fp3 = fopen("hello2.myasset", "w+"); 

	if (!ferror(fp3))
	{
	

		fwrite(u,space, 1, fp3);  //���ڴ��u����д�� fp���ļ�

		fclose(fp3);

	}

	free(u);//�ͷ��ڴ�


	


	return 0;
}
