# coding=utf-8

import sys


def is_tri(_a, _b, _c):
    if _a + _b > _c and _a + _c > _b and _b + _c > _a:
        return True
    else:
        return False


for line in sys.stdin:

    a, b, c = (int(x) for x in line.split())

    result = 0

    for i in range(1, a + 1):
        for j in range(1, b + 1):
            k_max = i + j
            for k in range(1, k_max):
                if is_tri(i, j, k):
                    result += 1

    print(result)
