def Solution(num1:str, num2:str):
    real1, imag1 = map(int, num1[:-1].split("+"))
    real2, imag2 = map(int, num2[:-1].split("+"))
    return str(real1 * real2 - imag1 * imag2) + "+" + str(real1 * imag2 + real2 * imag1) + "i"

def main():
    res = Solution("1+1i","1+1i")
    print(res)

if __name__ == "__main__":
    main()