#ifndef _SUDOKU_H_
#define _SUDOKU_H_

typedef int data_t;

class sudoku{
public:
	sudoku();
	~sudoku();
	void get_input();
	void print() const;
	void find_ans();
private:
	data_t arr[9][9];
	int is_given[9][9] = {0};
	data_t col[9];
	data_t row[9];
	data_t box[9];
	bool check_line(data_t* line);
	bool check_cell(int i, int j);
};


#endif
