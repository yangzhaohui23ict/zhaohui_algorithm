#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//ԭʼ�汾��Ҳ����ֱ�ӣ��������һ��
//Leetcode 1392��ȷ�����ˣ�����ǿ��Եģ�ʱ�临�Ӷ�Ҳ��OK�ģ������������������ʽ�ĳ���ʱ��̫����
vector<int> prefix_function(string s){
    vector<int> next;
    next.push_back(0);
    if(s.length()==next.size()){
        return next;
    }
    for(int i=1;i<s.length();i++){
        //������ж���˼�ǣ�����next[i-1]������֪����0��i-1���������ͬ��ǰ��׺���ȣ����ԣ�����ֻҪ�Ա�i���λ�ã���ǰ׺����һ���ַ��ǲ���һ���Ϳ���
        //����ǣ��Ͱ����ǰ��׺����+1��
        if(s[i]==s[next[i-1]]){
            next.push_back(next[i-1]+1);
        }
        //��������أ����ʱ�����Ǿ���Ҫ��һ������ȡ�������ȥȡ�γ���ǰ��׺��
        //����j��ʾ�ľ��ǣ�ǰ��׺�ĳ��ȡ���Ϊ����֪��������Ϊj ��ǰ��׺����ȵģ�������Ȼ���ʱ�����ǵĴγ�ǰ��׺Ҳȡ��������Խ�����ǰ׺��ǰ׺�ͺ�׺�ĺ�׺
        //����������Ϊǰ��׺��ȣ����к�׺�ĺ�׺����ǰ׺�ĺ�׺��
        //����ͱ���ˣ���ǰ׺������ǰ��׺��ȵ���󳤶ȵ��Ӵ������е����ƿ��
        else{
            int j=next[i-1];
            while(j){
                j=next[j-1];
                if(s[i]==s[j]){
                    next.push_back(j+1);
                    break;
                }

            }
            //�����Ƿ�ֹ���j==0�����û���Ƚϣ������ǿ��ܴ���s[i]==s[0]�ģ���ʱ��next=1
            if(next.size()!=i+1){
                if(s[i]==s[next[j]]){
                    next.push_back(1);
                }
                else{
                    next.push_back(0);
                }
            }
        }
        cout<<next[i]<<endl;
    }
    return next;
}



//���ţ������ܵ��Ż�һ�º�����Ŀ���Ǽ��ٴ������������ͳ���ʱ������
//˳�㽵�ʹ���Ŀɶ��Թ���

//����˼·���ҷ��֣�����ʹ�õ�j��ʵ�Ǵ�һ���յģ���push_back��ȥ��j������һ��ѭ����ֱ�ӾͿ������ϡ�
vector<int> prefix_function_polish(string s){
    int distence=0;
    vector<int> next;
    next.push_back(distence);
    int i=1;
    int l=s.length();
    while(i<l){
        if(s[i]==s[distence]){
            next.push_back(++distence);
            i++;
        }
        else{
            if(distence>0){
                distence=next[distence-1];
            }
            else{
                next.push_back(0);
                i++;
            }
        }
    }
    return next;
}


void copy_vector(vector<int> &a,vector<int> b){
    for(int i=0;i<b.size();i++){
        a.push_back(b[i]);
    }
    return;
}

void show_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}


/**

���ڣ�������������string���ַ��������Ƕ����ǽ���ƴ�ӣ�������Ҫcheck���Ӵ�������ǰ�棬Ȼ�����ǰ�������Ĳ��ԣ���������nextǰ׺���飬���ʱ��������ݾ;߱���ʵ������
��һ��λ�õ�Ԫ�أ�����ǰ׺����Ĵ�С��check�Ӵ��ĳ��ȵ�ʱ�������ζ�ţ������Ѿ��ҵ��ˣ�һ�������ǵ�Ŀ���Ӵ���ͬ���Ӵ�Ƭ���ˣ���������

�����Ҫ������



��ô�����ǾͰ������������������Ȼ����һЩ�����
������Կ��԰��������ҵ���һ��Ŀ���Ӵ���string�����λ�ã�������Ϊǰ׺����Ĵ�Сû�����ƣ���Щͬ����ͬ�Ӵ���λ�ã�����Ϊ�����ǰ׺�������cover��

    ��Ȼ������ǿ���ͨ����һ��һ����ִγ�����ͬǰ��׺����ġ�
    ���������������һ���̶ȵ��ظ����㣬����ʱ�临�Ӷȵ����


���ң�������ǵ�Ŀ���ǲ�����ͬ�Ӵ��Ļ�����ʵ������Ҫ�����ǰ׺�����������ơ��������ļ����˷ѡ�

���ԣ��������ǿ��԰��������ʽ������һ�º����ı�д��
**/


/**

    ��һ����Ҳ������׹��ܵİ汾
    �������ͨ��ƴ���ַ���������nextǰ׺������Ȼ������жϵķ�ʽ���Ϳ����ҵ��ַ������Ƿ����targetһ�����Ӵ���
    �ж���������ǰ׺�����У���û�д�С��target�ĳ���һ�µ�Ԫ��

    ����������ʵ�Ǵ���һ�������ģ�Ҳ���ǻ᲻�����һ��ǰ׺�������target���ȵ�ǰ׺Ԫ�أ�����У��������ָ���δ���

    ������������#�Ĳ�����Ŀ�ľ���Ϊ�˱���������⣬���#���������ȷ��str����ַ����У�������Σ���һ������������һ���Ӵ���
    ���仰˵#������ţ��������������滻���κ�һ������������str�еķ��š�

    ����˵����ʵ��������汾������һ����string��Ԫ�ش�����������µģ������Ѿ��Ƚ�������kmp�㷨�ˡ�������

**/

bool kmp_first_by_zhaohui(string str,string target){
    string new_str=target+"#"+str;
    vector<int> next;
    copy_vector(next,prefix_function_polish(new_str));
    for(int i=target.size()+1;i<next.size();i++){
        if(next[i]==target.size()){
            cout<<i<<endl;
            return true;
        }
    }
    return false;
}


int kmp_second_by_zhaohui(string str,string target){
    string new_str=target+"#"+str;
    vector<int> next;
    copy_vector(next,prefix_function_polish(new_str));
    for(int i=target.size()+1;i<next.size();i++){
        if(next[i]==target.size()){
            return i-target.size()-1;
        }
    }
    return -1;
}





/**

    �ڰݶ����� ����֧�ڧܧ�-���ߧܧ�ڧ�. ���ݧԧ��ڧ�� ���ߧ���-������ڧ��-����ѧ��ѵ��뱾�����У��ҿ���������������������Ƶģ�ͬ������ǰ׺���������

    �����������ܽ�Ϊ��ͳ��ÿ��ǰ׺�ĳ��ִ���

    ����ط��Ľ������Ȼ���ǿ���ͨ��һ��vector������ĸ�ʽ�����м�¼�������index=i��Ԫ�أ��Ϳ��Ա�ʾΪԭ�ַ��������λ�õ�����ɵ�ǰ׺�����������ַ����г��ֵĴ���

    eg:abcababcab

**/




vector<int> prefix_time_sta(string str){
    vector<int> ans;
    vector<int> next;
    copy_vector(next,prefix_function_polish(str));
    for(int i=0;i<str.length();i++){
        ans.emplace_back(1);
    }
    for(int i=0;i<str.length();i++){
        int distance=next[i];
        while(distance){
            ans[distance]++;
            distance=next[distance-1];
        }
    }
    return ans;
}







int main()
{
    string str2="abcabcd";
//    vector<int> ans;
//    copy_vector(ans,prefix_function_polish(str2));
//    show_vector(ans);
    string str1="bcd";
    cout<<kmp_first_by_zhaohui(str2,str1)<<endl;
    return 0;
}
