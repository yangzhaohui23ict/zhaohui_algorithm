#include <iostream>
#include<vector>
using namespace std;




/**

    数字图像处理，第二版，相较于更新的两个版本，有一部分基础内容

    digital image processing 电子工业出版社，R.C.conzalez

    digital image processing using MATLAB

    教材补充

        图像处理基础，数字图像处理（王桥，科学出版社）

        图像处理，分析与机器视觉（Milan soka）

    编程语言内容：学的是MATLAB，但是编程任务是python



**/



vector<vector<pair<int,int>>> ans;

void find_biggest(vector<vector<int>> grid,int x,int y,vector<pair<int,int>> &a)
{
    if(x==grid.size()||y==grid[0].size()){
        return;
    }
    if(x==grid.size()-1&&y==grid[0].size()-1){
        ans.push_back(a);
    }
    int m=grid.size();
    int n=grid[0].size();
    a.push_back(pair<int,int>(x+1,y));
    find_biggest(grid,x+1,y,a);
    a.erase(a.end()-1);
    a.push_back(pair<int,int>(x,y+1));
    find_biggest(grid,x,y+1,a);
    a.erase(a.end()-1);
    return;

}



vector<vector<pair<vector<pair<int,int>>,int>>> final_martix;

vector<pair<int,int>> dp(vector<vector<int>> grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<pair<int,int>> path;
    path.push_back(pair<int,int>(0,0));
    int value=grid[0][0];

    for(int i=0;i<m;i++){
        vector<pair<vector<pair<int,int>>,int>> a;
        final_martix.push_back(a);
    }

    final_martix[0].push_back(pair<vector<pair<int,int>>,int>(path,value));

    for(int i=1;i<m;i++){
        vector<pair<int,int>> path=final_martix[0][i-1].first;
        int value=final_martix[0][i-1].second;
        path.push_back(pair<int,int>(0,i));
        value+=grid[0][i];
        final_martix[0].push_back(pair<vector<pair<int,int>>,int>(path,value));
    }
    for(int i=1;i<n;i++){
        vector<pair<int,int>> path=final_martix[i-1][0].first;
        int value=final_martix[i-1][0].second;
        path.push_back(pair<int,int>(i,0));
        value+=grid[i][0];
        final_martix[i].push_back(pair<vector<pair<int,int>>,int>(path,value));
    }

    for(int i=1;i<m;i++){
//        vector<pair<vector<pair<int,int>>,int>> mid;
        for(int j=1;j<n;j++){
            vector<pair<int,int>> path;
            int value;
            int value1=final_martix[i-1][j].second;
            int value2=final_martix[i][j-1].second;
            if(value1>value2){
                path=final_martix[i-1][j].first;
                path.push_back(pair<int,int>(i,j));
                value=value1+grid[i][j];
//                mid.push_back();
            }
            else{
                path=final_martix[i][j-1].first;
                path.push_back(pair<int,int>(i,j));
                value=value2+grid[i][j];
//                mid.push_back(pair<vector<pair<int,int>>,int>(path,value));
            }
            final_martix[i].push_back(pair<vector<pair<int,int>>,int>(path,value));
        }

    }

    cout<<final_martix[m-1][n-1].second<<endl;
    return final_martix[m-1][n-1].first;

}




int main()
{

    vector<vector<int>> a;
    int b[9]={1,3,1,1,5,1,4,2,1};
    for(int i=0;i<3;i++){
        vector<int> mid;
        for(int j=0;j<3;j++){
            mid.push_back(b[3*i+j]);
        }
        a.push_back(mid);
    }
    vector<pair<int,int>> path;
    path=dp(a);
    for(int i=0;i<path.size();i++){
            cout<<"("<<path[i].first<<" , "<<path[i].second<<")";
        cout<<endl;
    }

    vector<pair<int,int>> tep;
    tep.push_back(pair<int,int>(0,0));
    find_biggest(a,0,0,tep);

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<"("<<ans[i][j].first<<" , "<<ans[i][j].second<<")";
        }
        cout<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
