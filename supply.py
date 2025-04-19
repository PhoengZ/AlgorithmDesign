from collections import deque
n,m,k = [int(e) for e in input().split()]
s = [(0,0) for  i in range(k+1)]
for i in range(k):
    a,b,c = [int(e) for e in input().split()]
    s[a] = (b,c)
store = deque()
plant = deque()
for i in range(1,k+1):
    if (s[i][0] == 0):
        plant.append(s[i][1])
        if (len(store) > 0):
            left = store.popleft()
            plant.popleft()
            print(left)
        else:
            print(0)
    else:
        store.append(s[i][1])
        if (len(plant) > 0):
            left = plant.popleft()
            store.popleft()
            print(left)
        else:
            print(0)
