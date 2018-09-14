# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(A):
    # write your code in Python 3.6
    length = len(A)
    result = 0
    for index in range(length):
        result += pm2(A[index])

    if abs(result) > 10000000:
        return -1

    return result

def pm2(n):
    return (-2) ** n
