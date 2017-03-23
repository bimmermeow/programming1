#pragma once
#include "NumberBox.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>


NumberBox::NumberBox(int groesse) {
	max_size = groesse;
	numbers = new int[groesse];
	int anzahl_nummern = 0;
}
NumberBox::~NumberBox() {
	delete numbers;
}
void NumberBox::add_a_number(int number) {
	numbers[anzahl_nummern] = number;
	anzahl_nummern++;
	printf("\n%d wurde als %d. Zahl hinzugefuegt.", number, anzahl_nummern);
}
void NumberBox::show_all_numbers_in_box() {
	for (int i = 0; i < anzahl_nummern; i++) {
		printf("\n%d", numbers[i]);
	}
}
void NumberBox::get_min_max() {
	int* temp = new int[max_size];
	memcpy(temp, numbers, anzahl_nummern*sizeof(int));
	for (int n = anzahl_nummern; n>1; n--) {
		for (int i = 0; i<n - 1; i++){
			if (temp[i] > temp[i + 1]){
				float stor = temp[i + 1];
				temp[i + 1] = temp[i];
				temp[i] = stor;
			} // ende if
		} // ende innere for-Schleife
	}
	printf("\nDie kleinste gespeicherte Zahl ist %d, die Groesste %d.", temp[0], temp[anzahl_nummern - 1]);
	delete temp;
}
float NumberBox::get_arithmetic_mean() {
	int summe = 0;
	for (int i = 0; i < anzahl_nummern; i++) {
		summe = numbers[i] + summe;
	}
	float durchschnitt = (float) summe / anzahl_nummern;
	return durchschnitt;
}

NumberBox* NumberBox::copy() {
	NumberBox* kopie = new NumberBox(max_size);
	for (int i = 0; i < anzahl_nummern; i++) {
		kopie->add_a_number(numbers[i]);
	}
	return kopie;
}