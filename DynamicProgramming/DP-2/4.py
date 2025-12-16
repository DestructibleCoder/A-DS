s = int(input())
n = int(input())
p = list(map(int, input().split()))
m = int(input())
q = list(map(int, input().split()))

dp = [[-1] for _ in range(sum(p) + 1)]
dp[0][0] = 0

for i in range(n):
    for j in range(len(dp)-p[i], -1, -1):
        if dp[j][0] != -1:
            dp[j+p[i]][0] = dp[j][0] + p[i]
            if len(dp[j]) > 1:
                for x in range(len(dp[j+p[i]]) - 1): dp[j+p[i]].pop()
                for x in range(1, len(dp[j])):
                    dp[j+p[i]].append(dp[j][x])
            dp[j+p[i]].append(f"+{p[i]}")

for i in range(m):
    for j in range(q[i], len(dp)):
        if dp[j][0] != -1:
            dp[j-q[i]][0] = dp[j][0] - q[i]
            if len(dp[j]) > 1:
                for x in range(len(dp[j-q[i]]) - 1): dp[j-q[i]].pop()
                for x in range(1, len(dp[j])):
                    dp[j-q[i]].append(dp[j][x])
                dp[j-q[i]].append(f"-{q[i]}")



if dp[s][0] == s:
    for i in range(1, len(dp[s])):
        print(dp[s][i], end=' ')
    print()
else:
    print("Impossible")
