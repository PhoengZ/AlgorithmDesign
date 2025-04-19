n,m = [int(e) for e in input().split()]
s = [int (e) for e in input().split()]
time = [0]*n
idx = 0
s.sort()
total = 0
while (idx != m):
    for i in range(n):
        if (idx == m):break
        time[i] += s[idx]
        idx+=1
        total+= time[i]
print(f"{total/m:.3f}")
