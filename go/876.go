/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func middleNode(head *ListNode) *ListNode {
    p := head
    count := 0
    for p != nil {
        count ++
        p = p.Next
    }
    //fmt.Println(count)
    count = count/2
    p = head
    for count > 0 {
        p = p.Next
        count --
    }
    return p
}