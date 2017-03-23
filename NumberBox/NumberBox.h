#pragma once

class NumberBox {
public:
			NumberBox(int groesse);
			~NumberBox();

	void	add_a_number(int number);
	void	show_all_numbers_in_box();
	void	get_min_max();
	float	get_arithmetic_mean();
	NumberBox* copy();
private:
	int*	numbers;
	int		anzahl_nummern;
	int		max_size;
};