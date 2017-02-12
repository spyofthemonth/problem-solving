#include <iostream>
using namespace std;

int main(){
	int differ = 1;
	int spaceDiffer = 2;
	for (int i = 1; i < 9; i++)
	{
		for (int a = 0; a < i + spaceDiffer; a++)
			cout << " ";
		for (int b = 0; b < i + differ; b++)
			cout << "#";
		cout << "\n";
		if (i == 4)
		{
			differ--;
			spaceDiffer--;
		}else if (i > 4)
		{
			differ -= 3;
		}else{
			differ++;
			spaceDiffer -= 2;
		}
	}
	return 0;
}

/*
Using only single character output statements that output a hash mark, space, or end of line, 
write a program that produces the following shape: 

   ##
  ####
 ######
########
########
 ######
  ####
   ##

*/