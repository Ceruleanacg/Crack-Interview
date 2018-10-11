# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution:
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        if not intervals:
            return 0

        interval_rooms_map = dict()

        for interval in intervals:

            if interval.start in interval_rooms_map:
                interval_rooms_map[interval.start] += 1
            else:
                interval_rooms_map[interval.start] = 1

            if interval.end in interval_rooms_map:
                interval_rooms_map[interval.end] -= 1
            else:
                interval_rooms_map[interval.end] = -1

        cur_room = 0
        max_room = 0

        keys_sorted = sorted(interval_rooms_map)

        for key in keys_sorted:
            cur_room += interval_rooms_map[key]
            max_room = max(max_room, cur_room)

        return max_room


a = Interval(0, 30)
b = Interval(5, 10)
c = Interval(15, 20)

print(Solution().minMeetingRooms([a, b, c]))