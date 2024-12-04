class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the top k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element
            }
        }

        // The root of the heap is the k-th largest element
        return minHeap.top();
    }
};
