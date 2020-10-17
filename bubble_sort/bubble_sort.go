package main

import (  
	"fmt"
	"log"
	"bufio"
    "os"
	"strconv"
	"time"
)

func bubble_sort(data []int){
	var aux int;
	for i := 0; i < len(data); i++{
		for j := 0; j < len(data) -1 -i; j++{
			if data[j] > data[j+1] { 
				aux = data[j]
				data[j] = data[j+1]
				data[j+1] = aux
			}
		}
	}
}

func main() {  
	file, _:= os.Open(os.Args[1])

	scanner := bufio.NewScanner(file)

	var data []int
	for scanner.Scan() {
		aux,_ := strconv.Atoi(scanner.Text())
		data = append(data,aux)
	}
	start := time.Now()
	bubble_sort(data)
    elapsed := time.Since(start)
	log.Printf("AAA", elapsed)
}
