#include <stdio.h>
#include <ctype.h>

int main()
{
	//int isdigit(int c)
	//true 
	//false

	//char c = '7';
	//if (isdigit(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}

	//int isalpha(int c)
	//char c = ',';
	//if (isalpha(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}

	//int isalnum(int c)
	//char c = ',';
	//if (isalnum(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}

	//int iscntrl(int c)
	//ASCIIÂë
	//0~31ºÅ ÒÔ¼° 127ºÅ
	//char c = '\b';
	//if (iscntrl(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}

	//int isgraph(int c)
	//A * Y 
 //	char c = '\t';
	//if (isgraph(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}
	
	//int islower(int c)
	//char c = 'a';
	//if (islower(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}
	//int isupper(int c)
	//char c = 'A';
	//if (isupper(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}

	//int isprint(int c)
	//char c = '\n';
	//if (isprint(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}

	//int ispunct(int c)
	//char c = ';';
	//if (ispunct(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}

//	int isspace(int c)
	//char c = ' ';
	//if (isspace(c))
	//{
	//	printf("Y \n");
	//}
	//else
	//{
	//	printf("F \n");
	//}
	//isxdigit()

	char c = '0xf';
	if (isxdigit(c))
	{
		printf("Y \n");
	}
	else
	{
		printf("F \n");
	}
	system("pause");
	return 0;
}