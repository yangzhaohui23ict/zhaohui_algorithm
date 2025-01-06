#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


/**

    刚刚搜了一下，也没找到什么好用的笔记软件，就只好先将就着了。

    1.剖析递归行为，和递归时间复杂度的估算，用例：求整个数组的最大值。
        最简单的肯定就是遍历，不过这里我们可以调整一下，写一个递归版本的。

    结合这个问题，我们可以简单的归纳总结出来递归问题的时间复杂度的计算方式：T(N)=a*T(N/b)+O(N^d)
    也就是，子问题递归的问题规模*子问题数量+除去调用子过程之外的代码的时间复杂度，只要是子问题同规模的就可以这样做，
    想下面这个问题的复杂度就是2*T(N/2)+O(1)

    而后，上面这个公式，明显还不是我们所熟知的时间复杂度的表现方式，这里需要进行计算logb(a)并且和d进行对比
    这个地方都是前人证明好的：
    如果小于，就是O(N^d)，如果等于，就是O(N^d*logN)，如果大于，就是O(N^log(b,a))



**/

int find_max(vector<int> &a,int L,int R)
{
    if(L==R){
        return a[L];
    }
    // 一个小办法，就是避免一些虚空情况，更加安全，无懈可击
    int mid=L+(R-L)/2;
    int zuo=find_max(a,L,mid);
    int you=find_max(a,mid+1,R);
    return max(zuo,you);
}




/**

    归并排序：整体思路：划分中点，先叫他左边有序，再叫她右边有序，然后集合起来。
    首先，集合操作，基于两个有序数组，一边一个指针，边对比边填就可以了。
    其他工作，其实就是递归了。

    刚好可以看一下这个归并排序的时间复杂度：2*T(N/2)+O(N^1);符合我们之前提到的公式,计算相等，所以复杂度就是O(N*logN)，另外空间复杂度是O（N)

**/

void mergee(vector<int> &a,int l,int mid,int r)
{
    vector<int> help;
    int l1=l;
    int l2=mid+1;
    while(l1<=mid&&l2<=r){
        help.push_back(a[l1]<=a[l2]?a[l1++]:a[l2++]);
    }
    while(l1<=mid){
        help.push_back(a[l1++]);
    }
    while(l2<=r){
        help.push_back(a[l2++]);
    }
    for(int i=0;i<help.size();i++){
        a[l+i]=help[i];
    }
}

void guibing_sort(vector<int> &a,int l,int r)
{
    if(l==r){
        return;
    }
    int mid=l+((r-l)/2);
    guibing_sort(a,l,mid);
    guibing_sort(a,mid+1,r);
    mergee(a,l,mid,r);
}

void show(vector<int> &a)
{
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}


/**
    我们来反思一下，为什么归并排序就可以实现时间复杂度上的优化，其实相比较于归并排序，之前的N2复杂度的排序，浪费了大量时间用来对比。对比N次，才能知道一个数的位置。
    多次的比较行为只能用来确定一个数，存在比较行为的大量浪费。
    而在归并排序之中，每次的比较信息都是传递下来的，变成了一个整体有序的部分，为后来的排序提供的帮助。
**/








/**
    小和问题：就是对于数组中的每一位数字，看他左边小于这位数的数组元素的和，即为这个元素的小和。然后统计整个数组的小和。

    这个问题，暴力解法：类似冒泡，每一个元素遍历一下。但是明显存在了优化空间。在归并排序的过程中，我们就可以实现这个任务。

    首先，变更视角，对于一个元素，看他右边有多少个数比他大，就会产生多少个小和。例如，1右边有4个数比他大，那么1就会贡献4个小和。

    而这个问题，明显归并排序的时候就可以顺便实现了。只要修改merge就可以了。

    这个地方我自己写的时候，忽视掉了一个问题，就是相比于一开始归并排序，这里在左右相等的情况下，需要优先放进去右边的

    在发现确实右大于左后，需要记得这个右边的数后面的也都是比这个数要大的，所以我们不能因为比较没有比到就忽视掉，需要用脚标直接计算有多少个这样的数吃到了这个左边数字的小和

**/


int mergee_xiaohe(vector<int> &a,int l,int mid,int r)
{
    vector<int> help;
    int l1=l;
    int l2=mid+1;
    int ans=0;
    while(l1<=mid&&l2<=r){
        if(a[l1]<a[l2]){
            ans+=a[l1]*(r-l2+1);
            help.push_back(a[l1++]);
        }
        else{
            help.push_back(a[l2++]);
        }
    }
    while(l1<=mid){
        help.push_back(a[l1++]);
    }
    while(l2<=r){
        help.push_back(a[l2++]);
    }
    for(int i=0;i<help.size();i++){
        a[l+i]=help[i];
    }
    return ans;
}

int guibing_sort_xiaohe(vector<int> &a,int l,int r)
{
    if(l==r){
        return 0;
    }
    int mid=l+((r-l)/2);
    return guibing_sort_xiaohe(a,l,mid)+guibing_sort_xiaohe(a,mid+1,r)+mergee_xiaohe(a,l,mid,r);
//    guibing_sort_xiaohe(a,l,mid);
//    guibing_sort_xiaohe(a,mid+1,r);
//    mergee_xiaohe(a,l,mid,r);
}






/**
    逆序对：就是左边的数比右边的数要大，这个问题和之前的小和问题是等效的。
**/








/**
    快速排序问题：给定一个数组和一个数，要求把小于等于这个数的放在数组的左边，大于这个数的放在数组的右边。

    说明：划分内部不需要有序

    要求：时间复杂度O(N),空间复杂度O(1)

    处理策略：对于当前数，有两个情况：

        如果小于等于这个数，就把这个数字和小于等于区域的下一个数交换，然后扩大这个小于等于区域一位。之后看下一个数。

        如果大于，那就省事了，直接i++，看下一个数

    原理：遍历过了的位置的信息，我们是需要明确，保存下来的，我们这里小于等于区域下一位的概念就是保存实质。

**/

exchange(vector<int> &a,int l,int r)
{
    int mid=a[l];
    a[l]=a[r];
    a[r]=mid;
}

int tough_sort(vector<int> &a,int num,int l,int r)
{
    int small_space=l-1;
    for(int i=l;i<=r;i++){
        if(a[i]<=num){
            exchange(a,small_space+1,i);
            small_space+=1;
        }
    }
    return small_space;
}



/**
    荷兰国旗问题：给定一个数组和一个数，要求把小于这个数的放在数组的左边，等于这个数的放在中间，大于这个数的放在数组的右边。

    说明：划分内部不需要有序

    要求：时间复杂度O(N),空间复杂度O(1)

    处理策略：对于当前数，有三个情况：

        如果小于这个数，就把这个数字和小于区域的下一个数交换，然后扩大这个小于等于区域一位。之后看下一个数。

        如果等于这个数，什么都不做，直接跳下一个

        如果大于，就把这个数字和大于区域的下一个数交换，大于区域左扩一位，但是！！！这个时候i不能变
        因为这个数是新过来的，我们需要判断这个数要去到的对应的位置区域

        当大于区域和i撞上了的时候，判断停止。

**/

vector<int> Nederlanden_sort(vector<int> &a,int num,int l,int r)
{
    int small_space=l-1;
    int big_space=r+1;
    for(int i=0;i<a.size()&&i!=big_space;i++){
        if(a[i]<num){
            exchange(a,small_space+1,i);
            small_space+=1;
        }
        if(a[i]>num){
            exchange(a,big_space-1,i);
            big_space-=1;
            i--;
        }
    }
    vector<int> ans;
    ans.push_back(small_space);
    ans.push_back(big_space);
    return ans;
}


/**

    讲完这两个内容，就可以讲到快排了。

    快排1.0版本：在整个数组中，拿最后一个数作为划分至，实现划分，划分之后，最后一个数和大于区域的第一个数做交换。然后在左右两个分组中，重复这个操作

        这个替换的数就不用动了，左右分开递归就可以，这样划分，到最后一定是有序的。因为每一次都排好了一个数的位置。

    快排2.0版本：利用荷兰国旗问题，就是避免了相同数据的问题，同样是最后一个数和大于区域的第一个数做交换，这时候是等于区域整个不用动了，左右来递归

        会比1.0版本稍微快一些，因为多搞定了相等的数字。

    但是，不论是1.0还是2.0版本，他的时间复杂度都是O（N^2），因为面对最差的例子，他们都是一次只能处理一个数字。

    因此，出现了3.0版本，反思之前两个版本的问题，其实导致时间复杂度不足的问题，就是划分值找的不好。理论上最好的划分值应该是中点。这个时候是N*logN

    3.0版本思路：对于划分值的调整，我找一个随机数，替换到最后一个位子上，然后重复执行1.0,2.0版本。这里经过概率计算，最最后，时间复杂度是N*logN

        因为这个时候就不再存在理论上的最差劲的情况了。

**/


void quick_sort_I(vector<int> &a,int l,int r)
{
    if(l<r){
        int num=a[r];
        int cut=tough_sort(a,num,l,r-1);
        exchange(a,cut+1,r);
        quick_sort_I(a,l,cut);
        quick_sort_I(a,cut+2,r);
    }
}



void quick_sort_II(vector<int> &a,int l,int r)
{
    if(l<r){
        int num=a[r];
        vector<int> space=Nederlanden_sort(a,num,l,r-1);
        exchange(a,space[1],r);
        quick_sort_I(a,l,space[0]);
        quick_sort_I(a,space[1]+1,r);
    }
}



void quick_sort_III(vector<int> &a,int l,int r)
{
    if(l<r){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(l,r);
        exchange(a,distrib(gen),r);
        int num=a[r];
        vector<int> space=Nederlanden_sort(a,num,l,r-1);
        exchange(a,space[1],r);
        quick_sort_I(a,l,space[0]);
        quick_sort_I(a,space[1]+1,r);
    }
}



void Random(int *a,int n,int l,int r)//生成范围在l~r的随机数
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(l,r);
	for(int i=0;i<n;i++){
		a[i]=distrib(gen);//生成区间r~l的随机数
	}
}



void check()
{
    int n=10;
    int a[n];
    Random(a,n,0,9);
    vector<int> input(a,a+10);
    show(input);
    quick_sort_III(input,0,input.size()-1);
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
    vector<int> a;
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    a.push_back(-1);
    cout << find_max(a,0,a.size()-1) << endl;
    guibing_sort(a,0,a.size()-1);

    int b[5]={1,3,4,2,5};
    vector<int> arr(b,b+5);
    show(arr);
    guibing_sort_xiaohe(arr,0,arr.size()-1);
    cout<<guibing_sort_xiaohe(arr,0,arr.size()-1)<<endl;

    cout<<"---------------------"<<endl;
    for(int i=0;i<10;i++){
        check();
    }
    cout<<"---------------------"<<endl;
    tough_sort(arr,3,0,arr.size()-1);
    show(arr);



    return 0;
}
