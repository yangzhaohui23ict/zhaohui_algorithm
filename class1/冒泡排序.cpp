//#include <iostream>
//#include <vector>
//using namespace std;
//
//void exchange(vector<int> &a,int zuo,int you){
//    int mid=a[zuo];
//    a[zuo]=a[you];
//    a[you]=mid;
//}
//
////  一种高级交换玩法，功能上和上面的一样，但是能够更加的节省内存，是一个很抖机灵的写法。
////  a=a^b;
////  b=a^b;
////  a=a^b;
////  这样之后就交换过来了。这是因为0异或任何数结果都是这个数，任意一个数对自己异或都是0，通过这两个原理，上述操作就可以实现交换。
////  但是你需要确保a,b指向的内存是不同的。换种说法，这个函数这里的两个参数，是不可以一样的。因为如果一样，会把这个位置的数摸成0。
////  没事别这么干，装个B没问题。
//void swapy(vector<int> &a,int zuo,int you){
////  异或运算，也可以看作是无进位相加。
//    a[zuo]=a[zuo]^a[you];
//    a[you]=a[zuo]^a[you];
//    a[zuo]=a[zuo]^a[you];
//}
//
////时间复杂度是O（N^2），额外空间复杂度是O（1）
////冒泡排序就是，从左开始，两两对比，按照从大到小或者从小到大的要求，叫小的数或者大的数排在右边，直到最右边，然后，不管最右边的数。当然，左右同理都可以
//int main()
//{
//    cout<<"冒泡排序"<<endl;
//    int b[10]={2,5,4,6,7,8,3,1,9,10};
//    vector<int> a(b,b+10);
//    for(int i=9;i>=0;i--){
//        for(int j=0;j<i;j++){
//            if(a[j]>a[j+1]){
//                swapy(a,j,j+1);
//            }
//        }
//    }
//    for(int i=0;i<10;i++){
//        cout<<a[i]<<' ';
//    }
//    return 0;
//}
