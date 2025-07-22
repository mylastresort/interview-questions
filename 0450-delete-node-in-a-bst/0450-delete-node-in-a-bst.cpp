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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1. look for the value, take its double pointer, and delete the old value
        // 2. update the the d pointer with the left node
        // if left of child not found, update with the right node and return
        // if left of child is found, get the right node and start from the current node and insert it

        TreeNode **head = &root;
        TreeNode **node = head;
        TreeNode* right = 0;
        while (*node) {
            if ((*node)->val > key) {
                if ((*node)->left) {
                    node = &((*node)->left);
                } else {
                    node = &((*node)->right);
                }
            } else if ((*node)->val < key) {
                if ((*node)->right) {
                    node = &((*node)->right);
                } else {
                    node = &((*node)->left);
                }
            } else {
                if (!(*node)->left) {
                    *node = (*node)->right;
                } else if (!(*node)->right) {
                    *node = (*node)->left;
                } else {
                    right = (*node)->right;
                    *node = (*node)->left;
                }
                break;
            }
        }

        if (right) {
            while ((*node)->right) {
                if ((*node)->val > right->val) {
                    node = &((*node)->left);
                } else {
                    node = &((*node)->right);
                }
            }
            (*node)->right = right;
        }

        return *head;
    }
};