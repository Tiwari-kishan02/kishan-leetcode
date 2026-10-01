class Solution(object):
    def searchRange(self, nums, target):
        def binary_search_left(nums, target):
            lo, hi = 0, len(nums) - 1
            while lo <= hi:
                mid = (lo + hi) // 2
                if nums[mid] < target:
                    lo = mid + 1
                else:
                    hi = mid - 1 
            return lo             

        left = binary_search_left(nums, target)        

        if left == len(nums) or nums[left] != target:
            return [-1, -1]

        right = binary_search_left(nums, target + 1) - 1

        return [left, right]