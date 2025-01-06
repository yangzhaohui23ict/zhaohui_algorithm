#include <iostream>

using namespace std;


/**

    二叉树的递归套路

    函数内容：

        1.二叉树的递归，关于3次返回的理解。调用左右节点前后3次。也就是，如果我们每一次到一个节点都留痕的话，他应该每一个节点这个痕迹出现3次。而这个就是递归序

            基于递归序，可以分为前中后序三种遍历方式。

            这里的前中后序，指的是根节点和左右子树的相对位置，也就是根节点位置在一二三号位。注意左永远在右之前，或者说，就是我们递归序中3次返回，我们在那一次输出的区别

        2.任何递归，都一定可以改成非递归。

            递归其实就是系统自动帮你压栈了，那我们不用他来，我们自己手动压栈就可以了。

            比如说，先序遍历，我们设置一个栈，把根节点放进去，然后每一次从栈中弹出一个节点，输出这个节点，然后先右再左压栈。重复这个操作。直到栈空了。

            如果这样的话，请问中序遍历和后序遍历应该要怎么来实现呢？

            对于后序遍历，就是将先序遍历中先右再左反过来，再通过一个收集栈记录弹出节点，从头右左变成了左右头，就可以了

            那么中序呢？

            如果逮到一个节点，把他的整棵树左边界进栈，然后对于弹出的节点，对于他的右子树重复这个操作（也是左边界）（这个代码应该很简单，不要写太长）

            这样做出来就是中序遍历的原理：因为整个一棵树，是可以被左边界分解掉的。（ps：当然了，右边界也可以）

        3.关于二叉树可视化的一个函数，将左神的代码在C++环境下复现一下

        4.完成一个二叉树的宽度优先遍历（BFS），这个我可太熟了

            另外，补充一下，二叉树的先序遍历就是深度优先遍历DFS

            这个地方这样做可以计算一个树的最大宽度这样


    二叉树概念补充

        如何判断一棵树是搜索二叉树

            左子树所有节点小于根节点小于所有右子树节点。

            或者说，中序遍历单调增（至少不递减）

            代码技巧，递归，中序遍历，将输出的位置改成与一个全局变量比较的位置即可。

        如何判断一棵树是完全二叉树

            按照宽度遍历二叉树

                在遍历的过程中，有右孩子但是没有左孩子，直接false

                在第一个条件不违规的前提下，如果第一次遇到了左右孩子不是双全的情况，那么节点来的所有节点，都必须是叶子结点。

        如何判断一棵树是满二叉树

            有一个比较麻烦的做法

                先求最大深度，再统计总的节点个数，如果总结点数等于2的深度次方-1，那就是满二叉树

        如何判断一棵树是平衡二叉树



    二叉树递归套路

        在可以向左树要到信息以及右树要到信息的前提下，进行题目的分析

        以平衡二叉树判断作为例子：

            问题分析的逻辑：

                首先，左子树是平衡二叉树

                其次，右子树也是

                最后，左右子树深度不能相差超过2

            需要左右子树给我什么信息：

                1.是不是平衡树

                2.深度

        然后，我们只要，利用给的信息，和我这个节点的信息，返回和向子树要的信息一样的数据结构。就可以了。我们可以把要数据的操作当做黑盒，然后把这个拆掉就可以了

        再以搜索二叉树来作为例子：

            问题分析的逻辑：

                首先，左子树是搜索二叉树

                其次，右子树也是

                再次，左子树的最大值小于这个节点

                最后，右子树的最小值大于这个节点

            需要左右子树给的信息：

                1.是不是搜索树

                2.最小值

                3.最大值

            这里可以发现，其实我们需要的是，左右子树需要提供数据的并集。

        写代码的时候，就坚决认一个点，我们就当左右子树的操作是黑盒，他已经给完了，你只要用好就行。

        这个操作可以实现，一切树型动态规划，而这个是面试中，能遇到的最难得了


    函数问题：

        1.给定一颗树的两个节点，找他们最低的公共祖先节点。

            因为树在某种概念上也是单向图的一种，所以我们可以考虑生成反向的树结构，对于每一个节点我们都可以找到对应的父节点这样。

            这个方式其实也可以使用哈希表的map来实现。只要记录下来每一个节点对应的父节点就可以了。

            然后，就一个节点一路往上，记录途中节点，第二个节点也往上走，去找。

        2.在二叉树中，给定一个节点，去找他的后续节点

            后续节点定义：在中序遍历中的下一个节点就是遍历节点。

            在这里的树结构中，存在一定的补充，一个节点同时有左右节点和父节点的指针。

            我们希望能够对于这个搜索的过程进行优化。

            确切一点来说，如果我们遍历整棵树，那没有意义的，大伙都会，甚至用不到父节点指针。

            假设，节点与后续节点之间的距离为K，那么可以不可以，时间复杂度就是O（K）

            这里就需要分析一下了：

                如果这个节点，有右子树，那么后续节点就是，他的右子树的最左节点。

                如果这个节点，没有右子树，那就网上看，如果我是我父亲的左孩子，是，就是这个节点，不是那就往上看。

                最右节点，就是默认为空

        3.二叉树的序列化和反序列化

            就是字符串to树结构，树结构to字符串

            对于一棵树，先序中序后序都可以

        4.如何判断一棵树是另一棵树的子树

        5.一张纸条，折n次，输出折痕的凹凸

            发现是一个二叉树的中序遍历。

            每一次产生的折痕就是一层。

            每一次的新产生的折痕，相比于上一层的折痕，都是上面凹折痕，下面凸折痕。



**/






int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
