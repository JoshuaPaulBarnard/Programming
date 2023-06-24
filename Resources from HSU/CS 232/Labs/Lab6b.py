
def spam_it(func):
    def spam_func(*args, **kwargs):
        a = str(func(*args, **kwargs)) + " "
        return a + a + a + a + a
    return spam_func

