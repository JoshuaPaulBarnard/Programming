
def document_it(func):
    def new_function(*args, **kwargs):
            print('Running the function:', func.__name__)
            print('Positional arguments:', args)
            print('Keyword arguments:', kwargs)
            result = func(*args, **kwargs)
            print('Result:', result)
            return result
    return new_function


def sum_of_squares(list_of_nums):
    return sum(a * a for a in list_of_nums)


def sum_of_cubes(list_of_nums):
    return sum(a * a * a for a in list_of_nums)


annoted_sum_of_squares = document_it(sum_of_squares)
annoted_sum_of_squares((1, 2, 3, 4))

sum_of_cubes((1, 2, 3, 4))
