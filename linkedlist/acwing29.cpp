// /**
#include <bits/stdc++.h>


using namespace std;

  struct ListNode {
    int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x,ListNode* next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* dummy=new ListNode(-1),*q=head->next,*p=dummy;
        p->next=head;
        
        while(q!=nullptr){
            // printf("test0");

            if(p->next->val==q->val){
                ListNode* r=q->next;
                //  printf("test1");
                // 这里 由于r是有可能为null的，应该先判断r是否为null再进行值判断
                while(r!=nullptr&& r->val==q->val){
                // while(r->val==q->val&&r!=nullptr){ 有问题！
                    r=r->next;
                }// if condition
               
                p->next=r; //[4 4 4]
                if(r!=nullptr){
                    q=r->next;
                }else{
                    // printf("test2 ");
    
                    return dummy->next; //return null?
                }
            }else{
                // printf("test3");

                p=p->next;
                q=q->next;
            }
            
        }//while loop 
        
        return dummy->next;
    }
};


int main(){
    Solution s;
    ListNode* l1=new ListNode(4);
    ListNode* l2=new ListNode(4,l1); // l2: next =l1
    ListNode* head=new ListNode(4,l2);//l3 :next l2
// 
// while(head!=nullptr){
//     cout<<head->val<<" ";
//     head=head->next;
// }
    s.deleteDuplication(head);
}