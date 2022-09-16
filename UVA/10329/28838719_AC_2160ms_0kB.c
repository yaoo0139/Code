import math
try:
	while True:
		up = 1
		down = 1
		m,n = map(int,input().split())
		for i in range (m):
			a,b = map(int,input().split())
			up *= math.comb(a,b)
		for i in range (n):
			a,b = map(int,input().split())
			down *= math.comb(a,b)
		if up%down == 0:
			ans = up//down
			if len(str(ans))>100:
				print("-1")
			else:
				print(ans)
		else:
			print("0")
		
except EOFError:
	pass