//#include <iostream>
//#include <vector>
//using namespace std;
//
////  ʱ�临�Ӷ���O��N^2��������ռ临�Ӷ���O��1��
////  �����ʱ�临�Ӷ�֮������Ҫ������
//
////  ����˼·����ʵ�����������0��0��λ��0��1��λ��һֱ���������飬��Ҫһ����ȷ�����������ģ�Ҳ����˵�������µ�һλ������һ�������󿴣�������ڻ���С�ڣ��ͺ�ǰ��Ľ���
//
////  �����ʱ�临�Ӷ��Ǻ����ݱ����й�ϵ�ģ���õ�����������ǿ���O(N)��ʱ�临�Ӷȸ���䣬����һ�㶼���������������еĹ��ơ�
//
//void exchange(vector<int> &a,int zuo,int you){
//    int mid=a[zuo];
//    a[zuo]=a[you];
//    a[you]=mid;
//}
//int main()
//{
//    int b[10]={2,5,4,6,7,8,3,1,9,10};
//    vector<int> a(b,b+10);
//    for(int i=0;i<a.size();i++){
//        for(int j=i;j>=0;j--){
//            cout<<j<<" ";
//            if(a[j]<a[j-1]){
//                exchange(a,j,j-1);
//            }
//            else{
//                break;
//            }
//        }
//        cout<<endl;
//    }
//    for(int i=0;i<a.size();i++){
//        cout<<a[i]<<" ";
//    }
//    return 0;
//}
