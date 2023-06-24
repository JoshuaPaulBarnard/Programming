my_tuple = ((0,  1,  2,  3,  4,  5,  6,  7,  8),
            (10, 11, 12, 13, 14, 15),
            (20, 21, 22, 23),
            (30, 31, 32, 33, 34, 35, 36, 37),
            (40, 41, 42, 43, 44, 45))

def list_at_index(my_tuple, index):
    a = []
    length = len(my_tuple) - 1
    tuple2 = []
    for i in range(0, length):
        a.append(len(my_tuple[i]))
    if index >= min(a) :
        return "Index too large"
    else:
        for i in range(0, length):
            tuple2.append(my_tuple[i][index])
    return(tuple2)


