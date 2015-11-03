#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {
public:
    // Adds a word into the data structure.
    void addWord(string word)
    {
        if (root == NULL)
            root = new Node('*');

        int n = word.length();
        Node *p = root;

        int i = 0;
        while (i < n)
        {
            Node *nextChild = p->next[word[i] - 'a'];
            if (nextChild == NULL)
            {
                nextChild = new Node(word[i]);
                p->next[word[i] - 'a'] = nextChild;
            }
            i++;

            if (i == n)
                nextChild->isAword = true;
            p = nextChild;
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word)
    {
        if (root == NULL)
            return false;

        return dfs(0, word, root);
    }

private:
    struct Node
    {
        char val;
        Node *next[26];
        bool isAword;
        Node(char c) : val(c), isAword(false)
        {
            memset(next, 0, sizeof(Node*)* 26);
        }
    };
    Node *root = NULL;

    bool dfs(int startIdx, const string &word, Node *node)
    {
        if (word[startIdx] == '.')
        {
            bool exists = false;
            for (int j = 0; j < 26; ++j)
            {
                if (node->next[j] != NULL)
                {
                    if (startIdx == word.length() - 1)
                        exists = node->next[j]->isAword;
                    else
                        exists = dfs(startIdx + 1, word, node->next[j]);

                    if (exists)
                        break;
                }
            }
            
            return exists;
        }
        else
        {
            Node *element = node->next[word[startIdx] - 'a'];
            if (element == NULL)
                return false;
            else
            {
                if (startIdx == word.length() - 1)
                    return element->isAword;
                else
                    return dfs(startIdx + 1, word, element);
            }
        }
    }
};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(int argc, char const *argv[])
{
    WordDictionary dict;

    // dict.addWord("a");
    dict.addWord("ab");
    // cout << dict.search("a") << endl << endl;
    // cout << dict.search("a.") << endl << endl;
    // cout << dict.search("ab") << endl << endl;
    // cout << dict.search(".a") << endl << endl;
    cout << dict.search(".b") << endl << endl;
    // cout << dict.search("ab.") << endl << endl;
    // cout << dict.search(".") << endl << endl;
    // cout << dict.search("..") << endl << endl;


	return 0;
}