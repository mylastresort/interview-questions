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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> _q;
        vector<vector<int>> ret;
        if (!root) return ret;
        _q.push(root);
        bool _t = true;
        while (_q.size()) {
            size_t sz = _q.size();
            vector<int> level;
            level.reserve(sz);
            for (size_t i = 0; i != sz; i++) {
                auto node = _q.front();
                _q.pop();
                if (node->right) {
                    _q.push(node->right);
                }
                if (node->left) {
                    _q.push(node->left);
                }
                level.push_back(node->val);
            }
            if (level.size()) {
                if (_t)
                    reverse(level.begin(), level.end());
                _t = !_t; 
                ret.push_back(level);
            }
        }
        return ret;
    }
};