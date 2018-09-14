class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        results = {

        }

        for s in strs:
            s_sorted = str(sorted(s))
            if s_sorted in results:
                results[s_sorted].append(s)
            else:
                results[s_sorted] = [s]
        return list(results.values())


print(Solution().groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
