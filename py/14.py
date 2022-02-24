def compare(a, b):
    results = ""
    temp1 = len(a)
    temp2 = len(b)
    if temp1 <= temp2:
        lenth = temp1
    else:
        lenth = temp2
    print(lenth)
    for i in range(lenth):
        if a[i] != b[i]:
            return results
        results += a[i]
    return results

def MaxPrefix(strs:list[str]):
    n = len(strs)
    result = strs[0]
    for i in range(n):
        if result == "":
            return result
        result = compare(result, strs[i])
    return result

def main():
    strs = ["flower","flight", "flow"]
    res = MaxPrefix(strs)
    print(res, end="")

if __name__ == "__main__":
    main()