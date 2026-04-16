import bisect

class Solution(object):
    def solveQueries(self, nums, queries):
        n = len(nums)
        
        pos = {}
        for i, num in enumerate(nums):
            pos.setdefault(num, []).append(i)
        
        res = []
        
        for q in queries:
            indices = pos[nums[q]]
            
            if len(indices) == 1:
                res.append(-1)
                continue
            
            idx = bisect.bisect_left(indices, q)
            
            # neighbors in circular list
            left = indices[idx - 1] if idx > 0 else indices[-1]
            right = indices[idx + 1] if idx < len(indices) - 1 else indices[0]
            
            # compute distances
            d1 = min(abs(q - left), n - abs(q - left))
            d2 = min(abs(q - right), n - abs(q - right))
            
            res.append(min(d1, d2))
        
        return res
