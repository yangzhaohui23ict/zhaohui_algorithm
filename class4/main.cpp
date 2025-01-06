#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/**

    排序的稳定性：对于相同大小的数字，经过排序之后，彼此之间的相互位置不改变。

    这个概念一般情况下，没有什么用处，尤其是在基础类型的数组下的时候。

    但是如果是非基础的数组，比如说一个类，有多个属性，我们希望根据多个属性进行排序，根据属性a排好之后，我还要根据属性b来排序

    那么这个时候，我们明显是希望以b的优先级最高，但是b一样的情况下还是通过a来排序，保留相对次序的意义就在这里。


    之前提到的一些排序算法，按照稳定性来进行分类。

    稳定排序：冒泡排序（相等不交换），插入排序（相等不前插），归并排序（主要看merge，相等拷贝左边就行了），计数排序，计数排序（先入桶先出桶，不急于比价的都很稳定）

    不稳定排序：选择排序，快排（在第一步，分区间的时候就做不到了），堆排序（生成大小根堆的时候就破坏了）

    另外，虽然归并，堆排序，快排都是NlogN级别的，但是快排实验证明过，常数项是最低的，所以有事没事用快排。

    目前排序算法的极限：时间是NlogN，在这个时间前提下要稳定，必须要O（N）的空间稳定度。

    另外，快排的分区间步骤中，如果需区分相等区域，其实就是一个0-1划分，可以同样适用于奇偶等其他0-1划分的内容。

    工程项目中存在的优化策略：短数组（<60）直接用插入排序都可以，不使用递归操作。这里的目的主要是节省空间，另外插入排序常数量很低。

**/











/**

    哈希表（unodered）：set和map没啥区别，本质上是一样的树，就是单key和带一个value的区别。

        所以不论是set还是map都可以说是哈希表。

        哈希表在使用的过程中，默认，增删改查都是常数级别的。

        另外，我们这里使用的哈希表也需要区分数据类型，面对基础类型，哈希表都是按值传递的。所占空间就是数据的空间。

        如果是我们自己定义的数据类型，那么哈希表就不会拷贝一份。而是传递内存地址，按引用传递。所占空间一律8字节。

        也就是面对不同的数据类型，使用深浅拷贝。

    有序表（ordered）：就是和哈希表相比，key补充了有序排列的特点。相比哈希表，因为多了有序的信息，所以在哈希表的功能基础上，还有一些功能补充:

        比如key的最大最小

        比如找key距离最近的元素

        具体原理很难，是一个实现平衡树的原理，红黑树，跳表，AVL，SB树等等

**/










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





/**

    单链表的节点结构

**/


struct dan_node
{
    int value;
    dan_node* next;
};


dan_node* creatlist(int n) {
	dan_node* Head=new dan_node;    //头节点 不存储数据
	Head->next = NULL;
	dan_node* pre = Head;  //指向下一个节点的过渡值

    int a[10];
    Random(a,10,0,9);
//    for(int i=0;i<10;i++){
//        cout<<a[i]<<"  ";
//    }
//    cout<<endl;
	for (int i = 0;i < n;i++) {
		dan_node* temp = new dan_node;
		temp->value=a[i];
		pre->next = temp;
		pre = temp;
		temp->next = NULL;
	}

	return Head->next;
}


void show_list(dan_node* head)
{
    dan_node* pre=head;
    while(pre){
        cout<<pre->value<<"  ";
        pre=pre->next;
    }
    cout<<endl;
}


dan_node* reverse_list(dan_node* head)
{
    show_list(head);
    dan_node* fan_head=NULL;

	dan_node* cur=head;
	while(cur){
        dan_node* next=cur->next;
        cur->next=fan_head;
        fan_head=cur;
        cur=next;
	}
    show_list(fan_head);
	return fan_head;
}


/**

    双链表的节点结构

**/


struct shuang_node
{
    int value;
    shuang_node* next;
    shuang_node* last;
};



shuang_node* creatlist_shuang(int n) {
	shuang_node* Head=new shuang_node;    //头节点 不存储数据
	Head->next = NULL;
	Head->last = NULL;
	shuang_node* pre = Head;  //指向下一个节点的过渡值


    int a[10];
    Random(a,10,0,9);

	for (int i = 0;i < n;i++) {
		shuang_node* temp = new shuang_node;
		temp->value=a[i];
		pre->next = temp;
		temp->last=pre;
		pre = temp;
		temp->next = NULL;
	}

	return Head->next;
}


void show_list_shuang(shuang_node* head)
{
    shuang_node* pre=head;
    while(pre){
        cout<<pre->value<<"  ";
        pre=pre->next;
    }
    cout<<endl;
}


/**
    如果只是翻转双向链表只是为了输出的话，其实没啥意义，毕竟输出数据，直接顺都可以
**/

void show_list_shuang_reverse(shuang_node* head)
{
    shuang_node* pre=head;

    while(pre->next!=NULL){
        pre=pre->next;
    }

    while(pre){
        cout<<pre->value<<"  ";
        pre=pre->last;
    }
    cout<<endl;
}



shuang_node* reverse_list_shuang(shuang_node* head)
{
//    show_list_shuang(head);
    shuang_node* fan_head=NULL;

    shuang_node* cur=head;

    while(cur){
        cur->last=cur->next;
        cur=cur->next;
    }

	cur=head;
	while(cur){
        shuang_node* next=cur->next;
        cur->next=fan_head;
        fan_head=cur;
        cur=next;
	}
//    show_list_shuang(fan_head);
	return fan_head;
}





/**

    打印两个有序链表的公共部分
    1,2,5
    0,2,3,5
    就是两个指针，指向两个链表，谁小谁后移，相等就打印并共同向后移动，只要有一个走完了，函数就结束。

**/


int a[3]={1,2,5};
int b[4]={0,2,3,5};
int c[9]={1,2,3,4,5,4,3,2,1};

vector<int> a_vec(a,a+3);
vector<int> b_vec(b,b+4);
vector<int> c_vec(c,c+9);

dan_node* creatlist_vector(vector<int> a)
{
	dan_node* Head=new dan_node;    //头节点 不存储数据
	Head->next = NULL;
	dan_node* pre = Head;  //指向下一个节点的过渡值

	for (int i = 0;i < a.size();i++) {
		dan_node* temp = new dan_node;
		temp->value=a[i];
		pre->next = temp;
		pre = temp;
		temp->next = NULL;
	}

	return Head->next;
}

void print_same_part(dan_node* a,dan_node* b)
{
    dan_node* biao1=a;
    dan_node* biao2=b;
    while(biao1&&biao2){
        if(biao1->value==biao2->value){
            cout<<biao2->value<<" ";
            biao1=biao1->next;
            biao2=biao2->next;
            continue;
        }
        if(biao1->value>biao2->value){
            biao2=biao2->next;
            continue;
        }
        if(biao1->value<biao2->value){
            biao1=biao1->next;
            continue;
        }
    }
    cout<<endl;
}


/**

    判断一个链表是不是回文链表

    最简单想到的方式：先逆序，然后两个链表同步判断。

    或者，通过栈来实现。也就是一样的，利用栈先进后出的性质来实现逆序。

    如果要节省空间，可以只放右半部分放到栈里面。

    但是这个时候就遇到了一个问题，我们怎么知道到了右半部分？

    所以我们引入快慢指针。快指针一次两步，慢指针一次一步，快指针走完的时候，慢指针来到中点位置。

    但是，需要注意的地方就是，快慢指针对于链表的长度奇偶性以及慢指针要踩中绝对中间以及中间偏左一位，这个地方是需要看具体情况

    如果还要展现自己优势，使用O（1）的空间复杂度，那么可以快慢指针后半段逆序，两头开始走，走向中间，如果都一样，回文。

    这里很考验code


**/

void huiwen_check_esay_way(dan_node* a)
{
    stack<int> zhan;
    dan_node* pre=a;
    while(pre){
        zhan.push(pre->value);
        pre=pre->next;
    }
    pre=a;
    int flag=0;
    while(pre){
        if(pre->value!=zhan.top()){
            flag=1;
            break;
        }
        pre=pre->next;
        zhan.pop();
    }
    if(flag){
        cout<<"非回文"<<endl;
    }
    else{
        cout<<"回文"<<endl;
    }
}





/**

    通过巧妙的方法，利用有限的几个变量就实现了这个方法。

**/


void huiwen_check_hard_way(dan_node* a)
{
    dan_node* fast=a;
    dan_node* slow=a;
    //快慢指针
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    fast=slow->next;
    slow->next=NULL;
    dan_node* temp=NULL;
    while(fast){
        temp=fast->next;
        fast->next=slow;
        slow=fast;
        fast=temp;
    }

    dan_node* zuo=a;
    dan_node* you=slow;
    int flag=0;
    while(zuo&&you){
        if(zuo->value!=you->value){
            flag=1;
            break;
        }
        else{
            zuo=zuo->next;
            you=you->next;
        }
    }

    if(flag){
        cout<<"非回文"<<endl;
    }
    else{
        cout<<"回文"<<endl;
    }
    show_list(a);
    //  翻转链表，有了结果之后，别忘记了，要把链表再转回来，就当做是锻炼代码了

    dan_node* last_node=slow->next;
    slow->next=NULL;


    while(last_node){
        temp=last_node->next;
        last_node->next=slow;
        slow=last_node;
        last_node=temp;
    }
    show_list(a);

}





/**

    将单向链表按某值划分成为左边小，中间相等，右边大的形式

    有一点那种荷兰国旗的意思。

    如果这个是笔试，我们可以链表转数组，然后对于数组玩partion，最后处理好的数组，改回去链表的数据就可以了。

    甚至数据可以直接是节点类型的。很简单

    但是如果在面试，需要尽可能少个空间使用。六个变量就可以实现这个问题。

    分别是小于，等于，大于三个区域的头和尾。这里的变量是节点。通过每过一个，就将这个数据节点连接到对应的区域尾处

    最后三个区域链接起来就可以了

**/


void list_partion(dan_node* a,int num)
{
    dan_node* small_begin=NULL;
    dan_node* small_end=NULL;
    dan_node* equal_begin=NULL;
    dan_node* equal_end=NULL;
    dan_node* big_begin=NULL;
    dan_node* big_end=NULL;

    dan_node* cur=a;

    while(cur){
        if(cur->value<num){
            if(small_begin==NULL){
                small_begin=cur;
                small_end=cur;
            }
            else{
                small_end->next=cur;
                small_end=cur;
            }
        }
        else if(cur->value==num){
            if(equal_begin==NULL){
                equal_begin=cur;
                equal_end=cur;
            }
            else{
                equal_end->next=cur;
                equal_end=cur;
            }
        }
        else{
            if(big_begin==NULL){
                big_begin=cur;
                big_end=cur;
            }
            else{
                big_end->next=cur;
                big_end=cur;
            }
        }
        cur=cur->next;
    }

    if(small_end){
        small_end->next=NULL;
    }
    if(equal_end){
        equal_end->next=NULL;
    }
    if(big_end){
        big_end->next=NULL;
    }


    show_list(small_begin);
    show_list(equal_begin);
    show_list(big_begin);

    dan_node* ans=new dan_node;
    dan_node* res=ans;
    if(small_begin!=NULL){
        while(small_begin){
            ans->next=small_begin;
            small_begin=small_begin->next;
            ans=ans->next;
        }
    }
    if(equal_begin!=NULL){
        while(equal_begin){
            ans->next=equal_begin;
            equal_begin=equal_begin->next;
            ans=ans->next;
        }
    }
    if(big_begin!=NULL){
        while(big_begin){
            ans->next=big_begin;
            big_begin=big_begin->next;
            ans=ans->next;
        }
    }

    show_list(res->next);
    return;
}



/**

    复制含有随机指针节点的链表

    就是一个正常的单链表，多出来了一个rand指针，这个指针随机只想链表中的一个节点。

    然后，我们需要拷贝出来另外一个链表，关键就是rand指针也要一样

    这个如果要使用额外空间，哈希表就可以，很简单，一个map（老节点，新节点），然后遍历一下链表，把对应节点指针指向对应新节点

    最后返回对应第一个新节点就可以了。

    那么问题来了，不用哈希表的方式怎么做？

    生成一个新的节点，就放在原始链表的节点后面，此时链表就是1,1,2,2,3,3这样，我们可以一对一对来拿。此时只考虑rand指针

    那么next指针自然可以找到对应的rand指针节点。最后分离出来。得到新的链表。

**/




int main()
{

//    dan_node* a=creatlist(10);
//    reverse_list(a);

//    shuang_node *a=creatlist_shuang(10);
//    show_list_shuang(a);
//    shuang_node *b=reverse_list_shuang(a);
//    show_list_shuang(b);
//    show_list_shuang_reverse(b);
//    cout<<endl;

//    print_same_part(creatlist_vector(a_vec),creatlist_vector(b_vec));
//    huiwen_check_hard_way(creatlist_vector(c_vec));
    list_partion(creatlist_vector(c_vec),7);
    return 0;
}
