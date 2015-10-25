//including the basic libs
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
//defining the functions
int menu();
void wuerf();
void zahlenraten();
void wurfel(int a);
//main loop
int main(void) {
	LOOP:do {
		int z;
		z = menu();
		switch(z) {
		case 1:
			wuerf();
			goto LOOP;
		case 2:
			zahlenraten();
			goto LOOP;
		case 3:
			goto END;
		default:
			printf("WHAT\n");
		}

	}while(1);
	END: return 0;
}

int menu() {
	int out;
	printf("--------------------------------------\n");
	printf("--------------Optionen----------------\n");
	printf("--1: Würfeln 2:Zahlen Raten 3:Ende----\n");
	printf("--------------------------------------\n");
	printf("--------------------------------------\n");
	printf("--------------------------------------\n");
	scanf("%i", &out);
	printf("\e[1;1H\e[2J");
	return out;
}

void wuerf() {
	int z;
	z = rand() % 6;
	z++;
	printf("\e[1;1H\e[2J");
	wurfel(z);
	getchar();
}
void zahlenraten() {
	int z,t,v;
	z = rand() % 100;
	for(t=35;t > 0;t--){
		printf("Gib einen vorschlag! Doch hasst noch %i versuche\n", t);
		scanf("%i",&v);
		if (v==z){
			printf("\e[1;1H\e[2J");
			printf("Korekt: Nice one! Du hasst nur %i versuche gebraucht\n", 35 - t);
			goto P;
		} else if (v>z) {
			printf("Zu  gross!\n");
		} else {
			printf("ZU klein\n");
		}
	}
	printf("\e[1;1H\e[2J");
	printf("Nice try:");
 P:getchar();
}
void wurfel(int a) {
	char z[7] = {"-------"};
	switch(a) {
	case 1:
		z[3] = "o"; break;
	case 2:
		z[0] = "o"; z[6] = "o"; break;
	case 3:
		z[0] = "o"; z[6] = "o"; z[3]= "o"; break;
	case 4:
		z[0] = "o"; z[6] = "o"; z[1]= "o"; z[5]= "o"; break;
	case 5:
		z[0] = "o"; z[6] = "o"; z[1]= "o"; z[5]= "o"; z[3] = "o"; break;
	case 6:
		z[0] = "o"; z[6] = "o"; z[1]= "o"; z[5]= "o"; z[2] = "o"; z[4] = "o"; break;
	}
	printf("--------------------------------------\n");
	printf("----------_______---------------------\n");
	printf("---------|%c-----%c|--------------------\n", z[0], z[1]);
	printf("---------|%c--%c--%c|--------------------\n",z[2], z[3], z[4]);
	printf("---------|%c-----%c|--------------------\n", z[5], z[6]);
	printf("---------|_______|--------------------\n");
	printf("--------------------------------------\n");


}
