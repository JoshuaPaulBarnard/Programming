# Loop 10 times in a for loop

j = 0

for j in range (15, -24, -3):
    print("Looping with j = ", j)

sample_input = input("Enter a value: ")

print("Type of data entered is: ")
print(type(sample_input))

sample_input = int(sample_input)
print("Type of data entered is: ")
print(type(sample_input))

hex_value1 = 0x1e45
hex_value2 = 0xcd5f
print(hex_value1 + hex_value2)


sample_string = "abcdefgh"
print(sample_string)
print("Replace c with $: ")
print(sample_string.replace('c', '$'))
print("substr from position 1 to position 4")
print(sample_string[1:4])
print("special slice, every other character")
print(sample_string[::2])
