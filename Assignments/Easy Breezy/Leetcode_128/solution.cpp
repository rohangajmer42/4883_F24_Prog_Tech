class Solution {
public:
    unordered_map<int, int> parent, size;
    int ans = 0;
    
    void make(int u) {
        parent[u] = u;
        size[u] = 1;
        ans = max(ans, 1);
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]); // Path compression
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] > size[b]) {
                swap(a, b);
            }
            parent[a] = b;
            size[b] += size[a];
            ans = max(ans, size[b]);
        }
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Iterate through all the numbers
        for (int num : nums) {
            if (parent.find(num) != parent.end()) continue;  // Skip if already processed
            
            make(num);  // Initialize the number in the set

            if (parent.find(num - 1) != parent.end()) Union(num, num - 1);  // Union with the left neighbor
            if (parent.find(num + 1) != parent.end()) Union(num, num + 1);  // Union with the right neighbor
        }
        return ans;
    }
};
