#include <iostream>
using namespace std;

int main(){
	int differ = 8;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < a; b++)
			cout << " ";
		for (int i = 0; i < a + differ; i++)
			cout << "#";
		cout << "\n";
		differ -= 3;
	}
	
	return 0;
}

/*
Using only single character output statements that output a hash mark, space, or end of line, 
write a program that produces the following shape: 

########
 ######
  ####
   ##

*/