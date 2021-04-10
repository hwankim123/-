N = int(input())
K = int(input())
sensor = list(map(int, input().split()))
sensor.sort()
distance = []
for i in range(N - 1):
    if sensor[i + 1] - sensor[i] != 0:
        distance.append(sensor[i + 1] - sensor[i])
distance.sort()
result = 0
for i in range(len(distance) - K + 1):
    result += distance[i]
print(result)