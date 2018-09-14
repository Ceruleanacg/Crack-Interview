# Complete the get_count function below.

visit_map = {}


def get_count(n):
    count = 0
    for num in range(n + 1):
        global visit_map
        visit_map = {}
        count += calculate_result(list(str(num)))
    return count


def calculate_result(num_list):
    if ''.join(num_list) in visit_map:
        return 0
    result = int(sum([int(num) ** 2 for num in num_list]))
    if result == 1:
        return 1
    visit_map[''.join(num_list)] = result
    return calculate_result(list(str(result)))
