import time

def partition(data, low, high):
	i = (low - 1)
	pivot = data[high]

	for j in range(low,high):
		if data[j] <= pivot:
			i = i+1
			data[i], data[j] = data[j], data[i] # swap values
	data[i+1], data[high] = data[high], data[i+1]
	return (i+1)

def quickSort(data, low, high):
	if len(data) == 1: #Base case
		return data
	if low < high:
		pivot = partition(data,low,high)

		quickSort(data,low, pivot -1)
		quickSort(data,pivot + 1, high)

def readArray(path):
	route = []
	with open(path, 'r') as f:
		for line in f:
			route.extend(line.strip().split('>'))
	return route


if __name__ == "__main__":
	arr = readArray("input.txt")
	arr = [int(i) for i in arr]
	start = time.time()

	# Sort here
	quickSort(arr,0,len(arr)-1)

	end = time.time()
	print(arr)

	print("Time spent sorting: " + str(end-start))
