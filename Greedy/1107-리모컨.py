N = input()
M = int(input())
broken = [False for i in range(10)]
b = []
if M != 0:
    b = list(map(int, input().split()))
for idx in b:
    broken[idx] = True

dis = str()
result = 0

def solve():
    global N, dis
    result = 0
    for i in range(len(N)):
        here = int(N[i])
        if broken[here]:
            temp1 = str()
            temp2 = str()
            for j in range(here + 1, 10):
                if not broken[j]:
                    temp1 = dis + str(j)
                    break
            for k in range(here - 1, -1, -1):
                if not broken[k]:
                    temp2 = dis + str(k)
                    break
            print(temp1, temp2)
            if len(temp1) == 0 and len(temp2) == len(dis) + 1:
                dis = temp2
                result += 1
            elif len(temp1) == len(dis) + 1 and len(temp2) == 0:
                dis = temp1
                result += 1
            elif len(temp1) != 0 and len(temp2) != 0:
                sliced = int(N[:len(dis) + 1])
                if int(temp1) > sliced and int(temp2) > sliced:
                    dis = str(min(int(temp1), int(temp2)))
                    result += 1
                elif int(temp1) < sliced and int(temp2) < sliced:
                    dis = str(max(int(temp1), int(temp2)))
                    result += 1
        else:
            dis += str(here)
            result += 1
        if dis == "0":
            break
    return result

if M == 10:
    print(abs(int(100) - int(N)))
else:
    result = solve()
    print(N, dis)
    if abs(int(100) - int(N)) < result + abs(int(N) - int(dis)):
        print("+/-")
        print(abs(int(100) - int(N)))
    else:
        print("번호")
        print(result + abs(int(N) - int(dis)))