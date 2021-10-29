package Leetcode

import "sort"

func threeSum(nums []int) [][]int {
	var lenth int = len(nums)
	ans := make([][]int, 0)
	sort.Ints(nums)
	for first := 0; first < lenth; first++ {
		if first > 0 && nums[first] == nums[first-1] {
			continue
		}
		third := lenth - 1
		target := -1 * nums[first]
		for second := first + 1; second < lenth; second++ {
			if second > first+1 && nums[second] == nums[second-1] {
				continue
			}
			for second < third && nums[second]+nums[third] > target {
				third--
			}
			if second == third {
				break
			}
			if nums[second]+nums[third] == target {
				ans = append(ans, []int{nums[first], nums[second], nums[third]})
			}
		}
	}
	return ans
}
