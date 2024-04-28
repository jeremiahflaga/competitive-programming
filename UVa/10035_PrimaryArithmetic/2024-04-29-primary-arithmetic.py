
while True:
  try:
    a, b = [int(i) for i in input().split()]

    if a <= 0 and b <= 0:
      break

    carry_counter = 0;
    for i in range(10, -1, -1):
      divisor = pow(10, i)
      digit_from_a = a // divisor
      digit_from_b = b // divisor

      
      # print("sum=", digit_from_a + digit_from_b)
      if digit_from_a + digit_from_b >= 10:
        carry_counter += 1
      
      a = a - (divisor * digit_from_a)
      b = b - (divisor * digit_from_b)
      
    if carry_counter == 0:
      print("No carry operation.")
    elif carry_counter == 1:
      print("1 carry operation.")
    else:
      print(carry_counter, "carry operations.")

  except EOFError:
    break
