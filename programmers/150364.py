# 2023 kakao blind recruitment > 1,2,3 떨어트리기
# https://school.programmers.co.kr/learn/courses/30/lessons/150364
import math

def solution(edges, target):
    # graph initialize
    graph = {i: [] for i in range(1, len(target) + 1)}

    for edge in edges:
        v1, v2 = edge
        graph[v1].append(v2)

    leaf_count = {i: 0 for i in range(1, len(target) + 1)}
    for v in graph:
        if len(graph[v]) == 0:
            leaf_count[v] = 0
            continue
        graph[v] = sorted(graph[v])

    selection = {i: -1 for i in range(1, len(target) + 1)}
    for v in graph:
        if len(graph[v]):
            selection[v] = 0

    leaf = []
    is_finish = False
    while not is_finish:
        node = 1
        while selection[node] != -1:
            next_node = graph[node][selection[node]]
            if len(graph[node]) >= 2:
                selection[node] = (selection[node] + 1) % len(graph[node])
            node = next_node

        leaf.append(node)
        leaf_count[node] += 1

        is_finish = True
        for i in leaf_count:
            if leaf_count[i] < int(math.ceil(target[i - 1] / 3)):
                is_finish = False
                break
            elif leaf_count[i] > target[i - 1]:
                return [-1]

    result = [1 for _ in range(len(leaf))]
    for i in leaf:
        target[i-1] -= 1

    for i in range(len(leaf) - 1, -1, -1):
        if target[leaf[i] - 1] >= 2:
            result[i] += 2
            target[leaf[i] - 1] -= 2
        elif target[leaf[i] - 1] == 1:
            result[i] += 1
            target[leaf[i] - 1] -= 1
        else:
            continue

    return result
