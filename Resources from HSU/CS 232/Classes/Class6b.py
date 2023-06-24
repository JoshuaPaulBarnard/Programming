
def knights(saying):
    def inner(quote):
            return "We are the knights who say: '%s'" % quote
    return inner(saying)


def knights2(saying):
    def inner2(quote):
            return "We are the knights who say: '%s'" % quote
    return inner2

