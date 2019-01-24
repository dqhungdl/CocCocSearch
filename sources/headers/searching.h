#ifndef SEARCHING
#define SEARCHING

#include "directory.h"
#include "trie.h"

class searching
{
private:
	int TotalFiles;							// Number of files found
	bool DirectoryOmitted;					// Directory is omitted (DirectoryOmitted==true) or not (DirectoryOmitted==false).
	directory Directory;					// Directory
	vector<string> WordsList;				// Key words's list
	trie Trie;								// Using trie data structure to manage all key words's

	// Special sign '\'
	string slashsign();

	// Check all words in specific file
	bool CheckFile(directory Directory);

	// Finding and printing all files in directory and subdirectories, using DFS algorithm
	void FindingandPrinting(directory CurrentDirectory);

public:
	// Init data
	void InitData();

	// Input data
	void ReadData(int argc,char *argv[]);

	// Checking directory is omitted or not and standardize directory
	void FixDirectory();

	// Checking key words's list is not empty
	void FixWordsList();

	// Finding all files which contain all key words and output data
	void FindingAllFilesandPrintingData();
};

#endif