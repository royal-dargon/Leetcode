package main

import "fmt"

func main() {
	var str string = "cbbd"
	s := solution3(str)
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

// 方法二 中心扩散法
// 枚举所有可能的回文子串的中心位置
// 中心位置可能是一个字符，也有可能是两个相邻的字符
func solution2(s string) string {
	return s
}

// 方法三 动态规划
// 一个回文去掉两头以后剩下的部分依然是回文
func solution3(s string) string {
	lenth := len(s)
	if lenth < 2 {
		return s
	}
	var maxLen int = 1
	var begin int = 0
	var dp [100][100]bool
	for i := 0; i < lenth; i++ {
		dp[i][i] = true
	}
	// 枚举出子串的长度
	for i := 2; i <= lenth; i++ {
		// 现在开始枚举左边界
		for j := 0; j < lenth; j++ {
			// 此时可以通过左边界和长度可以确定右边界
			right := i + j - 1
			// 这里是判断越界
			if right >= lenth {
				break
			}

			if s[j] != s[right] {
				dp[j][right] = false
			} else {
				if right-j < 3 {
					dp[j][right] = true
				} else {
					dp[j][right] = dp[j+1][right-1]
				}
			}
			if dp[j][right] && right-j+1 > maxLen {
				maxLen = right - j + 1
				begin = j
			}
		}
	}
	var str string = s[begin : begin+maxLen]
	return str
}
