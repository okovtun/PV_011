#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//MessageBox(NULL, "Это моё первое окно!", "Info - Заголовок окна", MB_ICONINFORMATION | MB_YESNOCANCEL | MB_DEFBUTTON3 | MB_SYSTEMMODAL | MB_TOPMOST);
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		//GetModuleHandle(NULL) - возвращает hInstance приложения.
		//hInstance - это *.exe файл
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon);

		HWND hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
		SetFocus(hEdit1);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			HWND hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
			HWND hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
			HWND hStatic = GetDlgItem(hwnd, IDC_STATIC1);

			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};

			SendMessage(hEdit1, WM_GETTEXT, (WPARAM)SIZE, (LPARAM)sz_buffer);
			SendMessage(hEdit2, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer);

			//MessageBox(NULL, "Была нажата кнопка OK", "Info", MB_ICONINFORMATION | MB_OK);
		}
		break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}