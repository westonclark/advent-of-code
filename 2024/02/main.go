package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func isSafeReport(levels []int) bool {
	// Check differences
	for i := 0; i < len(levels)-1; i++ {
		if abs(levels[i+1]-levels[i]) > 3 {
			return false
		}

	}

	// Check if increasing or decreasing
	isIncreasing := true
	isDecreasing := true
	for i := 0; i < len(levels)-1; i++ {
		if levels[i] >= levels[i+1] {
			isIncreasing = false
		}
		if levels[i] <= levels[i+1] {
			isDecreasing = false
		}
	}
	return isIncreasing || isDecreasing
}

func partOne(reports []string) int {
	safeReports := 0
	for _, report := range reports {
		levels := make([]int, 0)

		for _, s := range strings.Fields(report) {
			num, _ := strconv.Atoi(s)
			levels = append(levels, num)
		}

		if isSafeReport(levels) {
			safeReports++
		}
	}
	return safeReports
}

func partTwo(reports []string) int {
	safeReports := 0
	for _, report := range reports {
		levels := make([]int, 0)

		for _, s := range strings.Fields(report) {
			num, _ := strconv.Atoi(s)
			levels = append(levels, num)
		}

		if isSafeReport(levels) {
			safeReports++
			continue
		}

		// If not safe, try removing each element one at a time
		for i := 0; i < len(levels); i++ {
			newLevels := make([]int, 0)
			newLevels = append(newLevels, levels[:i]...)
			newLevels = append(newLevels, levels[i+1:]...)

			if isSafeReport(newLevels) {
				safeReports++
				break
			}
		}
	}
	return safeReports
}

func main() {
	data, err := os.ReadFile("input.txt")
	if err != nil {
		fmt.Println("Error reading input file", err)
		return
	}

	lines := strings.Split(strings.TrimSpace(string(data)), "\n")

	fmt.Println("Part 1 result:", partOne(lines))
	fmt.Println("Part 2 result:", partTwo(lines))
}
