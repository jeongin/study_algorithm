import sys

sys.setrecursionlimit(5000)

# d l r u
d_str = ['d', 'l', 'r', 'u']
dx = [1, 0, 0, -1]
dy = [0, -1, 1, 0]
answer = ''

def simulation(n, m, target_x, target_y, cur_x, cur_y, route, k):
    global answer

    distance = abs(target_x - cur_x) + abs(target_y - cur_y)
    if len(route) == k and target_x == cur_x and target_y == cur_y:
        answer = route
        return route
    elif len(route) > k or len(route) + distance > k:
        return "impossible"
    elif cur_x < 1 or cur_x > n or cur_y < 1 or cur_y > m:
        return "impossible"

    for d in range(4):
        result = simulation(n, m, target_x, target_y, cur_x + dx[d], cur_y + dy[d], route + d_str[d], k)

        if answer != '':
            break

        if result != "impossible":
            answer = result
            break

    return "impossible"


def solution(n, m, x, y, r, c, k):
    distance = abs(x - r) + abs(y - c)
    if distance > k or (k - distance) % 2:
        return "impossible"

    simulation(n, m, r, c, x, y, '', k)

    return answer
