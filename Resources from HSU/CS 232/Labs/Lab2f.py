#------------------------- My Method --------------------------

def split_it(input_val):
    split_val = input_val.split()
    for i in range (0, len(split_val)):
        print(split_val[i])



def yell_it(input_value):
    if type(input_value) == str:
        return input_value + "!!"
    elif type(input_value) == float:
        return str(round(input_value, 3)) + "!!"
    else:
        return str(input_value) + "!!"
