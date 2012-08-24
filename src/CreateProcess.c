/* CreateProcess.c */
/* $Id: CreateProcess.c,v 1.1.1.1 2003/06/19 19:00:15 fcardona Exp $ */

#include <Windows.h>

int
main(int argc, char *argv[])
{
  STARTUPINFO startupInfo;
  PROCESS_INFORMATION piProcInfo;

  GetStartupInfo(&startupInfo);

  if (CreateProcess(NULL, "NOTEPAD CreateProcess.c", NULL, NULL,
		    FALSE, 0, NULL, NULL, &startupInfo,
		    &piProcInfo)) {
    WaitForSingleObject(piProcInfo.hProcess, 0);
  }
  else {
  }
}
