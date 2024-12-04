/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;  // store the level order traversal
        
        if (!root) return result;    // If the root is null, return an empty result
        
        queue<TreeNode*> q;          
        q.push(root);                // Start with the root node
        
        while (!q.empty()) {
            int levelSize = q.size();   
            vector<int> currentLevel;   
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();  // Get the front node from the queue
                q.pop();                     

                                
                currentLevel.push_back(node->val);  // Add the node's value to the current level
                
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
            
            
            result.push_back(currentLevel);
        }
        
        return result;  // Return the final level order traversal
    }
};
