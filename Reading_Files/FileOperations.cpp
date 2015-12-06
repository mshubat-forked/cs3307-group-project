#include <string.h>

#include <iterator>
#include <vector>
#include <algorithm>

#include <windows.h>
#include <direct.h>
#include <richedit.h>

#include <iostream>
#include <fstream>
#include <sstream>
//#include <ctime>
#include <locale>

using namespace std;

#define LISTBOXITEMSNR	100
#define MAXPATH			256

#include "FileOperations.h"



unsigned long long t_FileRead(vector<char> &t_FileBuff0,
	char t_FileName[])
{
char * buffer;
  long size;
  ifstream file (t_FileName, ios::in|ios::binary|ios::ate);
  if(file.bad())
  {
        MessageBox(NULL,t_FileName, "Cannot open file", MB_ICONWARNING);
	return 0;
	}
  size = file.tellg();
  file.seekg (0, ios::beg);
  buffer = new char [size];
  file.read (buffer, size);
  file.close();
for(int i=0;i<size;i++)
	t_FileBuff0.push_back(*(buffer+i));
	
	delete[]buffer;

	return t_FileBuff0.size();
}
unsigned long long t_FileRead(char t_FileBuff0[],
	char t_FileName[])
{
	char t_FileBuffTmp[65536];
	
	fstream t_fstream;
	t_fstream.open(t_FileName,fstream::in|fstream::binary);

	unsigned long long start,t_FileSize;

	t_fstream.seekg(0,fstream::beg);
	start=t_fstream.tellg();
	t_fstream.seekg(0,fstream::end);
	t_FileSize=t_fstream.tellg();
	t_FileSize=t_FileSize-start;

	t_fstream.seekg(0,fstream::beg);

	unsigned long long j=t_FileSize;
	unsigned long long k=0;

	while(j>65536)
	{
		t_fstream.read(t_FileBuffTmp,65536);
		for(int i=0;i<65536;i++,k++)
			*(t_FileBuff0+k)=t_FileBuffTmp[i];
		j-=65536;
	}
	*(t_FileBuff0+k)=0;
	t_fstream.read(t_FileBuffTmp,j);
	for(int i=0;i<j;i++,k++)
		*(t_FileBuff0+k)=t_FileBuffTmp[i];
		*(t_FileBuff0+k)=0;

	t_fstream.close();
	return t_FileSize;
}
void t_FileSave(char t_FileName[],char t_FileBuff0[],unsigned long long t_FileSize)
{
	ofstream t_ofstream;
	t_ofstream.open(t_FileName,ios::out|ios::binary);
	t_ofstream.write(t_FileBuff0,t_FileSize);
	t_ofstream.close();
}
unsigned long long z_MergeMarkedFromListBox(
	vector<string> &z_FilenameList,vector<char> &t_FileBuff1)
{
			int i,t_ItemsNr;
			int t_ListBoxItems[LISTBOXITEMSNR];
			char szBuffer[MAXPATH + 1];
			vector<char>t_FileBuff0;
			vector<char>::iterator It;
			string z_StringTmp="";

			extern HWND MyhWndList;
			//Beep(1600,50);
			if((i = SendMessage (MyhWndList,LB_GETCURSEL, 0, 0L))==LB_ERR)
				return 0;
			if((t_ItemsNr = SendMessage (MyhWndList,LB_GETSELITEMS,
				LISTBOXITEMSNR,(LPARAM)t_ListBoxItems))==LB_ERR)return 0;
			bool z_FirstFile=1;
			for(unsigned k=0;k<t_ItemsNr;k++)
			{
				SendMessage(MyhWndList,LB_GETTEXT,
					t_ListBoxItems[k],(LPARAM)szBuffer);
				if(z_FirstFile)
				{
					for(unsigned ii=0;szBuffer[ii];ii++)
						z_StringTmp+=szBuffer[ii];
					z_FilenameList.push_back(z_StringTmp);
					z_StringTmp="";
					z_FirstFile=0;
				}
				unsigned long long t_FileSize;
				t_FileBuff0.clear();
				t_FileSize=t_FileRead(t_FileBuff0,szBuffer);
				for(It=t_FileBuff0.begin();It<t_FileBuff0.end();It++)
					t_FileBuff1.push_back(*It);
				unsigned long long t_i;
			}
			return t_FileBuff1.size();
}
