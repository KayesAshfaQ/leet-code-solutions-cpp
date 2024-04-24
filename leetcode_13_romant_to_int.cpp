#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (value(s[i]) < value(s[i + 1]))
            {
                result = result - value(s[i]);
            }
            else
            {
                result = result + value(s[i]);
            }
        }
        return result;
    }

    int value(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
        }
    }
};

int main()
{
    Solution solution = Solution();

    string s;
    cout << "Enter a roman number: \n";
    cin >> s;

    int result = solution.romanToInt(s);

    cout << result << endl;

    return 0;
}