#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<wchar.h>
#include<string.h>
#include<stdbool.h>



int char_to_tchar(const char *str,wchar_t*tc)                      //int A[1278]  sizeof(A)�����鳤��
{                                                                  //����int*A  sizeof��A����ָ�뱾��ĳ���
	return  MultiByteToWideChar(CP_UTF7,0,str,strlen(str),tc, strlen(str));  //***ʹ��wcslen ������Ǵ���ʱ�洢���ַ����ȣ���ʱ�ոճ�ʼ������ȻΪ0��
}//ȡ�ɣ�ʹ�ý��ճ��ȴ���洢����   


int tchar_to_char(wchar_t*tc, char*str)
{


	return WideCharToMultiByte(CP_ACP,0,tc, wcslen(tc),str, wcslen(tc)+7,"@",NULL);
	//***�״�ͬ�����ַ����ӿ��ַ�ת��Ϊ�ַ�����䳤����Ϊ������char���������ֽڴ��棬�����ַ������з���ͳһռ4���ֽ�.
	//���Ի��ռһλ


}



int main() {

	//char  1�ֽ� 
	//wchar_t 2~4�ֽ�  ��ue4 4�ֽڣ�
	//unicode ������wchar ����
	//wcslen wchar string length


	
	

//��ͨ�ַ�תΪ���ַ�

	//MultiByteToWideChar
		//WINAPI
		//MultiByteToWideChar(
		//	_In_ UINT CodePage,  �ַ���          CP_ACP ASCII�ַ���  CP_UTF8 UTF8�ַ��� CP_SYMBOL �����ַ���
		//	_In_ DWORD dwFlags,  ���  
		//	_In_NLS_string_(cbMultiByte) LPCCH lpMultiByteStr,   ��ת�����ַ�
		//	_In_ int cbMultiByte,                         �ַ�����
		//	_Out_writes_to_opt_(cchWideChar, return) LPWSTR lpWideCharStr,    ������ַ�
		//	_In_ int cchWideChar                      ��С
		//);

//����2��
//#define MB_PRECOMPOSED            0x00000001  // DEPRECATED: use single precomposed characters when possible.
//#define MB_COMPOSITE              0x00000002  // DEPRECATED: use multiple discrete characters when possible.
//#define MB_USEGLYPHCHARS          0x00000004  // DEPRECATED: use glyph chars, not ctrl chars
//#define MB_ERR_INVALID_CHARS      0x00000008  // error for invalid chars
//	
	 char * str = "Xueweili Ѧά��"; //�ַ���CP_ACPֻ��Ӣ�ģ�Ҫ֧������ת��������CP_UTF7
	 wchar_t str_out[128] = {0};
	 char_to_tchar(str,str_out);
	 
	 //wprintf(L"ת����Ϊ%s\n",str_out); // ���� ����û�п��ַ�
	 wprintf(L"the string is %s\n", str_out);

//���ַ�ת�ַ�


	// WideCharToMultiByte

		 //int
		 //WINAPI
		 //WideCharToMultiByte(
			// _In_ UINT CodePage,      CP_ϵ��
			// _In_ DWORD dwFlags,      MB_ϵ��
			// _In_NLS_string_(cchWideChar) LPCWCH lpWideCharStr,  ������
			// _In_ int cchWideChar,                    ��С
			// _Out_writes_bytes_to_opt_(cbMultiByte, return) LPSTR lpMultiByteStr,    ������ 
			// _In_ int cbMultiByte,                               ��С
			// _In_opt_ LPCCH lpDefaultChar,               �޷�ת�����Ը��ַ����    
			// _Out_opt_ LPBOOL lpUsedDefaultChar       ��������޷�ת�����ַ��������true
		 //);

	 wchar_t tc2[128] = L"Ѧά��xueweilidwgd��ffregregregege��Ϊsdsde";
	 LPBOOL  success =NULL;
	 char str2[128] = { 0 };

	 tchar_to_char(tc2, str2);

	 printf("char result is %s", str2);



	 //����  
	 //strcpy
	//wcscpy()   ����  wcscpy(A��B)�����Խ����ַ�B�����ݿ�����խ�ַ�A��   ��
	 
	//׷��  strcat()  wcscat()  ͬ��


	 //strcoll      wcscoll()  �Ƚ� 


	 //API����
	 //
	 //btowc ���ַ�תwchar
	//	mbrtowc �ַ���תwchar



		return 0;
}