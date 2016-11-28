import sys
def main():
    key = 0
    if len(sys.argv) != 2: 
        print("oops :( \n")
        return 1
    else:
        key = int(sys.argv[1])
    s = str(input("plaintext: "))
    print("ciphertext: ", sep='', end='')
    for i in range(len(s)):
        if s[i].isalpha():
            if s[i].isupper():
                hell = (ord(s[i]) - ord('A') + key) % 26 + ord('A')
                print(chr(hell), end='')
            else:
                hell = (ord(s[i]) - ord('a') + key) % 26 + ord('a')
                print(chr(hell), end='')
        else:
            print(s[i], end='')
    print()
main()
