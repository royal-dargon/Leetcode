class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        sum = 0
        weight = 1
        for i in range(n):
            k = -(i+1)
            sum = sum + weight * digits[k]
            weight = weight * 10
        sum = sum + 1
        result = []
        while sum != 0:
            temp = sum % 10
            sum = sum // 10
            result.insert(0, temp)
        return result

