#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int data) : val(data), left(NULL), right(NULL), next(NULL) {}
};

// answer starts here -----------------
Node* connect(Node* root) {
    if(!root)return root;

    queue<Node*> q;
    q.push(root);
    int size;
    while(!q.empty()){
        size = q.size();
        for(int i=0;i<size;i++){
            Node* tp = q.front();
            q.pop();
            if(i==size-1){
                tp->next = NULL;
            }else{
                tp->next = q.front();
            }
            if(tp->left)q.push(tp->left);
            if(tp->right)q.push(tp->right);
        }
    }

    return root;
}
// answer ends here -----------------

void printNextPointers(Node* root) {
    while (root) {
        Node* current = root;
        while (current) {
            cout << current->val << " -> ";
            if (current->next)
                cout << current->next->val << "  ";
            else
                cout << "NULL";
            current = current->next;
        }
        cout << endl;
        root = root->left; 
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    //           1          <----
    //        /    \
    //       2      3       <----
    //      / \    /  \
    //     4   5  N    7    <----

    connect(root);

    printNextPointers(root);

    return 0;
}
