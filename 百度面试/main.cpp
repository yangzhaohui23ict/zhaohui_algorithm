#include <iostream>

using namespace std;


/**

    一组石头
    每次选两个粉碎
    重量相同，一起粉碎
    重量不同，一个石头，质量为重量差
    返回这个石头最小的可能重量
    恰好完全粉碎，返回0

    样例：2,4,7,1,1,8

    1,1,2,4,7,8

    结果：1


    通过分割石头为两个相同的堆

**/


int main()
{
    int h[6]={1,1,2,5,7,8};

    int sum=0;

    for(int i=0;i<6;i++){
        sum+=h[i];
    }

    int target=sum/2;

    int dp[6][12]={0};

    for(int i=0;i<6;i++){
        dp[i][h[i]]=1;
    }

    for(int i=1;i<6;i++){
        for(int j=1;j<=12;j++){
            if(j-h[i]>=0){
               dp[i][j]=max(dp[i-1][j-h[i]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[5][12]<<endl;

    return 0;
}
