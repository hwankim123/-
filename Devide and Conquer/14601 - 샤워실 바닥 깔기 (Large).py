import sys
sys.setrecursionlimit(10**6)

N = int(input())
hole = list(map(int, input().split()))
hole[1] = 2**N - hole[1]  # hole[1] : 내가 생각하는 y 좌표
hole[0] -= 1 # hole[0] : 내가 생각하는 x 좌표
result = [[0 for row in range(2**N)] for col in range(2**N)]

count = 1
def solve(size, y, x, hy, hx):
    global count
    if size == 1:
        for i in range(2):
            for j in range(2):
                if y + i == hy and x + j == hx:
                    result[y + i][x + j] = -1
                else:
                    result[y + i][x + j] = count
    else:
        half = 2**(size-1)
        for i in range(2):
            for j in range(2):
                if y + half*i <= hy < y + half*(i + 1) and x + half*j <= hx < x + half*(j + 1):
                    solve(size - 1, y + half*i, x + half*j, hy, hx)
                else:
                    solve(size - 1, y + half*i, x + half*j, y + half - 1 + i, x + half - 1 + j)
        for i in range(2):
            for j in range(2):
                if y + half*i <= hy < y + half*(i + 1) and x + half*j <= hx < x + half*(j + 1):
                    continue
                else:
                    result[y + half - 1 + i][x + half - 1 + j] = count
    count += 1

solve(N, 0, 0, hole[1], hole[0])
for i in range(2**N):
    for j in range(2**N):
        print(result[i][j], end = ' ')
    print()