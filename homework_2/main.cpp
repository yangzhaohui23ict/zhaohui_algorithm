//#include <iostream>
//#include<vector>
//using namespace std;
//
//long long int mergee_xiaohe(vector<long long int> &a,int l,int mid,int r)
//{
//    vector<long long int> help;
//    int l1=l;
//    int l2=mid+1;
//    long long int ans=0;
//    while(l1<=mid&&l2<=r){
//        if(a[l1]<=a[l2]){
//            help.push_back(a[l1++]);
//        }
//        else{
//            ans+=(mid-l1+1);
//            help.push_back(a[l2++]);
//        }
//    }
//    while(l1<=mid){
//        help.push_back(a[l1++]);
//    }
//    while(l2<=r){
//        help.push_back(a[l2++]);
//    }
//    for(int i=0;i<help.size();i++){
//        a[l+i]=help[i];
//    }
//    return ans;
//}
//
//long long int guibing_sort_xiaohe(vector<long long int> &a,int l,int r)
//{
//    if(l==r){
//        return 0;
//    }
//    int mid=l+(r-l)/2;
//    long long int ans=(long long int)guibing_sort_xiaohe(a,l,mid)+(long long int)guibing_sort_xiaohe(a,mid+1,r)+(long long int)mergee_xiaohe(a,l,mid,r);
//
//    return ans;
//}
//
//
//
//
//
//
//int main()
//{
//    int n;
//    while(scanf("%d",&n)!=EOF&&n){
//        vector<long long int> shu;
//        for(int i=0;i<n;i++){
//            long long int num;
//            cin>>num;
//            shu.push_back(num);
//        }
//        long long int anss=guibing_sort_xiaohe(shu,0,shu.size()-1);
//        cout<<anss<<endl;
//    }
//    return 0;
//}



//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<math.h>
//#include<iostream>
//using namespace std;
//int a[500001],n;
//long long sum;
//void merge(int a[],int l,int mid,int r)
//{
//    int t[500001];
//    int i,j,p;
//    for(i=l,j=mid+1,p=0;i<=mid&&j<=r;p++)
//    {
//        if(a[i]<=a[j]) t[p]=a[i++];
//        else
//        {
//            t[p]=a[j++];
//            sum=sum+(mid-i+1);
//        }
//    }
//    while(i<=mid) t[p++]=a[i++];
//    while(j<=r) t[p++]=a[j++];
//    for(int i=l,p=0;i<=r;i++)
//     a[i]=t[p++];
//}
//void mergesort(int a[],int l,int r)
//{
//    if(l==r) a[l]=a[r];
//    else
//    {
//        int mid=l+(r-l)/2;
//        mergesort(a,l,mid);
//        mergesort(a,mid+1,r);
//        merge(a,l,mid,r);
//    }
//}
//int main()
//{
//    while(scanf("%d",&n)!=EOF&&n!=0)
//    {
//        sum=0;
//        for(int i=0;i<n;i++)
//            scanf("%d",&a[i]);
//        mergesort(a,0,n-1);
//        printf("%lld\n",sum);
//    }
//    return 0;
//}




#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


vector<vector<int>> cheng(vector<vector<int>> &a,vector<vector<int>> &b){
    vector<vector<int>> ans;
    ans.push_back({(a[0][0]*b[0][0]%(1000000007))+(a[0][1]*b[1][0]%(1000000007))%(1000000007),(a[0][0]*b[0][1]%(1000000007))+(a[0][1]*b[1][1]%(1000000007))%(1000000007)});
    ans.push_back({(a[1][0]*b[0][0]%(1000000007))+(a[1][1]*b[1][0]%(1000000007))%(1000000007),(a[1][0]*b[0][1]%(1000000007))+(a[1][1]*b[1][1]%(1000000007))%(1000000007)});
    return ans;

}

vector<vector<int>> ji(vector<vector<int>> &a,int n)
{
    vector<vector<int>> mid=a;
    while(n--){
        mid=cheng(mid,mid);
    }
    return mid;
}


void func_2(){
    int n;
    while(scanf("%d",&n)!=EOF){

        if(n%4==2){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        continue;

        vector<vector<int>> a;
        a.push_back({1,1});
        a.push_back({1,0});

        vector<int> wei;
        if(n==0||n==1){
            cout<<"no"<<endl;
            continue;
        }
        n=n-2;
        while(n){
            for(int i=0;;i++){
                if(pow(2,i+1)>n){
                    wei.push_back(i);
                    n=n-pow(2,i);
                    break;
                }
            }
        }
        vector<vector<int>> matrix=a;
        for(int i=0;i<wei.size();i++){
//            cout<<wei[i]<<" "<<endl;
            vector<vector<int>> m=ji(a,wei[i]);
            matrix=cheng(matrix,m);
        }
//        for(int i=0;i<2;i++){
//            for(int j=0;j<2;j++){
//                cout<<matrix[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        int final=((11*matrix[0][0])%(1000000007)+(7*matrix[1][0])%(1000000007))%(1000000007);
        if(final%3==0){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}






void func_3()
{
    int N;
    cin>>N;
    while(N--){
        int l;
        cin>>l;
        int a[50]={0};
        for(int i=1;;i++){
            int found=0;
            for(int j=0;j<l;j++){
                if(a[j]==0){
                    a[j]=i;
                    found=1;
                    break;
                }
                if(a[j]+i==(int)sqrt(a[j]+i)*(int)sqrt(a[j]+i)){
                    a[j]=i;
                    found=1;
                    break;
                }
            }
//            for(int j=0;j<l;j++){
//                cout<<a[j]<<" ";
//            }
            if(found==0){
                cout<<i-1<<endl;
                break;
            }
        }
    }
}


#include<iostream>
#include<vector>
#include<math.h>
#include <iomanip>
using namespace std;


void func_G(){
    int n;
    cin>>n;
    vector<long long int> shu;
    for(int i=0;i<n;i++){
        long long int num;
        cin>>num;
        shu.push_back(num);
    }
    vector<long long int> dp;
    dp.push_back(shu[0]);
    long long int ans=shu[0];
    for(int i=1;i<n;i++){
        if(dp[i-1]+shu[i]>shu[i]){
            dp.push_back((long long int)dp[i-1]+shu[i]);
            ans=ans>dp[i-1]+shu[i]?ans:(long long int)dp[i-1]+shu[i];
        }
        else{
            dp.push_back(shu[i]);
            ans=ans>shu[i]?ans:shu[i];
        }
    }
    cout<<ans<<endl;
    return ;
}








void func_J()
{
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a<b){
            cout<<"impossible"<<endl;
            continue;
        }
        int win=(a+b)/2;
        int loss=(a-b)/2;
        if(win+loss!=a||win-loss!=b){
            cout<<"impossible"<<endl;
        }
        else{
            cout<<win<<" "<<loss<<endl;
        }
    }
}





void func_F()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a%2==0||b%2==0){
            cout<<"Scenario #"<<i<<":"<<endl;
            double ans=a*b;
            cout<<fixed<< setprecision(2)<<ans<<endl;
            continue;
        }
        else{
            cout<<"Scenario #"<<i<<":"<<endl;
            double ans=a*b-1+sqrt(2);
            cout<<fixed<< setprecision(2)<<ans<<endl;
        }
    }
}





int main(){
    func_F();
    return 0;
}






























