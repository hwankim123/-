N = int(input())

cache = [-1 for i in range(N)]

def solve(here):
    if here == N - 2:
        return 3
    if here == N:
        return 1
    if cache[here] != -1:
        return cache[here]
    
    cache[here] = 3 * solve(here + 2)
    for i in range(here + 4, N + 1, 2):
        cache[here] += 2 * solve(i)
    return cache[here]

if N % 2 == 1:
    print(0)
else:
    print(solve(0))