#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// answer starts from here

// solution 1
bool flag = true;
void check(ListNode *head, ListNode* &tp){
    if(!head)return;
    check(head->next, tp);
    if(head->val != tp->val){
        flag = false;
        return;
    }
    tp=tp->next;
} 
bool isPalindrome(ListNode* head) {
    ListNode *tp = head;
    check(head, tp);
    return flag;
}


// solution 2
bool isPalindrome2(ListNode *head) {
    string str = "";
    while (head != NULL) {
        str += to_string(head->val);
        head = head->next;
    }

    string rev = str;
    reverse(rev.begin(), rev.end());
    return str == rev;
}



// answer ends here


void insertAtEnd(ListNode* &head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    ListNode* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

   bool ans = isPalindrome2(head);
   cout<<ans;
   // ans -> true

    return 0;
}
