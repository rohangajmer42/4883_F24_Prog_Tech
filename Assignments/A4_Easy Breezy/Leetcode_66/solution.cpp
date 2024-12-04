class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the array from the last digit to the first
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                // If the current digit is less than 9, just add 1 and return
                digits[i]++;
                return digits;
            }
            // If the digit is 9, change it to 0
            digits[i] = 0;
        }
        
        // If all digits were 9, the resulting array will be like [0, 0, ..., 0]
        // Thus, we need to add a 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
