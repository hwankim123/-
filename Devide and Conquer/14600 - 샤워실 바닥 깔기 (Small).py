N = int(input())
hole = list(map(int, input().split()))
hole[1] = 2**N - hole[1]  # hole[1] : 내가 생각하는 y 좌표
hole[0] -= 1 # hole[0] : 내가 생각하는 x 좌표
result = [[0 for row in range(2**N)] for col in range(2**N)]

count = 1
def solve(size, y, x):
    global count
    if size == 1:
        for i in range(2):
            for j in range(2):
                if y + i == hole[1] and x + j == hole[0]:
                    result[y + i][x + j] = -1
                else:
                    result[y + i][x + j] = count
        count += 1
    else:
        solve(size - 1, y, x)
        solve(size - 1, y + 2**(size - 1), x)
        solve(size - 1, y, x + 2**(size - 1))
        solve(size - 1, y + 2**(size - 1), x + 2**(size - 1))
        for i in range(2):
            for j in range(2):
                if 2*i <= hole[1] < 2*(i + 1) and 2*j <= hole[0] < 2*(j + 1):
                    continue
                else:
                    result[i + 1][j + 1] = count

solve(N, 0, 0)
for i in range(2**N):
    for j in range(2**N):
        print(result[i][j], end = ' ')
    print()