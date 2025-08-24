#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// main function
void deleteNode(ListNode* node) {
    if (node == NULL || node->next == NULL) return; 
    node->val = node->next->val;
    node->next = node->next->next;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original list: ";
    printList(head);

    // Let's delete node with value 5
    deleteNode(head->next);

    cout << "List after deleting node 5: ";
    printList(head);
    // ans - >  4 1 9
    return 0;
}
