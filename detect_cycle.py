from collections import deque
t = int(input().strip())
for i in range(t):
    v,e = [int(e) for e in input().split()]
    q = deque()
    sel = [False]*v
    g = [[] for e in range(v)]
    for j in range(e):
        a,b = [int(e) for e in input().split()]
        g[a].append(b)
        g[b].append(a)
    check = True
    for j in range(v):
        if (not check):break
        if (sel[j]):continue
        q.append((j,-1))
        sel[j] = True
        while(len(q) != 0 and check == True):
            t = q[0]
            q.popleft()
            for e in g[t[0]]:
                if (not sel[e]):
                    sel[e] = True
                    q.append((e,t[0]))
                else:
                    if (e != t[1]):
                        check = False
                        break
    if (check):print("NO")
    else:print("YES")
            
                    




    
