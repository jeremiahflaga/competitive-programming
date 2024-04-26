
from typing import List

class Elem:
    def __init__(self, value, index):
        self.value = value
        self.index = index


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]: 
      temparaturesLength = len(temperatures)
      output = list(range(0, temparaturesLength))
      stack = [] # stack using list

      stack.append(Elem(temperatures[0], 0))
      for i in range(1, temparaturesLength):
        currentValue = temperatures[i]
        stackTopElem = stack.pop()
        if currentValue > stackTopElem.value:
          stack.append(Elem(currentValue, i))
          difference = i - stackTopElem.index
          # print("GT => i=", i, " ", "stackTopElem.index=", stackTopElem.index, 
          #       " ", "currentValue=", currentValue, "", "difference=", difference)
          output[stackTopElem.index] = difference
          # print("len(stack)", len(stack))
        elif currentValue == stackTopElem.value:
          # print("EQ -> i=", i, " ", "stackTopElem.index=", stackTopElem.index, " ", "currentValue=", currentValue)
          stack.append(Elem(currentValue, i))
          output[stackTopElem.index] = 0
          # print("len(stack)", len(stack))
        else:
          # print("LT -> i=", i, " ", "stackTopElem.index=", stackTopElem.index, " ", "currentValue=", currentValue)
          stack.append(stackTopElem)
          stack.append(Elem(currentValue, i))
          # print("len(stack)", len(stack))
      
      # print("len(stack)", len(stack))
      if (len(stack) > 0):
        for i in range(1, len(stack)):
          elem = stack[i]
          output[elem.index] = 0           

      output[temparaturesLength-1] = 0
      return output

                
                
while True:
  try:
    line = [int(i) for i in input().strip('][').split(',')]
  except EOFError:
    break

  solution = Solution()
  print(solution.dailyTemperatures(line))

                
                