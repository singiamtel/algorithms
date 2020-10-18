import time

def merge(data, l,m,r):
    m1 = m - l + 1
    m2 = r - m

    L =  [0] * (m1)
    R =  [0] * (m2)

    for i in range (0, m1):
        L[i] = data[l+i]

    for j in range (0, m2):
        R[j] = data[m+1+j]

    x = 0
    y = 0
    z = l

    while x < m1 and y < m2:
        if L[x] <= R[y]:
            data[z] = L[x]
            x += 1
        else:
            data[z] = R[y]
            y += 1
        z +=1

    while x < m1:
        data[z] = L[x]
        x += 1
        z += 1

    while y < m2:
        data[z] = R[y]
        y += 1
        z += 1


def MergeSort(data, l,r):
    if(l < r):
        m = (l+r)/2
        m = int(m)
        MergeSort(data,l,m)
        MergeSort(data,m+1,r)
        merge(data,l,m,r)

def readArray(path):
	route = []
	with open(path, 'r') as f:
		for line in f:
			route.extend(line.strip().split('>'))
	return route


if __name__ == "__main__":
	arr = readArray("input.txt")
	start = time.time()

	MergeSort(arr,0,len(arr)-1)

	end = time.time()
	print(arr)
	print("Time spent sorting: " + str(end-start))
