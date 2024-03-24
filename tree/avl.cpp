#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
        int val;
        int height;
        TreeNode* left;
        TreeNode* right;
        TreeNode():val(-1){}
        TreeNode(int val):val(val){}
};
class AVL{
    public:
    bool insert(int val);
    bool remove(int val);
    TreeNode* search(int val);
    int height(TreeNode* node){
        return node==nullptr?-1:node->height;
    }
    // 叶子结点高度为0
    // 2        A
    // 1    B       C 
    // 0  D  E    F   G 

    // max(左,右子树)高度+1
    void updateHeight(TreeNode* node){
        node->height = max(height(node->left),height(node->right))+1;
    }
    

    // 平衡因子： 左子树高度-右子树高度
    int BalanceFactor(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        
        return height(node->left)-height(node->right);
    }
};

bool AVL::insert(int val){

}

bool AVL::remove(int val){
    
}
TreeNode* AVL::search(int val){
    
}