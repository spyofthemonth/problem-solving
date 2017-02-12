class Coordinate:
	def __init__(self, x, y):
		self.x = x
		self.y = y

def floatRange(begin, end):
	while begin < end:
		yield begin
		begin += 1

def isCentered(yIntercept, x):
	if (yIntercept % 1) == 0.5:
		outsideCoordinates.append(Coordinate(x, yIntercept))
		return 1
	return 0

inputArray = []
outsideCoordinates = []

while True:
	verticesInput = input()
	if verticesInput == "0 0 0 0 0 0":
		break;
	verticesInput = verticesInput.split()			#1 4 7 2 5 8
	inputArray.append(verticesInput)				# -2 / 	6
													# 
for i in inputArray:
	numSquares = 0
	gradientAB = (int(i[3]) - int(i[1])) / (int(i[2]) - int(i[0]))
	print(gradientAB)
	for b in floatRange(int(i[0]) + 0.5, int(i[2]) + 0.5):
		numSquares += isCentered(gradientAB * b + int(i[1]), b)

	gradientBC = (int(i[5]) - int(i[3])) / (int(i[2]) - int(i[4]))
	print(gradientBC)
	for c in floatRange(int(i[4]) + 0.5, int(i[2]) + 0.5):
		numSquares += isCentered(gradientBC * c + int(i[5]), c)

	gradientCA = (int(i[1]) - int(i[5])) / (int(i[4]) - int(i[0]))
	print(gradientCA)
	for d in floatRange(int(i[0]) + 0.5, int(i[4]) + 0.5):
		numSquares += isCentered(gradientCA * d + int(i[1]), d)

print(numSquares)

for coord in outsideCoordinates:
	print(str(coord.x) + " , " + str(coord.y))
	for comparCoord in outsideCoordinates:
		if (coord.x + 1) == comparCoord.x and outsideCoordinates.index(coord) != outsideCoordinates.index(comparCoord):
			#print(str(coord.x + 1))
			numSquares += 1
print(numSquares)
