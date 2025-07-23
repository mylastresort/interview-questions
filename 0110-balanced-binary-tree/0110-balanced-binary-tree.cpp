/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct Sol {
    int depth;
    bool balanced;

    Sol(int _d, bool _b): depth(_d), balanced(_b) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return _isBalanced(root).balanced;
    }

    Sol _isBalanced(TreeNode* root, int depth = 0) {
        auto l = Sol(depth, true);
        if (!root) return l;
        if (root->left)
            l = _isBalanced(root->left, depth + 1);
        if (!l.balanced) return l;
        auto r = Sol(depth, true);
        if (root->right)
            r = _isBalanced(root->right, depth + 1);
        if (!r.balanced) return r;
        if (abs(l.depth - r.depth) <= 1) {
            return Sol(max(l.depth, r.depth), true);
        }
        return Sol(l.depth, false);
    }
};