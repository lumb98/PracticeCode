#include <iostream>
#include <vector>
#include <stack>
#include <string>
/*
* 后序遍历要记住，只有在右孩子走到头或者有孩子是上一个被保存的节点时才进行输出。其他情况都入栈。
* 中序遍历要记住，只有走到头后就输出，然后往右转。
* 前序遍历要记住，往左走，只要走一步就输出一个。
*/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        stack<TreeNode*> s;
        TreeNode *node =root;
        TreeNode *prev=nullptr;
        while(!s.empty()||node!=nullptr){
            while(node!=nullptr){//走到头了
                s.push(node);
                node=node->left;//内循环只管往里走
            }
            node=s.top();     //走到头之后
            s.pop();
            if(node->right==nullptr||node->right==prev){
                ans.push_back(node->val);   //把这个头存起来。
                prev=node;
                node=nullptr;
            }else{
                s.push(node);
                node=node->right;
            }
        }
        return ans;
    }
};





class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        traversal(root,ans);
        return ans;
    }
private:
    void traversal(TreeNode *root , vector<int> &ans){
        if(root==nullptr)
            return;
        traversal(root->left,ans);
        traversal(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> ans;

};