#include <bits/stdc++.h>
#include <vector>
#include <list>
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

class LRUCache{
    public:
        LRUCache(){
            total = 0;
            this->capacity = 2;
            buckets = new Node*[bucket_size]; 
            for(int i=0;i<bucket_size;i++){
                buckets[i]=nullptr;
            }
            head = new Node({INT_MIN,0});
            tail = new Node({INT_MAX,0},head,nullptr);
            head->next = tail;
            }
        LRUCache(int capacity){
            total = 0;
            this->capacity = capacity;
            buckets = new Node*[bucket_size]; 
            for(int i=0;i<bucket_size;i++){//之前这里写的是capacity，没有初始化所有的内容！
                buckets[i]=nullptr;
            }
            head = new Node({INT_MIN,0});
            tail = new Node({INT_MAX,0},head,nullptr);
            head->next = tail;
        }
        ~LRUCache() {
        // 析构函数中释放所有动态分配的内存
        delete[] buckets; // 删除指针数组
    }
    
    int get(int key){
        int index = hash(key);
        Node* p = buckets[index];
        if(!p){
            return -1;
        }
        moveToHead(p);
        return p->kv.second;
    }
    void put(int key,int val){
        pair<int,int> pii={key,val};
        if(search(key)==INT_MAX&&isfull()){
            remove();
        }
        insert(pii);
    }
    // put的逻辑之前有问题： 我写的是：先判断是否满，满的话就丢一个（但是我没有考虑到更新的情况）
    int search(int key){
        int index = hash(key);
        if(!buckets[index]){
            return INT_MAX;
        }
        return buckets[index]->kv.second;
    }
    bool isempty(){
        if(total==0){
            return true;
        }
        return false;
    }
    bool isfull(){
        if(total == capacity){
            return true;
        }
        return false;
    }

    void display(){
        Node * p = head->next;
        while(p!=tail){
            cout<<"("<<p->kv.first<<","<<p->kv.second<<")"<<" ";
            p=p->next;
        }   
    }

    private:
    int hash(int key){
        return key % modulus;
    }   
    // LRU都是从头插入，然后从尾删除
    void insert(pair<int,int>&pii){
        // cout<<pii.first<<" ";
        int index = hash(pii.first);
        Node* node = buckets[index];
        if(!node){
            Node* p=new Node(pii,head->next,head); //head->p->tail->head
            p->next->prev = p;
            head->next = p;
            buckets[index] = p;
            total++;
        }else{
            node->kv.second = pii.second;
            moveToHead(node);//如果说这个kv pair已存在的话，刷新他的位置
        }
    }
    void moveToHead(Node* node){
        // node前后节点
        node->prev->next = node->next; //node前一个节点的next指针域修改
        node->next->prev = node->prev; //node后一个节点的prev指针域
        head->next->prev = node;   // head后一个节点的prev指针域
        node->next = head->next;  //  node的next指针域
        node->prev = head;
        head->next = node ;
    }
    void remove(){
        Node* p = tail->prev->prev;
        int key = tail->prev->kv.first;
        int index = hash(key);
        buckets[index]=nullptr;
        delete(tail->prev); //这里没有把桶内的指针=null?

        
        p->next = tail;
        tail->prev = p;
        total--;
    }
        const int modulus=7499;
        int capacity,total;
        Node** buckets;
        Node* head;
        Node* tail;
        const int bucket_size = 3500;
};

void test(){
    LRUCache lru(20);
    for(int i=1;i<51;i++){
        lru.put(i,i);
    }
    
   
    
    for(int i = 31; i <= 50; i++) {
        assert(lru.get(i) == i); // 确认键i存在且值正确
    }
    // 确认前30个插入的键已经被移除
    for(int i = 1; i <= 30; i++) {
        // cout<<i;
        assert(lru.get(i) == -1); // 确认键i已被移除
    }
    
    lru.put(31,35);
    lru.put(33,22);
    // cout<<lru.get(1);
    std::cout << "All tests passed successfully." << std::endl;

    lru.display();
    cout<<endl;
}
void test14(){
    LRUCache lru(2); // 步骤1：初始化LRUCache

    assert(lru.get(2) == -1); // 步骤2：预期返回-1

    lru.put(2, 6); // 步骤3：添加键值对(2,6)

    assert(lru.get(1) == -1); // 步骤4：预期返回-1

    lru.put(1, 5); // 步骤5：添加键值对(1,5)
    lru.put(1, 2); // 步骤6：更新键1的值为2

    assert(lru.get(1) == 2); // 步骤7：预期返回2
    assert(lru.get(2) == 6); // 步骤8：预期返回6

    std::cout << "All tests passed successfully." << std::endl;

}
// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],       [1,1],[2,2], [1], [3,3],[2],  [4,4],[1],   [3],  [4]]

int main(){
    


   test14();
}