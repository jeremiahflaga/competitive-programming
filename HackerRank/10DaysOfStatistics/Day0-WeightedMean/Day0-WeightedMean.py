#f = open('input1.txt', 'r')
f = open('input2.txt', 'r')

num_of_elements = int(f.readline())
elements = list(map(int, f.readline().split()))
weights = list(map(int, f.readline().split()))


sum_of_elems_times_weight = 0
sum_of_weights = 0
for i in range(num_of_elements):
    sum_of_elems_times_weight += elements[i] * weights[i]
    #print(sum_of_elems_times_weight)
    sum_of_weights += weights[i]
    #print(sum_of_weights)
    
weighted_mean = sum_of_elems_times_weight / sum_of_weights
print(round(weighted_mean, 1))