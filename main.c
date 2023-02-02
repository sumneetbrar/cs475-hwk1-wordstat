/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

#define max 20

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	// declare and initialize the histogram
	//int histogram[ALPHABET_SIZE];

	int vowels = 0;
	int consonants = 0;
	char string[max];
	char curStr[max];
	int loop = 0;
	int menu = 0;
	
	// TODO: start by getting strings from users until # is input
restart:

	printf("Enter a string and enter '#' when you are done inputting: ");
	while (curStr[loop] != '#') {
		fgets(curStr, max, stdin);
		strcat(string, curStr);
	}

	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
		string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
			vowels++;
		}
		else if (string[i] >= 'A' &&  string[i] <= 'z') {
			consonants++;
		}
	}

	int total = vowels + consonants;
	double percentV = vowels/consonants;
	float percentC = ((consonants/total)*100);

	// TODO: after # is input, print menu options

	while (menu != 4) {
		printf("**** WORD STATS MENU ****\n");
		printf("Enter 1 to print vowel and consonant frequency.\n");
		printf("Enter 2 to print histogram.\n");
		printf("Enter 3 to return to inputting more strings.\n");
		printf("Enter 4 to quit.\n");
		scanf("%d", &menu);

		if (menu == 1) {
			printf("Vowels = %d (%f), Consonants = %d (%f), Total = %d\n", vowels, percentV, consonants, percentC, total);
		};

		if (menu == 2) {
			
		};

		if (menu == 3) {
			goto restart;
		}

		if (menu == 4) {
			printf("Exiting...\n");
			return 0;
		};
	}
}
