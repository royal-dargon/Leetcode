func sortedSquares(nums []int) []int {
    var flag int = -1
    for i := 0;i < len(nums) && nums[i] < 0;i ++ {
        flag = i
    }
    ans := make([]int,0,len(nums))
    for i, j := flag,flag+1; i >= 0 || j < len(nums); {
        if i < 0 {
            ans = append(ans,nums[j] * nums[j])
            j ++
        } else if j == len(nums) {
            ans = append(ans,nums[i] * nums[i])
            i --
        } else if nums[i]*nums[i] < nums[j]*nums[j] {
            ans = append(ans,nums[i] * nums[i])
            i --
        } else {
            ans = append(ans,nums[j] * nums[j])
            j ++
        }
    } 
    return ans
}