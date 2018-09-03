# https://leetcode.com/problems/merge-sorted-array/description/


class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """

        index_1 = m - 1
        index_2 = n - 1
        index_merged = m + n - 1

        while index_1 >= 0 and index_2 >= 0:
            if nums1[index_1] > nums2[index_2]:
                nums1[index_merged] = nums1[index_1]
                index_merged -= 1
                index_1 -= 1
            else:
                nums1[index_merged] = nums2[index_2]
                index_merged -= 1
                index_2 -= 1
        while index_2 >= 0:
            nums1[index_merged] = nums2[index_2]
            index_merged -= 1
            index_2 -= 1
