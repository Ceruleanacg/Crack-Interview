class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        dic = dict()

        for num in nums:
            if num in dic:
                dic[num] += 1
            else:
                dic[num] = 1

        dic_sorted = sorted(dic.items(), key=lambda item: item[1], reverse=True)

        result = [item[0] for item in dic_sorted[:k]]

        return result


s = Solution()
s.topKFrequent([1, 1, 1, 2, 2, 3, 3, 3, 3], 2)