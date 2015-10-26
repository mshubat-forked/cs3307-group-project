#pragma once
#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H


#include <vector>

using namespace std;

extern unsigned long long t_FileRead(vector <char> &t_FileBuff0,
	char t_FileName[]);
extern unsigned long long t_FileRead(char t_FileBuff0[],
	char t_FileName[]);
extern void t_FileSave(char t_FileName[],
	char t_FileBuff0[],unsigned long long t_FileSize);
unsigned long long z_MergeMarkedFromListBox(
	vector<string> &z_FilenameList,vector<char> &t_FileBuff1);
//

#endif /* FILEOPERATIONS_H */
