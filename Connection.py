from collections import deque
n,e,k = [int(t) for t in input().split()]
g = [[] for t in range(n)]
answer = 0
for i in range(e):
    a,b = [int(t) for t in input().split()]
    g[a].append(b)
    g[b].append(a)
for i in range(n):
    q = deque()
    s = [False]*n
    s[i] = True
    c = 1
    q.append((i,0))
    while(len(q) != 0):
        t = q[0]
        q.popleft()
        for j in g[t[0]]:
            if not s[j] and t[1] + 1 <=k:
                s[j] = True
                q.append((j,t[1]+1))
                c+=1
    answer = max(c,answer)
print(answer)
    
