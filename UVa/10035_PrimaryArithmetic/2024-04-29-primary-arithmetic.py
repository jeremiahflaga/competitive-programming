
while True:
  try:
    a, b = [int(i) for i in input().split()]

    if a <= 0 and b <= 0:
      break

    carry_counter = 0;
    remainder = 0
    for i in range(1, 11):
      # divisor = pow(10, i)
      digit_from_a = a % 10
      digit_from_b = b % 10

      sum = digit_from_a + digit_from_b + remainder
      # print(" a=", a, 
      #       " b=", b, 
      #       " digit_from_a=", digit_from_a, 
      #       " digit_from_b=", digit_from_b, 
      #       " remainder=", remainder, 
      #       " sum=", sum)
      if sum >= 10:
        carry_counter += 1
        remainder = 1
      else:
        remainder = 0
        
      a = a // 10
      b = b // 10
      
    if carry_counter == 0:
      print("No carry operation.")
    elif carry_counter == 1:
      print("1 carry operation.")
    else:
      print(carry_counter, "carry operations.")

  except EOFError:
    break
