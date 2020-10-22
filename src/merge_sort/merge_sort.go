package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

func merge(arr []int, left int, middle int, right int) {
	// End of first and second subarrays
	var n1 int = middle - left + 1
	var n2 int = right - middle

	// Create temp arrays
	var arr1, arr2 []int

	// Copy data to temp arrays
	for i := 0; i < n1; i++ {
		arr1 = append(arr1, arr[left+i])
	}
	for j := 0; j < n2; j++ {
		arr2 = append(arr2, arr[middle+1+j])
	}

	i := 0
	j := 0
	k := left

	// Merge solutions
	for i < n1 && j < n2 {
		if arr1[i] <= arr2[j] {
			arr[k] = arr1[i]
			i++
		} else {
			arr[k] = arr2[j]
			j++
		}
		k++
	}
	for i < n1 {
		arr[k] = arr1[i]
		i++
		k++
	}
	for j < n2 {
		arr[k] = arr2[j]
		j++
		k++
	}

}

func mergeSort(arr []int, left int, right int) {
	if left < right {
		middle := left + (right-left)/2
		mergeSort(arr, left, middle)
		mergeSort(arr, middle+1, right)
		merge(arr, left, middle, right)
	}
}

func main() {
	file, _ := os.Open(os.Args[1])

	scanner := bufio.NewScanner(file)

	var data []int
	for scanner.Scan() {
		aux, _ := strconv.Atoi(scanner.Text())
		data = append(data, aux)
	}
	start := time.Now()
	mergeSort(data, 0, len(data)-1)
	elapsed := time.Since(start)
	fmt.Println(data)
	fmt.Printf("Tiempo", elapsed)
	fmt.Println("\n")
}
