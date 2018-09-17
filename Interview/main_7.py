# coding=utf-8

import sys


def find(sub_s, ori_s):
    s_list = ori_s.split(sub_s)
    res = len(s_list) - 1
    if len(s_list) == 0:
        return 0
    for item in s_list:
        res += find(sub_s, item)
    return res


if __name__ == '__main__':

    k = int(sys.stdin.readline().strip())

    sub_s = sys.stdin.readline()
    ori_s = sys.stdin.readline()

    s_map = {}

    for i in range(len(sub_s) - k):
        s_map[sub_s[i: i + k]] = sub_s[i: i + k]

    result = 0

    for s in s_map.keys():
        result += len(ori_s.split(s)) - 1

    print(result)