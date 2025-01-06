//#include <iostream>
//#include <vector>
//using namespace std;
//
////  时间复杂度是O（N^2），额外空间复杂度是O（1）
////  是这个时间复杂度之下最重要的排序
//
////  整体思路：其实就是总最左边0到0号位，0到1号位，一直到整个数组，我要一步步确保这个是有序的，也就是说，对于新的一位，让他一步步往左看，如果大于或者小于，就和前面的交换
//
////  这里的时间复杂度是和数据本身有关系的，最好的情况下甚至是可以O(N)。时间复杂度概念补充，这里一般都是以最差情况来进行的估计。
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
