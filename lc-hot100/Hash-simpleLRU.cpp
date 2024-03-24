#include <iostream>
#include <vector>

using namespace std;



class Node{
    public:
    pair<int,int>kv;
    Node* next;
    Node* prev;
    Node(){}
    Node(pair<int,int>pii):kv(pii){}
    Node(pair<int,int>pii,Node* next,Node* prev):kv(pii),next(next),prev(prev){}

};
class List{
    public:
        List(){
            head=nullptr;
            tail=nullptr;
        }
        bool empty(){
            if(head==nullptr&& tail==nullptr){
                return true;
            }
            return false;
        }



    // LRU都是从头插入，然后从尾删除
        void insert(pair<int,int>&pii){
            Node* p=new Node(pii,head,tail);
            if(tail==nullptr&&head==nullptr){
                head=p;
                tail=p;
            }//这里考虑的是不带头节点的插入情况，第一个节点插入需特殊处理
            else{ 
            tail->next=p;
            head->prev=p;
            }
        }
        void remove(){
            Node* p=tail->prev;
            p->next=head;
            head->prev=p;
            delete(tail);
            tail=p;
        }//这里只删除，tail==空的情况由上层处理
        
        pair<int,int>*  search(int key){
            pair<int,int>* pii=nullptr;
            Node* p=head;
            while(p!=nullptr){
                if(p->kv.first==key){
                    pii=&p->kv;
                }
                p=p->next;
            }
            return pii;
        }
        Node* head,* tail;
};
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        pair<int,int>* pii = list.search(key);
        
    }
    
    void put(int key, int value) {

    }
    int capacity;
    List list;
};
int main(){
    vector<int>v;
    v.push_back(1);
}