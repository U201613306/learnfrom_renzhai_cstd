#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//封装逐字节读写函数
void read_print_file(const char * filename)
{
	FILE* fp2 = NULL;
	fp2 = fopen(filename, "rb");
	if (ferror(fp2))
	{
		printf("文件没有成功打开");
		clearerr(fp2);

	}
	else
	{
		while (1)
		{
			char c = fgetc(fp2);  //逐字节读写函数,一般不用，效率太低，用fgets()  **遇到换行符会在读取后结束，下一次从下一行开始 （此时实际读取为n-2  \n \0）
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
	
	//文件创建与写入
	FILE* fp = NULL;
	FILE* fp2 = NULL;

	fp =fopen("file.txt","w");//没有的话，会在当前路径下创建
	fp2 = fopen("file.txt","r");//不同操作需要定义不同的文件流
	    
		/*r  以只读方式打开文件，该文件必须存在。
		r+  以读 / 写方式打开文件，该文件必须存在。
		a	以附加的方式打开只写文件。若文件不存在，则会创建该文件；如果文件存在，则写入的数据会被加到文件尾后，即文件原先的内容会被保留
		w	打开只写文件，若文件存在则文件长度清为零，即该文件内容会消失；若文件不存在则创建该文件。
		w+  打开r/w文件，每次打开之前会先清除内容，不存在可以先创建
			
			上述的形态字符串都可以再加一个 b 字符，如 rb、w + b 或 ab + 等组合，加入 b 字符用来告诉函数库以二进制模式打开文件。
			如果不加 b，表示默认加了 t，即 rt、wt，其中 t 表示以文本模式打开文件。
			
			二进制模式和文本模式的区别：固定符号不同（windows下，文本模式换行符为\r\n，而编程时为\n(fputs会自动补充字符)，linux下，文本和二进制模式也相同），二进制模式则完全相同
*/



	if (ferror(fp)) //失败返回1
	{

		printf("文件创建出错");
		clearerr(fp);  //读写错误后必须执行clearerr ，清除文件流

	}
	else
	{
		fprintf(fp, "%s", "I see you####");
	}
	

	

	fclose(fp); //***fclose 必须要加，fclose类似于保存文件。写入的操作只有在执行fclose（）才会保存生效

	//文件逐字节读取
	if (ferror(fp2))
	{
		printf("文件没有成功打开");
		clearerr(fp2);
		
	}
	else
	{
		while (1)
		{
			char c = fgetc(fp2);  //逐字节读写函数,一般不用，效率太低，用fgets()  **遇到换行符会在读取后结束，下一次从下一行开始 （此时实际读取为n-2  \n \0）
			if (feof(fp2))
			{
				break;
			}
			printf("%c", c);
		}
	}
	
	
	fclose(fp2);


	








	//文件读写非常耗性能
	//setvbuf()可以定义缓冲规则
	//(缓冲是指先保存，等到一定条件后再写入或输出），可以大大提升效率

	char buff[10240] = { 0 };  

	fprintf(stdout, "%s", "无缓冲区输出\n");//stdout是C的标准输出流（输出至屏幕），也可以采用自定义的文件流FILE*
	setvbuf(stdout,buff,_IOFBF,10240);  //缓冲区定义  ***慎重，设置对所有的printf类函数有效
	 //#define _IOFBF 0x0000    全缓冲
     //#define _IOLBF 0x0040    行缓冲
     //#define _IONBF 0x0004    无缓冲
	fprintf(stdout, "%s", "缓冲区输出1\n");
	fprintf(stdout, "%s", "缓冲区输出2\n");
	fprintf(stdout, "%s", "缓冲区输出3\n");
	fprintf(stdout, "%s", "缓冲区输出4\n");
	fprintf(stdout, "%s", "缓冲区输出5\n");
	//可以看到，数据保存至缓冲区buff，但是没有写入屏幕


	fflush(stdout); //清空缓冲区，开始写入(不加这个，只有当进程结束时，才会尝试out)





	//fputs 将字符串推入流

	FILE* fp3 = NULL;
	char buffer3[448] = "he was lay me 233";
	fp3 = fopen("file_puts.txt","w+");

	if (ferror(fp3)) {

		printf("创建打开文件失败");
		clearerr(fp3);
	}
	else
	{
		fputs(buffer3,fp3);
		fputs("ffh",fp3);
	}


	fclose(fp3);

	read_print_file("file_puts.txt"); 
	//此时stdio即标准输出流为全缓冲模式（setvbuf() //缓冲区定义），在printf_file函数中调用的printf会先缓存至buff，再输出，buff大小不够会爆缓存，出乱码
	


	//fgetpos fsetpos  得到和设置文件指针的位置（配合fputs  ，fseek可用于实现利用数组生成格式化的txt文本）
	
	FILE* fp4 = NULL;
	fpos_t pos1=0, pos2=0, pos3=0;
	fp4=fopen("file_getpos.txt", "w+");
	fgetpos(fp4,&pos1);
	pos1++;
	fsetpos(fp4,&pos1);
	fputs("hello",fp4);
	fgetpos(fp4, &pos2);
	pos2++;           //通过指针++ 在文件单词间加入空格
	fsetpos(fp4, &pos2);
	fputs("world",fp4);
	fputs("\n",fp4);
	fgetpos(fp4,&pos3);
	fseek(fp4,pos3+3,SEEK_SET); 
	fputs("this is", fp4);
	
	





	//fseek()  设置游标偏移
	
		//_Inout_ FILE* _Stream,  
		//_In_    long  _Offset,     偏移量
		//_In_    int   _Origin      偏移计算位置 
		//SEEK_CUR   当前
		//SEEK_END   结束
		//SEEK_SET   开头

	//略


	//freopen 重定向文件流   将写入文件流的内容保存至新建的文件流中
	
	//一般用于服务器运行日志的本地保存


	//_ACRTIMP FILE* __cdecl freopen(  返回重定向后的文件指针
	//	_In_z_  char const* _FileName,
	//	_In_z_  char const* _Mode,  打开方式
	//	_Inout_ FILE*       _Stream
	//);

	freopen("file_reopen.txt", "w+",stdout);  //将标准输出流定向至新的文件流file_reopen中

	printf("%s","文件不会在命令行输出");

	//*********reopen关联恢复   
	freopen("CON","w",stdout); 
	
	//CON  windows命令行文件名
	//  /dev/tty    类unix命令行

	printf("%s","\n标准输出流已恢复");




	//重定向输入流   
	//演示为重定向标准输入流（键盘输入）


	//char buffer4[128] = { 0 };

	////fscanf(stdin,"%s",buffer3);
	////scanf("%s",buffer3);       通过键盘输入到buffer[]   完全等效


	//scanf("%s",buffer4);  //键盘读取
	//freopen("file_scanf.txt","r",stdin);  //键盘读取改为本地文件读取

	//scanf("%s",buffer4);    //*****重定向后，从文件输入也是一行一行输入（类似于gets）,buffer4会被不断的覆盖

	//scanf("%s", buffer4);



	//reopen 标准输入流恢复     C中没有，C++有专门的方法








	//重定向错误输出流
	//fprintf(stderr)完全类似重定向输出流fprinf(stdout)





	//fwrite fread 结合fseek实现  文件的读写及内容备份


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
		fwrite(bufer1,strlen(bufer1)+1,1,fp5); //将字符写入文件 
		// 易错点：sizeof(bufer1)是数组定义大小(128)，strlen是实际使用大小（+1因为fwrite 类似于fgets，指定N位实际写入N-1位，最后一位\0）
		fseek(fp5,0,SEEK_SET);//光标置于首位
		fread(buff_copy,sizeof(buff_copy),1,fp5);
	}

	fclose(fp5);

	//ftell获取当前游标的位置（配合fseek 常用于获取文件长度）



	FILE*fp6 =fopen("file_re_wr.txt","r");

	fseek(fp6, 0, SEEK_END);

	long length =ftell(fp6);   //长度包括\0



	fclose(fp6);





	//frewind(fp)  文件游标移动至开头类似 fseek( ...,SEEK_SET)
	//略





	//puts 与fputs  类似于 printf 和fprintf ，  标准流和任意流

	//putc putwc  putchar(直接输出至stdout)   
	//perror 错误日志打印至stderr，结合fprintf(stderr)重定向，可以打印错误日志到本地
    //简单，略


	//setbuf  设置缓冲区 ,指定全缓冲  完全等同于setvbuf（...，_IOFBUF）(多了一个定义缓冲模式)

	



	//tmpfile()   创建临时文件，此文件不存在于操作系统中，只在内存中  （可以写一些密钥文件，运行完自动删除）

	FILE* fp8 = NULL;
	char buffer4[128] = { 0 };
	fp8 = tmpfile();

	fputs("this is a tmp file",fp8);
	rewind(fp8);   //指针归位
	fgets(buffer4,128,fp8);
	long dis =ftell(fp8);

	fclose(fp8); //临时文件会在关闭时删除


	





	//tmpnam（）  创建临时的文件名 （名称全局唯一） 
	//默认规则：大家都会把基于该文件名的文件操作置于C\\xue\\Appdata\\local\\Roaming\\Tmp中  方便用户删除








	//gets系列


	//gets_s();  读取键盘输入存入buffer
	char buffer5[128] = { 0 };    
	gets_s(buffer5,sizeof(buffer5));   //实际最大读取位数为127，最后一位必为\0


	// 写  fputs fputc  fwrite fprintf
	// 读  fgets fgetc  fread  fscanf

	//getchar  从键盘读取 单个字节  类似getwchar
	//getc  逐字节读取

	
	return 0;
}