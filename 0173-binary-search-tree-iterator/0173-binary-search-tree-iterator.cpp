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
class BSTIterator {
public:
    stack<TreeNode*> _st;
    BSTIterator(TreeNode* root) {
        if (!root)
            return;
        _st.push(root);
        while (_st.top()->left) {
            _st.push(_st.top()->left);
        }
    }

    int next() {
        if (!hasNext()) return -1;
        auto it = _st.top();
        _st.pop();
        if (it->right) {
            _st.push(it->right);
            while (_st.top()->left) {
                _st.push(_st.top()->left);
            }
        }
        return it->val;
    }

    bool hasNext() { return _st.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */