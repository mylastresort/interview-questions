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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* head = root;
        while (head) {
            if (head->val > val) {
                if (!head->left) {
                    head->left = new TreeNode(val);
                    break;
                }
                head = head->left;
                continue;
            }
            if (!head->right) {
                head->right = new TreeNode(val);
                break;
            }
            head = head->right;
        }

        return root;
    }
};