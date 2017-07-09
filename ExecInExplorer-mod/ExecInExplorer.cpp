#include <Windows.h>

#include "ExecInExplorer_Implementation.h"

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
  HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
  if (SUCCEEDED(hr))
  {
    ShellExecInExplorerProcess(L"http://www.msn.com");
    CoUninitialize();
  }
  return 0;
}
