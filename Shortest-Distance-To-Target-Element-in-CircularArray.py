class Solution(object):
    def closestTarget(self, words, target, startIndex):
        n = len(words)
        min_dist = float('inf')
        
        for i in range(n):
            if words[i] == target:
                # circular distance
                dist = min(abs(i - startIndex), n - abs(i - startIndex))
                min_dist = min(min_dist, dist)
        
        return min_dist if min_dist != float('inf') else -1
