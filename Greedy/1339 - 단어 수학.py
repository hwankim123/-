import operator
N = int(input())
word = []

for i in range(N):
    word.append(input())

AlpNum = dict()

for i in range(N):
    for j in range(len(word[i])):
        if word[i][j] in AlpNum:
            AlpNum[word[i][j]] += pow(10, len(word[i]) - j)
        else:
            AlpNum[word[i][j]] = pow(10, len(word[i]) - j)

sAlpNum = sorted(AlpNum.items(), key=operator.itemgetter(1), reverse=True)

for i in range(len(sAlpNum)):
    for j in range(N):
        for k in range(len(word[j])):
            if word[j][k] == sAlpNum[i][0]:
                word[j] = word[j][:k] + chr(48 + 9 - i) + word[j][k+1:]

result = 0
for i in range(N):
    result += int(word[i])
print(result)
