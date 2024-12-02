package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

const (
	inputFile = "input.txt"
)

func partOne(lines []string) int {
	result := 0

	leftValues := []int{}
	rightValues := []int{}

	for _, line := range lines {
		columns := strings.Split(line, " ")

		leftInt, err := strconv.Atoi(columns[0])
		if err != nil {
			fmt.Println("Error converting left collum to int", err)
			return 0
		}
		rightInt, err := strconv.Atoi(columns[len(columns)-1])
		if err != nil {
			fmt.Println("Error converting right collum to int", err)
			return 0
		}

		leftValues = append(leftValues, leftInt)
		rightValues = append(rightValues, rightInt)
	}

	// calulate the difference between the two values
	sort.Ints(leftValues)
	sort.Ints(rightValues)

	for i := 0; i < len(leftValues); i++ {
		difference := 0
		if leftValues[i] > rightValues[i] {
			difference = leftValues[i] - rightValues[i]
		} else {
			difference = rightValues[i] - leftValues[i]
		}

		result += difference
	}

	return result
}

func partTwo(lines []string) int {
	type valueCount struct {
		leftCount  int
		rightCount int
	}

	similarityScore := 0
	values := map[int]valueCount{}

	for _, line := range lines {
		columns := strings.Split(line, " ")

		leftInt, err := strconv.Atoi(columns[0])
		if err != nil {
			fmt.Println("Error converting left collum to int", err)
			return 0
		}
		rightInt, err := strconv.Atoi(columns[len(columns)-1])
		if err != nil {
			fmt.Println("Error converting right collum to int", err)
			return 0
		}

		// add left values to map
		valueCounts := values[leftInt]
		valueCounts.leftCount++
		values[leftInt] = valueCounts

		// add right values to map
		valueCounts = values[rightInt]
		valueCounts.rightCount++
		values[rightInt] = valueCounts
	}

	// calulate the similarity score for each value in the map
	for value, counts := range values {
		if counts.leftCount > 0 {
			similarityScore += value * counts.rightCount
		}
	}

	return similarityScore
}

func main() {
	data, err := os.ReadFile(inputFile)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error reading input file: %v\n", err)
		os.Exit(1)
	}

	lines := strings.Split(strings.TrimSpace(string(data)), "\n")

	fmt.Printf("Part 1 result: %d\n", partOne(lines))
	fmt.Printf("Part 2 result: %d\n", partTwo(lines))
}
