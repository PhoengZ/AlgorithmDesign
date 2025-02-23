n,k = [int(e) for e in input().split()]
dp = [[0]*(k+1) for e in range(n+1)]
for i in range(1,n+1):
    dp[i][1] = 1
    if (i <= k):dp[i][i] = 1
if (k > n):print(0)
else:
    for i in range(1,n+1):
        for j in range(1,min(i,k)+1):
            if (i == 1 and j == 1):continue
            dp[i][j] = (((j*dp[i-1][j])%1997) + (dp[i-1][j-1]%1997))%1997
    print(dp[n][k])