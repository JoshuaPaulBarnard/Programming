
# Name:     words_in_order: string -> string
# Purpose:  Returns a given string of words into
#   alphabetical ordered and lower case string.


def words_in_order(words_input):
    words_input = words_input.lower()
    words_split = sorted(words_input.split())
    return ', '.join(words_split)
