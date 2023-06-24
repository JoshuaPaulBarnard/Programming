#--------------  My Method ----------------------------

def yell_it(input_value):
    if type(input_value) == str:
        return input_value + "!!"
    elif type(input_value) == float:
        return str(round(input_value, 3)) + "!!"
    else:
        return str(input_value) + "!!"




#---------------- Teachers Method ----------------------

def yell_it2(input_val):
    if type(input_val) == str:
        return input_val + "!!"
    elif type(input_val) == float:
        return "%.3f" % input_val + "!!"
    else:
        return str(input_val) + "!!"


