f,w,n = [int(e) for e in input().split()]
food = [int(e) for e in input().split()]
food.sort()
idx = food[0]+w
c = 1
for i in range(1,f):
    if (food[i] <= idx+w or idx > n):continue
    idx = food[i] + w
    c+=1
print(c)