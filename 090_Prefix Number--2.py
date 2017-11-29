x=input()
ans=0
for i in range(1,len(x)):
	l=x[0:i]
	r=x[i:i+i]
	# print(l,r)
	if l[0]=='0' or r[0]=='0':
		continue;
	if l==r:
		ans+=1
print(ans)