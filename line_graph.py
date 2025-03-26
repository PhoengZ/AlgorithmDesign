import sys
input = sys.stdin.readline
from collections import deque
v,e = [int(t) for t in input().split()]
g = [[] for i in range(v)]
s = [False]*v
q = deque()
for i in range(e):
    a,b = map(int, sys.stdin.readline().split())
    g[a].append(b)
    g[b].append(a)
total = 0
for i in range(v):
    if s[i]:continue
    check = True
    s[i] = True
    q.append((i,-1))
    while (len(q) != 0):
        t = q.pop()
        if len(g[t[0]]) > 2:check = False
        for j in g[t[0]]:
            if not s[j]:
                s[j] = True
                q.append((j,t[0]))
            else:
                if (j != t[1]):
                    check = False
    if (check):total = total + 1
print(total)