class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<vector<int>>(1, vector<int>());

        vector<int> n(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = this->permute(n);
        vector<vector<int>> res;

        for (auto p : perms) {
            for (int i = 0; i != p.size(); i++) {
                vector<int> perm(p.size() + 1);
                for (int j = 0, _j = 0; j != p.size() + 1; j++) {
                    if (j == i) {
                        perm[j] = nums[0];
                    } else {
                        perm[j] = p[_j];
                        _j++;
                    }
                }
                res.push_back(perm);
            }
            vector<int> perm(p.begin(), p.end());
            perm.push_back(nums[0]);
            res.push_back(perm);
        }
        return res;
    }
};
