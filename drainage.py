n,l = [int(e) for e in input().split()]
l-=1
s = [int(e) for e in input().split()]
s.sort()
idx = s[0]+l
c = 1
for i in range(1,n):
    if (s[i] <= idx or idx > 1000000):continue
    idx = s[i] + l
    c+=1
print(c)