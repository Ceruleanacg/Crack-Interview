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
    

- ##### [题解](https://github.com/Ceruleanacg/Crack-Interview/blob/master/LeetCode/Array%20and%20Strings/20.%20Valid%20Parentheses/solution.py)
    