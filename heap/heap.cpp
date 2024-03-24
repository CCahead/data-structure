#include <iostream>

using namespace std;

// 小根堆： left,right>=root
class MyHeap{
    public:
        void push(int elem);
        void pop(int &elem);
        void display();
    private:
    // 从上往下
        void siftDown(int location){
            
            while(1){
                int left=leftchild(location),right=rightchild(location),mid=location;
                if(left<size&&heap[left]<heap[mid]){
                   mid=left;//如果说left<mid的话，mid指向左孩子
                }
                if(right<size&&heap[right]<heap[mid]){
                   mid=right;//左孩子或者根结点跟右侧节点比较，看哪个小：如果说右边更小就把mid指向右孩子
                }
                if(mid==location){
                    break;
                }//这里很重要 这是出堆条件
                swap(heap[mid],heap[location]);
                location=mid;
            }
        }
        // 从底向上堆化
        void siftUp(int location){
            while(1){
                int p=parent(location);
                if(p<1||heap[p]<heap[location]){
                    break;
                }
                // 如果说root<location，堆的条件已经满足了；或者说heap已经到达堆顶：
                // parent(0)=-1 这个时候出堆
                swap(heap[location],heap[p]);
                location=p;
            }
        }
        int leftchild(int loc){
            return loc*2;
        }
        int rightchild(int loc){
            return loc*2+1;
        }
        int parent(int loc){
            return loc/2;
        }
        int heap[100];
        int size;
};



void MyHeap::push(int elem){
    // 从数组下标1开始计数
    heap[++size]=elem;
    
    // 这时候size=1 也从
    siftUp(size);//从堆底往上堆化
}
// 3个元素 0 1 2

void MyHeap::pop(int &elem){
    elem=heap[1];
    swap(heap[1],heap[size--]);
    siftDown(1);//自顶向下堆化
}

void MyHeap::display(){
    cout<<endl;
    for(int i=1;i<=size;i++){
        cout<<heap[i]<<" ";
    }
}


int main(){
    MyHeap heap;
    
    for(int i=3;i>=0;i--){
        heap.push(i);
    }
    int a;
    heap.display();
    heap.push(-1);
    heap.display();

    heap.pop(a);
    heap.display();

}