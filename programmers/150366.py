# 2023 kakao blind recruitment > 표 병합
# https://school.programmers.co.kr/learn/courses/30/lessons/150366
empty = "EMPTY"
parent = [[(r, c) for c in range(51)] for r in range(51)]
table = [[empty] * 51 for _ in range(51)]
result = []


def get_parent(r: int, c: int):
    if parent[r][c] == (r, c):
        return parent[r][c]

    pr, pc = parent[r][c]
    return get_parent(pr, pc)


def update(r: int, c: int, v: str):
    pr, pc = get_parent(r, c)
    table[pr][pc] = v


def update_val(v1: str, v2: str):
    for r in range(51):
        for c in range(51):
            pr, pc = get_parent(r, c)
            if table[pr][pc] == v1:
                table[pr][pc] = v2


def merge(r1: int, c1: int, r2: int, c2: int):
    r1, c1 = get_parent(r1, c1)
    r2, c2 = get_parent(r2, c2)

    if (r1, c1) == (r2, c2):
        return
    elif table[r1][c1] != empty:
        parent[r2][c2] = parent[r1][c1]
    else:
        parent[r1][c1] = parent[r2][c2]


def unmerge(r: int, c: int):
    pr, pc = get_parent(r, c)
    v = table[pr][pc]

    merge_list = list()
    for ar in range(51):
        for ac in range(51):
            apr, apc = get_parent(ar, ac)
            if (apr, apc) == (pr, pc):
                merge_list.append((ar, ac))

    for (ar, ac) in merge_list:
        parent[ar][ac] = (ar, ac)
        table[ar][ac] = empty

    table[r][c] = v


def print_value(r, c):
    pr, pc = get_parent(r, c)
    result.append(table[pr][pc])


def solution(commands):
    for command in commands:
        cmd, *arg = command.split()
        if cmd == "UPDATE":
            if len(arg) == 3:
                r, c, v = arg
                update(int(r), int(c), v)

            else:
                v1, v2 = arg
                update_val(v1, v2)
        elif cmd == "MERGE":
            r1, c1, r2, c2 = map(int, arg)
            merge(r1, c1, r2, c2)
        elif cmd == "UNMERGE":
            r, c = map(int, arg)
            unmerge(r, c)
        else:
            r, c = map(int, arg)
            print_value(r, c)

    return result
