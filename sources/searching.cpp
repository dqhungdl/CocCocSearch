// Finding all needed files
#include "bits/stdc++.h"
#include "direct.h"
#include "dirent.h"
#include "windows.h"
#include "headers/searching.h"
using namespace std;

// Special sign '\'
string searching::slashsign()
{
	string tmp="";
	tmp+=char(92);
	return tmp;
}

// Check all words in specific file
bool searching::CheckFile(directory Directory)
{
	Trie.ResetCount();
	ifstream ReadFile((Directory.Path).c_str());
	string str;
	while(ReadFile>>str)
	{
		Trie.CheckWord(str);
		if(Trie.MatchAllWords()==true)
			return true;
	}
	ReadFile.close();
	return false;
}

// Finding and printing all files in directory and subdirectories, using DFS algorithm
void searching::FindingandPrinting(directory CurrentDirectory)
{
	vector<pair<string,int> > FilesList=CurrentDirectory.GetFilesListofDirectory();
	cout<<"\n Directory of "<<CurrentDirectory.Path<<"\n\n";
	int NumberofFilesFound=0;
	for(int i=0;i<int(FilesList.size());i++)
	{
		directory NewDirectory=CurrentDirectory.ChangeDirectory(FilesList[i].first);
		if(FilesList[i].second==0&&CheckFile(NewDirectory)==true)
		{
			cout<<"   "<<FilesList[i].first<<"\n";
			NumberofFilesFound++;
		}
	}
	TotalFiles+=NumberofFilesFound;
	cout<<"\t\t"<<NumberofFilesFound<<" File(s)\n";
	for(int i=0;i<int(FilesList.size());i++)
	{
		directory NewDirectory=CurrentDirectory.ChangeDirectory(FilesList[i].first);
		if(FilesList[i].second!=0&&FilesList[i].first!="."&&FilesList[i].first!="..")
			FindingandPrinting(NewDirectory);
	}
}

// Init data
void searching::InitData()
{
	TotalFiles=0;
	DirectoryOmitted=true;
	Directory.InitData();
	WordsList.clear();
}

// Input data
void searching::ReadData(int argc,char *argv[])
{
	stringstream ReadLine(argv[1]);
	string str;
	while(ReadLine>>str)
		WordsList.push_back(str);
	if(argc==3)
	{
		DirectoryOmitted=false;
		Directory.ReadData(argv[2]);
	}
}

// Checking directory is omitted or not and standardize directory
void searching::FixDirectory()
{
	if(DirectoryOmitted==false&&Directory.CheckDirectory()==false)
	{
		cout<<"The system cannot find the path specified.\n";
		exit(0);
	}
	else
	if(DirectoryOmitted==true)
		Directory.GetCurrentDirectory();
	else
	{
		for(int i=0;i<int(Directory.Path.size());i++)
			if(Directory.Path[i]=='/')
				Directory.Path[i]=slashsign()[0];
		if(Directory.Path[Directory.Path.size()-1]==slashsign()[0])
			Directory.Path.erase(Directory.Path.size()-1,1);
	}
}

// Checking key words's list is not empty
void searching::FixWordsList()
{
	if(int(WordsList.size())==0)
	{
		cout<<"No word to check.\n";
		exit(0);
	}
	Trie.AddWordsListtoTrie(WordsList);
}

// Finding all files which contain all key words and output data
void searching::FindingAllFilesandPrintingData()
{
	FindingandPrinting(Directory);
	cout<<"\n\t"<<"Total File(s) Listed: "<<TotalFiles<<" File(s)\n";
}