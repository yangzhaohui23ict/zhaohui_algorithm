#include <iostream>
#include <vector>
using namespace std;

//��������������ĳһ������һ�ο�һ�룬�ȱ���Ҫ�ã�����һ��O(logn)����ĸ��Ӷ�
//  ���������Ҿֲ���Сֵ���ȿ����ˣ�������ǣ��ǾͶ��֣����е㣬������λ�ò��ǣ����ұ��������Ҫ��Ļ�����ô���������һ�����ھֲ���Сֵ��
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
