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


//递归方法： 注意递归钱要确定孩子不是空指针。
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return root;
        TreeNode*ans=root;
        my_invert(root);
        return ans;
    }
protected:
    void my_invert(TreeNode* root){
        if(root->left==root->right)
            return;
        if(root->left!=nullptr)my_invert(root->left);
        if(root->right!=nullptr)my_invert(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }

};