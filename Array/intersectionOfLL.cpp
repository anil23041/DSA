#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        while (ptr1 != ptr2) {
            if (ptr1 == NULL) {
                ptr1 = headB;
            } else {
                ptr1 = ptr1->next;
            }

            if (ptr2 == NULL) {
                ptr2 = headA;
            } else {
                ptr2 = ptr2->next;
            }
        }

        return ptr1;
    }
};

int main() {
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(3);
    headA->next->next = common;

    ListNode* headB = new ListNode(2);
    headB->next = common;

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
