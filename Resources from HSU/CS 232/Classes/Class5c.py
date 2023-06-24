[number for number in range (0, 10)]

{number: number + 3 for number in range(0, 10)  \
if number % 2 == 1}

max_val = 1000

[x for x in range(2, max_val) if max_val % x == 0]

[prime for prime in range (2, max_val) if \
 len([x for x in range(2, prime) if prime % x == 0]) == 0]
