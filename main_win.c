#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h> //geht unter linux ned
#include <Windows.h> //au ned

void mysleep(int sleeptime) { // sleeptime in ms
#ifdef __linux__
	sleep(sleeptime / 1000.0);
#elif _WIN32
	Sleep(sleeptime);
#endif
}
bool I2() {
	system("cls");
	printf("Absoluten Pfad zur Datei angeben, um Zahlen zu sortieren\n");
	char path[300];
	gets_s(path, 300);
	printf("\nDatei wird geöffnet.");
	FILE *f;
	f = fopen(path, "r");
	if (f == NULL) {
		return false;
	}
	printf("\nZahlen werden gelesen.");
	char zeile[5000];
	float zahlen[1000];
	int i = 0;
	while (fgets(zeile, sizeof(zeile), f)) {
		zahlen[i] = atof(zeile);
		i++;
	}
	printf("\nZahlen werden sortiert.");
	int anzahl_zahlen = i;
	for (int n = anzahl_zahlen; n>1; n--) {
		for (int i = 0; i<n - 1; i++){
			if (zahlen[i] > zahlen[i + 1]){
				float stor = zahlen[i + 1];
				zahlen[i + 1] = zahlen[i];
				zahlen[i] = stor;
			} // ende if
		} // ende innere for-Schleife
	}
	strcat_s(path, 300, ".sorted.txt");
	fclose(f);
	printf("\nVersuche Datei %s zu erstellen", path);
	FILE *ergebnis = fopen(path, "w");
	for (int i = 0; i < anzahl_zahlen; i++)
	{
		fprintf(ergebnis, "%f\n", zahlen[i]);
	}
	fclose(ergebnis);
	printf("\nFertig.");
	return true;
}
bool I1() {
	system("cls");
	printf("Absoluten Pfad zur Datei angeben, um anzahl der zeilen anzuzeigen\n");
	char path[300];
	gets_s(path, 300);
	FILE *f;
	f = fopen(path, "r");
	if (f == NULL) {
		return false;
	}
	char zeile[5000];
	int zeilen = 0;
	while (fgets(zeile, sizeof(zeile), f)) {
		zeilen++;
	}
	printf("\nAnzahl der Zeilen: %i\n\n", zeilen);
	fclose(f);
	_getch();
	return true;
}
bool D2() {
	int anzahl = 0;
	char** notebook = malloc(1 * sizeof(char*));
	while (1 < 2) {
		printf("Notizzettel\n\n1 Notiz hinzufügen\n2 Notizen anzeigen\n3 Beenden\n\n");
		int auswahl;
		scanf_s("%d", &auswahl);
		fflush(stdin);
		//notebook[0] = malloc(1000 * sizeof(char));
		//notebook[0] = "test";
		//printf("%s", notebook[0]);
		switch (auswahl) {
		case 1:
			printf("Notiz eingeben:");
			char str[1000];
			gets_s(str, 1000);
			notebook[anzahl] = malloc(strlen(str) + 1 * sizeof(char));
			strcpy_s(notebook[anzahl], strlen(str) + 1 * sizeof(char), str);
			anzahl++;
			break;
		case 2:
			for (int i = 0; i < anzahl; i++) {
				printf("%s\n", notebook[i]);
			}
			break;
		case 3:
			return true;
			break;
		}
	}
}
bool D1() {
	while (1<2) {
		printf("Groesse des Arrays eingeben:");
		int variablengroesse;
		scanf_s("%d", &variablengroesse);
		printf("\nARRRRay wird initialisiert.");
		float* A = malloc(variablengroesse * sizeof(float));
		if (A == NULL) {
			printf("\n\nDu sollsch was gscheides eigeabe du Depp!");
			return true;
		}
		int gerade = 1;
		if (variablengroesse % 2 == 1) {
			A[variablengroesse / 2] = 999.0;
			gerade = 0;
		}
		for (int i = 0; i < variablengroesse / 2; i++)
		{
			A[i] = 123.0;
		}
		for (int i = variablengroesse - 1; i > variablengroesse / 2 - gerade; i--)
		{
			A[i] = 456.0;
		}
		printf("\n\nDo hosch dein initialisierta Array:");
		for (int i = 0; i < variablengroesse; i++)
		{
			printf("\nA[%d]=%f", i, A[i]);
		}
		printf("\n\nSo, dein Array wird jetz wieder gloescht (mir wellat ja spare...)\n");
		free(A);
		printf("\nWenn du willsch, kasch du nummmel a Array macha. (j/n)");
		char c = _getch();
		printf("\n\n");
		if (c == 'n' || c == 'N') {
			return true;
		}
	}
	return true;
}
bool T1() {
	enum pizzatyp { Magherita, Tonno, Funghi, UAS_Speciale, Salami, Schinken };
	enum groesse { S, M, L, Party };
	struct pizza { enum pizzatyp typ; enum groesse groesse; };
	struct bestellung {
		char name[100];
		char strasse_hsnr[100];
		char plz_ort[100];
		struct pizza pizzen[20];
	};
	
	printf("Buongiorno! Was fuer ne Pizza wolln se denn beim HS-Lieferservice bestellen?\n");
	printf("Folgende Pizzasorten gibts:\n\t 1 Magherita\n\t 2 Tonno\n\t 3 Funghi\n\t 4 UAS_Speciale\n\t 5 Salami\n\t 6 Schinken\n\nBitte gewuenschte Nummer eingeben:\n");
	struct bestellung bestell;
	fflush(stdin);
	scanf_s("%d", &bestell.pizzen[0].typ);
	fflush(stdin);
	bestell.pizzen[0].typ--;
	printf("Groessen:\n\t 1 S\n\t 2 M\n\t 3 L\n\t 4 Party\nBitte gewuenschte Nummer eingeben:\n");
	scanf_s("%d", &bestell.pizzen[0].groesse);
	fflush(stdin);
	bestell.pizzen[0].groesse--;
	printf("Persoenliche Daten: \n\tVorname und Name:          ");
	gets_s(bestell.name, 100);
	fflush(stdin);
	printf("\tStrasse und Hausnummer:    ");
	gets_s(bestell.strasse_hsnr, 100);
	fflush(stdin);
	printf("\tPLZ und Ort:               ");
	gets_s(bestell.plz_ort, 100);
	fflush(stdin);
	int anzahl;
	for (int i = 1; i < 20; i++) {
		printf("Darfs nochmal ne Pizza sein? (Y/N)\n");
		char eingabe;
		scanf_s("%c", &eingabe);
		if (eingabe == 'n' || eingabe == 'N') {
			anzahl = i;
			break;
		}
		fflush(stdin);
		printf("Folgende Pizzasorten gibts:\n\t 1 Magherita\n\t 2 Tonno\n\t 3 Funghi\n\t 4 UAS_Speciale\n\t 5 Salami\n\t 6 Schinken\n\nBitte gewuenschte Nummer eingeben:\n");
		scanf_s("%d", &bestell.pizzen[i].typ);
		fflush(stdin);
		bestell.pizzen[i].typ--;
		printf("Groessen:\n\t 1 S\n\t 2 M\n\t 3 L\n\t 4 Party\nBitte gewuenschte Nummer eingeben:\n");
		scanf_s("%d", &bestell.pizzen[i].groesse);
		fflush(stdin);
		bestell.pizzen[i].groesse--;
	}
	printf("Ihre Bestellung:\n\t%s\n\t%s\n\t%s", bestell.name, bestell.strasse_hsnr, bestell.plz_ort);
	for (int i = 0; i < anzahl; i++) {
		printf("\n\t%d, %i", bestell.pizzen[i].typ, bestell.pizzen[i].groesse);
	}
	printf("\n\n");
	return true;
}

bool N2() {
	srand(time(NULL));
	char* syllables[] = { "tan", "han", "klam", "ro", "ba", "lo" };
	printf("===========Aufgabe N2===========\n\nSilben: %s %s %s %s %s %s\n", syllables[0], syllables[1], syllables[2], syllables[3], syllables[4], syllables[5]);
	for (int i = 0; i < 10; i++) {
		int anzahl_silben = (rand() % 3) + 2;
		char silbe[200] = "";
		for (int j = 0; j < anzahl_silben; j++) {
			int silbennummer = rand() % 6;
			strcat_s(silbe, sizeof(silbe), syllables[silbennummer]);
		}
		printf("\nWort Nr. %2d hat %2d Buchstaben: %s", i+1, strlen(silbe), silbe);
	}
	printf("\n\n");
	return true;
}
bool N1() {
	printf("===========Aufgabe N1===========\n\nGeben sie die erste  Silbe an:");
	char silbe[3][10];
	gets_s(silbe[0], 10);
	printf("Geben sie die zweite Silbe an:");
	gets_s(silbe[1], 10);
	printf("Geben sie die dritte Silbe an:");
	gets_s(silbe[2], 10);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j< 3; j++)
		{
			printf("\n%s%s", silbe[j], silbe[i]);
		}
	}
	printf("\n\n");
	return true;
}
char brett[30][70] = { ' ' };
void init_board() {
	for (int i = 0; i < 50; i++) {
		brett[i][0] = '#';
		brett[i][69] = '#';
	}
	for (int i = 0; i < 70; i++) {
		brett[0][i] = '#';
		brett[29][i] = '#';
	}
}
void show_game_board() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 70; j++) {
			printf("%c", brett[i][j]);
			//printf("#");
		}
		printf("\n");
	}
}
void add_single_block(int x, int y, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			brett[y + i][x + j] = '#';
		}
	}
}
bool Y1() {
	srand(time(NULL));
	init_board();
	for (int i = 0; i < 20; i++) {
		add_single_block((rand() % 68)+1, (rand() % 28) + 1, (rand() % 4) + 3);
	}
	show_game_board();
	return true;
}
int fibonacci_rec(int i) {
	if (i == 2 || i == 1) {
		return 1;
	}
	else {
		return fibonacci_rec(i - 1) + fibonacci_rec(i - 2);
	}
}
int fibonacci_iterative(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	int prevPrev = 0;
	int prev = 1;
	int result = 0;

	for (int i = 2; i <= n; i++)
	{
		result = prev + prevPrev;
		prevPrev = prev;
		prev = result;
	}
	return result;
}
bool F2() {
	printf("%d", fibonacci_rec(6));
	return true;
}
void statistics(int n1, int n2, int n3, int* sum, float* avg) {
	*sum = n1 + n2 + n3;
	*avg = *sum / 3.0;
}
bool F1() {
	int sum = 0;
	float avg = 0;
	for (int n1 = 1; n1 <= 5; n1++) {
		for (int n2 = 1; n2 <= 5; n2++) {
			for (int n3 = 1; n3 <= 5; n3++) {
				statistics(n1, n2, n3, &sum, &avg);
				printf("n1 = %d n2 = %d n3 = %d--> sum = %d, avg = %f\n", n1, n2, n3, sum, avg);
			}
		}
	}
	return true;
}
void set_cursor_position(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
bool A1() {
	int maxsize = 20;
	int frame = 0;
	system("cls");
	while (true) { //Frames
		int obenlinks = maxsize - frame;
	//	printf("obenlinks:%d frame:%d\n", obenlinks, frame);
		for (int zeile = 1; zeile <= maxsize*2; zeile++) { //Zeilen
			if (zeile < maxsize - frame) { //leere zeile drucken
				printf("\n");
				continue;
			}
			for (int spalte= 1; spalte <= maxsize*2; spalte++) { // Spalten
				if ((spalte == obenlinks || spalte == frame*2+obenlinks) && (zeile == obenlinks || zeile ==frame*2+obenlinks)) { //eck
					printf("+");
				} else if ((zeile == obenlinks || zeile ==frame*2+obenlinks) && spalte >= obenlinks && spalte <= frame * 2+obenlinks) {
					printf("-"); //obere untere kante
				} else if ((spalte == obenlinks || spalte == frame * 2 + obenlinks) && zeile >= obenlinks && zeile <= frame * 2 + obenlinks) {
					printf("|"); //linke rechte kante
				} else {
					printf(" ");
				}
			}
			printf("\n");
		}
		mysleep(200);
		system("cls");
		frame++;
		if(frame > maxsize-1) frame = 0;
	}
	return true;
}
bool S1() {
	system("cls");
	printf("===========Aufgabe S1===========\n\n");
	bool zahl_expected = true;
	bool weiter = true;
	int berechnungsstatus = 0; //0= zahl1 beschreiben 1 = zahl2 beschreiben 3= ausrechenen
	int zahl1, zahl2, rechenart;	//0+ 1- 2* 3/
	while (weiter) {
		char c = _getch();
		switch (c) {
		case '1':; case '2':; case '3':; case '4':; case '5':; case '6':; case '7':; case '8':; case '9':; case '0':
			if (zahl_expected) {
				//printf("test");
				printf("%c", c);
				if (berechnungsstatus == 1) {
					zahl2 = (int)c - 48;
					berechnungsstatus = 2;
				}
				if (berechnungsstatus == 0) {
					zahl1 = (int)c - 48;
					berechnungsstatus = 1;
				}
				zahl_expected = false;
			}
			else {
				printf("\a");
			}
			break;
		case '*':
			if (zahl_expected) {
				printf("\a");
			}
			else {
				rechenart = 2;
				zahl_expected = true;
				printf("%c", c);

			}
			break;
		case '+':
			if (zahl_expected) {
				printf("\a");
			}
			else {
				rechenart = 0;
				zahl_expected = true;
				printf("%c", c);

			}
			break;
		case '/':
			if (zahl_expected) {
				printf("\a");
			}
			else {
				rechenart = 3;
				zahl_expected = true;
				printf("%c", c);

			}
			break;
		case '-':
			if (zahl_expected) {
				printf("\a");
			}
			else {
				rechenart = 1;
				zahl_expected = true;
				printf("%c", c);

			}
			break;
		case '=':
			weiter = false;
		}
		if (berechnungsstatus == 2) {
			switch (rechenart) {
			case 0:
				zahl1 = zahl1 + zahl2;
				zahl2 = 0;
				berechnungsstatus = 1;
				zahl_expected = false;
				break;
			case 1:
				zahl1 = zahl1 - zahl2;
				zahl2 = 0;
				berechnungsstatus = 1;
				zahl_expected = false;
				break;
			case 2:
				zahl1 = zahl1 * zahl2;
				zahl2 = 0;
				berechnungsstatus = 1;
				zahl_expected = false;
				break;
			case 3:
				zahl1 = zahl1 / zahl2;
				zahl2 = 0;
				berechnungsstatus = 1;
				zahl_expected = false;
				break;
			}
			system("cls");
			printf("===========Aufgabe S1===========\n\n%d", zahl1);
		}

	}
	return true;
}
bool L6() {
	printf("===========Aufgabe L6===========\nHöhe = 0 -> Zurück zur funktionsauswahl\nBreite = 0 -> Beenden\n\n");
	bool weitermachen = true;
	while (1<2) {
		int width, height;
		printf("Geben sie die gewünschte Breite an: ");
		scanf_s("%d", &width);
		if (width == 0) {
			weitermachen = false;
			break;
		}
		printf("Und jetzt die Höhe: ");
		scanf_s("%d", &height);
		if (height == 0) {
			weitermachen = true;
			break;
		}
		for (int zeile = 1; zeile <= height; zeile++) {
			for (int spalte = 1; spalte <= width; spalte++) {
				if (zeile == 1 && spalte == 1 || zeile == 1 && spalte == width || zeile == height && spalte == 1 || zeile == height && spalte == width) {
					printf("%c", '+');
				}
				else
				if (spalte == 1 || spalte == width) {
					printf("%c", '|');
				}
				else
				if (zeile == 1 || zeile == height) {
					printf("%c", '-');
				}
				else {
					printf(" ");
				}
			}
			printf("\n");

		}
	}
	return weitermachen;
}
bool L7() {
	printf("===========Aufgabe L7===========\nHöhe = 0 -> Zurück zur funktionsauswahl\nBreite = 0 -> Beenden\n\n");
	bool weitermachen = true;
	while (1<2) {
		int width, height, zeichenanzahl;
		printf("Geben sie die gewünschte Breite an: ");
		scanf_s("%d", &width);
		if (width == 0) {
			weitermachen = false;
			break;
		}
		printf("Und jetzt die Höhe: ");
		scanf_s("%d", &height);
		if (height == 0) {
			weitermachen = true;
			break;
		}
		zeichenanzahl = width*height;
		//printf("\nZeichen: %d", zeichenanzahl);
		for (int zeichen = 0; zeichen < zeichenanzahl; zeichen++) {
			int spalte = zeichen % width;
			int zeile = (zeichen / width);
			//printf("\nZeile: %d, Spalte: %d", zeile, spalte);
			if (zeile == 0 && spalte == 0 || zeile == 0 && spalte == width - 1 || zeile == height - 1 && spalte == 0 || zeile == height - 1 && spalte == width - 1) {
				printf("%c", '+');
			}
			else
			if (spalte == 0 || spalte == width - 1) {
				printf("%c", '|');
			}
			else
			if (zeile == 0 || zeile == height - 1) {
				printf("%c", '-');
			}
			else {
				printf(" ");
			}
			if (spalte == width - 1) {
				printf("\n");
			}
		}
	}
	return weitermachen;
}
bool L8() {
	printf("Hallo! Hier biite angeben, wie hoch die Pyramide werden soll: ");
	int rows;
	scanf_s("%d", &rows);
	printf("\n");
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < rows - i - 1; k++) {
			printf(" ");
		}
		for (int j = 0; j < i * 2 + 1; j++) {
			printf("#");
		}
		printf("\n");
	}
	return true;
}
bool R1() {
	printf("===========Aufgabe R1===========\nUntere Grenze = Obere grenze -> Zur�ck zur funktionsauswahl\nUntere Grenze > Obere Grenze -> Beenden\n\n");
	srand(time(NULL));
	bool weiter;
	while (1 < 2)
	{
		int untere, obere;
		printf("Geben sie die untere Grenze an: ");
		scanf_s("%d", &untere);
		printf("Und jetzt die obere: ");
		scanf_s("%d", &obere);
		printf("\n");
		if (untere == obere) {
			weiter = true;
			break;
		}
		if (untere > obere) {
			weiter = false;
			break;
		}
		int breite = (obere - untere) + 1;
		for (int i = 0; i < 10; i++) {
			int zahl = (rand() % breite) + untere;
			printf("%d ", zahl);
		}
		printf("\n\n");
	}
	return weiter;
}
bool testfkt() {
	char test2 = getchar();
	mysleep(2000);
	printf("\ntestfkt\n");
	mysleep(2000);
	// char test[256];
	// mysleep(2000);
	// fgets(test, 255, stdin);
	printf("%c\n", test2);
	return true;
}
bool snek() {
	bool laeuft = true;
	int laenge = 5;
	int snake[30][2] = { { 15, 38 },
	{ 15, 39 },
	{ 15, 40 },
	{ 15, 41 },
	{ 15, 42 },
	};
	system("chcp 437");
	int zeilen = 30;
	int spalten = 80;
	char horizontal[] = { 0xe2, 0x94, 0x81, '\0' };
	char vertikal[] = { 0xE2, 0x94, 0x83, '\0' };
	char lo[] = { 0xE2, 0x94, 0x8F, '\0' };
	char ro[] = { 0xE2, 0x94, 0x93, '\0' };
	char lu[] = { 0xE2, 0x94, 0x97, '\0' };
	char ru[] = { 0xE2, 0x94, 0x9B, '\0' };
	char block[] = { 0xE2, 0x96, 0x88, '\0' };
	int bewegungx = 1;
	int bewegungy = 0;
	while (laeuft) {
		//zeichnen
		for (int zeile = 1; zeile <= zeilen; zeile++) {
			for (int spalte = 1; spalte <= spalten; spalte++) {
				bool printsnake = false;
				for (int i = 0; i < sizeof(snake) / sizeof(snake[0]); i++) {
					if (snake[i][0] == zeile && snake[i][1] == spalte) {
						printsnake = true;
					}
				}
				if (zeile == 1 && spalte == 1) {
					printf("%s", lo);
				}
				else
				if (zeile == 1 && spalte == spalten) {
					printf("%s", ro);
				}
				else
				if (zeile == zeilen && spalte == 1) {
					printf("%s", lu);
				}
				else
				if (zeile == zeilen && spalte == spalten) {
					printf("%s", ru);
				}
				else
				if (spalte == 1 || spalte == spalten) {
					printf("%s", vertikal);
				}
				else
				if (zeile == 1 || zeile == zeilen) {
					printf("%s", horizontal);
				}
				else
				if (printsnake) {
					printf("%s", block);
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
		int i = 0;
		// printf("%d.%d %d.%d %d.%d %d.%d %d.%d %d.%d\n", snake[0][0], snake[0][1],
		// 																					snake[1][0], snake[1][1],
		// 																					snake[2][0], snake[2][1],
		// 																					snake[3][0], snake[3][1],
		// 																					snake[4][0], snake[4][1],
		// 																					snake[5][0], snake[5][1] );
		while (i<laenge) {
			// snake[i-1][1] = snake[i-2][1];
			// snake[i-1][0] = snake[i-2][0];
			if (bewegungx != 0) {
				snake[i][1] += bewegungx;
			}
			else {
				snake[i][0] += bewegungy;
			}
			i++;
		}
		// printf("%d.%d %d.%d %d.%d %d.%d %d.%d %d.%d\n", snake[0][0], snake[0][1],
		// 																					snake[1][0], snake[1][1],
		// 																					snake[2][0], snake[2][1],
		// 																					snake[3][0], snake[3][1],
		// 																					snake[4][0], snake[4][1],
		// 																					snake[5][0], snake[5][1] );
		mysleep(1000);
		// if(kbhit()) {
		// 	char taste = getch();
		// 	switch (taste) {
		// 		case 'w': //oben
		// 			bewegungy=1;
		// 			bewegungx=0;
		// 			break;
		// 		case 'a':
		// 			bewegungy=0;
		// 			bewegungx=-1;
		// 			break;
		// 		case 's':
		// 			bewegungy=-1;
		// 			bewegungx=0;
		// 			break;
		// 		case 'd':
		// 			bewegungy=0;
		// 			bewegungx=1;
		// 			break;
		// 		default:
		// 			break;
		// 	}
		// }
		// char test = getchar();
		// return true;
	}
	return true;
}
bool GIF() {
	int sleeptime = 100;
	while (1<2) {
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@H#HMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMZZZZMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNtl^:NMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN::..?=MNMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....vuNMNHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....;;vzMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNMMNfVyy..^^;;MNNNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNN=lNN======VV..;;uZMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MuuMMuz`  `NN..;::;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MttNMt=   `NM..;;;;MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NrzNMzvvvvvuz.^yy;?MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMuuuuuuuuZZMM;;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMzzzzzu@@@@MM;;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMM@@@@VVggff;?NNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMfVggggyZ;;;;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMggVVVy..;;:?MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMfffy....^^;;zuMMMMMMMMMNMMMMMMMMMM\nMMMMMMMMMMMMMMMMNMVVVVNMMMMMMMNN........;;;;MNN#MMMNfVVyM#MMMMMMMM\nMMMMMMMMMMMMMMMMHM`   ZfMMMMNMkp......^^:;rzMHMMNNfy   `MkMMMMMMMM\nMMMMMMMMMMMMMMMMHM`  ;?NMMMNM^.....^^::;;MMMHMMNN;;   `MkMMMMMMMM\nMMMMMMMMMMMMMMMM@N?;;:NMN#MMMN^...^^::;;rvM#MMMMNMMN;;;;#mMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NNNNNMM#Mmq^..^::;;ltMMM#MMMMNMNNNNNHMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMM#M?;^.;;llltMM##MNMMMM#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMMMMMMtlllNMMMMMMMNMMM#HMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#MMM#HHHHHHHHH##HHH#MMMMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM@@@@@@MMMMMMMMMMMMMMMMMM@@@@@@MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM@M`    `@H@HMNMMMMMMNMH@H@`    `N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM@N^.....`...NNMMMMMMNN..`.......#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NNNNNN#NNN#MMMMMM#NNNN###NNN#MMMMMMMMMMMMMMMMMM");
		mysleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@HH@MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMuuuZMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNrl^:NMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN:^..??MMN#MMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....tvMMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....:;rrMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NNNMNpppV..^^:;NNNNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N??NM??????fp..;;zuMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MZZMMZu   `NM..;;;;MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NllNN=?`  `NN..;;:?MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNNuuNMuuuuuuvr.^ff;?NMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMzrrrrvZyyyMM;;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMZuuZuZg@@@MM;?NNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNuMM@@@gfV@@yZ;?MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMfV@g@gZu;;:;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@gZZZZ..;;;?NMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMNMyZyZ......:;:?MNMMMMMMMMMMMNMMMMMM\nMMMMMMMMMMMMNMZZZZNMuMMMMMMMMMNN........^^;;uuMMMMMMMMMNZZZZMMMMMM\nMMMMMMMMMMMM@M`   uyMMMMMMMMMMMN........;;;;MN##MMMMMNyu   `MNMMMM\nMMMMMMMMMMMM@M`   ;?NMMMMMMMNMkp......^^:;rzMHMMMMMMNN?;   .NNMMMM\nMMMMMMMMMMMM@M????NMMMMMMMMMMN^.....^^::;;MMMHMMMMMMMMMN????N#MMMM\nMMMMMMMMMMMMMM#NNMMMMMNMMM#MMM^...^^:::;rzMMNMMNzMNMMMMMNMN#MMMMMM\nMMMMMMMMMMMMMMMMMMMMMM@NN#MMqb..^^::;;trMMNHMM#NNNNHMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M??^.:;lttrMMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMMMMNttltNM##MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHM##########N#MMH#MHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMMMMMMMMMMMMMMMMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM@@@@@@@@MMMMMMMMMMMMMM@@@@@@@@MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M`      `gHMNMMMMMMNM@@       `M#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN^......`..HHMMMMMMHH..........#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NNNNNNNNHMMMMMMMMMMHNNNNNNNN#MMMMMMMMMMMMMMMMMM");
		mysleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NvrrrN#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMttttMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM;;trMMMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMH#MN^.^^=lNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM;:....:;NMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....^^llMHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMHNNNMMMMMMMMMMMMMMMMMMHNMMgm.^qmmg@@M#MMMMMMMMMMMMMMMMMNNNNHMM\nMM#N?:::HMNNMMMMMMMMMMMM#N;::::;qk;:::::MMN#MMMMMMMMMMMMNMM#;::;NH\nMM#M.   :;NMMMMMMMMMMMMMNM``ff``NN` pV` MMMNMMMMMMMMMMMMM#;:   .M#\nMM#M.   ypMNMMMMMMMMMMMMNM` ;; `MN` ;; `MMMNMMMMMMMMMMMMMNpy   .N#\nMMMMyVVfNMMMMMMMMMMMMMMMMMyfVVVyllyfVVVVvuM#MMMMMMMMMMMMMMMNffVyMM\nMMMMNMMMMM#MMNMNMMMMMMMMMM#Mllll..llllyyqqMNMMMMMMMMNMNMM#MMMMMNMM\nMMMMMMMMMMNMMMNMNNMNMMMMMM#MfVVVVVVVVVZZMMM#MMMMNNNNM#MMMNMMMMMMMM\nMMMMMMMMMMMMMMNMMMMMMMMNMM#Mgggmggmggg@@uZMNMMNMMNMMM#MMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNMMM#MMMNM@@fVVVVV@@zr;;NMMMMMMNMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHNNNNMzz@@@@@@vr..;?NNNNNNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N..vuuuuz..^^;?MNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M..........;;;;NNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N^.........;;yyMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N..........:;MNMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M........^^;;MHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N........:;uuMHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N.......^;;NMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M.....^:;vuMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#Mlll=;;rzMMNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MMMMMrrNMM#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMN#NNNNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M#HMMMMMM##MNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM##MMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMm@@@@@@HMNMMMMMMNM@@@@@@@mMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#MH@`     .^NNMMMMMMNN^.     `@HM#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M........H#NHMMMMMMHNN#........N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHNNN#NNNN#MMMMMMMMMMMMMMNNNNNNNNNHMMMMMMMMMMMMMMMM");
		mysleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NNHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NzvvzMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MttttMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMM#NMNrt;?MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMtl^^^^MMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMM;;....;?NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHNtt^^.....^#MqMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMgmkkkb^.bqMMkNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#MNN?;;;;;pb;;;;;;NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMHMMN` Zy `#N` Zy `NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMHMNNMMMMMMMMMMMMHMMN` ?? `#N` ?? `NMMMMMMMMMNNMNMHMMMMMMMMMMMM\nMM#Nl===HNMNMMMMMMMMHMZuZZZZZZttZZZZZZMMMMMMMMNNMN====N#MMMMMMMMMM\nMM#M.   ?=NMMMMMMMMM#Mkbffrttt..tttrMNMMMMMMMMMM=?   `MHMMMMMMMMMM\nMM#M.   ruNMMMMMMMMMHMMMZuyyyyyyyyyyMNMMMMMMMMMMur   .MHMMMMMMMMMM\nMM#NuuuuNMMNMMMMMMMMHMyZ@@@ggggggg@gMNMMMMMMMMNMMNuuuzN#MMMMMMMMMM\nMMMM#NMMNMNMMMMMMMMM#M?;zug@VVVVVV@@MNMMMMMMMMMMNMMNM#MMMMMMMMMMMM\nMMMMMMMMMMNMNMzNMMMMHM?:..zu@@@@@@uuMNMMMMNMMNMNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMM#NMMMNMMNM;;^^..uZuZuu.^MNMMNMMMNHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMNMNMMNNMyZ;;..........MNMMMNMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#NNM;;..........MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHM;;^^.......^M#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMuz;;........MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHNMM;;^^......MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMur;:^.....MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMM#MMNrr;;???lM#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MMMrrMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MNNNNNNNNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NMMMMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMNHMMMMMMMMHNMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMm@@@@@MMMMMMMMMMMMNM@@@@@mMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#MH@`    `gHMNMMMMMMNMH@     `@HM#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M^`.....`..HHMMMMMMHH..........N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN#NNNNNNNNHMMMMMMMMMMHNNNNNNNNNNHMMMMMMMMMMMMMMMM");
		mysleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MZZZZMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMNN:^ltMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMMl?..^:MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMHNNMzv.....^MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#Muv;;......MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNMNM?:^^..yVVfMMNMN#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNMuu;:..yV=====lNM==NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;;:..NN`   zuMMuZMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;;;..#N`   ltNMltNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;yy..zurvvvvuMMvvNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;NMZZuuuuuuuuNMzNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM;:NM@@@@uzzzzuMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;yfg@ff@@@@MMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;;;yyggggffMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;;;..yVVVmgMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMNMMMMMMMMMuu;:^^....yffpMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMM#MyVVVNNMM#NNM?;;;.......^#MuMMMMMMMfVVVMMMMMMMMMMMMMMMMMM\nMMMMMMMMgM`   ypNMMMHMzr;;^^......fbM#MMMNfV   `NNMMMMMMMMMMMMMMMM\nMMMMMMMMgM`   :?NMMM#MNN;;::^^......MNMMMN?;   `NNMMMMMMMMMMMMMMMM\nMMMMMMMMgN;;;;NMMMMMMMHMrt;;::^....^MNMMNNMN;;;;#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMHNNNNNMMzMMMHMMMrt;:;;^...mgMNMMNMNNN#MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMH#MMMMHM##MNtlll;;^^;?NMMMMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMH#MMMMMMNMMMMMllllMMMMMMMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#MMMMM#HH#HHHHHHH#HH##MMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM@@@@@@MMMMMMMMMMMMMMMMMM@@@@@@MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M`    `@H@HMNMMMMMMNMH@Hg`    `NNMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN^......`..NNMMMMMMNN..`.`.....#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM##NNN#NNNNN#MMMMMM#NNNNNNNNNN#MMMMMMMMMMMMMMMMMM");
		mysleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHH@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMHNMMMMN#MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MuuuuMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMM#MNN^^lrMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHNMM=?..^:MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#MNMrt......MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMHMzr;;.....^MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NMM?:^^..ppppMMNNNHMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMzz;:..Vp??????NM??NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;;;..#N    uyMMZyMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;;:..NN`   =lNN=lNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;Vf..rvuuuuuuMMuuNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;NMyyyZvrvvrzMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;NM@@@guuuuZZMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;Zy@@ff@@@@MMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM;;;;uZgg@gffMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;;:..uZZZg@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMNMMMMMMMMMMMNM;;;;......ZyyyMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMM\nMMMMMMZZZZNMMMMMMMMMZu;:^^.......^#MMMMMMMMMMMMNZZZZMMMMMMMMMMMMMM\nMMMM#M`   uyNMMMMM##NM?;;;........NMMNMMMMMMMNyZ   `N#MMMMMMMMMMMM\nMMMM#M`   ??#MMMMMMM#Mur;;^^......fbMNMMMMMMMN??   `M#MMMMMMMMMMMM\nMMMMHN=???#MMMMMMMMMNMMN;;::^^......MNMMMMMMMMMN????N#MMMMMMMMMMMM\nMMMMMMNNNNMMMMNNMrMMMMNMvr;:::^....^MMMMrMNMMMMMNNM#MMMMMMMMMMMMMM\nMMMMMMMMMMMMMMHNNN##MMHNMMvt;;;:^^..kmMM#NNHMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMHNMMtttl;:.^??NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M##MNtlltMMMMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMNHMMH##N#######NMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM@@@@@@@@MMMMMMMMMMMMMM@@@@@@@@MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M`      `gHMNMMMMMMNMH@  `    `N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN^......`..HHMMMMMMHH..........#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NNNNNNNNHMMMMMMMMMMH#N##NNNN#MMMMMMMMMMMMMMMMMM");
		mysleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHNN#MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNvrrrNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMrtttMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MMNrt;?NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N==^^.^NM#HMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMM#NMN;;....:;M#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMtl^.......MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMHNNNMNMMMMMMMMMMMMMMMMNM@@gggq.^kgMMNNMMMMMMMMMMMMMMMMNMNNN#MMMM\nHN;:::#MMNMMMMMMMMMMMMHNMM;:::::qk;:::::NHMMMMMMMMMMMMNNM#:::;NHMM\nHM.   :;#MMMMMMMMMMMMMHMMM``ff``MN` pV` MHMMMMMMMMMMMMMN;:   .M@MM\nHM`   VbNMMMMMMMMMMMMMHMMM` ;; `NN` ;; `MHMMMMMMMMMMMMMMby   `MHMM\nMMVVVfNMMMMMMMMMMMMMMMHMzvVVVVVyllVVVVVVMMMMMMMMMMMMMMMMMNfffVMNMM\nMMNMMMMMHMMNMNMMMMMMMMHMqkVyllll..llltMNMMMMMMMMMMNMNNMNMMMMMNMMMM\nMMMMMMMMNMMM#MNNMNMMMMHMMMZZVVVVVVVVVfMNMMMMMMNNNNMNMMMNMMMMMMMMMM\nMMMMMMMMMMMMNMMMNMMMMMHNuu@@gggmggmgggMMMMNMMMMMMMMNMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMNMMMNMNN;;rz@@fVVyVV@@MMMMMNMMMNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNNNNNM;;..rz@@@@@@vuMNNNNNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHM;;^^..vuuuuz.^NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHN;;;;.........^NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMyy;;.........^NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMM;;.........^NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNM;;^^........NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMZu;:.......^NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMHNMN;;^^.....^NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#Mzv;:^.....NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NMMzv;;===tNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMrrNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMNNNNNNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M#HMMMMMMHNMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMm@@@@@@@MNMMMMMMNM@@@@@@@mMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#MH@`     .^MNMMMMMMNN^.     `@HM#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M........HNNHMMMMMMHNN#........N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHNNN#NNNN#MMMMMMMMMMMMMMNNNNNNNNNHMMMMMMMMMMMMMMMM");
		mysleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHNNHMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNzvvzNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMrttrMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN?;trNMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NMN^^^^llMHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM?;....:;MMN#MMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNN......^^trMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMqp^.kkkkggMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N;;;;;;bk;;;;;?NMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N` Zy `NN `yy `NMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMHNMNMNMMMMMMMM#N` ?? `NN` ?? `NMMHMMMMMMMMMMNMNMNNMMMM\nMMMMMMMMMMHN===l#MMNMMMMMMNMZZZZZZttZZZZZZuuMHMMMMMMMMNMM#===lNHMM\nMMMMMMMMMMHM.   ?=NMMMMMMMMMNMrttt..rttrfpbkMHMMMMMMMMMN=?   `MHMM\nMMMMMMMMMMHN.   vuNMMMMMMMMMNMVyyyyyyyyZuZMMMHMMMMMMMMMNuv   .M@MM\nMMMMMMMMMM#NzuuuMMMMMMMMMMMMMM@gggggggg@@@ZZMHMMMMMMMMMMMNuuuuNHMM\nMMMMMMMMMMMM#NNMNNMMuMMMMMMMNM@@VVVVVf@@uz;;MHMMMMMMMuMNMNMNMNMMMM\nMMMMMMMMMMMMMMMMMMNMNMMMMMMMNMZu@@@@@guz..;;NHMMMMMMMNM#MMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#NNMNMMMMN^.uZuZZu..^^;;M#NMNMMNN#MMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMM#MMNMNMM^.........;;ZyMNMMMNMNMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNN^.........;?NMNHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM^.......^^:?NNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.......:;uuMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM^......^:;MNN#MMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNN^....^;;rzMHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM=???;;rrMMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMNrrMMMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M#HMMMMMMMMH#MHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMm@@@@@MNMMMMMMMMMMMM@@@@@mMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#MH@`    `@HMNMMMMMMNMH@     `@HM#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M^`.....`..HHMMMMMMHH..........N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN#NNNNNNNNHMMMMMMMMMMH##NNNNNNNNHMMMMMMMMMMMMMMMM");
		mysleep(sleeptime);
	}
	return true;
}
int main() {
	bool weitermachen = true;
	while (weitermachen)
	{
		printf("===========Hallo Welt!===========\n\nSie koennen Funktionen ausfuehren. Einfach die Zahl eingeben.\nWenn sie beenden moechten, einfach ne andere Zahl eingeben.\n\n");
		printf("1  Aufgabe R1\n2  Snake\n3  testfkt\n4  GIF\n5  Aufgabe L6\n6  Aufgabe L7\n7  Aufgabe L8\n8  Aufgabe S1\n9  Aufgabe A1\n10 Aufgabe F1\n11 Aufgabe F2\n12 Aufgabe Y1\n13 Aufgabe N1\n14 Aufgabe N2\n15 Aufgabe T1\n16 Aufgabe D1\n17 Aufgabe D2\n18 Aufgabe I1\n19 Aufgabe I2\n\n");
		int auswahl;
		scanf_s("%d", &auswahl);
		fflush(stdin);
		switch (auswahl)
		{
		case 1:
			weitermachen = R1();
			break;
		case 2:
			weitermachen = snek();
			break;
		case 3:
			weitermachen = testfkt();
			break;
		case 4:
			weitermachen = GIF();
			break;
		case 5:
			weitermachen = L6();
			break;
		case 6:
			weitermachen = L7();
			break;
		case 7:
			weitermachen = L8();
			break;
		case 8:
			weitermachen = S1();
			break;
		case 9:
			weitermachen = A1();
			break;
		case 10:
			weitermachen = F1();
			break;
		case 11:
			weitermachen = F2();
			break;
		case 12:
			weitermachen = Y1();
			break;
		case 13:
			weitermachen = N1();
			break;
		case 14:
			weitermachen = N2();
			break;
		case 15:
			weitermachen = T1();
			break;
		case 16:
			weitermachen = D1();
			break;
		case 17:
			weitermachen = D2();
			break;
		case 18:
			weitermachen = I1();
			break;
		case 19:
			weitermachen = I2();
			break;
		default:
			weitermachen = false;
			break;
		}
	}

}
