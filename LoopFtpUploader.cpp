// LoopFtpUploador.cpp :
//author:huangqihua h00284904
//desc:无限循环，实现遍历当前路径下所有的cti2_15092886139_yyyymmddhhmmss.wav文件，调用当前目录下的ftp_up.bat脚本，上传该文件

//#include <stdafx.h>

#include <iostream>
#include <stdlib.h>

#include <windows.h>

#include <tchar.h>


#include <fstream>

using namespace std;

#define UPLOAD_INTERVAL_TIME 5000	 /*两个上传文件的间隔时长,5秒钟*/
#define RUN_INTERVAL_TIME 300000     /*每5分钟运行该程序*/

int main(int argc,char *argv[])
{
	/*
	TCHAR pFileName[MAX_PATH] = {0}; 
	//得到程序 自身运行路径
	
	DWORD dwRet = GetModuleFileName(NULL, pFileName, MAX_PATH); 
	if(0 == dwRet)
	{

	}
    TCHAR *pPos = _tcsrchr( pFileName, _T('\\'));
    if ( pPos != NULL )
    {
        *pPos = '\0';
    }
	*/
	
	//cout << pFileName;
	system("title LoopFtpUploador");
	while(true)
	{
		system("dir /a /b \"./\"|findstr \".wav\">list.txt");  /*将当前目录下的.wav文件名写入list.txt文件中*/

		std::ifstream fin("list.txt", std::ios::in);		/*设定读取当前目录中的list.txt文件*/

		TCHAR line[MAX_PATH] = {0};

		while(fin.getline(line,sizeof(line)))	/*按行读取list.txt中的内容*/
		{
			//cout << line;
			if(FALSE == ShellExecute(NULL, _T("open"), _T("ftp_up.bat"), _T(line), NULL, SW_HIDE))
			{
			}
			//DeleteFile(_T(line));		/*删除文件*/
			Sleep(UPLOAD_INTERVAL_TIME);
		}
		fin.clear();
		fin.close();
		Sleep(RUN_INTERVAL_TIME);
	}
	return 0;
}
