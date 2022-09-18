#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string reverseWords(string s)
{
    stack<string> stackString;
    string sTmp;
    for(int i=0; i<s.length(); ++i)
    {
        if(s[i] != ' ')
        {
            sTmp.append(1, s[i]);
        }
        else
        {
            if(sTmp.length() > 0)
            {
                stackString.push(sTmp);
                sTmp.clear();
            }
        }
    }
    if(sTmp.length() > 0)
    {
        stackString.push(sTmp);
        sTmp.clear();
    }

    string sResult;
    while(false == stackString.empty())
    {
        string sTop = stackString.top();
        stackString.pop();
        sResult.append(sTop + " ");
    }

    if(true == sResult.empty())
        return "";

    return sResult.erase(sResult.length()-1);
}

int main(int argc, char** argv)
{
    cout << reverseWords("the sky is blue") << endl;
    cout << reverseWords("") << endl;
    cout << reverseWords(" ") << endl;
    cout << reverseWords("  ") << endl;

    return 0;
}
