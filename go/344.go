package Leetcode

func reverseString(s []byte) {
	lenth := len(s)
	n := lenth - 1
	for i := 0; i <= n; i++ {
		s[i], s[n] = s[n], s[i]
		n--
	}
}
