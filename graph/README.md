一、首先 弄清楚 几个数组的含义，然后再去 看 邻接表的表示代码，发现容易理解一些，在这里再次回顾下几个数组的含义：

idx的初始值是0，这里其实是和数组模拟单链表那里是一样的


h[N] : 表示 第 i 个节点的 第一条边的 idx
ne[M] : 表示 与 第 idx 条边 同起点 的 下一条边 的 idx(next edge)
e[M] : 表示 第idx 条边的 终点(edge)

N ： 节点数量
M：边的数量
i : 节点的下标索引
idx ： 边的下标索引

二、然后结合代码模版理解定义

变量初始化定义：

int h[N], e[M], ne[M], idx;
当我们加入一条边的时候：

public static void add(int a,int b){
     e[idx] = b;      // 记录 加入的边 的终点节点
     ne[idx] = h[a]; // h[a] 表示 节点 a 为起点的第一条边的下标，ne[idx] = h[a] 表示把 h[a] 这条边接在了 idx 这条边的后面，其实也就是把 a 节点的整条链表 接在了 idx 这条边 后面；目的就是为了下一步 把 idx 这条边 当成 a 节点的单链表的 第一条边，完成把最新的一条边插入到 链表头的操作；
     h[a] = idx++; // a节点开头的第一条边置为当前边，idx移动到下一条边
}


作者：yxc
链接：https://www.acwing.com/file_system/file/content/whole/index/content/4800/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```c++
const int N = 100010,M = N * 2;
int h[N], e[M], ne[M], idx;

// a->b 二
void add(int a, int b){
    e[idx]=b;
    ne[idx]=h[a],h[a]=idx++;

}
int main(){
    memset(h,-1,sizeof h);//代表节点，有N个单链表
}
```