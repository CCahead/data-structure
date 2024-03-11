#include <iostream>

using namespace std;

// 小根堆： left,right>=root
class MyHeap{
    public:
        void push(int elem);
        void pop(int &elem);
        void display();
    private:
        void heapify(int location){
            int left,right,mid;
            while(true){
                if(heap[left]>=heap[right]){
                    swap(heap[left],heap[mid]);
                    mid=left;
                }
            }
        }
        int heap[100];
        int size;
};



void MyHeap::push(int elem){
    heap[size++]=elem;
    heapify(size-1);
}

void MyHeap::pop(int &elem){
    elem=heap[0];
    swap(heap[0],heap[size--]);
    size--;
    heapify(0);//自顶向下堆化
}

void MyHeap::display(){

}