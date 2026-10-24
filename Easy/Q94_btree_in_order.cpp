//Given the root of a binary tree, return the inorder traversal of its nodes' values.


#include <vector>
#include <stack>
using namespace std;

 struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;
        TreeNode* curr = root;

        while(curr!=nullptr || !st.empty()){
            //left traversal
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }