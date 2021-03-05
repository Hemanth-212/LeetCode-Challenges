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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v; // vector to store averages 
        queue<TreeNode*>q;
        int i,n;
        if(root)
        {
            q.push(root);
        }
        
        /* Level order traversal using queue */
        while(q.size())
        {
            n=q.size(); // No of nodes at a particular level
            double sum=0;
            for(i=0;i<n;++i)
            {
                TreeNode *r=q.front();
                q.pop();
                sum+=r->val;
                if(r->left)
                {
                    q.push(r->left);      
                }
                if(r->right)
                {
                    q.push(r->right);
                }
            }
            v.push_back(sum/n);
        }
        return v;
    }
};