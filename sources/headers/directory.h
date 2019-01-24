#ifndef DIRECTORY
#define DIRECTORY

class directory
{
private:
	// Special sign '\'
	string slashsign();
	
public:
	string Path;

	// Init data
	void InitData();

	// Input data
	void ReadData(char *str);

	// Checking current directory is exist or not
	bool CheckDirectory();

	// Getting current directory
	void GetCurrentDirectory();

	// Getting files's list in current directory
	vector<pair<string,int> > GetFilesListofDirectory();

	// Changing current directory
	directory ChangeDirectory(string FolderName);
};

#endif
