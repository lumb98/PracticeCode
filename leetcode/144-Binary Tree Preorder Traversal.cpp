#include <iostream>
#include <vector>
#include <stack>
#include <string>


using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    TreeNode(int x,TreeNode *l,TreeNode *r):val(x),left(l),right(r){}
};

class Solution1{
public:
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> ans;
        if(root==nullptr)
            return ans;
        
        stack<TreeNode*> s;
        
        TreeNode *temp=root;
        while(!s.empty()||temp !=nullptr){
            while(temp!=nullptr){
                s.push(temp);
                ans.push_back(temp->val);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
            temp=temp->right;
        }
        return ans;
    }

};





class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root){
        my_traversal(ans,root);
        return ans;
    }

protected:
    vector<int> ans;
    void my_traversal(vector<int> &ans,TreeNode *root){
        if(root==nullptr)
            return;
        ans.push_back(root->val);
        my_traversal(ans,root->left);
        my_traversal(ans,root->right);
    }

};


int main(void){
    string input;
    getline(cin,input);
    TreeNode inputTree;

}