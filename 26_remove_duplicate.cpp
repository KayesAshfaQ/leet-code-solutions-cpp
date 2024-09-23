#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i + 1);
                i--; // Adjust index after erasing
            }
        }

        return nums.size();
    }
};

int main()
{
    vector<int> nums;
    nums = {1, 1, 2}; // Corrected initialization
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}