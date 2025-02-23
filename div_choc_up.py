n,k = [int(e) for e in input().split()]
v = [int(e) for e in input().split()]
dp = [0]*(n+1)
dp[0] = 1
for i in range(1,n+1):
    for j in range(k):
        dp[i]+= (dp[i-v[j]])%1000003 if i-v[j] >= 0 else 0
    dp[i]% 1000003
print(dp[n]%1000003)