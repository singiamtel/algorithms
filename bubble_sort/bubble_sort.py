import time

def readArray(path):
	route = []
	with open(path, 'r') as f:
		for line in f:
			route.extend(line.strip().split('>'))
	return route


def swap(array, i, j):
	tmp = array[i]
	array[i] = array[j]
	array[j] = tmp


def bubbleSort(array):
	for i in range(len(array)-1):
		for j in range(len(array)-i-1):
			swap(array, j, j+1)
	return array


if __name__ == "__main__":
	arr = readArray("input.txt")
	start = time.time()
	arr = bubbleSort(arr)
	end = time.time()
	print(arr)
	print("Time spent sorting: " + str(end-start))