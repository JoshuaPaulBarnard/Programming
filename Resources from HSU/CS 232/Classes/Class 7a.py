
this_value = 10

def three():
    the_return_value = 3
    return the_return_value

def add_three():
    return this_value + 3

def add_three_2():
    this_value = 25
    return this_value + 3

def add_three_3():
    global this_value
    this_value = 30
    new_value = 245
    print(locals())
    return this_value + 3

def divide_em(num, den):
    return num / den

def divide_em2(num, den):
    try:
            return num / den
    except:
            return "That was naughty!"

my_tuples = ((0, 1, 2, 3), (10, 11, 12), (20, 21, 22, 23))

def list_at_index(the_tuples, the_index):
    try:
            return [the_tuples[i][the_index]  \
                    for i in range(0, len(the_tuples))]
    except:
            return 'Index too big'

def list_lookup(the_list):
    while True:
            value = input("Enter an index value: ")
            if value == 'q':
                    break
            try:
                    position = int(value)
                    return the_list[position]
            except IndexError as err:
                    print("Bad Index!")
                    return 0
            except Exception as other:
                    print("This happened: ", other)
                    return "Nope!"



