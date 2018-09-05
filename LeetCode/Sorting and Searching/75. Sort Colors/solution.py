class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        c_index = 0
        r_index = len(nums) - 1
        l_index = 0

        while c_index < r_index:
            if nums[c_index] == 2:
                nums[c_index], nums[r_index] = nums[r_index], nums[c_index]
                r_index -= 1
            elif nums[c_index] == 1:
                c_index += 1
            else:
                # num == 0
                nums[c_index], nums[l_index] = nums[l_index], nums[c_index]
                l_index += 1
                c_index += 1



