gridSize = int(input())
array = [" "]

for i in range(gridSize):
	rowInput = input()
	for b in rowInput:
		if b not in array and len(array) != 27:
			array.append(b)

finalOutputString = ""
array.pop(0)
for c in array:
	finalOutputString += c
print (finalOutputString)
	