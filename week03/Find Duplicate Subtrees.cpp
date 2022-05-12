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
    map<string, vector<TreeNode*>> dupSub;
    string dfsTraverse(TreeNode* root){
        long long m=1000000007;
        string leftHashVal="#", rightHashVal="#", hshVal=to_string(root->val);
        if(root->left!=NULL)
            leftHashVal=dfsTraverse(root->left);
        if(root->right!=NULL)
            rightHashVal=dfsTraverse(root->right);
        hshVal+=","+leftHashVal+","+rightHashVal;
        if(dupSub.count(hshVal)<=1)
            dupSub[hshVal].push_back(root);
        return hshVal;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplSubTree;
        if(root!=NULL){
            dfsTraverse(root);
            for(auto it: dupSub){
                if(it.second.size()>1){
                    duplSubTree.push_back(it.second[0]);
                }
            }
            return duplSubTree;
        }
        return {};
    }
};