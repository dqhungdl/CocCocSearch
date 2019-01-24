// Using trie data structure to manage all key words's
#include "bits/stdc++.h"
#include "direct.h"
#include "dirent.h"
#include "windows.h"
#include "headers/trie.h"
using namespace std;

// Init data
void trie::InitData()
{
	EMPTY_NODE.key=0;
	for(int i=0;i<=2*MAXCHAR;i++)
		EMPTY_NODE.Child[i]=-1;
	WordsCount=0;
	Trie.clear();
	Trie.push_back(EMPTY_NODE);
}

// Add specific word to trie
void trie::AddWord(string str)
{
	int idx=0;
	for(int i=0;i<int(str.size());i++)
	{
		if(Trie[idx].Child[int(str[i])+MAXCHAR]==-1)
		{
			Trie.push_back(EMPTY_NODE);
			Trie[idx].Child[int(str[i])+MAXCHAR]=Trie.size()-1;
		}
		idx=Trie[idx].Child[int(str[i])+MAXCHAR];
	}
	if(Trie[idx].key==0)
		Trie[idx].key=++WordsCount;
}

// Add all words in key words's list to trie
void trie::AddWordsListtoTrie(vector<string> WordsList)
{
	InitData();
	for(int i=0;i<int(WordsList.size());i++)
		AddWord(WordsList[i]);
}

// Reset words's checking
void trie::ResetCount()
{
	Used.clear();
}

//Checking the specific word is in the key words's list or not
void trie::CheckWord(string str)
{
	int idx=0;
	for(int i=0;i<int(str.size());i++)
	{
		if(Trie[idx].Child[int(str[i])+MAXCHAR]==-1)
			return;
		idx=Trie[idx].Child[int(str[i])+MAXCHAR];
	}
	if(Trie[idx].key==0)
		return;
	Used[Trie[idx].key]=true;
}

//Checking the specific file contains all the key words or not
bool trie::MatchAllWords()
{
	return (int(Used.size())==WordsCount);
}