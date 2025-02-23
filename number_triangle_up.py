n = int(input())
v = [[0]*(n+1) for i in range(n+1)]
dp = [[0]*(n+1) for i in range(n+1)]
for i in range(1,n+1):
    e = [int(e) for e in input().split()]
    for j in range(1,i+1):
        v[i][j] = e[j-1]
dp[1][1] = v[1][1]
for i in range(1,n+1):
    for j in range(1,i+1):
        dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+v[i][j]
print(max(dp[n]))