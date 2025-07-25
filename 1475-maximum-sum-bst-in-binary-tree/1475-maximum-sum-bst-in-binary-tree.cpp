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
    int sum;
    bool bst;
    int min;
    int max;

    Sol(bool bst, int sum, int min, int max)
        : sum(sum), bst(bst), min(min), max(max) {}
};

class Solution {
public:
    Sol _max(TreeNode* root, int& m) {
        Sol sol(true, root->val, root->val, root->val);
        Sol l = !root->left ? Sol(true, 0, INT32_MAX, root->val - 1)
                            : _max(root->left, m);
        Sol r = !root->right ? Sol(true, 0, root->val + 1, INT32_MIN)
                             : _max(root->right, m);

        cout << "l-sum: " << l.sum << endl;
        cout << "r-sum: " << r.sum << endl;

        if (l.bst && r.bst && root->val > l.max && root->val < r.min) {
            int sum = l.sum + r.sum + root->val;
            m = max(m, sum);
            return Sol(true, sum, min(l.min, root->val), max(r.max, root->val));
        }
        return Sol(false, max(l.sum, r.sum), l.min, r.max);
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        _max(root, sum);
        return sum;
    }
};