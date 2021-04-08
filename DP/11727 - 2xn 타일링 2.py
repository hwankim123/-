N = int(input())

cache = [0 for i in range(N)]
cache[0] = 1
cache[1] = 3
for i in range(2, N):
    cache[i] = (cache[i - 2] * 2 + cache[i - 1]) % 10007
print(cache[N - 1])