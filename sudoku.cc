#include<iostream>
#include"sudoku.h"

using namespace std;

sudoku::sudoku(){
}


sudoku::~sudoku(){
}


void sudoku::get_input(){

	for (unsigned i = 0; i <9; i++){
		for (unsigned j = 0; j<9; j++){
			arr[i][j] = -1;
		
		}
	}

	arr[0][0] = 5;
	arr[0][1] = 3;
	arr[0][4] = 7;
	arr[1][0] = 6;
	arr[1][3] = 1;
	arr[1][4] = 9;
	arr[1][5] = 5;
	arr[2][1] = 9;
	arr[2][2] = 8;
	arr[2][7] = 6;
	
	arr[3][0] = 8;
	arr[3][4] = 6;
	arr[3][8] = 3;
	arr[4][0] = 4;
	arr[4][3] = 8;
	arr[4][5] = 3;
	arr[4][8] = 1;
	arr[5][0] = 7;
	arr[5][4] = 2;
	arr[5][8] = 6;
	arr[6][1] = 6;
	arr[6][6] = 2;
	arr[6][7] = 8;
	arr[7][3] = 4;
	arr[7][4] = 1;
	arr[7][5] = 9;
	arr[7][8] = 5;
	arr[8][4] = 8;
	arr[8][7] = 7;
	arr[8][8] = 9;

	is_given[0][0] = 5;
	is_given[0][1] = 3;
	is_given[0][4] = 7;
	is_given[1][0] = 6;
	is_given[1][3] = 1;
	is_given[1][4] = 9;
	is_given[1][5] = 5;
	is_given[2][1] = 9;
	is_given[2][2] = 8;
	is_given[2][7] = 6;
	
	is_given[3][0] = 8;
	is_given[3][4] = 6;
	is_given[3][8] = 3;
	is_given[4][0] = 4;
	is_given[4][3] = 8;
	is_given[4][5] = 3;
	is_given[4][8] = 1;
	is_given[5][0] = 7;
	is_given[5][4] = 2;
	is_given[5][8] = 6;
	is_given[6][1] = 6;
	is_given[6][6] = 2;
	is_given[6][7] = 8;
	is_given[7][3] = 4;
	is_given[7][4] = 1;
	is_given[7][5] = 9;
	is_given[7][8] = 5;
	is_given[8][4] = 8;
	is_given[8][7] = 7;
	is_given[8][8] = 9;




#ifdef IMODE
	for (unsigned i = 0; i <9; i++){
		cout<<"insert "<<i+1 <<"th line"<<endl;
		for (unsigned j = 0; j<9; j++){
			cin>>arr[i][j];
		}

	}
#endif
}
void sudoku::print() const{
	for (unsigned i = 0; i<9; i++){
		cout<<endl;
		if (!(i%3)){cout<<"-------------------------------------\n";} 
		for (unsigned j = 0 ; j<9; j++){
			if (!(j%3)){cout<<"|";}
			if (arr[i][j]>0)
				printf("%2d  ", arr[i][j]);
			else
				printf("    ");
		}
	
	}

	cout<<"\n-------------------------------------\n"; 

}

bool sudoku:: check_line(data_t* line){
	data_t cnt[10] = {0};
	int num;
	for (unsigned i = 0; i<9 ; i++){
		num = line[i];
		if (1 <= num && num <= 9){
			cnt[num]++;
			if (cnt[num] >1){ return false;	}
		}
	}
	return true;
}

void sudoku::find_ans(){
	bool result = check_cell(0,0);
	if (result) 
		cout<<"success!"<<endl;
	else
		cout<<"faliled"<<endl;		
}


bool sudoku::check_cell(int i, int j){
	int index = 9*i + j;
	if (index == 81){
		return true;
	}

	if (is_given[i][j]) {return check_cell((index+1)/9, (index+1)%9);}

	for (data_t num = 1; num<= 9; num++){
		arr[i][j] = num;
		for (int x = 0; x<9; x++){
			row[x] = arr[i][x];	
			col[x] = arr[x][j];
			box[x] = arr[(i/3)*3 + x/3][(j/3)*3 + x%3];
			
		}

		if (check_line(row) && check_line(col) && check_line(box)&&check_cell((index+1)/9, (index+1)%9)){
			 return true;
		}
	}
	arr[i][j] = -1;
	return false;
}
