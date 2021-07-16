func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var temp [10000]int
	var res float64
	var len1 int = len(nums1)
	var len2 int = len(nums2)
	for i := 0; i < len1-1; i++ {
		for j := 0; j < len1-1; j++ {
			if nums1[j] > nums1[j+1] {
				var temp1 int = nums1[j]
				nums1[j] = nums1[j+1]
				nums1[j+1] = temp1
			}
		}
	}
	for i := 0; i < len2-1; i++ {
		for j := 0; j < len2-1; j++ {
			if nums2[j] > nums2[j+1] {
				var temp2 int = nums2[j]
				nums2[j] = nums2[j+1]
				nums2[j+1] = temp2
			}
		}
	}
	var i int = 0
	var m int = 0
	var n int = 0
	for (m < len1) && (n < len2) {
		if nums1[m] < nums2[n] {
			temp[i] = nums1[m]
			i = i + 1
			m = m + 1
		} else {
			temp[i] = nums2[n]
			i = i + 1
			n = n + 1
		}
	}
	for m < len1 {
		temp[i] = nums1[m]
		i = i + 1
		m = m + 1
	}
	for n < len2 {
		temp[i] = nums2[n]
		i = i + 1
		n = n + 1
	}
	k := len1 + len2
	if k%2 == 0 {
		res = (float64(temp[k/2-1]+temp[k/2]) / 2)
	} else {
		res = float64(temp[(k-1)/2])
	}
	return res
}