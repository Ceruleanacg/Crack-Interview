class Solution:
    def rotate(self, nums: list, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in range(k):
            last_num = nums.pop()
            nums.insert(0, last_num)

# print(Solution().rotate([1, 2, 3, 4, 5, 6, 7], 3))
