class Solution:
    def threeSum(self, nums: list):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = dict()

        num_count = len(nums)

        if num_count < 3:
            return []

        nums.sort()

        two_sum_targets = [-num for num in nums]

        for i in range(num_count):
            y_map = dict()
            target = two_sum_targets[i]
            for x in nums[i + 1:]:
                y = target - x
                if y in y_map:
                    res = -target, x, y_map[y]
                    if res not in results:
                        results[res] = list(res)
                else:
                    y_map[x] = x
        return list(results.values())


# print(Solution().threeSum([0, 0, 0]))
# print(Solution().threeSum([1, 2, -2, -1]))
# print(Solution().threeSum([-1, 0, 1, 2, -1, -4]))
