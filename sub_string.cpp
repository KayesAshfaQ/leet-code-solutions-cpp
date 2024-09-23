#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'longestSubArray' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int longestSubarray(vector<int> arr)
{

    vector<int> res;

    for (int i = 0; i < arr.size(); i++)
    {

        // when res is empty add the first element
        if (res.empty())
        {
            res.push_back(arr.at(i));
            continue;
        }

        // check if the difference between the last element and the current element is 1
        if (abs(res.back() - arr.at(i)) == 1)
        {
            // check if is there any element which difference is greater than 1 and remove it
            if (res.size() > 2)
            {
                for (int j = 0; j < res.size(); j++)
                {
                    if (abs(res.at(j) - arr.at(i)) > 1)
                    {
                        res.erase(remove(res.begin(), res.end(), j));
                    }
                }
            }

            // add the current element
            res.push_back(arr.at(i));
        }
        else
        {
            res.clear();
        }
    }

    cout << "Longest Sub array: " << res.size() << endl;

    return res.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++)
    {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = longestSubarray(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
