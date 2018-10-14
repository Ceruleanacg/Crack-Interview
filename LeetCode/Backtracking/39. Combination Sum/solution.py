class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        results = []
        candidates = sorted(candidates)
        self.dfs(candidates, target, 0, [], results)
        return results

    def dfs(self, candidates, target, last, result: list, results: list):
        if target == 0:
            results.append(result[:])
        if target < candidates[0]:
            return
        for num in candidates:
            if num > target:
                return
            if num < last:
                continue
            result.append(num)
            self.dfs(candidates, target - num, num, result, results)
            result.pop()

