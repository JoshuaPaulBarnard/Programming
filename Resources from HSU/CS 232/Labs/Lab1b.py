# function:  fahr_to_cels:  float -> float
# purpose: expects a temperature in Fahrenheit
#          outputs the equivalent temperature in Celcius


def fahr_to_cels(fahr_temp):
    fahr_float = float(fahr_temp)
    return (fahr_float - 32.0) * (5.0 / 9.0)

print( fahr_to_cels(50) )




