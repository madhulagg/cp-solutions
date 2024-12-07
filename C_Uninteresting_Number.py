def solve():
    t = int(input())  # Read the number of test cases
    for _ in range(t):
        n = input().strip()  # Read each number as a string
        digit_sum = 0
        
        # Process each digit in the number
        for digit in n:
            d = int(digit)
            if d == 0:
                digit_sum += 0
            elif d == 1:
                digit_sum += 1
            elif d == 2:
                digit_sum += 4
            elif d == 3:
                digit_sum += 9
            elif d == 4:
                digit_sum += 7
            elif d == 5:
                digit_sum += 7
            elif d == 6:
                digit_sum += 9
            elif d == 7:
                digit_sum += 9
            elif d == 8:
                digit_sum += 4
            elif d == 9:
                digit_sum += 9
        
        if digit_sum % 9 == 0:
            print("YES")
        else:
            print("NO")

