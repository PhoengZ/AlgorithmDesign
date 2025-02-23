n = int(input())

mod = 100000007
v = [0]*3
v1 = [0]*3
v[0] = v[1] = v[2] = 1
for i in range(1,n):
    v1[0] = (v[0]%mod + v[1]%mod + v[2]%mod)%mod
    v1[1] = (v[0]%mod + v[2]%mod)%mod
    v1[2] = (v[0]%mod + v[1]%mod)%mod
    v[0] = v1[0]
    v[1] = v1[1]
    v[2] = v1[2]
print((v[0]%mod + v[1]%mod + v[2]%mod) % mod)