alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
shift = int(input())
string = input()
finalString = ""

for i in string:
	if i not in alphabet:
		finalString += i
	else:
		for b in alphabet:
			if i == b:
				encrypt = alphabet.index(b) - shift
				if encrypt < 0:
					encrypt = 26 + encrypt
				finalString += alphabet[encrypt]
				shift += 1
				if shift > 25:
					shift = 1
print(finalString)