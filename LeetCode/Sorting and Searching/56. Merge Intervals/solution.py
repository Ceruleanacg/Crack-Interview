# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """

        if not intervals:
            return []

        intervals_sorted = sorted(intervals, key=lambda x: x.start)

        results = [intervals_sorted[0]]

        for interval in intervals_sorted[1:]:
            if interval.start <= results[-1].end:
                results[-1].end = max(results[-1].end, interval.end)
            else:
                results.append(interval)

        return results