# Jeremiah Flaga
# July 13, 2017

dict = {}

num_of_items = int(input())
list_of_numbers = list(map(int, input().split()))

for item in list_of_numbers:
    if item in dict:
        dict[item] += 1
    else:
        dict[item] = 1

#for k in dict.keys():
#    print('{}: {}'.format(k, dict[k]))

sum = 0
item_with_max_frequency = 0
max_frequency = 0
for item,freq in dict.items():
    sum += item * freq
    if freq == max_frequency and item < item_with_max_frequency:
        item_with_max_frequency = item
    elif freq > max_frequency:
        max_frequency = freq
        item_with_max_frequency = item
    
mean = sum / num_of_items
mode = item_with_max_frequency

# computing for median
list_of_numbers.sort()
median = 0
if num_of_items % 2 == 0:
    middle_item_1 = list_of_numbers[(num_of_items // 2) - 1]
    middle_item_2 = list_of_numbers[num_of_items // 2]
    median = (middle_item_1 + middle_item_2) / 2
else:
    median = middle_item_2 = list_of_numbers[num_of_items // 2]

print(mean)
print(median)
print(mode)
