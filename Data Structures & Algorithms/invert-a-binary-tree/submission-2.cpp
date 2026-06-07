/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    TreeNode* dfsMethod1(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* node = new TreeNode(root->val);
        node->right = invertTree(root->left);
        node->left = invertTree(root->right);
        return node;
    }
    TreeNode* dfsMethod2(TreeNode* root) {
        if(!root) return nullptr;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            swap(node->left, node->right);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return root;
    }
    TreeNode* bfs(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            swap(node->left, node->right);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        // return dfsMethod1(root);
        // return dfsMethod2(root);
        return bfs(root);
    }
};
