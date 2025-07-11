class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());

        while (heap.size() > 1) {
            auto first = heap.top();
            heap.pop();
            
            auto second = heap.top();
            heap.pop();

            heap.push(first - second);
        }

        return heap.top();
    }
};