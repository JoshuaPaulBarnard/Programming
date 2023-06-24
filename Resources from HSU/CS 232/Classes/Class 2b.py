sample_string = "It don't mean a thing"
print(sample_string[0], sample_string[1], sample_string[2])
sample_string.replace('a','$')

if sample_string[3] == 'd':
    print("Found a d!")
    sample_string.replace('d','$')

sample_string = sample_string.replace('d','$')
print(sample_string)

if sample_string[1] == '@':
    print("Found @")
elif sample_string[1] == "t":
    print("Foune t")
else:
    print("No good")

