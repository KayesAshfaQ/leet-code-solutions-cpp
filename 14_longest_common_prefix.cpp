#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            // print the finding of prefix
            // cout << "Finding prefix for: " << strs[i] << "result is : " << strs[i].find(prefix) << "." << endl;

            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                cout << "Prefix " << i << ": " << prefix << endl;
                if (prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};

int main()
{
    // create a demo vector of strings
    vector<string> demo = {"leets", "leetcode", "leet", "leeds"};

    // create an object of Solution
    Solution obj;

    // call the function
    cout << obj.longestCommonPrefix(demo);

    return 0;
}