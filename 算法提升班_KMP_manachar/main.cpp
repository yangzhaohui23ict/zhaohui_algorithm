#include <iostream>
#include<vector>
#include<string>
using namespace std;


/**

    KMP算法：就是两个string，你怎么来判断，string2是不是string1的子串。如果找到了子串，return的就是string1中string2部分的头索引

        对于这个问题的原始策略：一个个遍历，时间复杂度应该是O(mn)，其中mn分别对应两个string的长度。

        在讲KMP之前，我们需要补充两个概念，最长前缀和最长后缀的匹配长度

        string中的一个字符，给他配一个数据，这个数据和他没有什么关系，看他前面的string。对于这个string部分的前缀和后缀，在不等于string部分的前提下，相等的最大长度

            举个例子：abbabbK，那么这个时候K的匹配长度就是3，因为前缀后缀在长度3的时候都是abb

            另一个例子：aaaaaK，那么这个时候K的最大匹配长度是4，前后缀可以有重合，但是不能取到整体

        这个数据有什么用？给谁用的？

            这个数据是给string2算的，string2上面所有的字符都需要这个。

        nextarr数组，专门用来记录这个数据。

        在写这个数组的时候，我们需要确定两个特别点，就是0,1位点，这两个点分别是-1,0，人为规定，很好理解。

        这个地方，我们先知道原理就好，加速的快的算法我们学完KMP再回过头来讲。

        这个时候我们假设，已经算好了这个nextarr。然后开始进行是不是子串的判断。

    KMP算法细节：

        想一下找子串的过程，如果string1和string2在i开头开始对比，然后，到后面有一个位置没对上。

            老算法：i不对，我们在i+1这个开头位置继续去比较

            KMP：如果string1和string2两个比了一路，有一个不对了，这个时候我是能知道这个字符前面这个string2部分字符串的匹配长度的。

                接下来！string1对比没对上的那个位置不变，string2对比的位置回跳到前缀的下一位。然后继续去比。相当于把string2往右挪一下再继续比。

            啊？为什么啊？

            这个操作其实包含了有两个信息：

                首先，我们假设一开始比的位置是string1的i位置，那么现在我们开始比的位置是j，j是什么位置？

                我们已经将string1和2比了一路了，所以在错的这个点之前，这两个字符串相等，我们知道string2的匹配长度，那么自然，string1这一截的匹配长度也一样

                j就是最大匹配后缀的开头。

                1：从j开始的这个后缀，和string2对应的前缀一定是相等的，不用比

                2：i和j之间，string1没有以这部分开头还能匹配上string2的了，一定！

        这里我们用一个例子来专门的说明一下：

            string1：...abbstkscabbstkS...
            string2：abbstkscabbstkZ

            以a开头的string1部分太可惜了，差一点就能匹配上了。

            此时老方法：从b继续比

            KMP：从string的第二个a那里继续比，跳过了bbstksc的尝试。所以string1不用回跳，string2的Z指针调回去，取到s这里。

            这个时候，我们知道前面的推断1是理解了的。

            那么为什么推论2是对的呢？

                我们假设，中间还有一个位置，能配出来。那么至少，从这个位置到错的点是不是应该和string2的开头同等长度部分是相等的。

                而我们一开始string1和2一路匹配过来，这一段也刚好是对应了string2错误的这个点的后缀部分。

                那么这个时候，这一段就应该是大于nextarr的匹配序列。

                OK，冲突了，所以没有。

        OK，这里我们其实就可以理解KMP为什么要比之前的直接暴力解法更好了。

        补充一下：当且仅当string2不具备往前跳的条件的时候，也就是这个string1的头位置和string2的头位置都不一样，string1后移一位。

        具体算法执行比较简单：

            两个string两个指针，相等都往后走，不相等了，string2回到nextarr[i]这里，如果没得可跳了，string1的指针后移一位。

            最后出来，判断i2是不是把string2走完了就行。

        最后评价一下时间复杂度：O(N)，因为string1的指针单调不递减，并且，变化幅度只有N

    最后，nextarr怎么求？

        0,1位置认为规定-1,0，这个都好说

        加入当我们来到了i位置的时候，i-1的位置的nextarr是7，那么0-6号位，以及不包括i-1位置的后7个元素是一样的。

        这个时候，只要7号位元素（第8个）和i-1是一样的，那么nextarr在这个字符上就是8

        会更长吗？绝对不会，因为这样说明i-1那里nextarr错了。

        但是！如果不一样呢？一样前缀部分的最后一位，往前去跳。


    manachar算法：

**/





vector<int> get_nextarr(string str){
    vector<int> nextarr;
    int l=str.length();
    nextarr.push_back(-1);
    if(l==1){
        return nextarr;
    }
    nextarr.push_back(0);
    if(l==2){
        return nextarr;
    }
    int i=2;
    int cn=0;
    while(i!=l){
        if(str[i-1]==str[cn]){
            nextarr.push_back(++cn);
            i++;
        }
        else{
            if(cn>0){
                cn=nextarr[cn];
            }
            else{
                nextarr.push_back(0);
                i++;
            }
        }
    }
//    for(int i=0;i<l;i++){
//        cout<<nextarr[i]<<" ";
//    }
    return nextarr;
}




int KMP(string s1,string s2){
    if(s2.length()>s1.length()){
        return false;
    }
    int i=0;
    int j=0;
    vector<int> nextarr;
    nextarr=get_nextarr(s2);
    while(i<s1.length()&&j<s2.length()){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            if(nextarr[j]==-1){
                i++;
            }
            else{
                j=nextarr[j];
            }
        }
    }
    return j==s2.length()?i-j:-1;
}









int main()
{
    while(1){
        string a;
        string b;
        cin>>a>>b;
    //    get_nextarr(a);
        cout<<KMP(a,b)<<endl;
    }

    return 0;
}
