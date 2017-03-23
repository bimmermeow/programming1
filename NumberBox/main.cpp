#include "NumberBox.h"
#include <conio.h>
#include <stdio.h>

int main() {
	NumberBox* BoxyBoxyBox = new NumberBox(17);
	BoxyBoxyBox->add_a_number(5);
	BoxyBoxyBox->add_a_number(56);
	NumberBox* boxyzwei = BoxyBoxyBox->copy();
	boxyzwei->add_a_number(578);
	boxyzwei->add_a_number(1654);
	BoxyBoxyBox->show_all_numbers_in_box();
	boxyzwei->show_all_numbers_in_box();
	BoxyBoxyBox->get_min_max();
	boxyzwei->get_min_max();
	printf("\nDer Durchschnitt ist %f.", BoxyBoxyBox->get_arithmetic_mean());
	printf("\nDer Durchschnitt ist %f.", boxyzwei->get_arithmetic_mean());
	_getch();
}