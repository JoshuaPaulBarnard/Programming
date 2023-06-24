

def fib_create(realnum):
    fibonacci_numbers = [0, 1]
    for i in range(2,8*realnum):
        fibonacci_numbers.append(fibonacci_numbers[i-1]+fibonacci_numbers[i-2])
    fib_list = sorted(fibonacci_numbers)
    for i in range(0, max(fib_list)):
        new_list = list(filter(lambda i: len(str(i)) == realnum, fib_list))
    print(new_list)

    
