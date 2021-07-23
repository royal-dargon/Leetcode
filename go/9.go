func isPalindrome1(x int) bool {
	var slice [64]int
	if x < 0 {
		return false
	}
	count := 0
	for i := 0; x != 0; i++ {
		temp := x % 10
		slice[i] = temp
		x = x / 10
		count++
	}
	lenth := count
	temp := lenth - 1
	for i := 0; i < lenth/2; i++ {
		if slice[i] != slice[temp] {
			return false
		}
		temp = temp - 1
	}
	return true
}

func isPalindrome(x int) bool {
	if x < 0 || (x != 0 && x%10 == 0) {
		return false
	}
	var temp int = 0
	for x > temp {
		temp = temp*10 + x%10
		x = x / 10
	}
	return x == temp/10 || x == temp
}