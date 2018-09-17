# coding=utf-8

import sys
import math


if __name__ == '__main__':

    for line in sys.stdin:
        a, b = (int(x) for x in line.split())

        s = a + b
        r = math.sqrt(1 + 8 * s)
        n = int((-1 + r) / 2)

        real_n = (-1 + r) / 2

        if n != real_n:
            print(-1)
            continue

        result = 0

        for i in range(n, 0, -1):

            if a >= i:
                a -= i
                result += 1

            if a == 0:
                print(result)
                break

        if a != 0:
            print(-1)


