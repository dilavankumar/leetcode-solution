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
TreeNode* build(vector<int>& inorder, vector<int>& postorder,int &postIndex,int inStart,int inEnd,unordered_map<int,int>&mp){
    if(inStart>inEnd) return NULL;
    TreeNode* root=new TreeNode(postorder[postIndex]);
    postorder[postIndex--];
    int inIndex=mp[root->val];
    root->right=build(inorder,postorder,postIndex,inIndex+1,inEnd,mp);
    root->left=build(inorder,postorder,postIndex,inStart,inIndex-1,mp);
    
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int postIndex=postorder.size()-1;
        return build(inorder,postorder,postIndex,0,inorder.size()-1,mp);
        
    }
};