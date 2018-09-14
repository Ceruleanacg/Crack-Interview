# Complete the function below.

import math


def are_equivalent_triangles(triangle_one, triangle_two):
    a_edges_length = calculate_edge_length(triangle_one)
    b_edges_length = calculate_edge_length(triangle_two)

    for index in range(3):
        if a_edges_length[index] != b_edges_length[index]:
            return False

    return True


def calculate_edge_length(triangle):

    edges_length = [0., 0., 0.]

    point_a = triangle[0]
    point_b = triangle[1]
    point_c = triangle[2]

    edges_length[0] = math.sqrt((point_a[0] - point_b[0]) ** 2 + (point_a[1] - point_b[1]) ** 2)
    edges_length[1] = math.sqrt((point_b[0] - point_c[0]) ** 2 + (point_b[1] - point_c[1]) ** 2)
    edges_length[2] = math.sqrt((point_a[0] - point_c[0]) ** 2 + (point_a[1] - point_c[1]) ** 2)

    return edges_length
