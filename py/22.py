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
    

    def generaterParenthesis2(self, n:int):
        if n == 0:
            return ['']
        ans = []
        for c in range(n):
            for right in self.generaterParenthesis2(c):
                for left in self.generaterParenthesis2(n-c-1):
                    ans.append('({}){}'.format(left,right))
        return ans


def main():
    n = int(input())
    res = Solution().generaterParenthesis2(n)
    print(res)


if __name__ == "__main__":
    main()