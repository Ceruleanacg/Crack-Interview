# LeetCode

## 题解 - Solutions

### 数组与字符串 - Array and Strings

#### 1. Two Sum

- ##### [描述](https://leetcode.com/problems/two-sum/description/)
    给定一个整型数组和一个目标数，返回整型数组中两个数的和为目标数的下标（题目保证有解，数组中每一个数只能使用一次。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/1.%20Two%20Sum/solution.py)
    初始化字典`dic`，其键值为数组中某元素与其下标，遍历数组中每个元素`arr[i]`，目标值`target`与`arr[i]`的差记为`diff`，在`dic`中查找键`diff`，如果存在，则返回`diff`的下标与`i`，如果不存在，为`dic`建立`arr[i]`与`i`的键值对。


#### 125. Valid Palindrome

- ##### [描述](https://leetcode.com/problems/valid-palindrome/)
    给定一个字符串，判断该字符串是否是回文串。回文串是从前后方向阅读都相同的串。
    
- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/125.%20Valid%20Palindrome/solution.py)
    同时从字符串正序、逆序遍历字符串，如果所有字符都相同，则是回文串，否则不是回文串。


#### 8. String to Integer
- ##### [描述](https://leetcode.com/problems/string-to-integer-atoi)
    给定一个字符串，字符串可能包含非数字字符，例如字母和符号。如果以负号以外的非数字开头，则返回`0`，否则将字符串数字，含符号，转化为32位整型。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/tree/master/LeetCode/Array%20and%20Strings/8.%20String%20to%20Integer%20(atoi))
    略。

#### 344. Reverse String   
- ##### [描述](https://leetcode.com/problems/reverse-string/description/)   
    给定一个字符串，将字符串逆置。  

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/tree/master/LeetCode/Array%20and%20Strings/344.%20Reverse%20String)
    同时从字符串的正序、逆序遍历字符串，交换两个字符的位置，直到两下标相等。  

#### 20. Valid Parentheses
- ##### [描述](https://leetcode.com/problems/valid-parentheses/description/)
    给定一个字符串表达式，判断表达式中的括号是否合法，一个合法的括号应该像：{[()]}，这样的形式。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/20.%20Valid%20Parentheses/solution.py)
    维护一个栈，记作`stack`，然后遍历字符串，如果遇到左括号字符，则将该字符入栈，如果遇到右括号字符，则将栈顶出栈，判断括号是否匹配，如果匹配失败，则返回`False`，如果匹配成功，则继续遍历直到结束。如果遍历结束，栈不为空，则匹配失败，否则匹配成功。
    
#### 5. Longest Palindromic Substring
- ##### [描述](https://leetcode.com/problems/longest-palindromic-substring/description/)
    给定一个字符串，返回这个字符串的最大回文子串。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/5.%20Longest%20Palindromic%20Substring/solution.py)
    由于枚举所有长度的子串，并判断该子串是否是回文子串的复杂度（`O(n * m * m)`）过高，故考虑动态规划。在外层循环以下标`j`遍历字符串下标，`j`代表了子串的右界（`0 <= j <= len(s)`），内层循环以下标`i`遍历子串下标（`0 <= i <= j`），易知，当`j=i`时，原字符串`s`的子串`sub_s`，即`s[i:j+1]`是回文的，而当`j-i=1`时，如果`s[i]=s[j]`则子串`sub_s`，是回文的，而当`j-i>1`时，子串`sub_s`是否回文，取决于是否`s[i]=s[j]`且`s[i+1:j-1]`是否为真，如果为真，则`sub_s`回文。所以，我们维护一个`dp`二维数组，其下标`i,j`表示原字符串从下标`i`开始到`j`结束（包含`j`）的子串是否为回文子串。在便利过程中不断更新最长的下标`i, j`最后返回最长回文子串。

#### 49. Group Anagrams
- ##### [描述](https://leetcode.com/problems/group-anagrams/description/)
    给定一个字符串型数组，将具有相同字符组成的字符串分别保存为一个字符串型数组，返回一个字符串型数组型的数组，作为结果。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/49.%20Group%20Anagrams/solution.py)
    维护一个字典记作`dic`，其键值分别为按字典序排序后的字符串和字符串型数组。遍历字符串型数组，对每一个字符串`s`，按字典序排序，结果记作`s_sorted`，在`dic`中取`s_sorted`的值`res`，`res`是一个字符串型的数组，然后将`s`添加进`res`，最后返回`dic`的`values`作为结果。
    

#### 42. Trapping Rain Water
- ##### [描述](https://leetcode.com/problems/trapping-rain-water/description/)
    接雨水，给定一个整型数组`height`，数组内每个元素的值代表了“墙”的高度，墙的高度差可以用来储水，求给定一组墙高，能储多少水。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/42.%20Trapping%20Rain%20Water/solution.py)
    首先遍历`height`，找到最高“墙”的下标`i_max_height`，初始化一个`i_cur_peak=0`代表当前“左高峰”，然后从左到`i_max_height`遍历墙高，期间，如果当前“左高峰”小于当前墙高，则更新“左高峰”，否则，更新雨水总量`rain+=i_cur_peak-height[i]`，即“左高峰”减去当前墙高，直到遍历到墙的最高处为止。然后从右到`i_max_height`遍历墙高，逻辑同上。最后返回雨水总量。

### 链表 - Linked List

#### 206. Reverse Linked List
- ##### [描述](https://leetcode.com/problems/reverse-linked-list/description/)
    给定一链表，将它就地逆序。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Linked%20List/206.%20Reverse%20Linked%20List/solution.py)
    初始化前驱节点`pre_node=None`，通过`head_node`遍历链表，通过`cur_node`临时存储`head_node`，然后更新`head_node = head_node.next`，接着更新当前节点的后继节点为前驱节点，`cur_node.next = pre_node`，最后将前驱节点更新为当前节点，`pre_node = cur_node`，直到遍历结束，最终返回`pre_node`为逆序后的头结点。

#### 141. Linked List Cycle
- ##### [描述](https://leetcode.com/problems/linked-list-cycle/description/)
    给定一个链表，判断链表是否存在“环”

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Linked%20List/141.%20Linked%20List%20Cycle/solution.py)
    分别维护快慢指针，初始化为`s_node, f_node = head, head.next`，以快慢指针都为真的条件进入`while`循环，如果快指针与慢指针地址相等，则存在环，否则更新慢指针，`s_node=s_node.next`，更新快指针两次，`f_node=f_node.next`，`if f_node: f_node = f_node.next`，继续循环，如果循环结束，则不存在环。

#### 2. Add Two Numbers
- ##### [描述](https://leetcode.com/problems/add-two-numbers/description/)
    给定两个链表，它们从头节点到尾节点分别表示数字的最低位到最高位，求将两链表相加的结果链表。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Linked%20List/2.%20Add%20Two%20Numbers/solution.py)
    初始化进位记录标识符`count=0`与结果头节点`head`，以两链表为真的条件进入循环，将当前节点结果相加，并加`count`后，模10，如果进位，则将`count`记为`1`，并保存结果`cur_node.next = Node(x)`，然后更新`cur_node=cur_node.next`，直到循环结束。如果仍有较长链表遍历未结束，则遍历该链表，依次将其节点与`count`相加后添加在结果节点的`cur_node`后，直到遍历结束，最后检查进位是否需要需要创建新节点，并返回结果头节点。
    
#### 21. Merge Two Sorted Lists
- ##### [描述](https://leetcode.com/problems/merge-two-sorted-lists/description/)
    给定两个有序链表，将他们合并成新的有序链表，并返回这个链表的头节点。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Linked%20List/21.%20Merge%20Two%20Sorted%20Lists/solution.py)
    初始化新头节点与当前节点记为`head_node`与`cur_node`，以两链表为真的条件进入循环，比较两链表的当前值，将值小的节点添加为`cur_node`的后继节点，然后更新该节点为之后继，然后更新`cur_node=cur_node.next`，直到循环结束。循环结束后，如果仍有链表为真，则将剩余部分作为`cur_node`的后继，然后返回头节点。
    
#### 23. Merge k Sorted Lists
- ##### [描述](https://leetcode.com/problems/merge-k-sorted-lists/description/)
    给定k个有序链表，将他们合并成新的有序链表，并返回这个链表的头节点。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Linked%20List/23.%20Merge%20k%20Sorted%20Lists/solution.py)
    同上，略。
    
### 树和图 - Trees and Graphs

#### 98. Validate Binary Search Tree
- ##### [描述](https://leetcode.com/problems/validate-binary-search-tree/description/)
    给定一个树，判断该二叉树是否是二叉查找树

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/tree/master/LeetCode/Trees%20and%20Graphs/98.%20Validate%20Binary%20Search%20Tree)
    将中根遍历该二叉树的结果保存，检查该数组是否有序，如果有序，则是二叉查找树。
    
#### 94. Binary Tree Inorder Traversal
- ##### [描述](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)
    给定一颗二叉树，输出中根遍历结果。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/tree/master/LeetCode/Trees%20and%20Graphs/94.%20Binary%20Tree%20Inorder%20Traversal)
    初始化栈`stack`，将元组`(root, False)`入栈，以栈不为空进入循环，将栈顶元组出栈，结果记为`cur_node, visited`，如果`cur_node`为真时，`visited`为真，即已经访问了该节点，则将该节点的值`cur_node.val`添加到结果数组，如果`visited`为假，即尚未访问该节点，则依次将该节点的右节点，该节点，该节点的左节点入栈，他们的访问标记分别为`False, True, False`，然后继续循环。最后打印结果。

#### 102. Binary Tree Level Order Traversal
- ##### [描述](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
    给定一颗二叉树，输出层序遍历结果。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/102.%20Binary%20Tree%20Level%20Order%20Traversal/solution.py)
    初始化层节点数组`level_nodes=[root]`，以层节点数组不为空为条件进入循环，向结果数组添加层节点数组内所有节点的值，然后初始化临时层节点数组`tmp_level_nodes`，遍历当前层节点的所有节点，添加他们的左右孩子节点（需为真），然后更新`level_nodes=tmp_level_nodes`，直到循环结束，最后返回结果数组。

#### 103. Binary Tree Zigzag Level Order Traversal
- ##### [描述](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)
    给定一颗二叉树，输出层序遍历结果，双数层的结果逆序。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/103.%20Binary%20Tree%20Zigzag%20Level%20Order%20Traversal/solution.py)
    同上，在更新双数层节点时逆序即可，略。

#### 116. Populating Next Right Pointers in Each Node
- ##### [描述](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)
    给定一颗满二叉树，将二叉树的每一层变成一个链表（二叉树的节点数据结构已经有`next`成员变量）

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/solution.py)
    同上，在更新`level_nodes==tmp_level_nodes`后，遍历之，`node.next = next_level_nodes[index + 1]`更新后继节点。

#### 117. Populating Next Right Pointers in Each Node II
- ##### [描述](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/)
    给定一颗二叉树，将二叉树的每一层变成一个链表（二叉树的节点数据结构已经有`next`成员变量）

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/117.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node%20II/solution.py)
    同上，略。

#### 235. Lowest Common Ancestor of a Binary Search Tree
- ##### [描述](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)
    给定一颗二叉搜索树与其两个节点，返回这两个节点的最小公共祖先。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/235.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Search%20Tree/solution.py)
    利用二叉搜索树性质并递归，如果两个节点的值`pval, qval`都小于`root.val`，那么公共祖先一定在`root`节点的左子树中，所以递归调用当前函数，根节点，即二叉查找树为`root.left`。相反，如果`pval, qval`都大于`root.val`，则公共祖先一定在`root`节点的右子树中，执行上述操作。最终，如果`qval < root.val < pval`，则`root`为最小公共祖先。    

#### 236. Lowest Common Ancestor of a Binary Tree
- ##### [描述](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)
    给定一颗二叉树与其两个节点，返回这两个节点的最小公共祖先。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/236.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree/solution.py)
    初始化`p_path, q_path`分别保存先根遍历到`p, q`节点的路径。路径是指使用先根遍历，遍历该二叉树，直到某个节点的值等于目标节点的值`node.val==target.val`，并将完成标记`flag=Ture`，并将其他遍历结果移出路径，如何保存路径，请参见[257. Binary Tree Paths]()。然后遍历两个路径`p_path, q_path`，最后一个相同的节点，即是最小公共祖先。

#### 105. Construct Binary Tree from Preorder and Inorder Traversal
- ##### [描述](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
    已知一颗二叉树的先根和中根遍历结果，恢复二叉树。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/105.%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal/solution.py)
    利用递归，以中根遍历结果数组不为空的条件进入函数，将先根数组`pre_vals`的首个节点值`root_val`出队列，并求出`root_val`在中根遍历数组中的下标，记为`root_index`，易知，中根遍历数组中，该节点下标左边的值均为其左子树的值，该下标右边的值均为其右子树的值。创建节点`root=TreeNode(root_val)`，而`root.left`则递归本函数，入参分别为`pre_vals`与`in_vals[: root_index]`，而`root.right`则递归本函数，入参分别为`pre_vals`与`in_vals[root_index + 1:]`，最后返回根节点。

#### 200. Number of Islands
- ##### [描述](https://leetcode.com/problems/number-of-islands/description/)
    描述较为复杂，概述为寻找一个`0-1`矩阵中“孤岛”，即`1`构成的块的个数。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/200.%20Number%20of%20Islands/solution.py)
    维护一个`visited`数组，描述了某个下标`i, j`是否已经访问过，以下标`i, j`分别代表行列遍历图，如果图中`grid[i, j] == 1`，则进行深度优先遍历，需注意深度优先遍历的条件，即`0<=i<=row, 0<=j<=col`。如果`i, j`已经访问过，或者`grid[i, j]==0`则返回0，否则将本次遍历区域加1，并将`visited[i, j]=1`后，继续遍历，方向为上、下、左、右。最后以所有行列`i, j`为入口遍历完毕后，返回累计结果。
    
#### 257. Binary Tree Paths
- ##### [描述](https://leetcode.com/problems/binary-tree-paths/description/)
    给定一颗二叉树，输出先根遍历到所有叶子节点的路径字符串。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/257.%20Binary%20Tree%20Paths/solution.py)
    初始化临时路径`path`与结果路径集合`paths`，先根遍历二叉树，遍历的过程中，每访问一个节点，如果该节点为空，则返回，否则将其添加到临时路径`path`中，并检查该节点是否有左右孩子节点，如果没有，则执行一次`path`临时路径到结果路径的序列化，结果添加到`paths`中。如果有左右孩子节点，则继续对该节点的左右孩子进行先根遍历。如果访问到叶子节点，则对`path`执行`pop`操作，将该节点出栈。最后返回结果路径集合`paths`。

### 回溯 - Backtracking

#### 17. Letter Combinations of a Phone Number
- ##### [描述](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
    2-9数字中每个数字对应了电话号码上的几个字母，输入一串2-9的数字，输出数字对应的字母的所有排列组合

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Backtracking/17.%20Letter%20Combinations%20of%20a%20Phone%20Number/solution.py)
    注意DFS函数参数设计和递归停止条件，参数应该包含（当前当前索引、数字、当前模式、结果），如果索引等于长度，则应该停止，向结果添加模式，否则，遍历当前数字对应的字母，然后依次DFS，此时索引自增，模式自增当前字母

### 排序和搜索 - Sorting and Searching

#### 26. Remove Duplicates from Sorted Array
- ##### [描述](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
    就地从排序数组里移除冗余数字

- ##### [题解]()
    定义一个"有序尾索引"，该索引永远为有序数组无冗余的"前端"，然后遍历数组，如果数组的"有序尾索引"的值不等于当前值，则有序尾索引自增，然后更新有序尾索引对应的值为当前值，最后返回有序尾索引自增

#### 88. Merge Sorted Array
- ##### [描述](https://leetcode.com/problems/merge-sorted-array/description/)
    就地合并两个排序后的数组（第一个数组足够长）

- ##### [题解]()
    从后遍历两个数组，根据当前两索引对应的值的大小，将较大的索引对应的值放进合并索引（m + n - 1)位置中，然后对应索引自减，最后如果第二个数组索引仍然不为，0则继续填充合并索引位置，两索引自减少

#### 75. Sort Colors
- ##### [描述](https://leetcode.com/problems/sort-colors/description/)
    三色排序，即0，1，2就地O(n)时间排序，不可用基数排序

- ##### [题解]()
    维护三个指针，分别是左，当前，右指针，以当前指针小于等于右指针为条件进入循环，如果当前数字等于2，则将当前数字与右指针交换，然后右指针左移，当前与左指针不动，如果当前数字等于1，左右指针均不动，当前指针自增，如果当前数字等于0，交换当前与左指针的值，然后当前和左指针自增。
    
#### 153. Find Minimum in Rotated Sorted Array
- ##### [描述](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)
    有序数组在某一位被完全反转，例如[0, 1, 2, 3, 4] -> [3, 4, 0, 1, 2]，找出最小元素，无重复元素

- ##### [题解]()
    取左中右索引，如果中值比右值小，则将右索引更新为中索引，如果中值大于右值，则数组在此被反转，将左索引更新为中索引加1

#### 33. Search in Rotated Sorted Array
- ##### [描述](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)
    有序数组以某一个元素为枢轴进行旋转，例如[0, 1, 2, 4, 5, 6, 7] -> [4, 5, 6, 7 ,0, 1, 2]，在该数组中寻找一个目标数字，如果存在则返回下标，否则返回-1

- ##### [题解]()
    找到枢轴，然后比较目标数和枢轴的大小，如果目标数大于枢轴，则不存在。如果目标数小于枢轴且大于等于首个元素，则在此区间二分查找，否则在枢轴后至末尾二分查找

#### 74. Search a 2D Matrix
- ##### [描述](https://leetcode.com/problems/search-a-2d-matrix/description/)
    在一个二维数组里查找某个目标数，这个二维数组是按下标严格递增的，如存在则返回True，否则返回False

- ##### [题解]()
    按列遍历二维数组的首个元素，找到临界值行，在临界值行的上一行，进行二分查找

#### 240. Search a 2D Matrix II
- ##### [描述](https://leetcode.com/problems/search-a-2d-matrix-ii/description/)
    在一个二维数组里查找某个目标数，这个二维数组是的每一个行是有序的，每一列是有序的，如果存在返回True，否则返回False

- ##### [题解]()
    按列遍历二维数组的首个元素，找到临界值行，遍历0行至临界行进行二分查找


### 动态规划 - Dynamic Programming

#### 121. Best Time to Buy and Sell Stock
- ##### [描述](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
    输入一个数组代表一个时间段的股票价格，按照时间顺序，找到最佳买入和卖出价格，计算最大收益，如果没有最佳择时，收益为0

- ##### [题解]()
    初始化最大收益和最小价格为0，按顺序遍历价格，根据当前价格更新最小价格，根据当前最小价格和当前价格计算收益，根据最大收益和当前收益更新最大收益

#### 53. Maximum Subarray
- ##### [描述](https://leetcode.com/problems/maximum-subarray/)
    输入一个整型数组，输出最大子串和

- ##### [题解]()
    `dp[index] = max(num, num + dp[index - 1])`其中`dp[index]`为第index个下标的最大子数组和

#### 70. Climbing Stairs
- ##### [描述](https://leetcode.com/problems/climbing-stairs/description/)
    给定一个n层楼梯，n是正数，可以一次上1阶，也可以一次上2阶，输出有多少种上法

- ##### [题解]()
    `dp[i] = dp[i - 1] + dp[i - 2]`

#### 198. House Robber
- ##### [描述](https://leetcode.com/problems/house-robber/description/)
    

- ##### [题解]()
    
#### 152. Maximum Product Subarray
- ##### [描述](https://leetcode.com/problems/maximum-product-subarray/description/)
    

- ##### [题解]()
    
#### 139. Word Break
- ##### [描述](https://leetcode.com/problems/word-break/description/)
    

- ##### [题解]()
    
#### 279. Perfect Squares
- ##### [描述](https://leetcode.com/problems/perfect-squares/description/)
    

- ##### [题解]()
    
#### 62. Unique Paths
- ##### [描述](https://leetcode.com/problems/unique-paths/description/)
    

- ##### [题解]()
    
#### 120. Triangle
- ##### [描述](https://leetcode.com/problems/triangle/description/)
    

- ##### [题解]()
    
