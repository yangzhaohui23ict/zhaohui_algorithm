#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/**

    ������ȶ��ԣ�������ͬ��С�����֣���������֮�󣬱˴�֮����໥λ�ò��ı䡣

    �������һ������£�û��ʲô�ô����������ڻ������͵������µ�ʱ��

    ��������Ƿǻ��������飬����˵һ���࣬�ж�����ԣ�����ϣ�����ݶ�����Խ������򣬸�������a�ź�֮���һ�Ҫ��������b������

    ��ô���ʱ������������ϣ����b�����ȼ���ߣ�����bһ��������»���ͨ��a�����򣬱�����Դ��������������


    ֮ǰ�ᵽ��һЩ�����㷨�������ȶ��������з��ࡣ

    �ȶ�����ð��������Ȳ�������������������Ȳ�ǰ�壩���鲢������Ҫ��merge����ȿ�����߾����ˣ����������򣬼�����������Ͱ�ȳ�Ͱ�������ڱȼ۵Ķ����ȶ���

    ���ȶ�����ѡ�����򣬿��ţ��ڵ�һ�����������ʱ����������ˣ������������ɴ�С���ѵ�ʱ����ƻ��ˣ�

    ���⣬��Ȼ�鲢�������򣬿��Ŷ���NlogN����ģ����ǿ���ʵ��֤����������������͵ģ���������û���ÿ��š�

    Ŀǰ�����㷨�ļ��ޣ�ʱ����NlogN�������ʱ��ǰ����Ҫ�ȶ�������ҪO��N���Ŀռ��ȶ��ȡ�

    ���⣬���ŵķ����䲽���У�������������������ʵ����һ��0-1���֣�����ͬ����������ż������0-1���ֵ����ݡ�

    ������Ŀ�д��ڵ��Ż����ԣ������飨<60��ֱ���ò������򶼿��ԣ���ʹ�õݹ�����������Ŀ����Ҫ�ǽ�ʡ�ռ䣬����������������ܵ͡�

**/











/**

    ��ϣ��unodered����set��mapûɶ���𣬱�������һ�����������ǵ�key�ʹ�һ��value������

        ���Բ�����set����map������˵�ǹ�ϣ��

        ��ϣ����ʹ�õĹ����У�Ĭ�ϣ���ɾ�Ĳ鶼�ǳ�������ġ�

        ���⣬��������ʹ�õĹ�ϣ��Ҳ��Ҫ�����������ͣ���Ի������ͣ���ϣ���ǰ�ֵ���ݵġ���ռ�ռ�������ݵĿռ䡣

        ����������Լ�������������ͣ���ô��ϣ��Ͳ��´��һ�ݡ����Ǵ����ڴ��ַ�������ô��ݡ���ռ�ռ�һ��8�ֽڡ�

        Ҳ������Բ�ͬ���������ͣ�ʹ����ǳ������

    �����ordered�������Ǻ͹�ϣ����ȣ�key�������������е��ص㡣��ȹ�ϣ����Ϊ�����������Ϣ�������ڹ�ϣ��Ĺ��ܻ����ϣ�����һЩ���ܲ���:

        ����key�������С

        ������key���������Ԫ��

        ����ԭ����ѣ���һ��ʵ��ƽ������ԭ�������������AVL��SB���ȵ�

**/










/**

    ֮ǰд���˵ģ�������������������

**/

void Random(int *a,int n,int l,int r)//���ɷ�Χ��l~r�������
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(l,r);
	for(int i=0;i<n;i++){
		a[i]=distrib(gen);//��������r~l�������
	}
}





/**

    ������Ľڵ�ṹ

**/


struct dan_node
{
    int value;
    dan_node* next;
};


dan_node* creatlist(int n) {
	dan_node* Head=new dan_node;    //ͷ�ڵ� ���洢����
	Head->next = NULL;
	dan_node* pre = Head;  //ָ����һ���ڵ�Ĺ���ֵ

    int a[10];
    Random(a,10,0,9);
//    for(int i=0;i<10;i++){
//        cout<<a[i]<<"  ";
//    }
//    cout<<endl;
	for (int i = 0;i < n;i++) {
		dan_node* temp = new dan_node;
		temp->value=a[i];
		pre->next = temp;
		pre = temp;
		temp->next = NULL;
	}

	return Head->next;
}


void show_list(dan_node* head)
{
    dan_node* pre=head;
    while(pre){
        cout<<pre->value<<"  ";
        pre=pre->next;
    }
    cout<<endl;
}


dan_node* reverse_list(dan_node* head)
{
    show_list(head);
    dan_node* fan_head=NULL;

	dan_node* cur=head;
	while(cur){
        dan_node* next=cur->next;
        cur->next=fan_head;
        fan_head=cur;
        cur=next;
	}
    show_list(fan_head);
	return fan_head;
}


/**

    ˫����Ľڵ�ṹ

**/


struct shuang_node
{
    int value;
    shuang_node* next;
    shuang_node* last;
};



shuang_node* creatlist_shuang(int n) {
	shuang_node* Head=new shuang_node;    //ͷ�ڵ� ���洢����
	Head->next = NULL;
	Head->last = NULL;
	shuang_node* pre = Head;  //ָ����һ���ڵ�Ĺ���ֵ


    int a[10];
    Random(a,10,0,9);

	for (int i = 0;i < n;i++) {
		shuang_node* temp = new shuang_node;
		temp->value=a[i];
		pre->next = temp;
		temp->last=pre;
		pre = temp;
		temp->next = NULL;
	}

	return Head->next;
}


void show_list_shuang(shuang_node* head)
{
    shuang_node* pre=head;
    while(pre){
        cout<<pre->value<<"  ";
        pre=pre->next;
    }
    cout<<endl;
}


/**
    ���ֻ�Ƿ�ת˫������ֻ��Ϊ������Ļ�����ʵûɶ���壬�Ͼ�������ݣ�ֱ��˳������
**/

void show_list_shuang_reverse(shuang_node* head)
{
    shuang_node* pre=head;

    while(pre->next!=NULL){
        pre=pre->next;
    }

    while(pre){
        cout<<pre->value<<"  ";
        pre=pre->last;
    }
    cout<<endl;
}



shuang_node* reverse_list_shuang(shuang_node* head)
{
//    show_list_shuang(head);
    shuang_node* fan_head=NULL;

    shuang_node* cur=head;

    while(cur){
        cur->last=cur->next;
        cur=cur->next;
    }

	cur=head;
	while(cur){
        shuang_node* next=cur->next;
        cur->next=fan_head;
        fan_head=cur;
        cur=next;
	}
//    show_list_shuang(fan_head);
	return fan_head;
}





/**

    ��ӡ������������Ĺ�������
    1,2,5
    0,2,3,5
    ��������ָ�룬ָ����������˭С˭���ƣ���Ⱦʹ�ӡ����ͬ����ƶ���ֻҪ��һ�������ˣ������ͽ�����

**/


int a[3]={1,2,5};
int b[4]={0,2,3,5};
int c[9]={1,2,3,4,5,4,3,2,1};

vector<int> a_vec(a,a+3);
vector<int> b_vec(b,b+4);
vector<int> c_vec(c,c+9);

dan_node* creatlist_vector(vector<int> a)
{
	dan_node* Head=new dan_node;    //ͷ�ڵ� ���洢����
	Head->next = NULL;
	dan_node* pre = Head;  //ָ����һ���ڵ�Ĺ���ֵ

	for (int i = 0;i < a.size();i++) {
		dan_node* temp = new dan_node;
		temp->value=a[i];
		pre->next = temp;
		pre = temp;
		temp->next = NULL;
	}

	return Head->next;
}

void print_same_part(dan_node* a,dan_node* b)
{
    dan_node* biao1=a;
    dan_node* biao2=b;
    while(biao1&&biao2){
        if(biao1->value==biao2->value){
            cout<<biao2->value<<" ";
            biao1=biao1->next;
            biao2=biao2->next;
            continue;
        }
        if(biao1->value>biao2->value){
            biao2=biao2->next;
            continue;
        }
        if(biao1->value<biao2->value){
            biao1=biao1->next;
            continue;
        }
    }
    cout<<endl;
}


/**

    �ж�һ�������ǲ��ǻ�������

    ����뵽�ķ�ʽ��������Ȼ����������ͬ���жϡ�

    ���ߣ�ͨ��ջ��ʵ�֡�Ҳ����һ���ģ�����ջ�Ƚ������������ʵ������

    ���Ҫ��ʡ�ռ䣬����ֻ���Ұ벿�ַŵ�ջ���档

    �������ʱ���������һ�����⣬������ô֪�������Ұ벿�֣�

    ���������������ָ�롣��ָ��һ����������ָ��һ��һ������ָ�������ʱ����ָ�������е�λ�á�

    ���ǣ���Ҫע��ĵط����ǣ�����ָ���������ĳ�����ż���Լ���ָ��Ҫ���о����м��Լ��м�ƫ��һλ������ط�����Ҫ���������

    �����Ҫչ���Լ����ƣ�ʹ��O��1���Ŀռ临�Ӷȣ���ô���Կ���ָ�����������ͷ��ʼ�ߣ������м䣬�����һ�������ġ�

    ����ܿ���code


**/

void huiwen_check_esay_way(dan_node* a)
{
    stack<int> zhan;
    dan_node* pre=a;
    while(pre){
        zhan.push(pre->value);
        pre=pre->next;
    }
    pre=a;
    int flag=0;
    while(pre){
        if(pre->value!=zhan.top()){
            flag=1;
            break;
        }
        pre=pre->next;
        zhan.pop();
    }
    if(flag){
        cout<<"�ǻ���"<<endl;
    }
    else{
        cout<<"����"<<endl;
    }
}





/**

    ͨ������ķ������������޵ļ���������ʵ�������������

**/


void huiwen_check_hard_way(dan_node* a)
{
    dan_node* fast=a;
    dan_node* slow=a;
    //����ָ��
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    fast=slow->next;
    slow->next=NULL;
    dan_node* temp=NULL;
    while(fast){
        temp=fast->next;
        fast->next=slow;
        slow=fast;
        fast=temp;
    }

    dan_node* zuo=a;
    dan_node* you=slow;
    int flag=0;
    while(zuo&&you){
        if(zuo->value!=you->value){
            flag=1;
            break;
        }
        else{
            zuo=zuo->next;
            you=you->next;
        }
    }

    if(flag){
        cout<<"�ǻ���"<<endl;
    }
    else{
        cout<<"����"<<endl;
    }
    show_list(a);
    //  ��ת�������˽��֮�󣬱������ˣ�Ҫ��������ת�������͵����Ƕ���������

    dan_node* last_node=slow->next;
    slow->next=NULL;


    while(last_node){
        temp=last_node->next;
        last_node->next=slow;
        slow=last_node;
        last_node=temp;
    }
    show_list(a);

}





/**

    ����������ĳֵ���ֳ�Ϊ���С���м���ȣ��ұߴ����ʽ

    ��һ�����ֺ����������˼��

    �������Ǳ��ԣ����ǿ�������ת���飬Ȼ�����������partion�������õ����飬�Ļ�ȥ��������ݾͿ����ˡ�

    �������ݿ���ֱ���ǽڵ����͵ġ��ܼ�

    ������������ԣ���Ҫ�������ٸ��ռ�ʹ�á����������Ϳ���ʵ��������⡣

    �ֱ���С�ڣ����ڣ��������������ͷ��β������ı����ǽڵ㡣ͨ��ÿ��һ�����ͽ�������ݽڵ����ӵ���Ӧ������β��

    ��������������������Ϳ�����

**/


void list_partion(dan_node* a,int num)
{
    dan_node* small_begin=NULL;
    dan_node* small_end=NULL;
    dan_node* equal_begin=NULL;
    dan_node* equal_end=NULL;
    dan_node* big_begin=NULL;
    dan_node* big_end=NULL;

    dan_node* cur=a;

    while(cur){
        if(cur->value<num){
            if(small_begin==NULL){
                small_begin=cur;
                small_end=cur;
            }
            else{
                small_end->next=cur;
                small_end=cur;
            }
        }
        else if(cur->value==num){
            if(equal_begin==NULL){
                equal_begin=cur;
                equal_end=cur;
            }
            else{
                equal_end->next=cur;
                equal_end=cur;
            }
        }
        else{
            if(big_begin==NULL){
                big_begin=cur;
                big_end=cur;
            }
            else{
                big_end->next=cur;
                big_end=cur;
            }
        }
        cur=cur->next;
    }

    if(small_end){
        small_end->next=NULL;
    }
    if(equal_end){
        equal_end->next=NULL;
    }
    if(big_end){
        big_end->next=NULL;
    }


    show_list(small_begin);
    show_list(equal_begin);
    show_list(big_begin);

    dan_node* ans=new dan_node;
    dan_node* res=ans;
    if(small_begin!=NULL){
        while(small_begin){
            ans->next=small_begin;
            small_begin=small_begin->next;
            ans=ans->next;
        }
    }
    if(equal_begin!=NULL){
        while(equal_begin){
            ans->next=equal_begin;
            equal_begin=equal_begin->next;
            ans=ans->next;
        }
    }
    if(big_begin!=NULL){
        while(big_begin){
            ans->next=big_begin;
            big_begin=big_begin->next;
            ans=ans->next;
        }
    }

    show_list(res->next);
    return;
}



/**

    ���ƺ������ָ��ڵ������

    ����һ�������ĵ������������һ��randָ�룬���ָ�����ֻ�������е�һ���ڵ㡣

    Ȼ��������Ҫ������������һ�������ؼ�����randָ��ҲҪһ��

    ������Ҫʹ�ö���ռ䣬��ϣ��Ϳ��ԣ��ܼ򵥣�һ��map���Ͻڵ㣬�½ڵ㣩��Ȼ�����һ�������Ѷ�Ӧ�ڵ�ָ��ָ���Ӧ�½ڵ�

    ��󷵻ض�Ӧ��һ���½ڵ�Ϳ����ˡ�

    ��ô�������ˣ����ù�ϣ��ķ�ʽ��ô����

    ����һ���µĽڵ㣬�ͷ���ԭʼ����Ľڵ���棬��ʱ�������1,1,2,2,3,3���������ǿ���һ��һ�����á���ʱֻ����randָ��

    ��ônextָ����Ȼ�����ҵ���Ӧ��randָ��ڵ㡣������������õ��µ�����

**/




int main()
{

//    dan_node* a=creatlist(10);
//    reverse_list(a);

//    shuang_node *a=creatlist_shuang(10);
//    show_list_shuang(a);
//    shuang_node *b=reverse_list_shuang(a);
//    show_list_shuang(b);
//    show_list_shuang_reverse(b);
//    cout<<endl;

//    print_same_part(creatlist_vector(a_vec),creatlist_vector(b_vec));
//    huiwen_check_hard_way(creatlist_vector(c_vec));
    list_partion(creatlist_vector(c_vec),7);
    return 0;
}
