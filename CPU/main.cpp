#include "run.h"
#include <Windows.h>

int main() {
    OPENFILENAMEW ofn;
    WCHAR szFile[260];

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = L'\0';
    ofn.nMaxFile = sizeof(szFile) / sizeof(szFile[0]);
    ofn.lpstrFilter = L"All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameW(&ofn) == TRUE) {
        char szFileA[260];
        WideCharToMultiByte(CP_UTF8, 0, szFile, -1, szFileA, sizeof(szFileA), NULL, NULL);
        runner r;
        r.runASM(szFileA);
    }
	
	return 0;
}