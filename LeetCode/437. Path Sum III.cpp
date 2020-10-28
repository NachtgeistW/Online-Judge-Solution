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
	int pathSum(TreeNode *root, int sum) {
        if (root == nullptr) return 0;
        int pathImLeading = count(root, sum);  // 自己为开头的路径数
        int leftPathSum = pathSum(root->left, sum);  // 左边路径总数（相信它能算出来）
        int rightPathSum = pathSum(root->right, sum);  // 右边路径总数（相信它能算出来）
        return leftPathSum + rightPathSum + pathImLeading;
    }
    int count(TreeNode *node, int sum) {
        if (node == nullptr) return 0;
        // 我自己能不能作为一条单独的路径呢？
        int isMe = (node->val == sum) ? 1 : 0;
        // 左边的，你那边能凑几个 sum - node.val ？
        int leftNode = count(node->left, sum - node->val);
        // 右边的，你那边能凑几个 sum - node.val ？
        int rightNode = count(node->right, sum - node->val);
        return isMe + leftNode + rightNode;  // 我这能凑这么多个
    }
};
