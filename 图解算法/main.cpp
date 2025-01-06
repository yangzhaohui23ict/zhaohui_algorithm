#include <iostream>
#include <vector>
#include <math.h>
using namespace std;




/**

    先来一个分解质因数吧

**/

vector<int> zhiyinshu(int n){
    vector<int> ans;
    if(n==1){
        ans.push_back(1);
        return ans;
    }
    while(n!=1){
        for(int i=2;i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                n=n/i;
            }
        }
    }
    return ans;
}




/**

    做一个输出vector的函数，用来检查效果

**/


void show_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}




/**

    冬瓜糖砖题目这里需要将对应的质因数分成3组，用来对应最终组合出来的长方体的三维。

    这里就可以发散一下，n个数，分成m个组，要怎么做到。

**/


vector<vector<int>> dimension_3;

void fenzu(vector<int> data,int n,vector<int> &ans,int now){
    if(now==data.size()){
        dimension_3.push_back(ans);
        return;
    }
    for(int i=0;i<n;i++){
        ans[i]*=data[now];
        fenzu(data,n,ans,now+1);
        ans[i]/=data[now];
    }

}





/**

    老王开杂货店，要送N快冬瓜糖砖，每一块糖砖的三维都是10厘米，这些糖砖希望打包成一个长方体大包便于运输，希望使用的包装纸越少越好，输出最少的包装纸面积。

    先不要着急

    首先，这个必须是一个长方体。我们可以考虑分解质因子。三个数相乘的形式来组成这个长方体

**/

int function1(int N){
    vector<int> can_use=zhiyinshu(N);
    vector<int> ans;
    for(int i=0;i<3;i++){
        ans.push_back(1);
    }

    fenzu(can_use,3,ans,0);

    int final_acre=INT_MAX;

    for(int i=0;i<dimension_3.size();i++){
//        show_vector(dimension_3[i]);
        int temp_acre=2*(dimension_3[i][0]*dimension_3[i][1]+dimension_3[i][0]*dimension_3[i][2]+dimension_3[i][2]*dimension_3[i][1]);
        if(final_acre>temp_acre){
            final_acre=temp_acre;
        }
    }
    return final_acre*100;

}




int main()
{
    cout<<function1(9);
    return 0;
}
