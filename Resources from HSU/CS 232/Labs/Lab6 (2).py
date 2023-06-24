
def string_it(num):
    return str(num)

def spam_it(func):
    def spam_func(*args, **kwargs):
        a = str(func(*args, **kwargs))
        return str(func(*args, **kwargs)) + " " + str(func(*args, **kwargs)) + " " + str(func(*args, **kwargs)) + " " + func(num) + " " + func(num)
    return spam_func



my_test = spam_it(string_it)

print(my_test(5))
print(my_test(-7.0))
print(my_test(False))
print(my_test("hi"))
