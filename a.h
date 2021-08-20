#ifdef export_f
  #define DllExport __declspec(dllexport)

  DllExport void func();  
#else
  void func();
#endif


