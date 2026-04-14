class Solution(object):
    def minimumTotalDistance(self, robot, factory):
        robot.sort()
        factory.sort()
        
        n = len(robot)
        m = len(factory)
        
        # dp[i] = min cost to fix first i robots
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        
        for pos, limit in factory:
            new_dp = dp[:]
            
            for i in range(1, n + 1):
                cost = 0
                
                # try assigning k robots to this factory
                for k in range(1, min(limit, i) + 1):
                    cost += abs(robot[i - k] - pos)
                    new_dp[i] = min(new_dp[i], dp[i - k] + cost)
            
            dp = new_dp
        
        return dp[n]
