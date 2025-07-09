class Solution {
public:
    string stringHash(string s, int k) {
        string result;
        result.resize(s.size() / k);

        for (int sum = 0, i = 0; i != s.size(); i++) {
            sum += s[i] - 'a';
            if ((i + 1) % k == 0) {
                result[i / k] = 'a' + sum % 26;
                sum = 0;
            }
        }

        return result;
    }
};