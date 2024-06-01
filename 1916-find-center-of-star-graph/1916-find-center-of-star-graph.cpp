class Solution {
public:
    int findCenter(const vector<vector<int>>& edges) {
        const auto &vertex1 = edges[0];
        const auto &vertex2 = edges[1];
        if (vertex1[0] == vertex2[0] || vertex1[0] == vertex2[1])
            return vertex1[0];
        return vertex1[1];
    }
};