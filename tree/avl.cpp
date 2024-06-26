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
    /* 右旋操作 */
TreeNode *rightRotate(TreeNode *node) {
    TreeNode *child = node->left;
    TreeNode *grandChild = child->right;     //     N
    // 以 child 为原点，将 node 向右旋转             C
    child->right = node;                     //     Grand   
    node->left = grandChild;                     //
    // 更新节点高度
    updateHeight(node);
    updateHeight(child);
    // 返回旋转后子树的根节点
    return child;
}
TreeNode* leftRotate(TreeNode* node){
    TreeNode* child = node->right;
    TreeNode* grandChild = child->left; 
    child->left = node;
    node->right = grandChild;
    updateHeight(node);
    updateHeight(child);
}
// always fulfill with this law: L<Root<R 
// Thus, after rotation, the law still be fulfilled.
//  when doing left rotation: it means the imbalance node should do rotate to left.
// a               b
//   b          a     c
// bl     c       bl
// before: it has a<b<c; after rotation, it's still fulfilled.
// a<b and its subtree: a<bl<b<c => after rotating: a<bl<b<c
};

bool AVL::insert(int val){

}

bool AVL::remove(int val){
    
}
TreeNode* AVL::search(int val){
    
}