from tempfile import tempdir


class Solution:
    def generateParenthesis(self, n:int):
        if n == 1:
            return list({'()'})
        res = set()
        for i in self.generateParenthesis(n - 1):
            for j in range(len(i) + 2):
                res.add(i[0:j] + '()' + i[j:])
        return list(res)


def main():
    n = int(input())
    res = Solution().generateParenthesis(n)
    print(res)


if __name__ == "__main__":
    main()