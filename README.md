ExecInExplorer
==============

ExecInExplorer - Execute async commands in the context of explorer

This is a fork of Microsoft's
[ExecInExplorer example](https://github.com/Microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/winui/shell/appplatform/ExecInExplorer).
I modified it to execute the program arguments as a command line.

eg: ExecInExplorer notepad foo.txt

ExecInExplorer is useful if you are running as administrator and you want to
execute a program in the context of the user's explorer (eg it will de-elevate
the program if explorer isn't running as admin). For more information read
Raymond Chen's
[blog post](https://blogs.msdn.microsoft.com/oldnewthing/20131118-00/?p=2643).

ExecInExplorer calls function
[IShellDispatch2.ShellExecute](https://msdn.microsoft.com/en-us/library/windows/desktop/bb774148.aspx)
which will execute the command line asynchronously. The exit code returned by
ExecInExplorer is 0 if the command line to be executed was *dispatched*
successfully or otherwise an HRESULT indicating why it wasn't.

Note that since explorer is executing the command line in its context it uses
its current directory by default (typically C:\Windows\System32) and not the
current directory of ExecInExplorer. I did add code that makes it possible to
change the current directory but it is not enabled. To enable it would involve
calling GetCurrentDir_ThreadUnsafe to get the current directory and then
passing that to ShellExecInExplorerProcess as the third argument pszDir.

If you want to block waiting for the command line to finish there doesn't
appear to be any way to do it with this method. You can do it by copying the
user's shell token and passing that to CreateProcessWithTokenW (Vista+) and
then WaitForSingleObject on the process handle. For more information read Aaron
Margosis'
[blog post](https://blogs.msdn.microsoft.com/aaron_margosis/2009/06/06/faq-how-do-i-start-a-program-as-the-desktop-user-from-an-elevated-app/).

Other
-----

### License

[MIT license](https://github.com/jay/ExecInExplorer/blob/master/LICENSE)

### Source

The source can be found on
[GitHub](https://github.com/jay/ExecInExplorer).
Since you're reading this maybe you're already there?

### Send me any questions you have

Jay Satiro `<raysatiro$at$yahoo{}com>` and put ExecInExplorer in the subject.
