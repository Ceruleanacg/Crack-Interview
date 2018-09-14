# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(indices, K):
    # write your code in Python 3.6
    train_length = len(indices) // K
    sub_indices = []
    train_set = []
    test_set = []
    results = []
    for index in range(K):
        sub_indices.append(indices[index * train_length: index * train_length + train_length])

    num_rest = len(indices) - train_length * K
    for index in range(num_rest):
        sub_indice = sub_indices[index]
        sub_indice.append(indices[train_length * K + index])

    for index in range(K):
        test_set.append(sub_indices[index])
        cur_train_set = []
        for idx in range(K):
            if idx == index:
                continue
            cur_train_set.extend(sub_indices[idx])
        train_set.append(cur_train_set)
    for index in range(K):
        results.append(train_set[index])
        results.append(test_set[index])

    return results

