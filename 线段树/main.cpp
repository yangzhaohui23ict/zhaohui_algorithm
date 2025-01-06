#include <iostream>
#include <bits/stdc++.h>

using namespace std;


/**

    �߶�����һ�ִ洢������Ϣ����Ч��ʽ

    ��һ�׶Σ����ȣ�ʹ��sum���������߶�������Ĵ����������build��up����

    �ڶ��׶Σ�����Ҫ��ʵ��query�ˡ���Ҫʵ�ֵľ���query������������Ҫע��ľ��������õݹ�������ʱ��mid�ǻ��ָ�����ߵģ�����ע��һ��if�ж���ߵĵݹ�Ҫ�ӵ���mid

    �����׶Σ�Ҳ��������ĵĻ��ڣ��������ǣ�������ɶ���������޸ġ�

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

//���´��������
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
