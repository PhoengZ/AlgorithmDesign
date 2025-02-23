v = [int(e) for e in input().split()]
m = max(v[1:4])
l = [0]*(v[0]+1)
for i in range(1,m+1):
    for e in range(1,4):
        if (i - v[e] >= 0):
            l[i] = max(l[i-v[e]] + 1,l[i])
    if (l[i] == 0):l[i] = -10000
for i in range(m+2,v[0]+1):
    l[i] = max(l[i-v[1]],l[i-v[2]],l[i-v[3]]) + 1
print (l[v[0]])