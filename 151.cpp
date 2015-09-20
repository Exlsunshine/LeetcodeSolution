#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    void reverseWords(string &s)
    {
        int i = 0, j = 0;
        while (i < s.length() && j < s.length())
        {
            while (s[i] == ' ' && i < s.length())
                i++;

            j = i;
            while (s[j + 1] != ' ' && (j + 1) < s.length())
                j++;

            if (i > s.length() || j > s.length())
                break;

            reverseAword(s, i, j);

            i = j + 1;
        }

        int new_index = 0, curr_index = 0;
        while (curr_index < s.length())
        {
            while (s[curr_index] == ' ')
                curr_index++;

            while (curr_index < s.length() && s[curr_index] != ' ')
                s[new_index++] = s[curr_index++];

            while (curr_index < s.length() && s[curr_index] == ' ')
                curr_index++;


            if (curr_index >= s.length())
                break; 
            else
                s[new_index++] = ' ';
        }

        reverseAword(s, 0, new_index - 1);

        s.erase(new_index, s.length() - new_index + 1);
        //for (int i = new_index; i < s.length(); ++i)
        //    s[i] = '\0';
    }

private:
    void reverseAword(string &str, int start, int end)
    {
        int cnt = end - start;
        for (int i = 0; i <= cnt / 2; i++)
        {
            char c = str[start + i];
            str[start + i] = str[end - i];
            str[end - i] = c;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "    the    sky is   blue   ";

    cout << str << endl;
    s.reverseWords(str);
    cout << str << endl;


    return 0;
}