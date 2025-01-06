#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//原始版本，也是最直接，最好理解的一版
//Leetcode 1392，确定过了，这个是可以的，时间复杂度也是OK的，但是问题在于这个方式的常数时间太大了
vector<int> prefix_function(string s){
    vector<int> next;
    next.push_back(0);
    if(s.length()==next.size()){
        return next;
    }
    for(int i=1;i<s.length();i++){
        //这里的判断意思是，基于next[i-1]，我们知道了0到i-1这里，最大的相同的前后缀长度，所以，我们只要对比i这个位置，和前缀的下一个字符是不是一样就可以
        //如果是，就把这个前后缀长度+1；
        if(s[i]==s[next[i-1]]){
            next.push_back(next[i-1]+1);
        }
        //如果不是呢？这个时候我们就需要退一步，不取最长，而是去取次长的前后缀。
        //这里j表示的就是，前后缀的长度。因为我们知道，长度为j 的前后缀是相等的，并且显然这个时候，我们的次长前后缀也取自这里，可以讲叫做前缀的前缀和后缀的后缀
        //但是这里因为前后缀相等，所有后缀的后缀就是前缀的后缀。
        //问题就变成了，在前缀里面找前后缀相等的最大长度的子串。（有点像绕口令）
        else{
            int j=next[i-1];
            while(j){
                j=next[j-1];
                if(s[i]==s[j]){
                    next.push_back(j+1);
                    break;
                }

            }
            //这里是防止最后j==0的情况没做比较，这里是可能存在s[i]==s[0]的，这时候next=1
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



//试着，尽可能的优化一下函数，目的是减少代码行数，降低常数时间消耗
//顺便降低代码的可读性哈哈

//核心思路：我发现，这里使用的j其实是从一而终的，我push_back进去的j，在下一个循环中直接就可以用上。
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

现在，我们有了两个string的字符串，我们对他们进行拼接，将我们要check的子串放在最前面，然后我们按照上面的策略，计算他的next前缀数组，这个时候这个数据就具备了实际意义
当一个位置的元素，他的前缀数组的大小是check子串的长度的时候，这就意味着，我们已经找到了，一个和我们的目标子串相同的子串片段了！！！！！

这很重要！！！



那么，我们就按照这个来做可以吗？显然是有一些问题的
这个策略可以帮助我们找到第一个目标子串在string里面的位置，但是因为前缀数组的大小没有限制，有些同样相同子串的位置，会因为更大的前缀数组而被cover掉

    当然，这个是可以通过进一步一点点拆分次长的相同前后缀解决的。
    但是这样做会带来一定程度的重复计算，导致时间复杂度的提高


并且，如果我们的目的是查找相同子串的话，其实这里需要给这个前缀数组设置限制。避免过多的计算浪费。

所以，或许我们可以按照这个方式来进行一下函数的编写。
**/


/**

    第一个，也是最简易功能的版本
    这里，我们通过拼接字符串，计算next前缀函数，然后进行判断的方式，就可以找到字符串中是否存在target一样的子串。
    判断条件就是前缀函数中，有没有大小跟target的长度一致的元素

    但是这里其实是存在一个隐患的，也就是会不会存在一个前缀数组大于target长度的前缀元素，如果有，这个情况又该如何处理。

    答：这里这个添加#的操作，目的就是为了避免这个问题，这个#的意义就是确保str这个字符串中，不论如何，都一定不会有这样一个子串。
    换句话说#这个符号，我们甚至可以替换成任何一个，不存在于str中的符号。

    所以说，其实我们这个版本，就是一个在string中元素存在限制情况下的，功能已经比较完整的kmp算法了。。。吗？

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

    在拜读博文 Префикс-функция. Алгоритм Кнута-Морриса-Пратта的译本过程中，我看到了两个与这个问题相似的，同样基于前缀数组的问题

    这个问题可以总结为：统计每个前缀的出现次数

    这个地方的结果，显然我们可以通过一个vector的数组的格式来进行记录。这里的index=i的元素，就可以表示为原字符串到这个位置的所组成的前缀，在整个的字符串中出现的次数

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
