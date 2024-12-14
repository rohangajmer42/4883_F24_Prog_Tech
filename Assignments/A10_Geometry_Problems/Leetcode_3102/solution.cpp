class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> xySum, xyDiff;
        for (const auto& point : points) {
            int x = point[0], y = point[1];
            xySum.push_back(x + y);
            xyDiff.push_back(x - y);
        }

        // Precompute max and min for both x + y and x - y
        int maxSum = INT_MIN, secondMaxSum = INT_MIN;
        int minSum = INT_MAX, secondMinSum = INT_MAX;
        int maxDiff = INT_MIN, secondMaxDiff = INT_MIN;
        int minDiff = INT_MAX, secondMinDiff = INT_MAX;

        for (int i = 0; i < n; i++) {
            // Update max and second max for xySum
            if (xySum[i] > maxSum) {
                secondMaxSum = maxSum;
                maxSum = xySum[i];
            } else if (xySum[i] > secondMaxSum) {
                secondMaxSum = xySum[i];
            }

            // Update min and second min for xySum
            if (xySum[i] < minSum) {
                secondMinSum = minSum;
                minSum = xySum[i];
            } else if (xySum[i] < secondMinSum) {
                secondMinSum = xySum[i];
            }

            // Update max and second max for xyDiff
            if (xyDiff[i] > maxDiff) {
                secondMaxDiff = maxDiff;
                maxDiff = xyDiff[i];
            } else if (xyDiff[i] > secondMaxDiff) {
                secondMaxDiff = xyDiff[i];
            }

            // Update min and second min for xyDiff
            if (xyDiff[i] < minDiff) {
                secondMinDiff = minDiff;
                minDiff = xyDiff[i];
            } else if (xyDiff[i] < secondMinDiff) {
                secondMinDiff = xyDiff[i];
            }
        }

        // Resultant minimum maximum distance
        int result = INT_MAX;

        for (int i = 0; i < n; i++) {
            // Determine new max and min for xySum when removing points[i]
            int newMaxSum = (xySum[i] == maxSum) ? secondMaxSum : maxSum;
            int newMinSum = (xySum[i] == minSum) ? secondMinSum : minSum;

            // Determine new max and min for xyDiff when removing points[i]
            int newMaxDiff = (xyDiff[i] == maxDiff) ? secondMaxDiff : maxDiff;
            int newMinDiff = (xyDiff[i] == minDiff) ? secondMinDiff : minDiff;

            // Compute the new maximum distance
            int newMaxDist = max(newMaxSum - newMinSum, newMaxDiff - newMinDiff);
            result = min(result, newMaxDist);
        }

        return result;
    }
};
