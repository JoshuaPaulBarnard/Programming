# Given two strings A and B, return whether or not A can be shifted some number of times to get B.
# This function first checks if the lengths of the strings A and B are equal. If they are not, it immediately returns False, because it is not possible to shift A to get B if they have different lengths.
# If the lengths are equal, it concatenates the string A with itself and checks if B is a substring of the concatenated string. If it is, it returns True, otherwise it returns False.
# For example, if A is "abc" and B is "bca", the concatenated string "abcabc" contains "bca", so it returns True. If A is "abc" and B is "bad", the concatenated string "abcabc" does not contain "bad", so it returns False.


def can_be_shifted(original_string, target_string):
    """
    This function takes two strings, the original string and the target string, as inputs.
    It returns True if the original string can be shifted some number of times to get the target string, otherwise it returns False.
    """

    # Check if the lengths of the original string and the target string are equal
    if len(original_string) != len(target_string):
        return False  # If they are not, it is not possible to shift the original string to get the target string

    # Concatenate the original string with itself, this is to cover all possible shifts of the original string
    concatenated_string = original_string + original_string

    # Check if the target string is a substring of the concatenated string
    # If it is, it means the original string can be shifted some number of times to get the target string
    return target_string in concatenated_string




#print(can_be_shifted('abc', 'cab'))