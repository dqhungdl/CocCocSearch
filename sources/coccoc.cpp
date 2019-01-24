// Controlling program
#include "bits/stdc++.h"
#include "direct.h"
#include "dirent.h"
#include "windows.h"
#include "headers/searching.h"
using namespace std;

int main(int argc,char *argv[])
{
	// Checking invalid command
	if(argc<2||argc>3)
	{
		cout<<"Invalid command!";
		return 0;
	}

	// Processing
	searching Search;
	Search.InitData();
	Search.ReadData(argc,argv);
	Search.FixDirectory();
	Search.FixWordsList();
	Search.FindingAllFilesandPrintingData();

	return 0;
}
