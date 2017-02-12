numLines = int(input())
array = []

for i in range(numLines):
	line = input()
	holes = 0
	for b in line:
		if b == "A" or b == "O" or b == "D" or b == "D" or b == "P" or b == "Q" or b == "R":
			holes += 1
		elif b == "B":
			holes += 2
	array.append(holes)

for c in array:
	print(c)
