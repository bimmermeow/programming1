#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>  //_getch
#include <sys/select.h>
#include <stropts.h>
#include <string.h>

char getch(){
	#ifdef __linux__
  char buf=0;
  struct termios old={0};
  fflush(stdout);
  if(tcgetattr(0, &old)<0)
      perror("tcsetattr()");
  old.c_lflag&=~ICANON;
  old.c_lflag&=~ECHO;
  old.c_cc[VMIN]=1;
  old.c_cc[VTIME]=0;
  if(tcsetattr(0, TCSANOW, &old)<0)
      perror("tcsetattr ICANON");
  if(read(0,&buf,1)<0)
      perror("read()");
  old.c_lflag|=ICANON;
  old.c_lflag|=ECHO;
  if(tcsetattr(0, TCSADRAIN, &old)<0)
      perror ("tcsetattr ~ICANON");
  // printf("%c\n",buf);
  return buf;
	#endif
 }

// int _kbhit() {
//     static const int STDIN = 0;
//     static bool initialized = false;
//
//     if (! initialized) {
//         // Use termios to turn off line buffering
//         termios term;
//         tcgetattr(STDIN, &term);
//         term.c_lflag &= ~ICANON;
//         tcsetattr(STDIN, TCSANOW, &term);
//         setbuf(stdin, NULL);
//         initialized = true;
//     }
//
//     int bytesWaiting;
//     ioctl(STDIN, FIONREAD, &bytesWaiting);
//     return bytesWaiting;
// }
bool I2() {
	//system("cls");
	printf("Absoluten Pfad zur Datei angeben, um Zahlen zu sortieren\n");
	char path[300];
	//fgets(path, 300, stdin);
	scanf("%s", &path);
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
	strcat(path, ".sorted.txt");
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
bool L6() {
	printf("===========Aufgabe L6===========\nHöhe = 0 -> Zur�ck zur funktionsauswahl\nBreite = 0 -> Beenden\n\n");
	char horizontal[] = { 0xe2, 0x94, 0x81, '\0' };
	char vertikal[] = { 0xE2, 0x94, 0x83, '\0' };
	char lo[] = { 0xE2, 0x94, 0x8F, '\0' };
	char ro[] = { 0xE2, 0x94, 0x93, '\0' };
	char lu[] = { 0xE2, 0x94, 0x97, '\0' };
	char ru[] = { 0xE2, 0x94, 0x9B, '\0' };
	bool weiter = true;
	while (weiter) {
		int width, height;
		printf("Geben sie die gewünschte Breite an: ");
		scanf("%d\n", &width);
		printf("Und jetzt die Höhe: ");
		scanf("%d\n", &height);
		for(int zeile=1; zeile<=height; zeile++) {
			for (int spalte = 1; spalte <= width; spalte++) {
				if (zeile == 1 && spalte == 1) {
					printf("%s", lo);
				}
				else
				if (zeile == 1 && spalte == width) {
					printf("%s", ro);
				}
				else
				if (zeile == height && spalte == 1) {
					printf("%s", lu);
				}
				else
				if (zeile == height && spalte == width) {
					printf("%s", ru);
				}
				else
				if (spalte == 1 || spalte == width) {
					printf("%s", vertikal);
				}
				else
				if (zeile == 1 || zeile == height) {
					printf("%s", horizontal);
				}	else {
					printf(" ");
				}
			}
		}
	}
}
bool R1() {
	printf("===========Aufgabe R1===========\nUntere Grenze = Obere grenze -> Zur�ck zur funktionsauswahl\nUntere Grenze > Obere Grenze -> Beenden\n\n");
	srand(time(NULL));
	bool weiter;
	while (1 < 2)
	{
		int untere, obere;
		printf("Geben sie die untere Grenze an: ");
		//scanf_s("%d", &untere);
		scanf("%d", &untere);
		printf("Und jetzt die obere: ");
		//scanf_s("%d", &obere);
		scanf("%d", &obere);
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
	sleep(2);
	printf("\ntestfkt\n");
	sleep(2);
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
	while(laeuft) {
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
					// char zeichen[]={0xE2, 0x94, 0x8F, '\0'};
					printf("%s", lo);
				}
				else
				if (zeile == 1 && spalte == spalten) {
					// char zeichen[]={0xE2, 0x94, 0x93, '\0'};
					printf("%s", ro);
				}
				else
				if (zeile == zeilen && spalte == 1) {
					// char zeichen[]={0xE2, 0x94, 0x97, '\0'};
					printf("%s", lu);
				}
				else
				if (zeile == zeilen && spalte == spalten) {
					// char zeichen[]={0xE2, 0x94, 0x9B, '\0'};
					printf("%s", ru);
				}
				else
				if (spalte == 1 || spalte == spalten) {
					// char zeichen[]={0xE2, 0x94, 0x83, '\0'};
					printf("%s", vertikal);
				}
				else
				if (zeile == 1 || zeile == zeilen) {
					// char zeichen[]={ 0xe2, 0x94, 0x81, '\0' };
					printf("%s", horizontal);
				}
				else
				if (printsnake) {
					printf("%s", block);
				}
				else {
					printf(" ");
				}
				// printf("%s", zeichen);
			}
			printf("\n");
		}
		int i=0;
		// printf("%d.%d %d.%d %d.%d %d.%d %d.%d %d.%d\n", snake[0][0], snake[0][1],
		// 																					snake[1][0], snake[1][1],
		// 																					snake[2][0], snake[2][1],
		// 																					snake[3][0], snake[3][1],
		// 																					snake[4][0], snake[4][1],
		// 																					snake[5][0], snake[5][1] );
		while(i<laenge) {
			// snake[i-1][1] = snake[i-2][1];
			// snake[i-1][0] = snake[i-2][0];
			if(bewegungx!=0) {
				snake[i][1]+=bewegungx;
			} else {
				snake[i][0]+=bewegungy;
			}
			i++;
		}
		// printf("%d.%d %d.%d %d.%d %d.%d %d.%d %d.%d\n", snake[0][0], snake[0][1],
		// 																					snake[1][0], snake[1][1],
		// 																					snake[2][0], snake[2][1],
		// 																					snake[3][0], snake[3][1],
		// 																					snake[4][0], snake[4][1],
		// 																					snake[5][0], snake[5][1] );
		sleep(1);
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
}
bool GIF() {
	float sleeptime = 0.1;
	while (1<2) {
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@H#HMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMZZZZMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNtl^:NMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN::..?=MNMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....vuNMNHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....;;vzMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNMMNfVyy..^^;;MNNNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNN=lNN======VV..;;uZMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MuuMMuz`  `NN..;::;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MttNMt=   `NM..;;;;MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NrzNMzvvvvvuz.^yy;?MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMuuuuuuuuZZMM;;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMzzzzzu@@@@MM;;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMM@@@@VVggff;?NNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMfVggggyZ;;;;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMggVVVy..;;:?MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMfffy....^^;;zuMMMMMMMMMNMMMMMMMMMM\nMMMMMMMMMMMMMMMMNMVVVVNMMMMMMMNN........;;;;MNN#MMMNfVVyM#MMMMMMMM\nMMMMMMMMMMMMMMMMHM`   ZfMMMMNMkp......^^:;rzMHMMNNfy   `MkMMMMMMMM\nMMMMMMMMMMMMMMMMHM`  ;?NMMMNM^.....^^::;;MMMHMMNN;;   `MkMMMMMMMM\nMMMMMMMMMMMMMMMM@N?;;:NMN#MMMN^...^^::;;rvM#MMMMNMMN;;;;#mMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NNNNNMM#Mmq^..^::;;ltMMM#MMMMNMNNNNNHMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMM#M?;^.;;llltMM##MNMMMM#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMMMMMMtlllNMMMMMMMNMMM#HMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#MMM#HHHHHHHHH##HHH#MMMMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM@@@@@@MMMMMMMMMMMMMMMMMM@@@@@@MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM@M`    `@H@HMNMMMMMMNMH@H@`    `N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM@N^.....`...NNMMMMMMNN..`.......#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NNNNNN#NNN#MMMMMM#NNNN###NNN#MMMMMMMMMMMMMMMMMM");
		sleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@HH@MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMuuuZMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNrl^:NMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN:^..??MMN#MMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....tvMMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....:;rrMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NNNMNpppV..^^:;NNNNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N??NM??????fp..;;zuMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MZZMMZu   `NM..;;;;MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NllNN=?`  `NN..;;:?MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNNuuNMuuuuuuvr.^ff;?NMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMzrrrrvZyyyMM;;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMZuuZuZg@@@MM;?NNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNuMM@@@gfV@@yZ;?MNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMfV@g@gZu;;:;MMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@gZZZZ..;;;?NMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMNMyZyZ......:;:?MNMMMMMMMMMMMNMMMMMM\nMMMMMMMMMMMMNMZZZZNMuMMMMMMMMMNN........^^;;uuMMMMMMMMMNZZZZMMMMMM\nMMMMMMMMMMMM@M`   uyMMMMMMMMMMMN........;;;;MN##MMMMMNyu   `MNMMMM\nMMMMMMMMMMMM@M`   ;?NMMMMMMMNMkp......^^:;rzMHMMMMMMNN?;   .NNMMMM\nMMMMMMMMMMMM@M????NMMMMMMMMMMN^.....^^::;;MMMHMMMMMMMMMN????N#MMMM\nMMMMMMMMMMMMMM#NNMMMMMNMMM#MMM^...^^:::;rzMMNMMNzMNMMMMMNMN#MMMMMM\nMMMMMMMMMMMMMMMMMMMMMM@NN#MMqb..^^::;;trMMNHMM#NNNNHMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M??^.:;lttrMMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMMMMNttltNM##MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHM##########N#MMH#MHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMMMMMMMMMMMMMMMMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM@@@@@@@@MMMMMMMMMMMMMM@@@@@@@@MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M`      `gHMNMMMMMMNM@@       `M#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN^......`..HHMMMMMMHH..........#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NNNNNNNNHMMMMMMMMMMHNNNNNNNN#MMMMMMMMMMMMMMMMMM");
		sleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NvrrrN#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMttttMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM;;trMMMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMH#MN^.^^=lNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM;:....:;NMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.....^^llMHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMHNNNMMMMMMMMMMMMMMMMMMHNMMgm.^qmmg@@M#MMMMMMMMMMMMMMMMMNNNNHMM\nMM#N?:::HMNNMMMMMMMMMMMM#N;::::;qk;:::::MMN#MMMMMMMMMMMMNMM#;::;NH\nMM#M.   :;NMMMMMMMMMMMMMNM``ff``NN` pV` MMMNMMMMMMMMMMMMM#;:   .M#\nMM#M.   ypMNMMMMMMMMMMMMNM` ;; `MN` ;; `MMMNMMMMMMMMMMMMMNpy   .N#\nMMMMyVVfNMMMMMMMMMMMMMMMMMyfVVVyllyfVVVVvuM#MMMMMMMMMMMMMMMNffVyMM\nMMMMNMMMMM#MMNMNMMMMMMMMMM#Mllll..llllyyqqMNMMMMMMMMNMNMM#MMMMMNMM\nMMMMMMMMMMNMMMNMNNMNMMMMMM#MfVVVVVVVVVZZMMM#MMMMNNNNM#MMMNMMMMMMMM\nMMMMMMMMMMMMMMNMMMMMMMMNMM#Mgggmggmggg@@uZMNMMNMMNMMM#MMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNMMM#MMMNM@@fVVVVV@@zr;;NMMMMMMNMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHNNNNMzz@@@@@@vr..;?NNNNNNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N..vuuuuz..^^;?MNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M..........;;;;NNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N^.........;;yyMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N..........:;MNMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M........^^;;MHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N........:;uuMHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N.......^;;NMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M.....^:;vuMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#Mlll=;;rzMMNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MMMMMrrNMM#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMN#NNNNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M#HMMMMMM##MNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM##MMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMm@@@@@@HMNMMMMMMNM@@@@@@@mMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#MH@`     .^NNMMMMMMNN^.     `@HM#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M........H#NHMMMMMMHNN#........N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHNNN#NNNN#MMMMMMMMMMMMMMNNNNNNNNNHMMMMMMMMMMMMMMMM");
		sleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NNHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NzvvzMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MttttMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMM#NMNrt;?MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMtl^^^^MMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMM;;....;?NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHNtt^^.....^#MqMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMgmkkkb^.bqMMkNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#MNN?;;;;;pb;;;;;;NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMHMMN` Zy `#N` Zy `NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMHMNNMMMMMMMMMMMMHMMN` ?? `#N` ?? `NMMMMMMMMMNNMNMHMMMMMMMMMMMM\nMM#Nl===HNMNMMMMMMMMHMZuZZZZZZttZZZZZZMMMMMMMMNNMN====N#MMMMMMMMMM\nMM#M.   ?=NMMMMMMMMM#Mkbffrttt..tttrMNMMMMMMMMMM=?   `MHMMMMMMMMMM\nMM#M.   ruNMMMMMMMMMHMMMZuyyyyyyyyyyMNMMMMMMMMMMur   .MHMMMMMMMMMM\nMM#NuuuuNMMNMMMMMMMMHMyZ@@@ggggggg@gMNMMMMMMMMNMMNuuuzN#MMMMMMMMMM\nMMMM#NMMNMNMMMMMMMMM#M?;zug@VVVVVV@@MNMMMMMMMMMMNMMNM#MMMMMMMMMMMM\nMMMMMMMMMMNMNMzNMMMMHM?:..zu@@@@@@uuMNMMMMNMMNMNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMM#NMMMNMMNM;;^^..uZuZuu.^MNMMNMMMNHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMNMNMMNNMyZ;;..........MNMMMNMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#NNM;;..........MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHM;;^^.......^M#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMuz;;........MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHNMM;;^^......MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMur;:^.....MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMM#MMNrr;;???lM#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MMMrrMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MNNNNNNNNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NMMMMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMNHMMMMMMMMHNMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMm@@@@@MMMMMMMMMMMMNM@@@@@mMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#MH@`    `gHMNMMMMMMNMH@     `@HM#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M^`.....`..HHMMMMMMHH..........N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN#NNNNNNNNHMMMMMMMMMMHNNNNNNNNNNHMMMMMMMMMMMMMMMM");
		sleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MZZZZMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMNN:^ltMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMMl?..^:MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMHNNMzv.....^MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#Muv;;......MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNMNM?:^^..yVVfMMNMN#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNMuu;:..yV=====lNM==NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;;:..NN`   zuMMuZMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;;;..#N`   ltNMltNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;yy..zurvvvvuMMvvNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;NMZZuuuuuuuuNMzNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM;:NM@@@@uzzzzuMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;yfg@ff@@@@MMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;;;yyggggffMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;;;..yVVVmgMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMNMMMMMMMMMuu;:^^....yffpMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMM#MyVVVNNMM#NNM?;;;.......^#MuMMMMMMMfVVVMMMMMMMMMMMMMMMMMM\nMMMMMMMMgM`   ypNMMMHMzr;;^^......fbM#MMMNfV   `NNMMMMMMMMMMMMMMMM\nMMMMMMMMgM`   :?NMMM#MNN;;::^^......MNMMMN?;   `NNMMMMMMMMMMMMMMMM\nMMMMMMMMgN;;;;NMMMMMMMHMrt;;::^....^MNMMNNMN;;;;#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMHNNNNNMMzMMMHMMMrt;:;;^...mgMNMMNMNNN#MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMH#MMMMHM##MNtlll;;^^;?NMMMMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMH#MMMMMMNMMMMMllllMMMMMMMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#MMMMM#HH#HHHHHHH#HH##MMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM@@@@@@MMMMMMMMMMMMMMMMMM@@@@@@MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M`    `@H@HMNMMMMMMNMH@Hg`    `NNMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN^......`..NNMMMMMMNN..`.`.....#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM##NNN#NNNNN#MMMMMM#NNNNNNNNNN#MMMMMMMMMMMMMMMMMM");
		sleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHH@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMHNMMMMN#MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MuuuuMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMM#MNN^^lrMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHNMM=?..^:MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#MNMrt......MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMHMzr;;.....^MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NMM?:^^..ppppMMNNNHMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMzz;:..Vp??????NM??NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;;;..#N    uyMMZyMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;;:..NN`   =lNN=lNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;Vf..rvuuuuuuMMuuNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;NMyyyZvrvvrzMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;NM@@@guuuuZZMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMN;;Zy@@ff@@@@MMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM;;;;uZgg@gffMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNM;;;:..uZZZg@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMNMMMMMMMMMMMNM;;;;......ZyyyMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMM\nMMMMMMZZZZNMMMMMMMMMZu;:^^.......^#MMMMMMMMMMMMNZZZZMMMMMMMMMMMMMM\nMMMM#M`   uyNMMMMM##NM?;;;........NMMNMMMMMMMNyZ   `N#MMMMMMMMMMMM\nMMMM#M`   ??#MMMMMMM#Mur;;^^......fbMNMMMMMMMN??   `M#MMMMMMMMMMMM\nMMMMHN=???#MMMMMMMMMNMMN;;::^^......MNMMMMMMMMMN????N#MMMMMMMMMMMM\nMMMMMMNNNNMMMMNNMrMMMMNMvr;:::^....^MMMMrMNMMMMMNNM#MMMMMMMMMMMMMM\nMMMMMMMMMMMMMMHNNN##MMHNMMvt;;;:^^..kmMM#NNHMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMHNMMtttl;:.^??NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M##MNtlltMMMMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMNHMMH##N#######NMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM@@@@@@@@MMMMMMMMMMMMMM@@@@@@@@MMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M`      `gHMNMMMMMMNMH@  `    `N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN^......`..HHMMMMMMHH..........#HMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMM#NNNNNNNNHMMMMMMMMMMH#N##NNNN#MMMMMMMMMMMMMMMMMM");
		sleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHNN#MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNvrrrNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMrtttMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#MMNrt;?NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N==^^.^NM#HMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMM#NMN;;....:;M#MMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMtl^.......MNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMHNNNMNMMMMMMMMMMMMMMMMNM@@gggq.^kgMMNNMMMMMMMMMMMMMMMMNMNNN#MMMM\nHN;:::#MMNMMMMMMMMMMMMHNMM;:::::qk;:::::NHMMMMMMMMMMMMNNM#:::;NHMM\nHM.   :;#MMMMMMMMMMMMMHMMM``ff``MN` pV` MHMMMMMMMMMMMMMN;:   .M@MM\nHM`   VbNMMMMMMMMMMMMMHMMM` ;; `NN` ;; `MHMMMMMMMMMMMMMMby   `MHMM\nMMVVVfNMMMMMMMMMMMMMMMHMzvVVVVVyllVVVVVVMMMMMMMMMMMMMMMMMNfffVMNMM\nMMNMMMMMHMMNMNMMMMMMMMHMqkVyllll..llltMNMMMMMMMMMMNMNNMNMMMMMNMMMM\nMMMMMMMMNMMM#MNNMNMMMMHMMMZZVVVVVVVVVfMNMMMMMMNNNNMNMMMNMMMMMMMMMM\nMMMMMMMMMMMMNMMMNMMMMMHNuu@@gggmggmgggMMMMNMMMMMMMMNMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMNMMMNMNN;;rz@@fVVyVV@@MMMMMNMMMNMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMNNNNNM;;..rz@@@@@@vuMNNNNNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHM;;^^..vuuuuz.^NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHN;;;;.........^NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMyy;;.........^NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMHMMM;;.........^NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNM;;^^........NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMNMZu;:.......^NNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMHNMN;;^^.....^NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#Mzv;:^.....NMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NMMzv;;===tNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMrrNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMNNNNNNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M#HMMMMMMHNMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#NMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMm@@@@@@@MNMMMMMMNM@@@@@@@mMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#MH@`     .^MNMMMMMMNN^.     `@HM#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M........HNNHMMMMMMHNN#........N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHNNN#NNNN#MMMMMMMMMMMMMMNNNNNNNNNHMMMMMMMMMMMMMMMM");
		sleep(sleeptime);
		printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHNNHMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNzvvzNNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMrttrMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN?;trNMNHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#NMN^^^^llMHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM?;....:;MMN#MMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNN......^^trMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMqp^.kkkkggMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N;;;;;;bk;;;;;?NMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#N` Zy `NN `yy `NMMHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMHNMNMNMMMMMMMM#N` ?? `NN` ?? `NMMHMMMMMMMMMMNMNMNNMMMM\nMMMMMMMMMMHN===l#MMNMMMMMMNMZZZZZZttZZZZZZuuMHMMMMMMMMNMM#===lNHMM\nMMMMMMMMMMHM.   ?=NMMMMMMMMMNMrttt..rttrfpbkMHMMMMMMMMMN=?   `MHMM\nMMMMMMMMMMHN.   vuNMMMMMMMMMNMVyyyyyyyyZuZMMMHMMMMMMMMMNuv   .M@MM\nMMMMMMMMMM#NzuuuMMMMMMMMMMMMMM@gggggggg@@@ZZMHMMMMMMMMMMMNuuuuNHMM\nMMMMMMMMMMMM#NNMNNMMuMMMMMMMNM@@VVVVVf@@uz;;MHMMMMMMMuMNMNMNMNMMMM\nMMMMMMMMMMMMMMMMMMNMNMMMMMMMNMZu@@@@@guz..;;NHMMMMMMMNM#MMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMM#NNMNMMMMN^.uZuZZu..^^;;M#NMNMMNN#MMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMM#MMNMNMM^.........;;ZyMNMMMNMNMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNN^.........;?NMNHMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM^.......^^:?NNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN^.......:;uuMNMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM^......^:;MNN#MMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNN^....^;;rzMHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM=???;;rrMMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMNrrMMMNMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMM#M#HMMMMMMMMH#MHMMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMM#MMMMMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMMMMMm@@@@@MNMMMMMMMMMMMM@@@@@mMMMMMMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#MH@`    `@HMNMMMMMMNMH@     `@HM#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMM#M^`.....`..HHMMMMMMHH..........N#MMMMMMMMMMMMMMMM\nMMMMMMMMMMMMMMMMHN#NNNNNNNNHMMMMMMMMMMH##NNNNNNNNHMMMMMMMMMMMMMMMM");
		sleep(sleeptime);
	}
	return true;
}
int main() {
	bool weitermachen = true;
	while (weitermachen)
	{
		printf("===========Hallo Welt!===========\n\nSie k�nnen Funktionen ausf�hren. Einfach die Zahl eingeben.\nWenn sie beenden m�chten, einfach ne andere Zahl eingeben.\n\n");
		printf("1 Aufgabe R1\n2 Snake\n3 testfkt\n4 GIF\n5 L6\n6 I2\n");
		int auswahl;
		// scanf_s("%d", &auswahl);
		scanf("%d", &auswahl);
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
			weitermachen = I2();
			break;
		default:
			weitermachen = false;
			break;
		}
	}

}
