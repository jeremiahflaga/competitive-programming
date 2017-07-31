# Jboy Flaga
# July 31, 2017


# these first part of the code were taken from Day1-Qaurtiles.py
def get_median(list_of_elements):
    n_elements = len(list_of_elements)

    if n_elements <= 0:
        return 0
    
    if n_elements % 2 == 0:
        middle_item_1 = list_of_elements[(n_elements // 2) - 1]
        middle_item_2 = list_of_elements[n_elements // 2]
        median = (middle_item_1 + middle_item_2) / 2
    else:    
        median = middle_item_2 = list_of_elements[n_elements // 2]

    return float(median)


def get_lower_half_and_upper_half(elements):
    n_elements = len(elements)
    
    # As there are an odd number of data points, we do not include the median (the central value in the ordered list) in either half:
    if n_elements <= 0 or n_elements == 1:
        return []
    
    if n_elements % 2 == 0:
        index_of_middle_elem_1 = (n_elements // 2) - 1
        index_of_middle_elem_2 = n_elements // 2
        lower_half = elements[0:index_of_middle_elem_2]
        upper_half = elements[index_of_middle_elem_2:]
    else:    
        index_of_middle_elem = n_elements // 2
        lower_half = elements[0:index_of_middle_elem]
        upper_half = elements[index_of_middle_elem + 1:]

    return (lower_half, upper_half)


def get_quartiles(elements):    
    elements.sort()

    (lower_half_elements, upper_half_elements) = get_lower_half_and_upper_half(elements)

    q1 = get_median(lower_half_elements)
    q2 = get_median(elements)
    q3 = get_median(upper_half_elements)

    return (q1, q2, q3)

### Get inputs from file
f = open('input1.txt', 'r')
num_of_elements = int(f.readline())
elements = list(map(int, f.readline().split()))
frequencies = list(map(int, f.readline().split()))

### Get inputs from standard in
# num_of_elements = int(input())
# elements = list(map(int, input().split()))
# frequencies = list(map(int, input().split()))

elems_with_freqs = []
for i in range(num_of_elements):
    elem = elements[i]
    freq = frequencies[i]
    for j in range(freq):
        elems_with_freqs.append(elem)

# print(elems_with_freqs)

(q1, q2, q3) = get_quartiles(elems_with_freqs)

print(round(q3 - q1, 1))
