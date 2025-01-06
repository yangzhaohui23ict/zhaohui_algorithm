#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void func_B()
{
    int m,n;
    while(cin>>n>>m&&m&&n){
        vector<int> head;
        vector<int> knight;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            head.push_back(num);
        }
        for(int i=0;i<m;i++){
            int num;
            cin>>num;
            knight.push_back(num);
        }
        sort(head.begin(),head.end());
        sort(knight.begin(),knight.end());
        int l1=0;
        int l2=0;
        int sum=0;
        while(l1<n&&l2<m){
            if(knight[l2]>=head[l1]){
                sum+=knight[l2];
                l1++;
                l2++;
            }
            else{
                l2++;
            }
        }
        if(l1<n){
            cout<<"Loowater is doomed!"<<endl;
        }
        else{
            cout<<sum<<endl;
        }
    }
}


bool cmp2(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    double l1=(double)a.first.first/a.first.second;
    double l2=(double)b.first.first/b.first.second;
    if(l1==l2){
        return a.second<b.second;
    }
    return l1>l2;
}

void func_C()
{
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        vector<pair<pair<int,int>,int>> data;
        for(int i=0;i<num;i++){
            int a,b;
            cin>>a>>b;
            data.push_back({{b,a},i+1});
        }
        sort(data.begin(),data.end(),cmp2);
        for(int i=0;i<num;i++){
            cout<<data[i].second;
            if(i!=num-1){
                cout<<" ";
            }
        }
        cout<<endl;
        if(n>0){
            cout<<endl;
        }
    }
}



void func_D()
{
    int n;
    cin>>n;
    int a[101][101]={0};
    int pre[101][101]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            pre[i][j]=a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            pre[i][j]+=pre[i][j-1];
        }
    }
    int ans=-99999999;
//     for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<pre[i][j]<<" ";
//        }
//        cout<<endl;
//     }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int p=i;p<n;p++){
                for(int q=j;q<n;q++){
                    int sum=0;
                    for(int k=i;k<=p;k++){
                        sum+=(pre[k][q]-pre[k][j]+a[k][j]);
                    }
                    ans=max(ans,sum);
                }
            }
        }
    }
    cout<<ans<<endl;
}





void func_G()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            sum+=num;
        }
        int ans=0;
        if(sum<n){
            ans=1;
        }
        if(sum>n){
            ans=(sum-n);
        }
        cout<<ans<<endl;
    }
}



void func_H()
{
    int t;
    cin>>t;
    while(t--){
        int color[26]={0};
        for(int i=0;i<4;i++){
            char a;
            cin>>a;
            color[a-'a']++;
        }
        int ans=-1;
        for(int i=0;i<26;i++){
            if(color[i]!=0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}


bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}


void func_J()
{
    int n,s;
    cin>>s>>n;
    vector<int> strength;
    vector<pair<int,int>> bouns;
//    for(int i=0;i<n;i++){
//        int num;
//        cin>>num;
//        strength.push_back(num);
//    }
    for(int i=0;i<n;i++){
        int num1,num2;
        cin>>num1>>num2;
        bouns.push_back({num1,num2});
    }
    sort(bouns.begin(),bouns.end(),cmp);
    int now=0;
    while(now<n){
        if(s>bouns[now].first){
            s+=bouns[now].second;
            now++;
        }
        else{
            break;
        }
    }
    if(now<n){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}

int main()
{
    func_D();
    return 0;
}
