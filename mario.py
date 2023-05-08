# While loop
while True:
    # Variable 'height' gets the value that the user enters in front of the 'Height: ' displayed message.
    height = input("Height: ")
    # Only if 'height' is a positive integer between 1 and 8, 'break'.
    if height.isdigit() and 1 <= int(height) <= 8:
        height = int(height)
        break
    else:
        print("Please enter a positive integer between 1 and 8.")

# For loop
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)