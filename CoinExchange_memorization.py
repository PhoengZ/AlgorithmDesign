def f(n,m,v,dp):
    if (m < 0):return 1000000
    if n == 0:return dp[n][m]
    if dp[n][m] != 0:return dp[n][m]
    dp[n][m] = min(f(n,m-v[n-1],v,dp)+1,f(n-1,m,v,dp))
    return dp[n][m]

n,m = [int(e) for e in input().split()]
v = [int(e) for e in input().split()]
v.sort()
dp = [[0]*(m+1) for e in range(n+1)]
for i in range (1,m+1):dp[0][i] = 100000000
ans = f(n,m,v,dp)
print(ans)