/*
Given a binary tree, determine if it is height-balanced.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
*/

#include <cmath>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int countNodes(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    
    int leftCount = countNodes(node->left);
    int rightCount = countNodes(node->right);
    
    return leftCount + rightCount + 1;
}

int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    
    return max(leftHeight, rightHeight) + 1;
}

bool isSubtreeBalanced(TreeNode* node) {
    if (node == nullptr) {
        return true;
    }
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    int heightDiff = abs(leftHeight - rightHeight);
    
    if (heightDiff > 1) {
        return false;
    }
    
    bool leftBalanced = isSubtreeBalanced(node->left);
    bool rightBalanced = isSubtreeBalanced(node->right);
    
    return leftBalanced && rightBalanced;
}

bool isBalanced(TreeNode* root) {
    return isSubtreeBalanced(root);
}
