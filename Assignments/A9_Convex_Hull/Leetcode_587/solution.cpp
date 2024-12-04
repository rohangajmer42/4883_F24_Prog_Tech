class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 3) return trees; // All points are on the hull for <= 3 points

        // Function to calculate cross product
        auto cross = [](const vector<int>& O, const vector<int>& A, const vector<int>& B) {
            return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]);
        };

        // Sort points lexicographically
        sort(trees.begin(), trees.end());

        vector<vector<int>> hull;

        // Build lower hull
        for (const auto& point : trees) {
            while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull[hull.size() - 1], point) < 0) {
                hull.pop_back();
            }
            hull.push_back(point);
        }

        // Build upper hull
        int lowerHullSize = hull.size();
        for (int i = trees.size() - 1; i >= 0; --i) {
            while (hull.size() > lowerHullSize && cross(hull[hull.size() - 2], hull[hull.size() - 1], trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }

        // Remove duplicate points
        hull.pop_back(); // Last point is the same as the first point
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());

        return hull;
    }
};
