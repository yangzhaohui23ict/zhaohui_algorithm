#include <iostream>
#include <vector>
#include <math.h>
using namespace std;




/**

    ����һ���ֽ���������

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

    ��һ�����vector�ĺ������������Ч��

**/


void show_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}




/**

    ������ש��Ŀ������Ҫ����Ӧ���������ֳ�3�飬������Ӧ������ϳ����ĳ��������ά��

    ����Ϳ��Է�ɢһ�£�n�������ֳ�m���飬Ҫ��ô������

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

    �������ӻ��꣬Ҫ��N�춬����ש��ÿһ����ש����ά����10���ף���Щ��שϣ�������һ�����������������䣬ϣ��ʹ�õİ�װֽԽ��Խ�ã�������ٵİ�װֽ�����

    �Ȳ�Ҫ�ż�

    ���ȣ����������һ�������塣���ǿ��Կ��Ƿֽ������ӡ���������˵���ʽ��������������

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
