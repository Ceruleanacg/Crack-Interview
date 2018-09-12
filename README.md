# LeetCode

## Solutions
Why should we do this again and again?

### Array and Strings

##### A-Marked

- [1. Two Sum](https://leetcode.com/problems/two-sum/description/)
    - 描述：给定一个目标数，返回数组中能使和为目标数的数的索引    
    - 考点：哈希表
    - 思路：遍历数组，目标值与当前索引对应的值求差，并在字典里查找查对应的索引，如果存在则返回，如果不存在，则将当前索引值 - 索引在字典建立映射
- [125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
    - 描述：给定一个字符串，判断该字符串是否是回文，即从前后方向阅读都相同
    - 考点：字符串
    - 思路：通过Python的逆置语法糖逆置，然后字符串匹配
- [8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi)
    - 描述：给定一个字符串，将之字符中数字部分转换为整型
    - 考点：字符串
    - 思路：
- [344. Reverse String](https://leetcode.com/problems/reverse-string/description/)
    - 描述：给定一个字符串，将之逆置
    - 考点：字符串
    - 思路：通过Python的逆置语法糖逆置
- [151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/description/)
    - 描述：给定一个字符串，将字符串内的每个字符逆置
    - 考点：
    - 思路：
- [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)
    - 描述：括号匹配：{[()]}
    - 考点：栈
    - 思路：遇到左括号入栈，遇到右括号出栈，出栈左括号和右括号如果对不上，则非法，否则合法，最后检查栈是否为空，为空则合法
- [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)
    - 描述：最长回文子串
    - 考点：动态规划
    - 思路：状态转移方程，理清情况，如果左边界等于右边界，则是回文，如果右边界减去左边界等于1，且对应的值相等，则是回文，如果右边界减去左边界大于1，如果对应的值相等，且右边界减去1和左边界加1是回文，则是回文

### Linked List

- [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)
    - 描述：给定一个链表，将之就地逆置
    - 考点：链表
    - 思路：遍历链表，保存当前结点，将当前结点的后继结点更新为前驱结点，然后将前驱结点更新为当前结点
- [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/)
    - 描述：给定一个链表，判断该链表是否存在闭环
    - 考点：链表
    - 思路：快慢指针法，快指针初始化为慢指针的后继，然后用慢指针遍历链表，快指针一次更新两次，如果慢指针见底，则无环，如果快慢指针相遇，则闭环
- [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)
    - 描述：两链表从头到尾表示数字的低位到高位，将两链表相加
    - 考点：链表
    - 思路：遍历链表相加，注意进位，本次遍历注意结束时不需要创建新节点，再次遍历（如必要），将剩余链表的高位依次添加，注意进位，最后根据进位标志判断是否需要创建新节点
- [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/)
    - 描述：将两条已经排序链表合并，已知第一条链表足够长
    - 考点：链表，分治
    - 思路：初始化头结点，定义当前结点为头结点，遍历链表，将第一条与第二条结点中当前较小的结点作为当前节点的后继，然后更新该条当前节点为其后继，最后将多余的结点作为当前节点的后继，然后返回头结点
- [445. Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/description/)
    - 描述：两链表从头到位表示数字的高位到地位，不逆序，将链表相加
    - 考点：链表
    - 思路：依次遍历两链表，将链表每个节点的值加和，然后求和重新构造链表

### Trees and Graphs

- [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/)
    - 描述：验证一棵树是否是二叉查找树
    - 考点：二叉查找树的性质（中序遍历有序）
    - 思路：中序遍历，检查中序遍历结果是否有序
- [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)
    - 描述：中序遍历二叉树
    - 考点：二叉树中序遍历，递归，栈
    - 思路：
        - 递归：先递归左孩子，然后添加根节点值，然后递归右孩子
        - 迭代：首先初始化（根节点，未访问）元组并入栈，然后循环，将栈顶出栈，判断节点是否为真，然后判断节点是否已经访问，如果已经访问，则向结果数组添加结果，如果未访问，则依次入栈右、根、左节点，并标记他们的访问情况为否、是、否
- [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
    - 描述：二叉树层序遍历
    - 考点：二叉树层序遍历
    - 思路：维护一个层节点数组，数组存储当前层所有节点，然后循环（如果层节点数组不为空），遍历层节点所有节点的值，然后将层节点所有非空孩子节点作为新层数组
- [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)
    - 描述：Z字形输出二叉树节点的值
    - 考点：二叉树层序遍历
    - 思路：维护一个层节点数组，数组存储当前层所有节点，然后循环（如果层节点数组不为空），遍历层节点所有节点的值，单次不反转，双次反转，然后将层节点所有非空孩子节点作为新层数组
- [116. Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)
    - 描述：将一个满二叉树的每一层变成一个链表
    - 考点：二叉树层序遍历
    - 思路：维护一个层节点数组，数组存储当前层所有节点，然后循环（如果层节点数组不为空），遍历层节点所有值，然后串成链表
- [117. Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/)
    - 描述：将一个二叉树的每一层变成一个链表
    - 考点：二叉树层序遍历
    - 思路：同116思路
- [235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)
    - 描述：求二叉查找树两节点的公共祖先
    - 考点：递归
    - 思路：如果根节点的值介于两节点的值间，则返回，否则，如果两节点的值都小于根节点，那么递归本函数，将根节点换为根节点的左孩子，否则右递归

### Backtracking

- [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
    - 描述：2-9数字中每个数字对应了电话号码上的几个字母，输入一串2-9的数字，输出数字对应的字母的所有排列组合
    - 考点：回溯、深度优先遍历、递归
    - 思路：注意DFS函数参数设计和递归停止条件，参数应该包含（当前当前索引、数字、当前模式、结果），如果索引等于长度，则应该停止，向结果添加模式，否则，遍历当前数字对应的字母，然后依次DFS，此时索引自增，模式自增当前字母

### Sorting and Searching

- [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
    - 描述：就地从排序数组里移除冗余数字
    - 考点：
    - 思路：定义一个"有序尾索引"，该索引永远为有序数组无冗余的"前端"，然后遍历数组，如果数组的"有序尾索引"的值不等于当前值，则有序尾索引自增，然后更新有序尾索引对应的值为当前值，最后返回有序尾索引自增
- [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/)
    - 描述：就地合并两个排序后的数组（第一个数组足够长）
    - 考点：分治
    - 思路：从后遍历两个数组，根据当前两索引对应的值的大小，将较大的索引对应的值放进合并索引（m + n - 1)位置中，然后对应索引自减，最后如果第二个数组索引仍然不为，0则继续填充合并索引位置，两索引自减少
- [75. Sort Colors](https://leetcode.com/problems/sort-colors/description/)
    - 描述：三色排序，即0，1，2就地O(n)时间排序，不可用基数排序
    - 考点：双指针
    - 思路：维护三个指针，分别是左，当前，右指针，以当前指针小于等于右指针为条件进入循环，如果当前数字等于2，则将当前数字与右指针交换，然后右指针左移，当前与左指针不动，如果当前数字等于1，左右指针均不动，当前指针自增，如果当前数字等于0，交换当前与左指针的值，然后当前和左指针自增。
- [153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)
    - 描述：有序数组在某一位被完全反转，例如[0, 1, 2, 3, 4] -> [3, 4, 0, 1, 2]，找出最小元素
    - 考点：二分查找
    - 思路：取左中右索引，如果中值比右值小，则将右索引更新为中索引，如果中值等于或大于右值，则数组在此被反转，将左索引更新为中索引加1
    

### Dynamic Programming

##### B-Marked

- [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
