#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x):val(x),left(nullptr),right(nullptr){}
        TreeNode():val(-1),left(nullptr),right(nullptr){}
};
class BiSearchTree{
    public:
        TreeNode* root;
        BiSearchTree(){
            root=new TreeNode();
        }
        BiSearchTree(int val){
            root=new TreeNode(val);
        }
        bool Insert(int val);
        bool Delete(int val);
        TreeNode* Search(int val);
        void PreOrderTraverse(TreeNode* t);
        void InOrderTraverse(TreeNode* t);
        void PostOrderTraverse(TreeNode* t);
};
bool BiSearchTree::Insert(int val){
    TreeNode* pre=root,*cur=pre;
    while(cur!=nullptr){
        pre=cur;
        if(cur->val>val){
            cur=cur->left;
        }else if(cur->val<val){
            cur=cur->right;
            
        }else if(cur->val==val){
            return false;
        }
    }
    cur=new TreeNode(val);
    if(pre->val>val){
        
        pre->left=cur; 
    }else{
        pre->right=cur;
    }
    return true;
    
}
bool BiSearchTree::Delete(int val){
    TreeNode* p=root;
    
}
TreeNode* BiSearchTree::Search(int val){
    TreeNode* p=root;
    while(1){
        if(p->val<val){
            p=p->right;
        }else if(p->val>val){
            p=p->left;
        }else if(p->val==val){

            return p;
        }
        else if(p==nullptr){
            return p;
        }
    }
}

bool BiSearchTree::Delete(int val){
    TreeNode* cur=root,*pre=cur;
    while(1){
        if(cur->val==val){
            break;
        }
        pre=cur;
        if(cur->val>val){
            cur=cur->left;
        }else if(cur->val<val){
            cur= cur->right;
        }
    }
    // 找到cur节点
    if(cur==nullptr){
        return false;
    }
// 看cur孩子为0或者1的情况
    if(cur->left==nullptr|| cur->right==nullptr){
        TreeNode* child= cur->left!=nullptr?cur->left:cur->right;
         // 删除节点 cur
        if (cur != root) {
            if (pre->left == cur)
                pre->left = child;
            else
                pre->right = child;
        } else {
            // 若删除节点为根节点，则重新指定根节点
            root = child;
        }
    }//condition 1
    // 有2个孩子:
    // 在中序遍历的情况下，cur的下一个节点只有两种情况：cur的右孩子或者cur右子树的最左孩子

    else{
        TreeNode* tmp=cur->right;
        while(tmp->left!=nullptr){
            tmp=tmp->left;
        }//这一步是找右子树的最左孩子
        int tmpVal = tmp->val;
        // 递归删除节点 tmp
        Delete(tmp->val);
        // 用 tmp 覆盖 cur
        cur->val = tmpVal;
        // 这一步非常巧妙啊，它并不改变这个树的结构，他直接把data域改了
    }//condition 2

    
}
void BiSearchTree::PreOrderTraverse(TreeNode* t){
    if(t==nullptr){
        return ;
    }
    cout<<t->val<< " ";
    PreOrderTraverse(t->left);
    PreOrderTraverse(t->right);

}
void BiSearchTree::InOrderTraverse(TreeNode* t){
    if(t==nullptr){
        return ;
    }
    InOrderTraverse(t->left);
    cout<<t->val<< " ";
    InOrderTraverse(t->right);

}
void BiSearchTree::PostOrderTraverse(TreeNode* t){
    if(t==nullptr){
        return ;
    }
    PostOrderTraverse(t->left);
    PostOrderTraverse(t->right);
    cout<<t->val<< " ";

}


int main(){
    BiSearchTree bt(5);
    vector<int>v={3,8,2,4,7,9};
    for(auto it:v){
        bt.Insert(it);
    }
    bt.PreOrderTraverse(bt.root);
    cout<<endl;
    bt.InOrderTraverse(bt.root);
    cout<<endl;
    bt.PostOrderTraverse(bt.root);
}