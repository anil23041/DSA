#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle in the linked list
bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle
}

// Helper function to create a linked list with or without cycle
ListNode* createListWithCycle(bool makeCycle) {
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node0;
    node0->next = node4;

    if (makeCycle) {
        node4->next = node2; // Creating a cycle (loop back to node2)
    }

    return head;
}

int main() {
    // Create list with cycle
    ListNode* head = createListWithCycle(true);

    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}
