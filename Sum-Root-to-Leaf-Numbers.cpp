#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};

// answer starts here -----------------
int tSum = 0;

void sumNum(TreeNode *root, int sum, int k){
    if (!root){
        return;
    }
    if (root->left == NULL && root->right == NULL){
        if (k == 0){
            sum += root->val;
        }
        else
            sum = (sum * 10) + root->val;

        tSum += sum;
        return;
    }
    if (k == 0){
        sum += root->val;
    }
    else
        sum = (sum * 10) + root->val;

    sumNum(root->left, sum, k + 1);
    sumNum(root->right, sum, k + 1);
}

int sumNumbers(TreeNode *root){
    int sum = 0;
    int k = 0;
    sumNum(root, sum, k);

    return tSum;
}
// answer ends here -----------------

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    //           5
    //        /    \
    //       1      4
    //      / \    / \
    //     N   N  3   6

    cout << sumNumbers(root);
    // ans -> 1140
    return 0;
}