package main

import "fmt"

func main() {
	var str string = "cbbd"
	s := solution1(str)
	fmt.Println(s)
}

// 方法一 暴力解法
func solution1(s string) string {
	lenth := len(s)
	if lenth < 2 {
		return s
	}
	// 这里需要保存的是回文字符串的长度
	// 同时还保存了回文字符串的起始位置
	var maxLen int = 1
	var begin int = 0

	// 严格枚举所有长度大于1的子串
	// 下面是左边界
	for i := 0; i < lenth-1; i++ {
		for j := i + 1; j < lenth; j++ {
			if j-i+1 > maxLen && valid(s, i, j) {
				maxLen = j - i + 1
				begin = i
			}
		}
	}
	var str string = s[begin : begin+maxLen]
	return str
}

func valid(s string, i int, j int) bool {
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}
