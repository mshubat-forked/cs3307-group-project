#pragma once
#ifndef MyRichEdit_h
#define MyRichEdit_h

#include <windows.h>

using namespace std;

extern HWND  MyhWndList,MyhWndRichEdit;

extern WNDPROC MyWndEditOld;
extern WNDPROC MyWndListOld;

extern LRESULT CALLBACK MyListProc (HWND, UINT, WPARAM, LPARAM);
extern LRESULT CALLBACK MyEditProc (HWND, UINT, WPARAM, LPARAM);

#endif
