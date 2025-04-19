n = int(input())
s = [int(e) for e in input().split()]
end = [int(e) for e in input().split()]
ending = [(end[i],i) for i in range(n)]
ending.sort()
t = ending[0][0]
count = 1
for i in range(1,n):
    if (t > s[ending[i][1]]):continue
    t = ending[i][0]
    count+=1
print(count)