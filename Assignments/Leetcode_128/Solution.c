class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        unordered_set<int> numSet(nums.begin(), nums.end()); // Create a set for fast lookups
        int longestSequence = 0;

        for (int num : numSet) {
            // Only start counting if it's the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentSequence = 1;

                // Count the consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentSequence += 1;
                }

                // Update the longest sequence length
                longestSequence = max(longestSequence, currentSequence);
            }
        }

        return longestSequence;
    }
};
