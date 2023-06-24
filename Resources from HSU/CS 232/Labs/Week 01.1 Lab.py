# CS 232 Spring 2016
# Week 01 Lab Exercise

# An example of a function that takes one argument
# and returns one value

def fahr_to_cels(fahr_temp):
	fahr_temp = float(fahr_temp)  # Convert to float
	return (fahr_temp - 32.0) * 5.0 / 9.0

# After defining the function above, we can run it in the
# interactive window, or write code like below to run it
	
x = float(input('Enter a Farenheit temperature: '))

# A print statement with a specific format
# (we'll go over this in more detail in future weeks)

print('The celsius temp is',"%.2f" % fahr_to_cels(x))


