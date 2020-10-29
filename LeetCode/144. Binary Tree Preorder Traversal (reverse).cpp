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
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        if (root == nullptr)
            return vec;
        
        stack<TreeNode *> stk;

        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                vec.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return vec;
    }
};
