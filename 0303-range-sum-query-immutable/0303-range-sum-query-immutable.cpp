class NumArray {
public:
    std::vector<int> pf;

    NumArray(vector<int>& nums) {
        auto sum = 0;
        for (auto i : nums) {
            sum += i;
            pf.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int left_minus_1 = 0;
        if (left > 0) {
            left_minus_1 = this->pf[left - 1];
        }
        return this->pf[right] - left_minus_1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */