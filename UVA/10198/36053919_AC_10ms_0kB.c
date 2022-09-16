try:
	arr = [0 for _ in range(1005)]
	arr[1] = 2
	arr[2] = 5
	arr[3] = 13
	for i in range(4, 1001):
		arr[i] = arr[i-1] * 2 + arr[i-2] + arr[i-3]
	while(1):
		n = int(input())
		print(arr[n])
except EOFError:
	pass