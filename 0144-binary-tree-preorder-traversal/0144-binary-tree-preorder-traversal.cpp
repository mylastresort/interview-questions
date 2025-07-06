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
    vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> st;
        std::stack<int> dir;
        vector<int> ret;

        if (root) {
            st.push(root);
            dir.push(0);
        }

        while (!st.empty()) {
            auto cur = st.top();
            auto d = dir.top();

            switch (d) {
            case 0: // nothing is visited
                ret.push_back(cur->val);
                if (cur->left) {
                    st.push(cur->left);
                    dir.push(0);
                    continue;
                }
                dir.pop();
                dir.push(1);
                if (cur->right) {
                    st.push(cur->right);
                    dir.push(0);
                    continue;
                }
                dir.pop();
                dir.push(2);
            case 1: // left is visited
                if (cur->right) {
                    st.push(cur->right);
                    dir.push(0);
                    continue;
                }
                dir.pop();
                dir.push(2);
            case 2: // right is visited
                dir.pop();
                // ret.push_back(cur->val);
                st.pop();
                if (!st.empty()) {
                    if (dir.top() == 0) {
                        dir.pop();
                        dir.push(1);
                    } else {
                        dir.pop();
                        dir.push(2);
                    }
                }
            }
        }

        return ret;
    }
};