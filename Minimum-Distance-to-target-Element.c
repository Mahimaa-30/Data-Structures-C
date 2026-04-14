class Solution(object):
    def getMinDistance(self, nums, target, start):
        n = len(nums)
        
        for d in range(n):
            # check left
            if start - d >= 0 and nums[start - d] == target:
                return d
            
            # check right
            if start + d < n and nums[start + d] == target:
                return d
