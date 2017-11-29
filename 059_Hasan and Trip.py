import math

def dist(l1,l2):
	return math.sqrt((l1[0]-l2[0])*(l1[0]-l2[0])+(l1[1]-l2[1])*(l1[1]-l2[1]))

n=int(input())
v = []
for i in range (n) :
    v.append(list(map(int,input().split())))

ans= [ 0 for i in range(n)]
ans[0]=0
for i in range(1,n):
	ans[i]=v[0][2] - dist(v[i],v[0])

ans[-1] = ans[0] + v[0][2] - dist(v[0],v[-1])

for i in range(n):
	for j in range(i+1,n):
		ans[j] = max(ans[j], ans[i] + v[i][2] - dist(v[i],v[j]))
ans[-1] += v[-1][-1]
print(round(ans[-1],6))