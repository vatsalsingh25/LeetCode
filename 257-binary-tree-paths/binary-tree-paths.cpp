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
    void func(TreeNode* root,vector<string> &ans,string temp){
        if(root==nullptr) return;
        temp+=to_string(root->val);

        if(root->left==nullptr && root->right==nullptr) ans.push_back(temp);
        else {
            temp+="->";
            func(root->left,ans,temp);
            func(root->right,ans,temp);
        }
        temp.pop_back();    
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        func(root,ans,temp);
        return ans;
    }
};