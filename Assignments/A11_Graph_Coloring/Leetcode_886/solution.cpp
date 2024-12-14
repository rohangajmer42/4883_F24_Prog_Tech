class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // Create an adjacency list
        vector<vector<int>> graph(n + 1);
        for (const auto& dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }

        // Vector to track colors, -1 means uncolored
        vector<int> color(n + 1, -1);

        // BFS to check bipartition
        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1) { // Not colored
                queue<int> q;
                q.push(i);
                color[i] = 0; // Start coloring with 0

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int neighbor : graph[curr]) {
                        if (color[neighbor] == -1) {
                            // Color with the opposite color
                            color[neighbor] = 1 - color[curr];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[curr]) {
                            // Same color on both sides, not bipartite
                            return false;
                        }
                    }
                }
            }
        }

        return true; // Successfully colored bipartite graph
    }
};
