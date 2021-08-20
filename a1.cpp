#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "a.h"


int main () {
  MessageBox(NULL, _T("hello"), _T("hello"), MB_OK);



  system("pause");
  return 0;

}

void func () { std::cout << "hello world" << std::endl; }



