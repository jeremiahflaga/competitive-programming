# use a decreasing monotonic stack: https://www.geeksforgeeks.org/introduction-to-monotonic-stack-data-structure-and-algorithm-tutorials/

from typing import List

# class Elem:
#     def __init__(self, value, index):
#         self.value = value
#         self.index = index


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]: 

      temparaturesLength = len(temperatures)
      output = [0] * temparaturesLength
      stack = [] # stack using list

      # print("====================================")
      for i in range(0, temparaturesLength):
        currentValue = temperatures[i]

        # While stack is not empty AND top of stack is more than the current element
        while stack and temperatures[stack[-1]] < currentValue:
            # print("\twhile...")
            # print("\tstack=", *stack,  sep = ", ")
            # print("\toutput=", *output,  sep = ", ")

            # Pop the top element from the stack
            indexFromStack = stack.pop()
            difference = i - indexFromStack
            output[indexFromStack] = difference
            
            # print("\ti=", i, " ", "indexFromStack=", indexFromStack, " ", 
            #       "temperatures[indexFromStack]=", temperatures[indexFromStack], " ", 
            #       "currentValue=", currentValue,  " ", 
            #       "difference=", difference)
            # print("====================================")
  
        # print("after while...")
        # print("stack=", *stack,  sep = ", ")
        # print("output=", *output,  sep = ", ")

        # Push the current element into the stack
        stack.append(i)

        # print("====================================")

      # print("stack=", *stack,  sep = ", ")
      # print("output=", *output,  sep = ", ")

      while stack:
         indexFromStack = stack.pop()
         output[indexFromStack] = 0

      return output
                
                
while True:
  try:
    line = [int(i) for i in input().strip('][').split(',')]
  except EOFError:
    break

  solution = Solution()
  print(solution.dailyTemperatures(line))

                
                