v = [int(e) for e in input().split()]
dp = [[0] * v[1] for i in range(v[0])]
vp = []
for i in range(v[0]):
    g = [int(e) for e in input().split()]
    vp.append(g)
for i in range(v[0]):
    for j in range(v[1]):
        if (i-1 >= 0 and j-1 >= 0):dp[i][j] = max(dp[i-1][j-1] + vp[i][j]*2,dp[i-1][j]+vp[i][j],dp[i][j-1]+vp[i][j])
        if (i-1 >= 0 and j-1 <0):dp[i][j] = dp[i-1][j]+vp[i][j]
        if (i-1 < 0 and j-1 >= 0):dp[i][j] = dp[i][j-1]+vp[i][j]
        if (i-1 < 0 and j-1 < 0):dp[i][j] = vp[i][j]
print(dp[v[0]-1][v[1]-1])