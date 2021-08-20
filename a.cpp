#include <iostream>
#include <windows.h>
#include "a.h"
using namespace std;

typedef void(* ptrTest)();

int main () {
  HINSTANCE handle;
  const char * filename = "b.dll";
  int size = strlen(filename);
  std::cout << "1" << std::endl;
  DWORD bufferSize = MultiByteToWideChar(CP_ACP, 0, filename, size, NULL, 0);
  if (bufferSize == 0) {
    return NULL;
  }
  wchar_t *f = new wchar_t[bufferSize];
  bufferSize = MultiByteToWideChar(CP_ACP, 0, filename, size, f, bufferSize);
  if (bufferSize == 0) {
    delete f;
    return NULL;
  }

  handle = LoadLibraryW(f);

  std::cout << "2" << std::endl;

  ptrTest test;
  if (handle) {
    std::cout << "3" << std::endl;
    test = (ptrTest)GetProcAddress(handle, "test");
    if (test != NULL) {
      std::cout << "4" << std::endl;
      test();
    }
  } else {
    DWORD code = GetLastError();
    std::cout << "err_code:" << code << std::endl;
  }

  std::cout << "5" << std::endl;


  system("pause");
  return 0;

}

void func () { std::cout << "hello world" << std::endl; }



