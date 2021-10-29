package Leetcode

func twoSum(numbers []int, target int) []int {
	res := make([]int, 0, 2)
	letf, right := 0, len(numbers)-1
	flag := 1
	for flag == 1 {
		if numbers[letf]+numbers[right] == target {
			break
		}
		if numbers[letf]+numbers[right] < target {
			letf++
		} else {
			right--
		}
	}
	res = append(res, letf+1)
	res = append(res, right+1)
	return res
}
