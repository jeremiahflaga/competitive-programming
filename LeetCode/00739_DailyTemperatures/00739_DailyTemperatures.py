# Note: this implementation results to "Time Limit Exceeded" when using input2.txt
# Hint and Discussion on LeetCode (https://leetcode.com/problems/daily-temperatures/description/) says "use monotonic stack"

from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = []
        temparaturesLength = len(temperatures)
        for i in range(temparaturesLength):
            todaysTemperature = temperatures[i]
            daysToWait = 0
            hasTemperatureGreaterThanTodays = False
            for j in range(i+1, temparaturesLength):
                daysToWait += 1
                if (temperatures[j] > todaysTemperature):
                    hasTemperatureGreaterThanTodays = True
                    break
            if hasTemperatureGreaterThanTodays:
                answer.append(daysToWait)
            else:
                answer.append(0)

        return answer
                
                
                
                
while True:
  try:
    line = [int(i) for i in input().strip('][').split(',')]
  except EOFError:
    break

  solution = Solution()
  print(solution.dailyTemperatures(line))

                
                