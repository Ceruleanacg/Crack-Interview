class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0

        index_max_height = 0
        index_cur_peak = 0

        rains = 0

        for index in range(1, len(height)):
            if height[index] > height[index_max_height]:
                index_max_height = index

        for index in range(0, index_max_height):
            if index_cur_peak < height[index]:
                index_cur_peak = height[index]
            else:
                rains += index_cur_peak - height[index]

        index_cur_peak = 0

        for index in range(len(height) - 1, index_max_height, -1):
            if index_cur_peak < height[index]:
                index_cur_peak = height[index]
            else:
                rains += index_cur_peak - height[index]

        return rains


print(Solution().trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
