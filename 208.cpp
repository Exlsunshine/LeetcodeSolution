class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode()
	{
		next = NULL;
		child = NULL;
		val = ' ';
		isAword = false;
	}

	TrieNode *next;
	TrieNode *child;
	char val;
	bool isAword;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word)
	{
		TrieNode *p = root->child;
		int level = 0;
		TrieNode *previouseP = root;
		bool isSameLevel = false;

		while (level < word.length())
		{
			if (p == NULL)
			{
				TrieNode *newNode = new TrieNode();
				newNode->val = word[level];
				if (isSameLevel)
					previouseP->next = newNode;
				else
					previouseP->child = newNode;
				p = newNode;
				if (root->child == NULL)
					root->child = p;

				level++;

				for (int i = level; i < word.length(); ++i)
				{
					TrieNode *newNode = new TrieNode();
					newNode->val = word[i];
					p->child = newNode;
					p = p->child;
				}

				p->isAword = true;

				return;
			}

			if (p->val == word[level])
			{
				isSameLevel = false;
				previouseP = p;
				p = p->child;
				level++;

				if (level == word.length())
				{
					previouseP->isAword = true;
					break;
				}
			}
			else
			{
				isSameLevel = true;
				previouseP = p;
				p = p->next;
			}
		}
	}

	// Returns if the word is in the trie.
	bool search(string word)
	{
		TrieNode *p = root->child;
		int level = 0;

		while (p != NULL && level < word.length())
		{
			if (p->val == word[level])
			{
				level++;
				if (level == word.length() && p->isAword)
					return true;

				p = p->child;
			}
			else
				p = p->next;
		}

		if (level < word.length())
			return false;

		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix)
	{
		TrieNode *p = root->child;
		int level = 0;

		while (p != NULL && level < prefix.length())
		{
			if (p->val == prefix[level])
			{
				p = p->child;
				level++;
			}
			else
				p = p->next;
		}

		if (level < prefix.length())
			return false;
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");