#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove n-th node from the end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; ++i) {
        if (fast) fast = fast->next;
    }

    // Move both fast and slow until fast reaches the last node
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the nth node
    ListNode* delNode = slow->next;
    if (delNode) {
        slow->next = delNode->next;
        delete delNode;
    }

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create a list from array
ListNode* createList(const vector <int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (int i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = createList(values);
    cout << "Original list: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "After removing " << n << "-th node from end: ";
    printList(head);

    return 0;
}
