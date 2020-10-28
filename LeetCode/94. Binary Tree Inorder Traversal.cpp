/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		if (root == nullptr)
			return pre;
		inorderTraversal(root->left);
		if (root != nullptr)
			pre.push_back(root->val);
		inorderTraversal(root->right);
		return pre;
	}
	vector<int> pre;
};
