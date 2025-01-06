#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


/**

    �ո�����һ�£�Ҳû�ҵ�ʲô���õıʼ��������ֻ���Ƚ������ˡ�

    1.�����ݹ���Ϊ���͵ݹ�ʱ�临�ӶȵĹ��㣬��������������������ֵ��
        ��򵥵Ŀ϶����Ǳ����������������ǿ��Ե���һ�£�дһ���ݹ�汾�ġ�

    ���������⣬���ǿ��Լ򵥵Ĺ����ܽ�����ݹ������ʱ�临�Ӷȵļ��㷽ʽ��T(N)=a*T(N/b)+O(N^d)
    Ҳ���ǣ�������ݹ�������ģ*����������+��ȥ�����ӹ���֮��Ĵ����ʱ�临�Ӷȣ�ֻҪ��������ͬ��ģ�ľͿ�����������
    �������������ĸ��ӶȾ���2*T(N/2)+O(1)

    �������������ʽ�����Ի�������������֪��ʱ�临�Ӷȵı��ַ�ʽ��������Ҫ���м���logb(a)���Һ�d���жԱ�
    ����ط�����ǰ��֤���õģ�
    ���С�ڣ�����O(N^d)��������ڣ�����O(N^d*logN)��������ڣ�����O(N^log(b,a))



**/

int find_max(vector<int> &a,int L,int R)
{
    if(L==R){
        return a[L];
    }
    // һ��С�취�����Ǳ���һЩ�����������Ӱ�ȫ����и�ɻ�
    int mid=L+(R-L)/2;
    int zuo=find_max(a,L,mid);
    int you=find_max(a,mid+1,R);
    return max(zuo,you);
}




/**

    �鲢��������˼·�������е㣬�Ƚ�����������ٽ����ұ�����Ȼ�󼯺�������
    ���ȣ����ϲ��������������������飬һ��һ��ָ�룬�߶Աȱ���Ϳ����ˡ�
    ������������ʵ���ǵݹ��ˡ�

    �պÿ��Կ�һ������鲢�����ʱ�临�Ӷȣ�2*T(N/2)+O(N^1);��������֮ǰ�ᵽ�Ĺ�ʽ,������ȣ����Ը��ӶȾ���O(N*logN)������ռ临�Ӷ���O��N)

**/

void mergee(vector<int> &a,int l,int mid,int r)
{
    vector<int> help;
    int l1=l;
    int l2=mid+1;
    while(l1<=mid&&l2<=r){
        help.push_back(a[l1]<=a[l2]?a[l1++]:a[l2++]);
    }
    while(l1<=mid){
        help.push_back(a[l1++]);
    }
    while(l2<=r){
        help.push_back(a[l2++]);
    }
    for(int i=0;i<help.size();i++){
        a[l+i]=help[i];
    }
}

void guibing_sort(vector<int> &a,int l,int r)
{
    if(l==r){
        return;
    }
    int mid=l+((r-l)/2);
    guibing_sort(a,l,mid);
    guibing_sort(a,mid+1,r);
    mergee(a,l,mid,r);
}

void show(vector<int> &a)
{
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}


/**
    ��������˼һ�£�Ϊʲô�鲢����Ϳ���ʵ��ʱ�临�Ӷ��ϵ��Ż�����ʵ��Ƚ��ڹ鲢����֮ǰ��N2���Ӷȵ������˷��˴���ʱ�������Աȡ��Ա�N�Σ�����֪��һ������λ�á�
    ��εıȽ���Ϊֻ������ȷ��һ���������ڱȽ���Ϊ�Ĵ����˷ѡ�
    ���ڹ鲢����֮�У�ÿ�εıȽ���Ϣ���Ǵ��������ģ������һ����������Ĳ��֣�Ϊ�����������ṩ�İ�����
**/








/**
    С�����⣺���Ƕ��������е�ÿһλ���֣��������С����λ��������Ԫ�صĺͣ���Ϊ���Ԫ�ص�С�͡�Ȼ��ͳ�����������С�͡�

    ������⣬�����ⷨ������ð�ݣ�ÿһ��Ԫ�ر���һ�¡��������Դ������Ż��ռ䡣�ڹ鲢����Ĺ����У����ǾͿ���ʵ���������

    ���ȣ�����ӽǣ�����һ��Ԫ�أ������ұ��ж��ٸ��������󣬾ͻ�������ٸ�С�͡����磬1�ұ���4������������ô1�ͻṱ��4��С�͡�

    ��������⣬���Թ鲢�����ʱ��Ϳ���˳��ʵ���ˡ�ֻҪ�޸�merge�Ϳ����ˡ�

    ����ط����Լ�д��ʱ�򣬺��ӵ���һ�����⣬���������һ��ʼ�鲢����������������ȵ�����£���Ҫ���ȷŽ�ȥ�ұߵ�

    �ڷ���ȷʵ�Ҵ��������Ҫ�ǵ�����ұߵ��������Ҳ���Ǳ������Ҫ��ģ��������ǲ�����Ϊ�Ƚ�û�бȵ��ͺ��ӵ�����Ҫ�ýű�ֱ�Ӽ����ж��ٸ����������Ե������������ֵ�С��

**/


int mergee_xiaohe(vector<int> &a,int l,int mid,int r)
{
    vector<int> help;
    int l1=l;
    int l2=mid+1;
    int ans=0;
    while(l1<=mid&&l2<=r){
        if(a[l1]<a[l2]){
            ans+=a[l1]*(r-l2+1);
            help.push_back(a[l1++]);
        }
        else{
            help.push_back(a[l2++]);
        }
    }
    while(l1<=mid){
        help.push_back(a[l1++]);
    }
    while(l2<=r){
        help.push_back(a[l2++]);
    }
    for(int i=0;i<help.size();i++){
        a[l+i]=help[i];
    }
    return ans;
}

int guibing_sort_xiaohe(vector<int> &a,int l,int r)
{
    if(l==r){
        return 0;
    }
    int mid=l+((r-l)/2);
    return guibing_sort_xiaohe(a,l,mid)+guibing_sort_xiaohe(a,mid+1,r)+mergee_xiaohe(a,l,mid,r);
//    guibing_sort_xiaohe(a,l,mid);
//    guibing_sort_xiaohe(a,mid+1,r);
//    mergee_xiaohe(a,l,mid,r);
}






/**
    ����ԣ�������ߵ������ұߵ���Ҫ����������֮ǰ��С�������ǵ�Ч�ġ�
**/








/**
    �����������⣺����һ�������һ������Ҫ���С�ڵ���������ķ����������ߣ�����������ķ���������ұߡ�

    ˵���������ڲ�����Ҫ����

    Ҫ��ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)

    ������ԣ����ڵ�ǰ���������������

        ���С�ڵ�����������Ͱ�������ֺ�С�ڵ����������һ����������Ȼ���������С�ڵ�������һλ��֮����һ������

        ������ڣ��Ǿ�ʡ���ˣ�ֱ��i++������һ����

    ԭ���������˵�λ�õ���Ϣ����������Ҫ��ȷ�����������ģ���������С�ڵ���������һλ�ĸ�����Ǳ���ʵ�ʡ�

**/

exchange(vector<int> &a,int l,int r)
{
    int mid=a[l];
    a[l]=a[r];
    a[r]=mid;
}

int tough_sort(vector<int> &a,int num,int l,int r)
{
    int small_space=l-1;
    for(int i=l;i<=r;i++){
        if(a[i]<=num){
            exchange(a,small_space+1,i);
            small_space+=1;
        }
    }
    return small_space;
}



/**
    �����������⣺����һ�������һ������Ҫ���С��������ķ����������ߣ�����������ķ����м䣬����������ķ���������ұߡ�

    ˵���������ڲ�����Ҫ����

    Ҫ��ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)

    ������ԣ����ڵ�ǰ���������������

        ���С����������Ͱ�������ֺ�С���������һ����������Ȼ���������С�ڵ�������һλ��֮����һ������

        ��������������ʲô��������ֱ������һ��

        ������ڣ��Ͱ�������ֺʹ����������һ����������������������һλ�����ǣ��������ʱ��i���ܱ�
        ��Ϊ��������¹����ģ�������Ҫ�ж������Ҫȥ���Ķ�Ӧ��λ������

        �����������iײ���˵�ʱ���ж�ֹͣ��

**/

vector<int> Nederlanden_sort(vector<int> &a,int num,int l,int r)
{
    int small_space=l-1;
    int big_space=r+1;
    for(int i=0;i<a.size()&&i!=big_space;i++){
        if(a[i]<num){
            exchange(a,small_space+1,i);
            small_space+=1;
        }
        if(a[i]>num){
            exchange(a,big_space-1,i);
            big_space-=1;
            i--;
        }
    }
    vector<int> ans;
    ans.push_back(small_space);
    ans.push_back(big_space);
    return ans;
}


/**

    �������������ݣ��Ϳ��Խ��������ˡ�

    ����1.0�汾�������������У������һ������Ϊ��������ʵ�ֻ��֣�����֮�����һ�����ʹ�������ĵ�һ������������Ȼ�����������������У��ظ��������

        ����滻�����Ͳ��ö��ˣ����ҷֿ��ݹ�Ϳ��ԣ��������֣������һ��������ġ���Ϊÿһ�ζ��ź���һ������λ�á�

    ����2.0�汾�����ú����������⣬���Ǳ�������ͬ���ݵ����⣬ͬ�������һ�����ʹ�������ĵ�һ��������������ʱ���ǵ��������������ö��ˣ��������ݹ�

        ���1.0�汾��΢��һЩ����Ϊ��㶨����ȵ����֡�

    ���ǣ�������1.0����2.0�汾������ʱ�临�Ӷȶ���O��N^2������Ϊ����������ӣ����Ƕ���һ��ֻ�ܴ���һ�����֡�

    ��ˣ�������3.0�汾����˼֮ǰ�����汾�����⣬��ʵ����ʱ�临�ӶȲ�������⣬���ǻ���ֵ�ҵĲ��á���������õĻ���ֵӦ�����е㡣���ʱ����N*logN

    3.0�汾˼·�����ڻ���ֵ�ĵ���������һ����������滻�����һ��λ���ϣ�Ȼ���ظ�ִ��1.0,2.0�汾�����ﾭ�����ʼ��㣬�����ʱ�临�Ӷ���N*logN

        ��Ϊ���ʱ��Ͳ��ٴ��������ϵ���������ˡ�

**/


void quick_sort_I(vector<int> &a,int l,int r)
{
    if(l<r){
        int num=a[r];
        int cut=tough_sort(a,num,l,r-1);
        exchange(a,cut+1,r);
        quick_sort_I(a,l,cut);
        quick_sort_I(a,cut+2,r);
    }
}



void quick_sort_II(vector<int> &a,int l,int r)
{
    if(l<r){
        int num=a[r];
        vector<int> space=Nederlanden_sort(a,num,l,r-1);
        exchange(a,space[1],r);
        quick_sort_I(a,l,space[0]);
        quick_sort_I(a,space[1]+1,r);
    }
}



void quick_sort_III(vector<int> &a,int l,int r)
{
    if(l<r){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(l,r);
        exchange(a,distrib(gen),r);
        int num=a[r];
        vector<int> space=Nederlanden_sort(a,num,l,r-1);
        exchange(a,space[1],r);
        quick_sort_I(a,l,space[0]);
        quick_sort_I(a,space[1]+1,r);
    }
}



void Random(int *a,int n,int l,int r)//���ɷ�Χ��l~r�������
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(l,r);
	for(int i=0;i<n;i++){
		a[i]=distrib(gen);//��������r~l�������
	}
}



void check()
{
    int n=10;
    int a[n];
    Random(a,n,0,9);
    vector<int> input(a,a+10);
    show(input);
    quick_sort_III(input,0,input.size()-1);
    int e=input[0];
    for(int i=0;i<input.size();i++){
        if(input[i]>=e){
            e=input[i];
        }
        else{
            cout<<"wrong"<<endl;
            break;
        }
    }
    show(input);
    return;
}





int main()
{
    vector<int> a;
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    a.push_back(-1);
    cout << find_max(a,0,a.size()-1) << endl;
    guibing_sort(a,0,a.size()-1);

    int b[5]={1,3,4,2,5};
    vector<int> arr(b,b+5);
    show(arr);
    guibing_sort_xiaohe(arr,0,arr.size()-1);
    cout<<guibing_sort_xiaohe(arr,0,arr.size()-1)<<endl;

    cout<<"---------------------"<<endl;
    for(int i=0;i<10;i++){
        check();
    }
    cout<<"---------------------"<<endl;
    tough_sort(arr,3,0,arr.size()-1);
    show(arr);



    return 0;
}
