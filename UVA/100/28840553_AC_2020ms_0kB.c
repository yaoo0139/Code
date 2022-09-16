arr=[0 for i in range(1000000)] 
for i in range (1,1000000):
	n = int(i)
	cycle = int(1)
	if i%2==0:
		arr[i] = arr[i//2] + 1
		continue
	while n!=1:
		if n%2==0 :
			if(i>n):
				arr[i] = arr[n//2] + cycle 
				break
			n=n//2
		else:
			n=3*n+1
		cycle += 1
	if (i>n):
		continue
	arr[i] = int(cycle)
try:
	while True:
		a,b = map(int,input().split())
		print(a,b,end=" ")
		if a>b:
			a,b = b,a
		ma = int(0)
		for i in range (a, b+1):
			if ma < arr[i]:
				ma = arr[i]
		print(ma)
	
except EOFError:
	pass