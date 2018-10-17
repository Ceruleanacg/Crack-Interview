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
    由于枚举所有长度的子串，并判断该子串是否是回文子串的复杂度（`O(n * m * m)`）过高，故考虑动态规划。在外层循环以下标`j`遍历字符串下标，`j`代表了子串的右界（`0 <= j <= len(s)`），内层循环以下标`i`遍历子串下标（`0 <= i <= j`），易知，当`j=i`时，原字符串`s`的子串`sub_s`，即`s[i:j+1]`是回文的，而当`j-i=1`时，如果`s[i]=s[j]`则子串`sub_s`是回文的，而当`j-i>1`时，子串`sub_s`是否回文，取决于是否`s[i]=s[j]`且`s[i+1:j-1]`是否为真，如果为真，则`sub_s`回文。所以，我们维护一个`dp`二维数组，其下标`i,j`表示原字符串从下标`i`开始到`j`结束（包含`j`）的子串是否为回文子串。在遍历过程中不断更新最长的下标`i, j`最后返回最长回文子串。

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

#### 15. 3Sum
- ##### [描述](https://leetcode.com/problems/3sum/description/)
    给定一个整型数组`num`，例如`[-1, 0, 1, 2, -1, -4]`，返回一组结果，每个结果是一个数组，满足：在`nums`中选3个数字，这3个数字的和为`0`，过滤重复解。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/15.%203Sum/solution.py)
    首先，3个数字`a, b, c`的和为`0`，即`a + b = c`，则将问题转化为了一个`Two Sum`问题，所以，我们先排序数组`nums`，并初始化`targets`数组：`[-num for num in nums]`。以下标`i`进入循环，初始化`y_map`与`target = targets[i]`，`y_map`用来记录是否`y`已经查找过。然后遍历`nums[i + 1:]`的每一个元素`x`，将`target - x`记作`y`，如果`y`在`y_map`中，则添加结果`-target, x, y`作为一个解。否则，`y_map[x] = x`，记录当前`x`到`y_map`字典中。最后去重结果并返回。

#### 48. Rotate Image 
- ##### [描述](https://leetcode.com/problems/rotate-image/description/)
    给定一个二维数组`matrix`，将它顺时针旋转90°，不可以申请新空间。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/48.%20Rotate%20Image/solution.py)
    首先，将`matrix`转置，以`i, j`为行列，进入循环，即对于每一个元素`matrix[i][j] = matrix[j][i]`，需注意，此处`j`从`i`开始，因为只需遍历`matrix`的上三角矩阵即可。然后，再将转置的矩阵`martix`水平翻转，即以`i, j`为行列进入循环，使得`matrix[i][j] = matrix[i][num_col - j - 1]`，需要注意，`j`的上界是`num_col // 2`，因为`num_col // 2`为轴心。

#### 66. Plus One
- ##### [描述](https://leetcode.com/problems/plus-one/description/)
    给定一个数组`nums`，如`[1, 2, 3]`，代表了`123`的各位，现在对个位加一，返回结果数组，如`[1, 2, 4]`。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/66.%20Plus%20One/solution.py)
    初始化`carry`进位标识符，首先对个位加一，如果结果大于`10`，则模`10`后标记`carry = 1`，然后遍历剩余的位数加`carry`，同时判断是否进位，直到遍历结束。如果遍历结束后`carry = 1`，则插入`1`到数组下标为`0`处。

#### 189. Rotate Array
- ##### [描述](https://leetcode.com/problems/rotate-array/description/)
    给定一个数组`nums`，与一个整数`k`，代表将前`k`位数移至数组末尾，就地修改数组`nums`。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/189.%20Rotate%20Array/solution.py)
    以下标`i`进入循环，循环执行`k`次，每次`nums.insert(nums.pop(0)`即可。

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
    
#### 695. Max Area of Island
- ##### [描述](https://leetcode.com/problems/max-area-of-island/description/)
    给定一个二维数组`grid`，其元素为`0`或`1`，找到最大的“孤岛”，并返回其大小。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/695.%20Max%20Area%20of%20Island/solution.py)
    维护`result`变量记录结果，维护一个二维数组`visited`，`vistied[i][j]`描述了`grid[i][j]`是否已经被访问过，然后对以`i, j`为下标进入循环，对`grid[i][j]`进行深度优先遍历。在深度优先遍历时，维护一个`res = 1`变量，如果`grid[i][j] == 0`，则返回`0`，如果`grid[i][j] == 1`，才能继续遍历，同时，将`visited[i][j] = 1`，并将`res += 1`，然后进行方向为上、下、左、右的深度优先遍历。如果`res > result`，则更新`result = res`，最后返回`result`作为结果。
    
#### 547. Friend Circles
- ##### [描述](https://leetcode.com/problems/friend-circles/description/)
    给定一个二维数组`M`，其中元素为`0`或`1`，表示第`j`个人是否是第`i`个人的直接朋友。如果`k`是`j`的朋友，`j`是`i`的朋友，则`i`与`k`是间接朋友，它们形成了一个“朋友圈”，求`M`中朋友圈的个数。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/547.%20Friend%20Circles/solution.py)
    维护一个`visited`数组，表示是否已经检查过第`i`个人的朋友圈。然后以`i`为第`i`个人的下标，进入循环，如果`visited[i] == 1`，即已经检查过该人的朋友圈，则`continue`，否则，首先将`visited[i] = 1`，然后初始化栈`stack = [i]`，准备深度优先遍历：当栈`stack`不为空，则栈尾出栈记作`j`，则以`k`为第`k`个人的下标，进入循环，如果`visited[k] == 0`且`M[j][k] == 1`，即第`k`个人的朋友圈尚未检查，而且`j`与`k`互为朋友，则将`k`入栈。当以`i`为下标的外部循环结束，则将`res += 1`，结果自增。最后返回`res`作为结果。

#### 104. Maximum Depth of Binary Tree
- ##### [描述](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)
    给定一颗二叉树，输出二叉树的深度。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Trees%20and%20Graphs/104.%20Maximum%20Depth%20of%20Binary%20Tree/solution.py)
    略，参考层序遍历二叉树，遍历时记录深度即可。
    
### 回溯 - Backtracking

#### 17. Letter Combinations of a Phone Number
- ##### [描述](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
    数字`2-9`中，每个数字对应电话号码上的几个字母，给定一个由`2-9`组成的字符串，输出所有可能的字母组合。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Backtracking/17.%20Letter%20Combinations%20of%20a%20Phone%20Number/solution.py)
    初始化结果数组`result`，对给定数字字符串`s`以及每个字符所能对应的字母，进行深度优先遍历。即，遍历数字字符串`s`，对每一个下标`i`，与其对应的数字`num`，查询它可能的组成字母，依次递归调用深度优先遍历函数。深度优先遍历函数有四个参数，分别是当前下标`i`，数字字符串`s`，当前组合`pattern`，结果数组`result`，直到当前下标`i == len(s)`时，将`pattern`添加到`result`中，并返回结果数组。

### 排序和搜索 - Sorting and Searching

#### 26. Remove Duplicates from Sorted Array
- ##### [描述](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
    给定一个已经排序的数组，数组中可能有重复元素，就地移除重复元素，并返回新的数组长度。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Sorting%20and%20Searching/26.%20Remove%20Duplicates%20from%20Sorted%20Array/solution.py)
    初始化有序下标`j == 0`，以下标`i = 0`开始遍历排序数组`nums`，如果排序数组`nums`在有序下标`j`的值不等于在下标`i`的值，则将`j += 1`，并使得`nums[j] = nums[i]`。如果排序数组`nums`在有序下标`j`的值等于下标`i`的值，则什么都不做。最后返回`j + 1`作为结果。

#### 88. Merge Sorted Array
- ##### [描述](https://leetcode.com/problems/merge-sorted-array/description/)
    给定两个排序后的数组`a, b`，其中`a`数组足够长，归并两个排序数组至`a`数组并返回。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/tree/master/LeetCode/Sorting%20and%20Searching/88.%20Merge%20Sorted%20Array)
    从后遍历数组`a, b`，初始化三个下标`a_i == len(a) - 1`，`b_i == len(b) - 1`, `m_i = len(a) + len(b) - 1`，分别代表`a`的下标，`b`的下标，结果下标，以`a_i, b_i`均大于等于`0`进入循环，如果`a[a_i] > b[b_i]`，则`a[m_i] = a[a_i]`，然后`m_i -= 1`，`a_i -= 1`，反之同理，直到循环结束。如果`b_i`仍大于等于`0`，则说明`b`仍有剩余，这些数字都很小，所以以`b_i`大于等于`0`为条件进入循环，依次`a[m_i] = b[b_i]`，然后`m_i -= 1`，然后`b_i -= 1`，最后结束。

#### 75. Sort Colors
- ##### [描述](https://leetcode.com/problems/sort-colors/description/)
    三色排序，给定一个整型数组`nums`，只包含`0, 1, 2`三种元素，以O(n)的时间就地排序，不可使用基数排序，后返回结果。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Sorting%20and%20Searching/75.%20Sort%20Colors/solution.py)
    初始化三个下标`i == 0, j == len(nums) - 1, k == 0`，分别代表左下标，右下标，当前下标。然后`k < j`，即当前下标小于右下标为条件进入循环，如果`nums[k] == 2`，则交换`num[k]`与`num[j]`的值，然后`j -= 1`，即右下标左移。如果`nums[k] == 1`，则`k += 1`。如果`nums[k] == 0`，则交换`num[k]`与`nums[i]`的值，然后`i += 1, k += 1`，直到循环结束。
    
#### 153. Find Minimum in Rotated Sorted Array
- ##### [描述](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)
    给定一个有序数组`nums`，数组在某一位被翻转，例如：如[0, 1, 2, 3, 4] -> [3, 4, 0, 1, 2]，返回最小元素。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Sorting%20and%20Searching/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array/solution.py)
    初始化三个下标`i == 0, j == len(nums) - 1, mid == 0`，分别代表左下标，右下标，中下标。然后以`i < j`为条件进入循环，计算`mid = (i + j) // 2`，如果`nums[mid] < nums[j]`，则说明区间有序，更新`j = mid`，继续循环。如果`nums[mid] >= nums[j]`，则说明区间内存在翻转，最小元素应在翻转区间，将`i = mid + 1`后，继续循环。当循环结束，返回nums[i]作为结果。

#### 33. Search in Rotated Sorted Array
- ##### [描述](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)
    给定一个有序数组`nums`和目标数`target`，数组在某一位被翻转，例如：如[0, 1, 2, 3, 4] -> [3, 4, 0, 1, 2]，查找`target`，如果存在则返回其下标，否则返回`-1`。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Sorting%20and%20Searching/33.%20Search%20in%20Rotated%20Sorted%20Array/solution.py)
    初始化`peak_i = -1, peak_num == -inf`，代表最大值和其下标。遍历数组`nums`，找到最大值和其下标。此时，如果`target`大于`peak_num`，则返回`-1`。然后进行判断，如果`target >= nums[0]`，则在`[0:peak_i + 1]`区间进行二分查找，如果`target < nums[0]`，则`target`在翻转区间内，则在`[peak_i + 1:]`区间内进行二分查找。

#### 74. Search a 2D Matrix
- ##### [描述](https://leetcode.com/problems/search-a-2d-matrix/description/)
    给定一个二维数组`nums`和一个目标数`target`，该二维数组的每个元素是严格按下标增长的。在二维数组`nums`查找元素`target`，如果存在则返回`True`，否则返回`False`。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Sorting%20and%20Searching/74.%20Search%20a%202D%20Matrix/solution.py)
    初始化`peak_j = 0`，以`nums[j][0] <= target`为条件，遍历`nums`每行的第一个元素，记录`peak_j = j`，在区间行`nums[j][:]`进行二分查找，后返回结果。

#### 240. Search a 2D Matrix II
- ##### [描述](https://leetcode.com/problems/search-a-2d-matrix-ii/description/)
    给定一个二维数组`nums`和一个目标数`target`，该二维数组是的每一个行是有序的，每一列是有序的。在二维数组`nums`查找元素`target`，如果存在则返回`True`，否则返回`False`。
    
- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Sorting%20and%20Searching/240.%20Search%20a%202D%20Matrix%20II/solution.py)
    初始化`peak_j = 0`，以`nums[j][0] <= target`为条件，遍历`nums`每行的第一个元素，记录`peak_j = j`，以下标`i`遍历`0`行到`j`行，在区间行`nums[i][:]`进行二分查找，后返回结果。

#### 252. Meeting Rooms
- ##### [描述](https://leetcode.com/problems/meeting-rooms/description/)
    给定一个数组`intervals`，数组内的元素是一个整型二元组，表示了会议的开始和结束时间，如果会议时间有冲突，判断会议之间是否有冲突。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Sorting%20and%20Searching/33.%20Search%20in%20Rotated%20Sorted%20Array/solution.py)
    将该数组按开始时间排序后结果记为`intervals`，然后以`i`为下标遍历数组，如果`intervals[i].start < intervals[i-1].end`，则有冲突，返回`False`，否则继续循环直到结束，返回`True`，即没有冲突。

#### 253. Meeting Rooms II
- ##### [描述](https://leetcode.com/problems/meeting-rooms-ii/description/)
    给定一个数组`intervals`，数组内的元素是一个整型的二元组，表示了会议的开始和结束时间，因为会议时间有可能冲突，返回最多需要的会议室数量。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Sorting%20and%20Searching/253.%20Meeting%20Rooms%20II/solution.py)
    维护一个字典`interval_rooms_map`，它的键是会议开始或结束时间，它的值时此刻会议室的“名义数量”，然后遍历`intervals`，对`interval_rooms_map[interval.start] += 1`，对`interval_rooms_map[interval.end] -= 1`，表示每个会议`interval`的起始时间对会议室的“名义数量”，即如果会议开始，那么占用数需要自增，如果结束，那么占用数自减。然后，获取该字典的所有键并升序排序，其结果记为`keys_sorted`。然后，初始化`max_room = 0, cur_room = 0`，代表最大会议室数量和当前会议室数量，通过`key_sorted`的`key`遍历`interval_rooms_map`的值，并使得`cur_room += interval_rooms_map[key]`，同时更新最大会议室数量`max_room = max(max_room, cur_room)`，最后返回`max_room`。

### 动态规划 - Dynamic Programming

#### 121. Best Time to Buy and Sell Stock
- ##### [描述](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
    给定一个数组`prices`，数组内每个元素代表了某个股票某时刻的价格，选择一个时间买入，一个时间卖出，返回最大的收益。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Dynamic%20Programming/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock/solution.py)
    初始化最大收益`s_max=0`，最小价格`p_min=-inf`，遍历`prices`中的每个价格`price`，取`p_min = min(price, p_min)`，然后计算当前买入价格收益`profit = price - p_min`，选择更新最大收益`s_max=max(profit, s_max)`，最后返回`s_max`作为结果。

#### 53. Maximum Subarray
- ##### [描述](https://leetcode.com/problems/maximum-subarray/)
    给定一个整型数组`nums`，返回最大的子数组的和。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Dynamic%20Programming/53.%20Maximum%20Subarray/solution.py)
    初始化`dp = [0] * len(nums)`，以下标`i`遍历数组`nums`，则`dp[i] = max(nums[i], nums[i] + dp[i - 1])`，即以下标为`i`截止的子数组`nums[:i+1]`，它的最大
    `dp[i] = max(num, num + dp[i - 1])`其中`dp[i]`为第`i`个下标的最大子数组和。

#### 70. Climbing Stairs
- ##### [描述](https://leetcode.com/problems/climbing-stairs/description/)
    给定一个`n`阶楼梯，一次可以爬`1`阶楼梯或者`2`阶楼梯，返回爬到`n`阶，有多少种爬法。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Dynamic%20Programming/70.%20Climbing%20Stairs/solution.py)
    初始化`dp = [0] * (n + 1)`，`dp[i]`表示爬到第`i`阶，有多少种爬法，所以，可以写出递推式：`dp[i] = dp[i - 1] + dp[i - 2]`，最后，返回`dp[n - 1]`作为结果。

#### 198. House Robber
- ##### [描述](https://leetcode.com/problems/house-robber/description/)
    给定一个数组`nums`，`nums`中每个下标`i`对应的`nums[i]`代表`i`位置财产的价值。限定不可以同时拿取两个相邻位置的财产，返回可拿取财产的最大值。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Dynamic%20Programming/198.%20House%20Robber/solution.py)
    初始化`dp = [0] * len(nums)`，则有初始情况`dp[0] = nums[0]`，`dp[1] = max(nums[0], nums[1])`，`dp[i]`代表了当财产个数为`i`个时，可拿取财产的最大值，所以，可以写出递推式：`dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])`，最后返回`max(dp[-1], dp[-2])`作为结果。

#### 152. Maximum Product Subarray
- ##### [描述](https://leetcode.com/problems/maximum-product-subarray/description/)
    给定一个整型数组`nums`，返回最大的子数组的积。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Dynamic%20Programming/152.%20Maximum%20Product%20Subarray/solution.py)
    初始化`dp = [0] * len(nums)`，`dp[i]`表示以`nums[i]`为最后一个元素的子数组的最大子数组的积。由于负数的存在，需要初始化`dp_min = [0] * len(nums)`和`dp_max = [0] * len(nums)`，`dp_min[i]`与`dp_max[i]`分别代表以`nums[i]`为最后一个元素的子数组的最小数组积和最大数组积。`dp_min`的意义在于，由于负数的存在，如果`dp_min[i - 1]`是一个负数，而`nums[i]`同样是一个负数，则`dp_min[i - 1] * nums[i]`将会是正数。所以我们可以写出递推式：`dp[i] = max(dp_min[i-1] * nums[i], dp_max[i-1] * nums[i], nums[i])`，然后更新`dp_max[i] = dp[i]`，`dp_min[i] = min(dp_min[i-1] * nums[i], dp_max[i-1] * nums[i], nums[i])`，最后返回`max(dp)`作为结果。

#### 139. Word Break
- ##### [描述](https://leetcode.com/problems/word-break/description/)
    给定一个字符串`s`，给定一个字符串数组`wordDic`，其元素是一些单词。如果`s`能被`wordDic`中的单词组合而成，则返回`True`，否则返回`False`。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Dynamic%20Programming/139.%20Word%20Break/solution.py)
    初始化`dp = [False] * len(s) + 1`，`dp[i]`表示以`s[i]`结尾的子串，是否能被`wordDic`中的单词组合。则外循环以下标`i`遍历字符串`s`，内循环以下标`j`遍历`i`到`len(s)`，如果`dp[i]`为真，即以`s[i]`结尾的子串可以被`wordDic`中的单词组合，而且子串`s[i: j+1]`在`wordDic`中，那么`dp[j + 1] = Ture`，最后，返回`dp[-1]`作为结果。
    
#### 62. Unique Paths
- ##### [描述](https://leetcode.com/problems/unique-paths/description/)
    给定一个二维数组的行列`m, n`，从位置`mat[0][0]`出发，到达`mat[-1][-1]`，限定能向右或者向下移动，返回走法的总数。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Dynamic%20Programming/62.%20Unique%20Paths/solution.py)
    初始化`dp = [[1 for _ in range(0, n)] for _ in range(0, m)]`，`dp[i][j]`表示从出发点`mat[0][0]`到该点的走法数量。则以下标`i, j`遍历行列，则可以写出递推式：`dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`，最后返回`dp[-1][-1]`作为结果。
    
#### 120. Triangle
- ##### [描述](https://leetcode.com/problems/triangle/description/)
    给定一个数组`triangle`，`triangle`中的元素均为整型数组。现自顶向下在`triangle`中的每行选择一个数，限定在`i`行选择第`j`个数后，在`i+1`行选择时只能选择`j, j + 1`，最终使得它们的和最小，并返回结果。

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Dynamic%20Programming/120.%20Triangle/solution.py)
    初始化`dp = [0] * (len(triangle) + 1)`，`dp[i]`表示“自底向上”选择数字时，第`i`行为止最小的和。则以`i`为下标，倒序遍历`triangle`的每一行，以`j`为下标遍历`triangle[i]`每一个元素，可以写出递推式：`dp[j] = traiangle[i][j] + min(dp[j], dp[j + 1])`，最后返回`dp[0]`作为结果。

#### 
- ##### [描述]()

- ##### [题解]()