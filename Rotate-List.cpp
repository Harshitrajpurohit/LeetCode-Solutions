#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return nullptr;
    
    int len = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    
    k = k % len;
    if (k == 0) return head;
    
    ListNode* tp = head;
    for (int i = 0; i < len - k - 1; i++) {
        tp = tp->next;
    }
    
    tail->next = head;
    head = tp->next;
    tp->next = nullptr;
    
    return head;
}

// Helper to create a linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, n);
    
    cout << "Original list: ";
    printList(head);
    
    int k = 2;
    head = rotateRight(head, k);
    
    cout << "List after rotating right by " << k << ": ";
    printList(head);
    
    // Free memory (optional)
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
