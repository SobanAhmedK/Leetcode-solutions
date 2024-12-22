// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "(*)"
// Output: true
// Example 3:

// Input: s = "(*))"
// Output: true

// Constraints:

// 1 <= s.length <= 100
// s[i] is '(', ')' or '*'.

#include <typeinfo>
#include<string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0;
        int high = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '(' && s[i] != ')' && s[i] != '*')

            {
                return false;
            }
            else if (s[i] == '(')
            {
                low++;
                high++;
            }

            else if (s[i] == ')')
            {
                if (low > 0)
                {
                    low--;
                }
                high--;
            }

            else if (s[i] == '*')
            {
                if (low > 0)
                {
                    low--;
                }
                high++;
            }
            if (high < 0)
            {
                return false;
            }
        }

        return low == 0;
    }
};
int main()
{
    Solution s1 = Solution();
    bool status = s1.checkValidString("(*)");
    cout << status;

    return 0;
}
