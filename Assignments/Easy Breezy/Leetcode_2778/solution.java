class Solution {
    public int sumOfSquares(int[] nums) {
        int n = nums.length;
        int sum = 0;

        // Iterate through each index in the array (1-indexed)
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {  // Check if i divides n
                sum += nums[i - 1] * nums[i - 1];  // Square the special element and add to sum
            }
        }
        
        return sum;
    }
}
