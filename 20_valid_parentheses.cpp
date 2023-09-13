#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        if (s.size() == 0)
            return true;

        if (s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (st.size())
            {
                char c = st.top();
                if (c == '(' && s[i] != ')')
                    return false;
                else if (c == '[' && s[i] != ']')
                    return false;
                else if (c == '{' && s[i] != '}')
                    return false;

                // pop the top element    
                st.pop();
            }
            else
                return false;
            // cout<<st.top();
        }

        if (!st.empty())
            return false;
        return true;
    }
};