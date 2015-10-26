#pragma once
#ifndef MyListBox_h
#define MyListBox_h

#include <windows.h>

extern char *t_FileBuff0;
extern char *t_FileBuff1;
extern unsigned long long t_j;

extern HWND  MyhWndList,MyhWndRichEdit;

extern WNDPROC MyWndListOld;

extern LRESULT CALLBACK MyListProc (HWND, UINT, WPARAM, LPARAM);

#endif