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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, pair<TreeNode *, TreeNode *>> mp;

        for(int i=0; i<n; i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            bool isParent = (mp.find(parent) != mp.end());
            bool isChild = (mp.find(child) != mp.end());

            if(!isParent and !isChild){
                TreeNode *p = new TreeNode(parent);
                TreeNode *c = new TreeNode(child);

                if(isLeft)
                p->left = c;
                else
                p->right = c;

                mp[parent] = {p, NULL};
                mp[child] = {c, p};
            }
            else if(isParent and !isChild){                
                TreeNode *c = new TreeNode(child);
                auto it = mp[parent];
                TreeNode *p = it.first;

                if(isLeft)
                p->left = c;
                else
                p->right = c;               
                mp[child] = {c, p};
            }
            else if(!isParent and isChild){                
                TreeNode *p = new TreeNode(parent);
                auto it = mp[child];
                TreeNode *c = it.first;

                if(isLeft)
                p->left = c;
                else
                p->right = c;

                mp[child] = {c, p};
                mp[parent] = {p, NULL};
            }
            else if(isParent and isChild){                
                auto it1 = mp[parent];
                auto it2 = mp[child];
                TreeNode *p = it1.first;
                TreeNode *c = it2.first;

                if(isLeft)
                p->left = c;
                else
                p->right = c;

                mp[child] = {c, p};
                mp[parent] = {p, it1.second};
            }      
        } 
        
        for(auto it: mp){
            if(it.second.second==NULL)
            return it.second.first;
        }    
          return NULL;
    }
};