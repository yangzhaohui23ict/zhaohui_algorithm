#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;


void func_A()
{
    int n;
    cin>>n;
    for(int q=1;q<=n;q++){
        int a,b;
        cin>>a>>b;
        vector<int> num;
        for(int i=0;i<a;i++){
            int shu;
            cin>>shu;
            num.push_back(shu);
        }
        int dp[51][9005]={0};
        int dp2[51][9005]={0};
        int ans=0;
        for(int i=num[0];i<b;i++){
            dp[0][i]=1;
            dp2[0][i]=num[0];
            ans=ans>dp[0][i]?ans:dp[0][i];
        }

        for(int i=1;i<a;i++){
            for(int j=0;j<b;j++){
                if(j<num[i]){
                    dp[i][j]=dp[i-1][j];
                    dp2[i][j]=dp2[i-1][j];
                }
                else{
                    int buyong=dp[i-1][j];
                    int yong=dp[i-1][j-num[i]];

                    int buyong2=dp2[i-1][j];
                    int yong2=dp2[i-1][j-num[i]]+num[i];

                    dp[i][j]=dp[i-1][j];
                    dp2[i][j]=dp2[i-1][j];

                    if(yong+1>buyong){
                        dp[i][j]=yong+1;
                        dp2[i][j]=yong2;
                    }
                    if(yong+1==buyong){
                        if(yong2>buyong2){
                            dp2[i][j]=yong2;
                        }
                    }
                }
                ans=ans>dp[i][j]?ans:dp[i][j];
            }
        }
//        for(int i=0;i<a;i++){
//            for(int j=0;j<b;j++){
//                cout<<dp2[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<"Case "<<q<<": "<<ans+1<<" "<<dp2[a-1][b-1]+678<<endl;
    }
}




void func_B()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        int a[1010][1010]={0};
        for(int j=0;j<word.length();j++){
            a[j][1]=1;
        }
        for(int j=0;j<word.length()-1;j++){
            if(word[j]==word[j+1])
            a[j][2]=1;
        }
        for(int m=3;m<=word.length();m++){
            for(int n=0;n<=word.length()-m;n++){
                if(a[n+1][m-2]==1&&word[n]==word[n+m-1]){
                    a[n][m]=1;
                }
            }
        }
        int result[1010]={0};
        for(int m=1;m<=word.length();m++){
            result[m]=m;
            for(int n=1;n<=m;n++){
                if(a[m-n][n]==1){
//                    cout<<m<<" "<<n<<endl;
                    result[m]=min(result[m],result[m-n]+1);
                }
            }
        }
//        for(int m=1;m<=word.length();m++){
//            cout<<result[m]<<"  ";
//        }
//        cout<<endl;
        cout<<result[word.length()]<<endl;
//        for(int m=0;m<word.length();m++){
//            for(int n=0;n<=word.length();n++){
//                cout<<a[m][n]<<" ";
//            }
//            cout<<endl;
//        }
    }
}


int cmp(int a[20][200],int l1,int l2)
{
    for(int i=0;i<200;i++){
        if(a[l1][i]==a[l2][i]){
            continue;
        }
        else{
            if(a[l1][i]<a[l2][i]){
                return l1;
            }
            else{
                return l2;
            }
        }
    }
}

void func_C()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        int mat[20][200]={0};
//      这个的意思就是，到每一行的最短的节点路径
        int path[20][200]={0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        int hang[20][200]={0};
        int from[3]={-1,0,1};
        for(int i=0;i<m;i++){
            path[i][0]=i;
            hang[i][0]=mat[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=999999999;
                int choose=-1;
                for(int k=0;k<3;k++){
                    int xuan=(j+from[k]+m)%(m);
                    if(hang[xuan][i-1]<sum){
                        sum=hang[xuan][i-1];
                        choose=xuan;
                    }
                    else if(hang[xuan][i-1]==sum){
                        choose=min(xuan,choose);
                    }
                }
                path[j][i]=choose;
                hang[j][i]=sum+mat[j][i];
            }
        }
        int ans=999999999;
        int lujing=-1;
        for(int i=0;i<m;i++){
            if(hang[i][n-1]<ans){
                ans=hang[i][n-1];
                lujing=i;
            }
        }

        int walk[200]={0};

        for(int i=n-1;i>=0;i--){
            walk[i]=lujing;
            lujing=path[lujing][i];
        }
        for(int i=0;i<n-1;i++){
            cout<<walk[i]+1<<' ';
        }
        cout<<walk[n-1]+1<<endl;
        cout<<ans<<endl;
        break;
    }

}

void func_C2() {
    int aMat[100][10], aPrev[100][10];

    for (int nRows, nCols; cin >> nRows >> nCols; ) {

        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; cin >> aMat[j++][i]);
        }

        for (int j = nCols - 2; j >= 0; --j) {
            for (int i = 0; i < nRows; ++i) {

                int *p = &aMat[j + 1][0];

                int nMin = (i - 1 + nRows) % nRows, d = (i + 1) % nRows;

                if (p[i] < p[nMin] || (p[i] == p[nMin] && i < nMin)) {
                    nMin = i;
                }

                if (p[d] < p[nMin] || (p[d] == p[nMin] && d < nMin)) {
                    nMin = d;
                }

                aMat[j][i] += p[nMin];

                aPrev[j][i] = nMin;
            }
        }

        int nMin = min_element(&aMat[0][0], &aMat[0][nRows]) - &aMat[0][0];
        int nWeight = aMat[0][nMin];

        cout << nMin + 1;

        for (int j = 1; j < nCols; ++j) {

            nMin = aPrev[j - 1][nMin];
            cout << ' ' << nMin + 1;
        }

        cout << '\n' << nWeight << endl;
    }
}


void Random(int *a,int n,int l,int r)//生成范围在l~r的随机数
{
	srand(time(0));  //设置时间种子
	for(int i=0;i<n;i++){
		a[i]=rand()%(r-l+1)+l;//生成区间r~l的随机数
	}
}

void Print(int *a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int rand_make()
{
	int n=16;//数组元素的个数，即生成随机数的个数
	int a[n];
	Random(a,n,1,5);//生成随机数的通常范围为0~32767，这里通过取模控制取值为0~100
	cout<<8<<" "<<2<<endl;
	Print(a,n);
	return 0;
}

//int time=INT_MAX;
//
//void digui_E(int n,int t,int time[60],int nowstation)
//{
//    if(t<0){
//        return;
//    }
//    if(nowstation==0){
//        time=min(time,t);
//    }
//    if(nowstation==0||nowstation==n-1){
//
//    }
//}

void func_E()
{
    int n,t;
    for(int ca=1;cin>>n&&n;ca++){
        if(n==0){
            break;
        }
        cin>>t;
        int time[60]={0};
        int sum=0;
        for(int i=0;i<n-1;i++){
            cin>>time[i];
            sum+=time[i];
        }
        int m1,m2;
        cin>>m1;
        int left_go[300]={0};
        for(int i=0;i<m1;i++){
            cin>>left_go[i];
        }
        cin>>m2;
        int right_go[300]={0};
        for(int i=0;i<m2;i++){
            cin>>right_go[i];
        }

        if(left_go[0]+sum>t){
            cout<<"Case Number "<<ca<<": impossible"<<endl;
            continue;
        }

        int have_goto_right[60][300]={0};
        int have_goto_left[60][300]={0};

        for(int j=0;j<m1;j++){
            have_goto_right[0][left_go[j]]=1;
        }
        for(int j=0;j<m2;j++){
            have_goto_left[n-1][right_go[j]]=1;
        }


//      绘制时刻表，用来确定什么时间段在对应站点有往左或者往右的车次 (横向是时间，纵向是站点)
        int have_use_time=time[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<m1;j++){
                have_goto_right[i][left_go[j]+have_use_time]=1;
            }
            have_use_time+=time[i];
        }

        have_use_time=time[n-2];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m2;j++){
                have_goto_left[i][right_go[j]+have_use_time]=1;
            }
            have_use_time+=time[i-1];
        }

        int dp[60][300];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=t;j++){
                dp[i][j]=99999;
            }
        }
        dp[n-1][t]=0;
        for(int i=t-1;i>=0;i--){
            for(int j=0;j<n;j++){
                dp[j][i]=dp[j][i+1]+1;
                if(j<n-1&&have_goto_right[j][i]==1&&i+time[j]<=t){
                    dp[j][i]=min(dp[j][i],dp[j+1][i+time[j]]);
                }
                if(j>0&&have_goto_left[j][i]==1&&i+time[j-1]<=t){
                    dp[j][i]=min(dp[j][i],dp[j-1][i+time[j-1]]);
                }
            }
        }

//        for(int i=0;i<n;i++){
//            for(int j=0;j<=t;j++){
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<"Case Number "<<ca<<": "<<dp[0][0]<<endl;
//        cout<<dp[0][0]<<endl;
    }
}





void func_F()
{
    int n;
    int ca=1;
    while(cin>>n&&n){
        vector<pair<pair<int,int>,int>> mian;
        for(int i=0;i<n;i++){
            vector<int> cube;
            for(int j=0;j<3;j++){
                int num;
                cin>>num;
                cube.push_back(num);
            }
            sort(cube.begin(),cube.end());
            mian.push_back({{cube[0],cube[1]},cube[2]});
            mian.push_back({{cube[0],cube[2]},cube[1]});
            mian.push_back({{cube[1],cube[2]},cube[0]});
        }
        for(int i=0;i<mian.size();i++){
            for(int j=i;j<mian.size();j++){
                if(mian[i].first.first>mian[j].first.first&&mian[i].first.second>mian[j].first.second){
                    pair<pair<int,int>,int> tep=mian[j];
                    mian[j]=mian[i];
                    mian[i]=tep;
                }
            }
        }
        int ans[100]={0};
        ans[0]=mian[0].second;
        for(int i=1;i<mian.size();i++){
            ans[i]=mian[i].second;
            for(int j=0;j<i;j++){
                if(mian[i].first.first>mian[j].first.first&&mian[i].first.second>mian[j].first.second){
                    ans[i]=max(ans[i],ans[j]+mian[i].second);
                }
            }
//            cout<<mian[i].first.first<<"   "<<mian[i].first.second<<endl;
        }
        int fin=-1;
        for(int i=1;i<mian.size();i++){
            fin=max(fin,ans[i]);
        }
        cout<<"Case "<<ca++<<": maximum height = "<<fin<<endl;
//        cout<<fin<<eCndl;
    }
}


void func_G()
{
    int from,to;

    int a[100000000][10]={0};
    for(int i=1;i<100000000;i++){
        int num=i;
        for(int j=0;j<10;j++){
            a[i][j]=a[i-1][j];
        }
        while(num){
            a[i][num%10]++;
            num=num/10;
        }
    }

    while(cin>>from>>to&&(from||to)){
        int p=from;
        int q=to;
        from=min(p,q);
        to=max(p,q);
        for(int i=0;i<10;i++){
            cout<<a[to][i]-a[from-1][i];
            if(i!=9){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

long long int count_num(int num,int wei)
{
    long long int sum=0;
    for(int i=1;i<12;i++){
        int left=num/(int)pow(10,i)-(wei==0);
        sum+=left*((int)pow(10,i-1));
        int m=(num%(int)pow(10,i)-num%(int)pow(10,i-1))/(int)pow(10,i-1);
        if(m>wei){
            sum+=(int)pow(10,i-1);
        }
        else if(m==wei){
            sum+=(num%(int)pow(10,i-1)+1);
        }
        if(num<(int)pow(10,i)){
            break;
        }
    }
    return sum;
}

void func_G2()
{
    int from,to;
    while(cin>>from>>to&&(from||to)){
        long long int ans[10]={0};
        int p=from;
        int q=to;
        from=min(p,q);
        to=max(p,q);
        for(int i=0;i<10;i++){
            ans[i]=count_num(to,i)-count_num(from-1,i);
        }
        for(int i=0;i<10;i++){
            cout<<ans[i];
            if(i!=9){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}


int main()
{
    func_G2();
    return 0;
}
