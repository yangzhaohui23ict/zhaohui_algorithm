#include <iostream>
#include<vector>
using namespace std;


/**

    一个整数数组

    找出一个最长的非递减序列

    1000,300，-5,2,4，-100

    vector<int>

**/


int main()
{
    int a[6]={1000,300,-5,2,4,-100};//1,1,1,2,3,1

    vector<int> up;
    vector<int> ans;
    up.push_back(1);
    int num=1;
    for(int i=1;i<6;i++){
        if(a[i]>=a[i-1]){
            num++;
        }
        else{
            num=1;
        }
        up.push_back(num);
    }


    for(int i=0;i<up.size();i++){
        cout<<up[i];
    }
    cout<<endl;

    int biggest=INT_MIN;int big_from=0;
    for(int i=0;i<up.size();i++){
        if(biggest<up[i]){
            biggest=up[i];
            big_from=i;
        }
    }

    int real_from=big_from-biggest+1;
    cout<<real_from<<endl;

    for(int i=real_from,j=0;j<biggest;i++,j++){
        cout<<a[i]<<"  ";
    }



    return 0;
}
