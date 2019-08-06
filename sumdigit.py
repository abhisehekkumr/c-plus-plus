t = int(input(''))

while(t>0):
	t = t-1;
	flag = False
	number = int(input(''))
	nn = number
	sum = 0
	if(number<0):
		flag = True
		number = number*(-1)

	while (number>0):
		sum = sum + number%10
		number = number//10

	if(flag):
		print("the sum of the digits %d are %d:" % (nn,int(-1*sum)))
	else:
		print("sum of the digits %d are %d :" % (nn,int(sum)))