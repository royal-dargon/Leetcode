package Leetcode

func reverseWords(s string) string {
	res := []byte{}
	lenth := len(s)
	for i := 0; i < lenth; {
		start := i
		for i < lenth && s[i] != ' ' {
			i++
		}
		end := i - 1
		for end >= start {
			res = append(res, s[end])
			end--
		}
		for i < lenth && s[i] == ' ' {
			i++
			res = append(res, ' ')
		}
	}
	return string(res)
}
