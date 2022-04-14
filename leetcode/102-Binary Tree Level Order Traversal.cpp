#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>


using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    TreeNode(int x,TreeNode *l,TreeNode *r):val(x),left(l),right(r){}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) 
            return ans;
        queue<TreeNode*> sans,snext;
        snext.push(root);
        while(!snext.empty()){
            swap(snext,sans);
            vector<int> temp;
            while(!sans.empty()){
                TreeNode *node=sans.front();
                sans.pop();
                
                temp.push_back(node->val);

                if(node->left!=nullptr) snext.push(node->left);
                if(node->right!=nullptr) snext.push(node->right);
                
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};