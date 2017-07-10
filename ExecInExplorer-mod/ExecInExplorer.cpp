/* LICENSE: MIT License
Copyright (C) 2017 Jay Satiro <raysatiro@yahoo.com>
https://github.com/jay/ExecInExplorer/blob/master/LICENSE
*/

#include <Windows.h>
#include <tchar.h>

#include <vector>

#include "ExecInExplorer_Implementation.h"
#include "ExecInExplorer_Util.h"

using namespace std;


int WINAPI wWinMain(HINSTANCE, HINSTANCE, const PWSTR original_cmdline, int)
{
  HRESULT hr;
  WCHAR *prog, *argline;

  if(ProgAndArgLineFromCmdLine(original_cmdline, &prog, &argline)) {
    hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if(SUCCEEDED(hr)) {
      hr = ShellExecInExplorerProcess(prog, argline);
      CoUninitialize();
    }
    free(prog);
    free(argline);
  }
  else
    hr = (HRESULT)-1;

  return SUCCEEDED(hr) ? 0 : (int)hr;
}
