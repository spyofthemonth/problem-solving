finalString = ""

def standardSwitch(x):
	return {"0": "and", "1": "one", "2": "two", "3": "three", "4": "four", "5": "five", "6": "six", "7": "seven", "8": "eight", "9": "nine"}[x]
def tenSwitch(x):
	return {"0": "ten", "1": "eleven", "2": "twelve", "3": "thirteen", "4": "fourteen", "5": "fifteen", "6": "sixteen", "7": "seventeen", "8": "eighteen", "9": "nineteen"}[x]
def otherTensSwitch(x):
	return {"2": "twenty", "3": "thirty", "4": "fourty", "5": "fifty", "6": "sixty", "7": "seventy", "8": "eighty", "9": "ninety"}[x]

def translate(scale, number):
	global finalString
	numberLength = len(number)
	if number == "000":
		return numberLength
	if numberLength == 3:
		for count, i in enumerate(number):
			if count == 0 and i != "0":
				finalString += standardSwitch(i) + " hundred "
			elif count == 1 and i == "0":
				if number[count+1] == "0":
					break
				else:
					finalString += "and "
					finalString += standardSwitch(number[count+1]) + " "
					break
			elif i != "0":
				finalString += "and "
				if i == "1":
					finalString += tenSwitch(number[count+1]) + " "
					break
				else:
					finalString += otherTensSwitch(i)
					if number[count+1] != "0":
						finalString += "-" + standardSwitch(number[count+1]) + " "
					else:
						finalString += " "
					break
	elif numberLength == 2:
		if number[0] == "1":
			finalString += tenSwitch(number[number.index(number[0])+1]) + " "
		elif number[0] != "0":
			finalString += otherTensSwitch(number[0])
			if number[number.index(number[0])+1] != "0":
				finalString += "-" + standardSwitch(number[number.index(number[0])+1]) + " "
			else:
				finalString += " "
		else:
			finalString += standardSwitch(number[1]) + " "
	else:
		finalString += standardSwitch(number) + " "
	if scale != "hundred":
		if scale == "cents" and number == "01":
			finalString += "cent "
		else:
			finalString += scale + " "
	return numberLength

def main():
	global finalString
	moneyInput = input()
	amount = ""
	cents = moneyInput.split(".")[1]
	credit = True
	for i in moneyInput:
		if i != "-" and i != "$":
			if i == ".":
				break
			amount += i
		elif i == "-":
			credit = False
	if amount != "0":
		while True:
			if len(amount) > 9:
				amount = amount[translate("billion", amount[:-9]):]
			elif len(amount) > 6:
				amount = amount[translate("million", amount[:-6]):]
			elif len(amount) > 3:
				amount = amount[translate("thousand", amount[:-3]):]
			elif len(amount) > 0:
				amount = amount[translate("hundred", amount):]
			else:
				if finalString == "one ":
					finalString += "dollar and "
				else:
					finalString += "dollars and " 
				break
	else:
		finalString += "zero dollars and "
	if cents != "00":
		translate("cents",cents)
	else:
		finalString += "zero cents"
		if amount != "0":
			finalString += " "
	if credit and moneyInput != "$0.00":
		finalString += "in credit"
	elif moneyInput != "$0.00":	
		finalString += "in debit"

	print(finalString)

main()