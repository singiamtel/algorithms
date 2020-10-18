import time


def readArray(path):
	route = []
	with open(path, 'r') as f:
		for line in f:
			route.extend(line.strip().split('>'))
	return route


if __name__ == "__main__":
	arr = readArray("input.txt")
	start = time.time()

	# Sort here

	end = time.time()
	print(arr)
	print("Time spent sorting: " + str(end-start))
