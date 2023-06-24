# CS232-01-jpb68.py
# Joshua P. Barnard
# Last Modified: 2/11/2016
#____________________________________________________________________


# Problem 1
# return_value:  float float float -> float
# purpose:  Expects three numeric (float) values
#           returns the multiples within the first two
# side_effects:  prints a message containing the multiples
#                within the starting and ending values


def multiples_in_range(step, start, end):
    while start % step != 0:
        start = start + 1

    for i in range(start, end, step):
        print(i)
    


#____________________________________________________________________


# Problem 2
# return_value:  float -> string
# purpose:  Expects a numeric (float) value
#           returns a string
# side_effects:  returns a single character representing the
#                grade based on the inputed float value.


def grade(score):
    if score < 60:
        return "F"
    elif score < 64:
        return "D-"
    elif score < 67:
        return "D"
    elif score < 70:
        return "D+"
    elif score < 74:
        return "C-"
    elif score < 77:
        return "C"
    elif score < 80:
        return "C+"
    elif score < 84:
        return "B-"
    elif score < 87:
        return "B"
    elif score < 90:
        return "B+"
    elif score < 94:
        return "A-"
    else:
        return "A"

#____________________________________________________________________



# Problem 3
# return_value:  [float, int, or string]  ->  [float, int, or string]
# purpose:  Expects a float, integer, or string
#           returns the a float, integer, or string respectively.
# side_effects:  Adds a 1 to integers, a 0.1 to floats, and an
#                exclamation mark to strings.                

def bump_it(val):
    if type(val) == type(5):
        val = val + 1
#        statement = 'The new value of your integer is: ' + repr(val)
#        print statement
        return val

    elif type(val) == type(5.5):
        val = val + 0.1
#        statement = 'The new value of your float is: ' + repr(val)
#        print statement
        return val

    elif type(val) == type("hehe"):
        return val + "!"

    else:
        return val

#____________________________________________________________________




# Problem 4
# return_value:  string -> string
# purpose:  Expects a string, outputs a string
# side_effects:  Takes in a first name and outputs a goofy nickname.

def nickname(name):
    name = name.capitalize()
    if len(name) >= 5:
        name = name[0:4] + "y"
        return name

    elif len(name) < 5:
        return name

    elif (len(name) >= 5) & (name[4] == "y"):
        name = name[0:4]
        return name

    else:
        s = "Sorry, the computer does not understand.  Please speak in only 0's and 1's"
        return s


#____________________________________________________________________




# Problem 5
# return_value:  float float float -> float
# purpose:  Expects three numeric (float) values
#           returns the multiples within the first two
# side_effects:  Downcases uppercase letters, and uppercases
#                lowercase letters.

def flip_it(word):
    if word.isupper() == True:
        word = word.lower()
        return word
        
    elif word.islower() == True:
        word = word.upper()
        return word

    elif word[0].isupper() == True:
        length =  len(word)  
        a = word[0].lower()
        b = word[1:length]
        word = a + b
        return word

    elif word[0].islower() == True:
        length =  len(word)
        a = word[0].upper()
        b = word[1:length]
        word = a + b
        return word

    else:
        s = "Sorry, the computer does not understand.  Please speak in only 0's and 1's"
        return s

    
