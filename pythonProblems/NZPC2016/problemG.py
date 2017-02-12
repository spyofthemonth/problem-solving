import statistics

inputArray = []

while True:
	locationInput = int(input())
	if locationInput == 0:
		break;
	inputArray.append(locationInput)

for i in inputArray:
	stringOutput = ""		
	left = 1
	right = 50
	while True:
		middle = statistics.median(range(left, right+1))
		middle = int(middle)

		if middle < i:
			stringOutput += (str(middle) + " ")
			left = middle + 1 
		elif middle > i:
			stringOutput += (str(middle) + " ")
			right = middle - 1
		elif middle == i:
			stringOutput += str(middle)
			print(stringOutput)
			break;
