
my_tuple = (( 0, 1, 2, 3, 4, 5, 6, 7, 8),
            (10, 11, 12, 13, 14, 15),
            (20, 21, 22, 23), (30, 31, 32, 33, 34, 35, 36, 37),
            (40, 41, 42, 43, 44, 45))
print(list(i for i in my_tuple))
print(list(len(i) for i in my_tuple))
print(min(list(len(i) for i in my_tuple)))
print(min(len(i) for i in my_tuple))
def list_at_index(the_tuples, the_index):
    if the_index >= min(len(i) for i in my_tuple):
        return 'Index out of range'
    else:
        return [the_tuples[i][the_index]  \
                for i in range(0, len(the_tuples))]







