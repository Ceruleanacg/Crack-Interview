# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

results = dict()


def solution(N):
    # write your code in Python 3.6
    # 1000000
    if N in results:
        return results[N]
    else:
        result = f_series(N)
        results[N] = result
        return result


def f_series(n):
    if n < 2:
        return n
    else:
        if n in results:
            return results[n]
        else:
            result = (f_series(n - 1) + f_series(n - 2)) % 1000000
            results[n] = result
            return result
