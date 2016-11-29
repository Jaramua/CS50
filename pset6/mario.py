def triangle():
    while True:
        # checking the correctness of input
        height = int(input("Height: "))
        if 0 < height < 23:
            # drawing pyramid
            for r in range(1, height+1):
                for s in range(height - r, 0, -1):
                    print(" ", sep=' ', end='')
                for h in range(1, r + 2):
                    print("#", sep=' ', end='')
                print()
            break
triangle()
