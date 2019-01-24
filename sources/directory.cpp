// Directory processing
#include "bits/stdc++.h"
#include "direct.h"
#include "dirent.h"
#include "windows.h"
#include "headers/directory.h"
using namespace std;

// Special sign '\'
string directory::slashsign()
{
	string tmp="";
	tmp+=char(92);
	return tmp;
}

// Init data
void directory::InitData()
{
	Path="";
}

// Input data
void directory::ReadData(char *str)
{
	Path=str;
}

// Checking current directory is exist or not
bool directory::CheckDirectory()
{
	DWORD check=GetFileAttributes(Path.c_str());
	return (check!=INVALID_FILE_ATTRIBUTES&&(check&FILE_ATTRIBUTE_DIRECTORY));
}

// Getting current directory
void directory::GetCurrentDirectory()
{
	char buffer[MAX_PATH];
	getcwd(buffer,sizeof(buffer));
	Path=buffer;
}

// Getting files's list in current directory
vector<pair<string,int> > directory::GetFilesListofDirectory()
{
	DIR *dir;
	struct dirent *file;
	vector<pair<string,int> > FilesList;
	dir=opendir(Path.c_str());
	while((file=readdir(dir))!=NULL)
		FilesList.push_back(make_pair(file->d_name,file->d_type));
	closedir(dir);
	return FilesList;
}

// Changing current directory
directory directory::ChangeDirectory(string FolderName)
{
	directory NewDirectory;
	NewDirectory.Path=Path+slashsign()+FolderName;
	return NewDirectory;
}