#include <iostream>
#include <vector>
using namespace std;

//有序数组中来找某一个数，一次砍一半，比遍历要好，这是一个O(logn)级别的复杂度
//  无序数组找局部最小值，先看两端，如果不是，那就二分，看中点，如果这个位置不是，并且比左或者右要打的话，那么这个区间内一定存在局部最小值。
int main()
{
    vector<int> a;
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int num=6;
    int up=a.size();
    int down=0;
    while(up>=down){
        int mid=(up+down)/2;
        if(a[mid]==num){
            cout<<mid;
        }
        if(a[mid]<num){
            down=mid+1;
        }
        else{
            up=mid-1;
        }
    }

    return 0;
}
