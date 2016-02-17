#include <iostream>

using namspace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
    	int i = 0;
    	std::vector<string> ans;

    	while (i < words.size())
    	{
    		int len = words[i].length();
    		int idx = i;
    		int wordsLen = words[i].length();
    		for (int j = i + 1; j < words.size(); ++j)
    		{
    			if (len + 1 + words[j].length() <= maxWidth)
    			{
    				idx = j;
    				len = len + 1 + words[j].length();  // with one ' '.
    				wordsLen += words[j].length();      // without ' ', just pure words length.
    			}
    			else
    				break;
    		}

            string str = "";// final string.
    		string avg = "";// some ' ' that will be inserted between #every# two neighbour words
    		
    		// if we pick up more than one word this time.
    		if (idx != i)
    		{
    		    // if this is the last line, every words should be seperated by only one ' '
    		    if (idx == words.size() - 1)
    		        avg = " ";
        		else
        		{
        		    // the number of ' ' in avg should be
        		    // (remain space) / (number of gaps between words from i to idx),
        		    // where remain space = maxWidth - wordsLen,
        		    // number of gaps between words form i to idx = idx - i,
        		    for (int j = 0; j < (maxWidth - wordsLen) / (idx - i); ++j)
        			    avg += " ";
        		}
        		
        		// if ' ' cannot be inserted evenly,
        		// spaceRemain = (remain space) % (number of gaps between words from i to idx)
        		// but if this is the last line, every words should be seperated by only one ' '
        		// if that is so, spaceRemain = 0;
        		int spaceRem = (idx == words.size() - 1 ? 0 : (maxWidth - wordsLen) % (idx - i));
        		for (int j = i; j <= idx; ++j, spaceRem--)
        			str = str + words[j] + (j != idx ? avg : "") + (spaceRem > 0? " " : "");
        		
        		if (idx == words.size() - 1)
        		    str += string(maxWidth - str.length(), ' ');
            }
            else
                str = words[i] + string(maxWidth - wordsLen, ' ');
    		
    		ans.push_back(str);
    		i = idx + 1;
    	}

    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}