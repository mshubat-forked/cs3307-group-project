#include <windows.h>

#include <richedit.h>

#include "MyRichEdit.h"

using namespace std;

LRESULT CALLBACK MyEditProc (HWND hWnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{

	switch(iMsg)
	{
		case WM_RBUTTONDOWN:
		{
			static HMENU	hSubMenu,hMenu;
			
			hMenu=CreatePopupMenu();

			hSubMenu=CreatePopupMenu();
			
		    AppendMenu(hSubMenu,MF_STRING,2040,"Save text here as zzzzzzzz.txt");
			
		    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hSubMenu,"txt");
			

		}
	}

	return CallWindowProc (MyWndEditOld, hWnd, iMsg, wParam, lParam);
}
