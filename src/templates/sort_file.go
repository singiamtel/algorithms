package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"time"
)

func resolver() {
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
	resolver()
	elapsed := time.Since(start)
	fmt.Println(data)
	log.Printf("Tiempo", elapsed)
}
