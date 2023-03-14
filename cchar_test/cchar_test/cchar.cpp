#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<wchar.h>
#include<string.h>
#include<stdbool.h>



int char_to_tchar(const char *str,wchar_t*tc)                      //int A[1278]  sizeof(A)是数组长度
{                                                                  //定义int*A  sizeof（A）是指针本身的长度
	return  MultiByteToWideChar(CP_UTF7,0,str,strlen(str),tc, strlen(str));  //***使用wcslen 计算的是传入时存储的字符长度（此时刚刚初始化，显然为0）
}//取巧，使用接收长度代替存储长度   


int tchar_to_char(wchar_t*tc, char*str)
{


	return WideCharToMultiByte(CP_ACP,0,tc, wcslen(tc),str, wcslen(tc)+7,"@",NULL);
	//***易错：同样的字符串从宽字符转换为字符串会变长，因为汉字在char中以两个字节储存，而宽字符中所有符号统一占4个字节.
	//所以会多占一位


}



int main() {

	//char  1字节 
	//wchar_t 2~4字节  （ue4 4字节）
	//unicode 编码以wchar 定义
	//wcslen wchar string length


	
	

//普通字符转为宽字符

	//MultiByteToWideChar
		//WINAPI
		//MultiByteToWideChar(
		//	_In_ UINT CodePage,  字符集          CP_ACP ASCII字符集  CP_UTF8 UTF8字符集 CP_SYMBOL 符号字符集
		//	_In_ DWORD dwFlags,  标记  
		//	_In_NLS_string_(cbMultiByte) LPCCH lpMultiByteStr,   被转换的字符
		//	_In_ int cbMultiByte,                         字符长度
		//	_Out_writes_to_opt_(cchWideChar, return) LPWSTR lpWideCharStr,    输出的字符
		//	_In_ int cchWideChar                      大小
		//);

//参数2：
//#define MB_PRECOMPOSED            0x00000001  // DEPRECATED: use single precomposed characters when possible.
//#define MB_COMPOSITE              0x00000002  // DEPRECATED: use multiple discrete characters when possible.
//#define MB_USEGLYPHCHARS          0x00000004  // DEPRECATED: use glyph chars, not ctrl chars
//#define MB_ERR_INVALID_CHARS      0x00000008  // error for invalid chars
//	
	 char * str = "Xueweili 薛维力"; //字符集CP_ACP只有英文，要支持中文转换，请用CP_UTF7
	 wchar_t str_out[128] = {0};
	 char_to_tchar(str,str_out);
	 
	 //wprintf(L"转换后为%s\n",str_out); // 错误 中文没有宽字符
	 wprintf(L"the string is %s\n", str_out);

//宽字符转字符


	// WideCharToMultiByte

		 //int
		 //WINAPI
		 //WideCharToMultiByte(
			// _In_ UINT CodePage,      CP_系列
			// _In_ DWORD dwFlags,      MB_系列
			// _In_NLS_string_(cchWideChar) LPCWCH lpWideCharStr,  缓冲区
			// _In_ int cchWideChar,                    大小
			// _Out_writes_bytes_to_opt_(cbMultiByte, return) LPSTR lpMultiByteStr,    缓冲区 
			// _In_ int cbMultiByte,                               大小
			// _In_opt_ LPCCH lpDefaultChar,               无法转换则以该字符填充    
			// _Out_opt_ LPBOOL lpUsedDefaultChar       如果存在无法转换的字符，则输出true
		 //);

	 wchar_t tc2[128] = L"薛维力xueweilidwgd需ffregregregege行为sdsde";
	 LPBOOL  success =NULL;
	 char str2[128] = { 0 };

	 tchar_to_char(tc2, str2);

	 printf("char result is %s", str2);



	 //拷贝  
	 //strcpy
	//wcscpy()   类似  wcscpy(A，B)还可以将宽字符B的内容拷贝到窄字符A中   略
	 
	//追加  strcat()  wcscat()  同理


	 //strcoll      wcscoll()  比较 


	 //API讲解
	 //
	 //btowc 单字符转wchar
	//	mbrtowc 字符串转wchar



		return 0;
}