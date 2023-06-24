
def sum_it(*args):
    return sum(args)

def spam_it(func):
    def spam_func(*args, **kwargs):
        a = str(func(*args, **kwargs)) + " "
        return a + a + a + a + a
    return spam_func



my_test = spam_it(sum_it)

print(my_test(5))
print(my_test(-7.0))
print(my_test(False))


print(my_test(1, 2, 3))


print(my_test("hi"))
