#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdarg.h>
#include<malloc.h>
#include<string.h>

//project :自定义数据格式，写成自定义的文件类型，并成功读取

typedef struct 
{
	unsigned int w;
	unsigned int h;
	unsigned int d;
	unsigned int buf_size;  //整个数据包部分的大小
	char bisf : 1;//位域
	unsigned char m; //加密方式
}fjpg_h;


typedef struct  {

	unsigned char r;
	unsigned char g;
	unsigned char b;


} fjpg_buff;  //jpg的数据部分结构
int main()
{
	//自定义引擎文件的储存格式，自定义图片的储存格式
	//  filename.asset
	//  jpg  h   buf= r(char)g b
	//  png      buf = R G B A(Alpha通道)


	//自定义资源格式的要点（图片  ，  服务器发包，ZB雕刻的法线图片（normal）等）
	//1. 内存必须要连续
	//2. 头   1024*1024 r深度位数  a通道位数   加密方式等等 
	//3. 具体数据 RGB RGB RGB RGB(1像素) （A）


	



	fjpg_h jpeg_h;    //头
	fjpg_buff  buff[32 * 32];  //数据包   （缺点：其实官方分配的 jpeg_h 和buff内存上不是连续的，所以不是真正的包）




	//jpg头 的初始化
	jpeg_h.h = 32;
	jpeg_h.w = 32;
	jpeg_h.d = 0;
	jpeg_h.bisf = 0;
	jpeg_h.buf_size = sizeof(buff);
	jpeg_h.m = 2;                      //加密方式


	//给数据内容初始化
	
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


//假设头和数据部分储存是连续的

	//方法一  ：  以二进制流的方式保存 自定义格式的数据

	FILE*  fp = fopen("hello.myasset","w+"); //创建自定义格式的资产

	if (!ferror(fp))
	{
		// ****资产写入，以最好以二进制流的形式，fputs fprintf 是字符式，遇到"\0"会停止写入，必须用fwrite

		fwrite((char *)&jpeg_h,sizeof(jpeg_h),1,fp);   //将头结构转为char式切分

		fwrite((char*)&buff,sizeof(buff),1,fp);    
		fclose(fp);

	}


	//以二进制流的方式读取自定义格式文件
	//这里选择fread一口气读取

	char buf[128 * 128] = {0};

	FILE* fp2 = fopen("hello.myasset","r");
	if (!ferror(fp2))
	{
		while (1)
		{ 
			int test = 0;
			test = fread(buf, sizeof(buf), sizeof(char), fp2);   //读出失败返回负值

			if (feof(fp2)|| (test<0))
			{
				break;
			}
		}
	}
	fclose(fp2);

	//读取出数据流后，按照定义的格式切割内存
	//提取头
	char *p = buf;
	fjpg_h* out_h = (fjpg_h*)p;  //强转切割内存（（B*）A  A存储的空间用B的定义大小切割）
	p += sizeof(fjpg_h);    //指针偏移一个头大小，指向数据部分的首地址
	fjpg_buff * out_buf = (fjpg_buff*)p; //剩余空间按照定义的数据内存划分

	for (int k=0;k<(out_h->buf_size/3);k++)  //头中包含数据部分的结构信息
	{
		printf("还原   第%d 个像素    r=%d  g=%d b=%d\n", k+1,out_buf[k].r, out_buf[k].g,out_buf[k].b);

	}





	//解决缺点 ：为了实现内存上的连续，   自己分配一块内存，然后将头和数据的内容写入对应内存

	//内存块分配
	int space = jpeg_h.buf_size + sizeof(jpeg_h);
	char* u = (char*)malloc(space); //分配内存，返回指向内存的指针
	memset(u,0,space);//以字节为单位填充

	//// 内存块写入  方案一：(已知头的格式，直接切一个头，然后强转或内存拷贝过来)
	//fjpg_h * out_h2 = (fjpg_h*)u;
	////   或者  memcpy(u, (char*)&jpeg_h, sizeof(jpeg_h));  //直接把头部内存拷过来
	//*out_h2 = jpeg_h;   //  *out_h2   表示 地址对应的内容，这是用同类型的A struct 初始化B

	//char * p2 = u;//不要用原始指针偏移（以后地址变了）
	//p2 += sizeof(fjpg_h);
	//memcpy(p2,(char*)buff,out_h2->buf_size);        //memcpy内存拷贝函数   将已经初始化的数据包buff，以char为单位拷贝给 u对应的内存块
	//



	//内存块写入  方案二：(切割内存豆腐)（常见于外挂）
	//*****前提：我们不知道数据头的定义（不知道 fjpeg_h头 ）,但是我们知道具体的数据类型（如int char float等 ）
	//使用具体数据类型来偏移
	//切割头部的内存豆腐
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

	 //数据部分
	 pp += sizeof( char);

	pp += 0x2; //位域

	 fjpg_h * out_pp = (fjpg_h*)u; //u的内存已经分配完毕，现在完全匹配fjpeg_h的结构
	 memcpy(pp, (char*)buff, out_pp->buf_size);












	FILE*  fp3 = fopen("hello2.myasset", "w+"); 

	if (!ferror(fp3))
	{
	

		fwrite(u,space, 1, fp3);  //将内存块u整体写入 fp的文件

		fclose(fp3);

	}

	free(u);//释放内存


	


	return 0;
}
