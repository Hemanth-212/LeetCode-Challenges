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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode *r=new TreeNode(v);
            r->left=root;
            return r;
        }
        else
        {
            queue<TreeNode*>q;
            q.push(root);
            int i,n;
            --d;
            
            /* Level order traversal or BFS is preformed till 
               d-1 level */
            while(q.size() && --d)
            {
                n=q.size();
                for(i=0;i<n;++i)
                {
                    TreeNode *r=q.front();
                    q.pop();
                    if(r->left)q.push(r->left);
                    if(r->right)q.push(r->right);
                }
            }
            while(q.size()){   
                TreeNode *r=q.front();
                //cout<<r->val<<" ";
                q.pop();
                TreeNode *r1=new TreeNode(v);
                TreeNode *r2=new TreeNode(v);
                r1->left=r->left;
                r2->right=r->right;
                r->left=r1;
                r->right=r2;
            }
            return root;
        }
        
    }
};