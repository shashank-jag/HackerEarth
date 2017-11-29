inf=1<<60
for _ in range(0,int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	a=[inf]+a+[inf]
	p=[i-1 for i in range(n+2)]
	q=[i+1 for i in range(n+2)]    
	v = [(x, i) for i, x in enumerate(a)]	
	f=[False]*(n+2)
	ans=0
	rest=n
	for x,i in sorted(v):
		while(f[p[i]]):
			p[i]=p[p[i]]
		while(f[q[i]]):
			q[i]=q[q[i]]
		ans+=min(a[p[i]],a[q[i]])
		f[i]=True
		rest-=1
		if(rest<2):
			break
	print(ans)