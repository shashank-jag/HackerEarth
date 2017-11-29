import math

def f(ind, sum, m, n,dp):
	if ind==m-1 and sum>0 and sum<=n:
		return 1
	elif ind==m-1:
		return 0
	if dp[ind][sum]!=-1:
		return dp[ind][sum]
	ret = 0
	for i in range(1,sum+1):
		ret += f(ind+1,sum-i,m,n,dp)
	dp[ind][sum]=ret
	return (ret)

t=int(input())
for i in range(0,t):
	dp = [ [-1 for i in range(0,2505)] for i in range(0,1010)]
	m,n,k = map(int,input().split())
	total = math.pow(n,m)
	comb = f(0,k,n,m,dp)
	i=0
	print(comb,total,comb/total)
	while comb > 0 and comb<total:
		i+=1
		comb*=10
	print("%.3f %d" %((comb/total),i))