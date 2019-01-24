#ifndef TRIE
#define TRIE

class trie
{
private:
	struct node
	{
		int key,Child[2*MAXCHAR+5];
	};
	int WordsCount;							// Number of distinct words in key words's list
	map<int,bool> Used;						// Check if some words are in specific file
	node EMPTY_NODE;						// Empty trie's node
	vector<node> Trie;						// Using trie data structure to manage all key words's

	// Init data
	void InitData();

	// Add specific word to trie
	void AddWord(string str);

public:
	// Add all words in key words's list to trie
	void AddWordsListtoTrie(vector<string> WordsList);

	// Reset words's checking
	void ResetCount();

	//Checking the specific word is in the key words's list or not
	void CheckWord(string str);

	//Checking the specific file contains all the key words or not
	bool MatchAllWords();
};

#endif