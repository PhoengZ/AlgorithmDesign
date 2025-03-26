from collections import deque
q = deque()
n,e,k = [int(i) for i in input().split()]
s = [False]*(n+1)
g = [[]for i in range(n+1)]
for i in range(e):
    a,b = [int(i) for i in input().split()]
    g[a].append(b)
    g[b].append(a)
s[0] = True
q.append((0,0))
total = 0
while(len(q) != 0):
    t = q[0]
    q.popleft()
    for i in g[t[0]]:
        if (not s[i] and t[1] + 1 <= k):
            s[i] = True
            if (t[1]+1 == k):total+=1
            q.append((i,t[1]+1))
print(total)
