// #include "TrieNode.h"
#include <string>
#include <vector>

using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
    void printWords(TrieNode *root, string word, string output) {
        if(root->isTerminal) {
            cout<<word+output<<endl;
        }
        for(int i=0; i<26; i++) {
            if(root->children[i])
                printWords(root->children[i],word,output+root->children[i]->data);
        }
    }
    
    bool findNode(TrieNode *root, string word, string str) {
        if(word.size()==0) {
            printWords(root,str,"");
            return true;
        }
        int index = word[0]-'a';
        if(root->children[index] == NULL) 
            return false;
        else {
            bool check = findNode(root->children[index],word.substr(1),str);
            return check;
        }
    }
    
    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
        for(int i=0; i<input.size(); i++) {
            insertWord(input[i]);
        }
        findNode(root,pattern,pattern);
    }
};