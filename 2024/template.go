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
		fmt.Fprintf(os.Stderr, "Error reading input file: %v\n", err)
		os.Exit(1)
	}

	lines := strings.Split(strings.TrimSpace(string(data)), "\n")

	fmt.Printf("Part 1 result: %d\n", partOne(lines))
	fmt.Printf("Part 2 result: %d\n", partTwo(lines))
}
