#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int size = nums.size();
        unordered_set<int> UniqueElements;
        for (int i = 0; i < size; i++)
        {

            if (UniqueElements.count(nums[i]) > 0)
            {
                return true;
            }

            UniqueElements.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2, 4, 3};
    Solution s;
    bool result=false;
    result = s.containsDuplicate(arr);
    cout << result;
    return 0;
}