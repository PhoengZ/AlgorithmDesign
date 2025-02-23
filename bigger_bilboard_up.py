v = int(input())
s = [int(e) for e in input().split()]
dp = [0]*v
dp[0] = s[0]
dp[1] = max(s[0],s[1])
dp[2] = max(s[0],s[1],s[2])
if (v <= 3):print(max(dp))
else:
    for i in range(3,v):
        dp[i] = max(dp[i-3]+s[i],dp[i-1])
    print(dp[v-1])
