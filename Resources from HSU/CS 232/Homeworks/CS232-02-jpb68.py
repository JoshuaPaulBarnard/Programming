# CS232-02-jpb68.py
# Joshua P. Barnard
# Last Modified: 2/23/2016
#____________________________________________________________________


# Problem 1
# return_value:  string  -> string
# purpose:       Expects a string
#                 Returns a string
# side_effects:  Prints a message converting the string into a
#                 pig-latin form of that string.

def pig_latin(word):
        lst = ['sh', 'gl', 'ch', 'ph', 'tr', 'br', 'fr', 'bl', 'gr', 'st', 'sl', 'cl', 'pl', 'fl']
        word = word.split()
        for k in range(len(word)):
                i = word[k]
                if i[0] in ['a', 'e', 'i', 'o', 'u']:
                        word[k] = i+'-ay'
                elif t(i) in lst:
                        word[k] = i[2:] + '-' + i[:2]+'ay'
                elif i.isalpha() == False:
                        word[k] = i
                else:
                        word[k] = i[1:]+ '-' + i[0]+'ay'
        return ' '.join(word)

def t(str):
        return str[0]+str[1]

if __name__ == "__word__":
        x = word()
        print(x)


    


#____________________________________________________________________


# Problem 2
# return_value:  string ->  string
# purpose:       Expects a list of strings
#                 Returns a list of strings
# side_effects:  Prints a message converting a list of strings 
#                 into their pig-latin form.

def pig_list(sentance):
    for i, item in enumerate(sentance):
        sentance[i] = pig_latin(item)
    print(sentance)


#____________________________________________________________________



# Problem 3
# return_value:  integer  ->  integer
# purpose:       Expects a integer
#                 Returns a list of integers
# side_effects:  Prints a list of integers from the Fibonacci Sequence
#                 of the length specificied by the input value.

def fib_create(realnum):
    fibonacci_numbers = [0, 1]
    for i in range(2,8*realnum):
        fibonacci_numbers.append(fibonacci_numbers[i-1]+fibonacci_numbers[i-2])
    fib_list = sorted(fibonacci_numbers)
    for i in range(0, max(fib_list)):
        new_list = list(filter(lambda i: len(str(i)) == realnum, fib_list))
    print(new_list)


#____________________________________________________________________




# Problem 4
# return_value:  string -> dictionary
# purpose:       Expects a string
#                 Returns a dictionary
# side_effects:  Converts a string into a dictionary containing the
#                 count for each lowercase character in the string.

def letter_freq(word):
    word = word.lower()
    letterfreq={}
    for letter in word:
        letterfreq[letter] = 0
    for letter in word:
        letterfreq[letter] += 1
    return letterfreq


#____________________________________________________________________




# Problem 5
# return_value:  dictionary -> chart
# purpose:       Expects a Dictionary
#                 Returns a bar chart
# side_effects:  Takings in a dictionary, organizes it, and 
#                 produces a bar chart.

def freq_bar_cart(D2):
    D2 = dict(sorted(D2.iteritems()))



#____________________________________________________________________




# Problem 6
# return_value:  dictionary -> chart
# purpose:       Expects a Dictionary
#                 Returns a coordinate graph
# side_effects:  Takes in a dictionary and returns a 
#                 coordinate map of the data.
    
