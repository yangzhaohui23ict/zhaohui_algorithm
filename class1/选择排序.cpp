//#include <iostream>
//#include<vector>
//
//using namespace std;
//
////ѡ�����򣬱�����һ���ܼ򵥵��������������ҵ�һ����ֵ�����������0λ�õ���������Ȼ�󲻹�0��λ���ظ����ϲ�����
////����ѡ��������˵��ʱ�临�Ӷ���O��N^2��������ռ临�Ӷ���O��1��
//void exchange(vector<int> &a,int zuo,int you){
//    int mid=a[zuo];
//    a[zuo]=a[you];
//    a[you]=mid;
//}
//
//
//int main()
//{
//    int b[10]={2,5,4,6,7,8,3,1,9,10};
//    vector<int> a(b,b+10);
//    for(int i=0;i<10;i++){
//        int zuixiao=i;
//        for(int j=i;j<10;j++){
//            if(a[j]<a[zuixiao]){
//                zuixiao=j;
//            }
//        }
////  ����Ҫ���ľ���ȥ������Сֵλ���iλ��Ľ�����֮��Ͳ��ùܵ�iλ����
////  �����ֲ�����ʽ����һ�־��ǱȽϼ򵥵ģ�ֱ�ӽ�����ֵ��
////        int mid=a[zuixiao];
////        a[zuixiao]=a[i];
////        a[i]=mid;
////  ����Ҳ���Ե���һ�º�����ʵ��
//        exchange(a,i,zuixiao);
//    }
//    for(int i=0;i<10;i++){
//        cout<<a[i]<<' ';
//    }
//    return 0;
//}
