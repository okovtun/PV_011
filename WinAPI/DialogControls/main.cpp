#include<Windows.h>
#include"resource.h"

CONST CHAR* variant[] =
{
	"This",
	"is",
	"my",
	"first",
	"List",
	"Box"
};

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hList = GetDlgItem(hwnd, IDC_LIST1);
		for (int i = 0; i < sizeof(variant) / sizeof(variant[0]); i++)
			SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)variant[i]);
		SendMessage(hList, LB_SETCURSEL, 2, 0);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			const int SIZE = 256;
			char sz_buffer[SIZE]{};
			char sz_msg[SIZE]{};
			strcpy(sz_msg, "Вы выбрали пункт: ");
			
			HWND hList = GetDlgItem(hwnd, IDC_LIST1);
			INT i = SendMessage(hList, LB_GETCURSEL, 0, 0);
			SendMessage(hList, LB_GETTEXT, i, (LPARAM)sz_buffer);
			strcat(sz_msg, sz_buffer);
			MessageBox(hwnd, sz_msg, "Info", MB_ICONINFORMATION | MB_OK);

		}
			break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}