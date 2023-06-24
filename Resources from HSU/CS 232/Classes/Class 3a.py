# string_it:  List -> List
# Purpose:  Expects a list of atomic objects and returns a
#       list with all objects converted to strings

def string_it(input_list):
    output_list = []
    for i in range (0, len(input_list)):
        output_list.append(str(input_list[i]))
    return output_list
    
