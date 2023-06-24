
def get_text(name):
    return "Hello there, " + name + "!"


def p_decorate(func):
    def func_wrapper(name):
        return "<p> " + func(name) + " </p>"
    return func_wrapper

my_get_text = p_decorate(get_text)

    
