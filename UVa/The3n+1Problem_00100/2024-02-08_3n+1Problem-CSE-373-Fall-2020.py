# This is for "extra credit programming challenges week 1: 110101 3n+1 (100)" of CSE 373 - Analysis of Algorithms - Fall 2020
# https://www3.cs.stonybrook.edu/~skiena/373/
# Professor Steven S. Skiena

# use memoization, else you will get time limit error
cycle_lengths = {}


def computeCycleLength(x):
  if x in cycle_lengths:
    return cycle_lengths[x]
  
  if x <= 1:
    return 1
  
  if x % 2 == 1:
    n = (3*x)+1
  else:
    n = x//2

  cycle_lengths[x] = computeCycleLength(n) + 1
  return cycle_lengths[x]

while True:
  try:
    i, j = [int(i) for i in input().split()]
  except EOFError:
    break
    
  if i > j:
    big = i
    small = j
  else:
    big = j
    small = i
    
  max_cycle_length = 0
  for x in range(small, big+1):
    current_cycle_length = computeCycleLength(x)
    if current_cycle_length > max_cycle_length:
      max_cycle_length = current_cycle_length
      
  print("{} {} {}".format(i, j, max_cycle_length))


# lesson learned: thoroughly check the output
