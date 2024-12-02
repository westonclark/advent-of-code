package main

import (
	"fmt"
	"os"
	"strings"
)

func partOne(lines []string) int {
	return 0
}

func partTwo(lines []string) int {
	return 0
}

func main() {
	data, err := os.ReadFile("input.txt")
	if err != nil {
		fmt.Println("Error reading input file", err)
		return
	}

	lines := strings.Split(string(data), "\n")
	for _, line := range lines {
		fmt.Println(line)
	}

	fmt.Println("Part 1 result:", partOne(lines))
	fmt.Println("Part 2 result:", partTwo(lines))
}
