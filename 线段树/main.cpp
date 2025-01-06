#include <iostream>
#include <bits/stdc++.h>

using namespace std;


/**

    线段树，一种存储区间信息的有效格式

    第一阶段，首先，使用sum，完成这个线段树结果的搭建，基本就是build和up函数

    第二阶段，就需要来实现query了。主要实现的就是query函数，这里需要注意的就是在设置递归条件的时候mid是划分给了左边的，所以注意一下if判断左边的递归要加等于mid

    第三阶段，也是最最核心的环节，添加懒标记，进而完成对于区间的修改。

**/

vector<int> sum;
vector<int> add;


void vector_init(vector<int> &a,int num){
    a.assign(num*4,0);
    return;
}

int query(vector<int> sum,int jobl,int jobr,int l,int r,int index){
    if(jobl<=l&&jobr>=r){
        return sum[index];
    }
    int ans=0;
    int mid=(l+r)/2;
    if(jobl<=mid){
        ans+=query(sum,jobl,jobr,l,mid,index*2);
    }
    if(jobr>mid){
        ans+=query(sum,jobl,jobr,mid+1,r,index*2+1);
    }
    return ans;
}

void up(vector<int> &sum,int index){
    sum[index]=sum[index*2]+sum[index*2+1];
    return;
}

void lazy(vector<int> &sum,vector<int> &add,int index,int value,int num){
    sum[index]+=(value*num);
    add[index]+=value;
}

//向下传播懒标记
void down(vector<int> &sum,vector<int> &add,int index,int ln,int rn){
    if(add[index]){
        lazy(sum,add,index*2,add[index],ln);
        lazy(sum,add,index*2+1,add[index],rn);
        add[index]=0;
    }
}

void change(vector<int> &sum,vector<int> &add,int jobl,int jobr,int l,int r,int value,int index){
    if(jobl<=l&&jobr>=r){
        lazy(sum,add,index,value,r-l+1);
        return;
    }
    int mid=(l+r)/2;
    down(sum,add,index,mid-l+1,r-mid);
    if(mid>=jobl){
        change(sum,add,jobl,jobr,l,mid,value,index*2);
    }
    if(mid<jobr){
        change(sum,add,jobl,jobr,mid+1,r,value,index*2+1);
    }
    up(sum,index);
}


void show_vector(vector<int> num){
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

void build(vector<int> num,vector<int> &sum,int l,int r,int index){
    if(l==r){
        sum[index]=num[l];
        cout<<l<<" "<<num[l]<<endl;
        return;
    }
    int mid=(l+r)/2;
    build(num,sum,l,mid,index*2);
    build(num,sum,mid+1,r,index*2+1);
    up(sum,index);
    return;
}

int main()
{
    vector<int> input_num={1,2,3,4,5,6,7,8,9,0};
    int l=input_num.size();
    vector_init(sum,l);vector_init(add,l);
    build(input_num,sum,0,l-1,1);
    show_vector(sum);
    cout<<query(sum,3,5,0,l-1,1)<<endl;
    change(sum,add,0,5,0,l-1,3,1);
    show_vector(sum);
    show_vector(add);
    change(sum,add,2,2,0,l-1,-1,1);
    show_vector(sum);
    show_vector(add);
    cout << "Hello world!" << endl;
    return 0;
}
