class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        # m,n; (m+n)//2; i belongs to [0, m], (m+n)//2-i belongs to [(n-m)//2, (m+n)//2]
        # n must >= m
        if nums1 == None:
            m = 0
        else:
            m = len(nums1)       
        if nums2 == None:
            n = 0 
        else:
            n = len(nums2)
        if m > n:
            nums1, nums2 = nums2, nums1
            m, n = n, m 
        # we cann't assume i or j must or must not include in left part
        # maybe total nums1 belongs to left, or total nums2 belongs to right
        # so, i j must be interval
        ilo, ihigh = 0, m
        while ilo <= ihigh:
            i = (ilo + ihigh) // 2
            j = (m+n)//2 -i
            # i == m, no problem, i will be smaller.
            # i == 0, i must be bigger
            if j != n and i != 0 and nums1[i-1] > nums2[j]:
                ihigh = i-1 
            elif i != m and j != 0 and nums2[j-1] > nums1[i]:
                ilo = i+1
            else:
                break 
        if i == m:
            right = nums2[j]
        elif j == n:
            right = nums1[i]
        else:
            right = min(nums1[i], nums2[j]) 
        if (m+n) % 2 == 0:
            if i == 0:
                left = nums2[j-1]
            elif j == 0:
                left = nums1[i-1]
            else:
                left = max(nums1[i-1], nums2[j-1])
            return (left + right) / 2
        else:
            return right 