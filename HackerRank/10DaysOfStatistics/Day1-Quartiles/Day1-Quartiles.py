# Jboy Flaga
# July 25, 2017

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


def get_lower_half_and_upper_half(list_of_elements):
    n_elements = len(list_of_elements)
    
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


f = open('input2.txt', 'r')

num_of_elements = int(f.readline())
elements = list(map(int, f.readline().split()))

# num_of_elements = int(input())
# elements = list(map(int, input().split()))
#print(elements)

elements.sort()

(lower_half_elements, upper_half_elements) = get_lower_half_and_upper_half(elements)

q1 = get_median(lower_half_elements)
q2 = get_median(elements)
q3 = get_median(upper_half_elements)

def print_quartile(num):
    # help from https://stackoverflow.com/questions/6681743/splitting-a-number-into-the-integer-and-decimal-parts-in-python#answer-6681778
    decimal_part = num % 1
    if decimal_part > 0.0:
        return round(num, 1);
    else:
        return int(num // 1)

print(print_quartile(q1))
print(print_quartile(q2))
print(print_quartile(q3))
