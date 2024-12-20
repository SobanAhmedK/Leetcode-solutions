
#include <iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode * head = new ListNode();
        ListNode *sorted = head;
        ListNode * pointer_1;
        ListNode * pointer_2;
        pointer_1=list1;
        pointer_2=list2;
        while (pointer_1 != nullptr && pointer_2 != nullptr)

        {
            if (pointer_1->val <= pointer_2->val)
            {
                
                sorted->next = pointer_1;
                pointer_1=pointer_1->next;
               
            }
            
            else if (pointer_1->val > pointer_2->val)
            {
                
                sorted->next = pointer_2;
                pointer_2=pointer_2->next;
               
            }
            sorted=sorted->next;

        }

        if( pointer_1 != nullptr)
        {
            sorted->next = pointer_1;
        }
        else if( pointer_2 != nullptr)
        {
            sorted->next = pointer_2;
        }
        return head->next;
    

    }
};
