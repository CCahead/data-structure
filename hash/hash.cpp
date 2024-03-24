#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int key;//4
        int val;//4
        Node* next; //12?
        Node(){}
        Node(int key,int val):key(key),val(val){}
        Node(int key,int val,Node* next):key(key),val(val),next(next){}
};
// v[1]-> Node...
class Hash{
    public:
        Hash(){
            size=100;
            v.resize(size);
            // v=vector<Node*>(100);
            for(auto &bucket:v){
                bucket=new Node(INT_MIN,0);
            }
        }
        Hash(int size){
            this->size=size;
            v.resize(this->size);
            for(auto &bucket:v){
                bucket=new Node(INT_MIN,0);
            }
            // 这里之前写的auto bucket:v 导致没有办法改变bucket的指向值，buckets全为nullptr
        }
        void insert(int key,int val);
        void remove(int key);
        void search(int key);
        void display();
    private:
        vector<Node*>v;
        int module=100,size;
        // 这一步合并操作：hash直接返回桶索引
        Node* hash(int key){
            return v[key%module];
        }
};

void Hash::insert(int key,int val){
    Node* bucket=hash(key),*p = bucket;
    bool flag=false;
    while(p->next!=nullptr){
        if(p->key==key){
            p->val=val;
            flag=true;
            bucket->val++;
            break;
        }
        p=p->next;
    }
    if(!flag){
        Node* q=new Node(key,val,bucket->next);
        bucket->next=q;
        bucket->val++;
    }
}
void Hash::remove(int key){
    Node* bucket = hash(key),*p=bucket,*q=bucket->next;
    while(q!=nullptr){
        if(p->key==key){
            bucket->val--;
            p->next=q->next;
            break;
        }
        p=p->next;
        q=q->next;
    }
}
void Hash::search(int key){
    Node* bucket = hash(key),*p=bucket;
    while(p->next!=nullptr){
        if(p->key==key){
            cout<<key<<" "<<p->val<<endl;
            break;
        }
        p=p->next;
    }
}
void Hash::display(){
    for(auto bucket:v){
        if(bucket->val==0){
            continue;
        }
        Node* p=bucket->next;
        while(p!=nullptr){
            cout<<p->key<<" "<<p->val<<endl;
            p=p->next;
        }
    }
}
// hashtable可以实现O（1）访问，那请问谁来把这个key值记录下来呢？我存了，但怎么取？谁来取？
int main(){
    Hash hash;
    hash.insert(1,1);
    hash.insert(2,1);
    hash.insert(3,1);
    hash.search(1);
    hash.display();
}