#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


/**

    补充一下，快排的额外空间复杂度是多少：是O（logN）级别的。

**/



/**

    堆：在逻辑上是一个完全二叉树的结构，并且是一个比较特殊的完全二叉树

    如何在实际上支持一个完全二叉树的结构：

        可以在一个数组上实现，对于i号位上的元素，他在对应的堆或者说完全二叉树上的左右子树，应该对应在2i+1.2i+2号位上的元素，父子书应该是（i-1）/2号位上的元素

    堆，又可以细分为大根堆和小根堆，也就是在这个二叉树中，每一个节点为头的整颗子树，对于这个子树中的所有节点的最大值，就是头结点的值，小根堆同理。

    可以设置一个接口，用户输入数字，程序以数组的形式保留大根堆。每一个数输入进来，我们都可以先将它放到初始位置上，每一次输入进来之后，都去和自己的父节点比较，只要大，就交换。

    这样调整之后就是大根堆。（如果交换了，那么你就需要继续往上对比，直到小于父节点或者说来到顶层了），这个过程，称之为heapinsert

    在代码实现的过程中，我们的while语句之所以只有一个条件，是因为如果来到了根节点，这个计算方式得到的是两个根节点数值对比，循环也自然结束


**/


void excange(vector<int> &a,int l,int r)
{
    int mid=a[l];
    a[l]=a[r];
    a[r]=mid;
}

void heapInsert(vector<int> &a,int index)
{
    while(a[index]>a[(index-1)/2]){
        excange(a,index,(index-1)/2);
        index=(index-1)/2;
    }
}

/**

    大根堆的作用：可以提供数字的最大值。这个显而易见，就是根节点。

    但是此时，如果我们需要去除掉这个根节点，并且保持大根堆结构要怎么做：先用最后一个节点的数值，替换掉根节点的元素，然后使最后一个节点无效。

    然后，从头结点开始，在他的左右孩子节点中，找一个最大值，比大小，如果小，则交换。循环这个步骤。直到这个数终于大于他的孩子节点，或者没有孩子节点了。

    这个过程称之为heapify
**/

//  这里index是指的开始下降的节点位置，我们之前提到的是从头节点开始，但是实际上这个操作可以在任意位置实现
//  这里heapsize是指这个数组堆的实际有效范围。
void heapify(vector<int> &a,int index,int heapsize)
{
    int left=index*2+1;
    //  需要确保这个节点还有孩子
    while(left<heapsize){
        int largest=(left+1<heapsize && a[left+1]>a[left])?left+1:left;

        largest=a[largest]>a[index]?largest:index;

        //  说明这个父节点就是最大的
        if(largest==index){
            break;
        }
        else{
            excange(a,largest,index);
            index=largest;
            left=index*2+1;
        }
    }
}



/**

    此时，已经有了从下往上和从上往下维护大小根堆的实现方式，那么此时面对，堆中任意一个元素的变化。

    如果变小了，就叫这个节点往下，如果变大了，就叫这个节点往上，如果不知道，那么其实可以两个都执行一遍，一般只有一个会实现。

    另外heapinsert和heapify的操作，都是O(logN)级别的操作。

    在完成了这两个基础操作的了解之后，就可以开始进行堆排序了。

**/


/**

    堆排序：对于任意一个数组，先让他成为一个大根堆。

    实现方式：一个个元素进来，挨个heapinsert，然后，将根节点和最后一个节点交换，这个时候输出出来的就是最大值。对于剩下的部分，进行heapify，重复以上

    在进行这个操作不愁的时候，需要记得交换之后，heapsize要-1，用来确保heapify不出问题。

    关于时间复杂度，明显是O(logN)，建立大根堆的过程和排序的过程都是这个复杂度，然后时间复杂度与系数无关。

    另外，额外空间复杂度是O（1）的。只用了几个变量。
**/


void heapsort(vector<int> &a)
{
    if(a.size()<2){
        return;
    }
    for(int i=0;i<a.size();i++){
        heapInsert(a,i);
    }
    int heapsize=a.size();
    excange(a,0,--heapsize);

    while(heapsize>0){
        heapify(a,0,heapsize);
        excange(a,0,--heapsize);
    }
}

/**

    关于之前提到的建立大根堆，其实还有更好的优化方式。在用户直接给出整个数组的时候，从后往前看，对于每个元素进行一次heapify就可以了。

    这样为什么会更好。因为这样会有一半的数据因为在底层，不用进行操作，上面的一步步下来，但是上层节点本身数量少，这样操作是O(N)级别的。

    但是，事实上这对于堆排序这个操作，并没有太大的意义，只能稍微快一点点。因为排序那个地方是一定的

**/

void heapsort_little_quicky(vector<int> &a)
{
    if(a.size()<2){
        return;
    }
    for(int i=a.size()-1;i>=0;i--){
        heapify(a,i,a.size());
    }
    int heapsize=a.size();
    excange(a,0,--heapsize);

    while(heapsize>0){
        heapify(a,0,heapsize);
        excange(a,0,--heapsize);
    }
}



/**

    堆排序的补充问题：几乎有序问题。

    一个数组几乎有序，也就是说，如果把数组排好序的话，每一个元素可以移动的距离不超过k，并且这个数一般很小。这时，请选择一个好的排序算法。

    思路：准备一个小根堆，遍历数组，先遍历k+1个数组的元素。因为这个时候，小根堆的最小值，一定在0位置。相同原理循环，最后，只要把小根堆的数据有序输出

    此时的程序，时间复杂度是O(N*logk)，并且k一般不大，普遍可以认为是O（N）

    另外，C++有自己的堆列表，可以之后搜一下进行补充，直接用的话，也可以认为是log级别的复杂度。但是这个地方类似于黑盒，除了输入输出，别的都改不了

    所以说，如果一些高级的堆操作，还是得自己手写。

**/






/**

    关于堆，堆的结构远远比堆排序要重要

**/





/**

    比较器概念补充，在C++中就是重载运算符，面对一些其他的数据类型，便于对比大小，可以自己来定义一些比较复杂的比较策略。

**/




/**

    桶排序，之前的排序都可以说是给予比较的排序，

    用在数据存在明显的数据边界的情况，比如说年龄排序，就可以词频数组还原回去原数组，比如说18岁1个，19岁3个，对应排序就是18,19,19,19，O（N）级别

    所以这种操作存在明显的使用界限，需要对于数据状况针对性使用。属于是高端定制类型。

    上面的操作是计数排序方法。

    接下来讲一下非比较排序中比较关键的一个：基数排序

    对于数组中的元素，准备0-9号，对应的十个桶，将元素统一补齐位数，从个位开始，进入对应数字的桶里面，然后从0号桶开始输出出来，对于桶元素，先进先出。

    然后再来十位数，百位数分别来实现，最后位数都跑完，最最后输出出来的就是排序好的。

    这个算法的局限性：需要数据至少有一个进制的机制。

**/


int maxbits(vector<int> &a)
{
    auto maxx=max_element(a.begin(), a.end());
    int res=0;
    int num=a[maxx-a.begin()];
    while(num!=0){
        num/=10;
        res++;
    }
    return res;
}


int getdigit(int a,int b)
{
    int num=pow(10,b-1);
    a=a/num;
    return a%10;
}



//  digit表示位数
void radix_sort(vector<int> &a,int l,int r,int digit)
{
    int radix=10;
    vector<int> mid;
    //  所有数据出入桶的次数
    for(int i=1;i<=digit;i++){
        //  用来统计词频
        int count[10]={0};
        for(int j=l;j<=r;j++){
            count[getdigit(a[j],i)]++;
        }
        //  对于count，进行前缀和操作。此时count中每一个元素表示，对应位数是0-特定数字的数据有多少个。

        for(int j=1;j<10;j++){
            count[j]=count[j]+count[j-1];
        }

        //  然后，对于mid中的数据，从右往左看，这个时候，对应count的数字-1就表示了这个数字在出桶之后对应的位置。
        //  然后，此时，这个对应位置--
        //  利用count数组实现了分片，等于完成了一次入桶出桶，节省了很多的空间。

        int *bucket = new int[a.size()];

        for(int j=r;j>=l;j--){
            int wei=getdigit(a[j],i);
            bucket[count[wei]-1]=a[j];
            count[wei]--;
        }

        for(int j=l,k=0;j<=r;j++,k++){
            a[j]=bucket[k];
        }

    }
}








/**

    之前写好了的，用来输出随机数组序列

**/

void Random(int *a,int n,int l,int r)//生成范围在l~r的随机数
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(l,r);
	for(int i=0;i<n;i++){
		a[i]=distrib(gen);//生成区间r~l的随机数
	}
}

void show(vector<int> &a)
{
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}


void check()
{
    int n=10;
    int a[n];
    Random(a,n,0,1000);
    vector<int> input(a,a+10);
    show(input);
    radix_sort(input,0,input.size()-1,maxbits(input));
    int e=input[0];
    for(int i=0;i<input.size();i++){
        if(input[i]>=e){
            e=input[i];
        }
        else{
            cout<<"wrong"<<endl;
            break;
        }
    }
    show(input);
    return;
}







int main()
{
    cout<<"堆排序"<<endl;
    for(int i=0;i<10;i++){
        check();
    }

}
