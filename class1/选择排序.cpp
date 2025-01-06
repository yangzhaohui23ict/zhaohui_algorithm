//#include <iostream>
//#include<vector>
//
//using namespace std;
//
////选择排序，本身是一个很简单的任务，在数组中找到一个最值，把这个数和0位置的数交换，然后不管0号位，重复如上操作。
////对于选择排序来说，时间复杂度是O（N^2），额外空间复杂度是O（1）
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
////  这里要做的就是去进行最小值位点和i位点的交换，之后就不用管到i位点了
////  有两种操作方式，第一种就是比较简单的，直接交换数值。
////        int mid=a[zuixiao];
////        a[zuixiao]=a[i];
////        a[i]=mid;
////  或者也可以调用一下函数来实现
//        exchange(a,i,zuixiao);
//    }
//    for(int i=0;i<10;i++){
//        cout<<a[i]<<' ';
//    }
//    return 0;
//}
