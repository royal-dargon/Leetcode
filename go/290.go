// Leetcode 290题 单词的规律 判断给定的规律和字符串是否是相同的规律
package main

import (
	"fmt"
	"strings"
)

func main() {
	p := "abba"
	str := "dog cat cat dog"
	fmt.Println(wordPattern(p, str))
}

func wordPattern(patten string, s string) bool {
	var res bool = false
	word2ch := map[string]byte{}
	ch2word := map[byte]string{}
	words := strings.Split(s, " ")
	if len(patten) != len(words) {
		return res
	}
	for i, word := range words {
		ch := patten[i]
		if (word2ch[word] > 0 && word2ch[word] != ch) || (ch2word[ch] != "" && ch2word[ch] != word) {
			return false
		}
		word2ch[word] = ch
		ch2word[ch] = word
	}
	return true
}
