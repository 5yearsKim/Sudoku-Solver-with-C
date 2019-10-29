#include <iostream>
#include "sudoku.h"


using namespace std;

int main(){
	sudoku sdk;

	sdk.get_input();
	sdk.print();
	sdk.find_ans();
	sdk.print();


	return 0;	
}



