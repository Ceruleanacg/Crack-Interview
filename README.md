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
    - 考点：字典树
    - 思路：

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

### Trees and Graphs

- [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/)
- [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)
- [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
- [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

### Backtracking

- [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

### Sorting and Searching

- [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
- [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/)

### Dynamic Programming

##### B-Marked

- [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
