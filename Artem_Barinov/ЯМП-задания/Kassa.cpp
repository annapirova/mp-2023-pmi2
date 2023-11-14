#include <stdio.h>
#include <stdlib.h>

int ID[10] = { 10, 29, 38, 47, 56, 65, 74, 83, 92, 11 };
int price[10] = { 39 , 85 , 23 , 22, 116 , 54 , 100 , 22 , 105 , 45 };
int sasalele[10] = { 10, 10, 0, 0, 30, 5, 40, 0, 5, 0 }; // eto skidka
int quantity[10] = { 0 }; // a eto colitestvo

void commands() {
	printf("\nCommands: \n");
	printf("a) Prodact menu: '1'\n");
	printf("b) Add a product: '2'. After that, you should enter an ID of product (1-10)\n");
	printf("c) My prodact list: '3'\n");
	printf("d) Information about product: '4'. After that, you should enter an ID of product (1-10)\n");
	printf("e) All commands menu: '5'\n");
	printf("f) Cheque and exit: '0'\n");
}
void products() {
	printf("\nProducts (id and name):\n");
	printf("1 - Coca-cola;\n");
	printf("2 - Coconuts;\n");
	printf("3 - Dragon fruit;\n");
	printf("4 - Farm apples;\n");
	printf("5 - Fresh berries of cherry;\n");
	printf("6 - Fresh berries of strawberry;\n");
	printf("7 - Fresh tomatoes;\n");
	printf("8 - Mango;\n");
	printf("9 - Pepsi;\n");
	printf("10 - Water (non - carbonated);\n");
}
void prodListDop(int id) { // opredelenie tovara po id i vivod
	switch (id) {
	case 0: printf("Coca-cola: "); break;
	case 1: printf("Coconuts: "); break;
	case 2: printf("Dragon fruit: "); break;
	case 3: printf("Farm apples: "); break;
	case 4: printf("Fresh berries of cherry: "); break;
	case 5: printf("Fresh berries of strawberry: "); break;
	case 6: printf("Fresh tomatoes: "); break;
	case 7: printf("Mango: "); break;
	case 8: printf("Pepsi: ");	break;
	case 9: printf("Water (non - carbonated): "); break;
	}
}
int proverka(int min, int max, char ch) { // proverka vvoda id ili colitestva productov
	int value;
	do {
		if (scanf_s("%d", &value) != 1) {
			if (ch == 'p') {
				printf("\nInvalid character: ID must be in the range from 1 to 10 inclusive!\nNot a string or literal!\nTry again!\n");
				printf("ID of product: ");
			}
			if (ch == 'q') {
				printf("\nInvalid character: quantity of products must be a number!\nNot a string or literal!\nTry again!\n");
				printf("Quantity of product: ");
			}
			if (ch == 'c') {
				printf("Invalid character: command must be a number from 0 to 5!\nTry again!\n");
				printf("ID of command: ");
			}
			rewind(stdin);
			continue;
		}
		if (value >= min && value <= max)
			return value;
		else
			printf("The value is out of range! Try again: ");
	} while (max);
}
void prodInf() {
	printf("Enter an ID of product: ");
	int id = proverka(0, 10, 'p');
	if (id)
		printf("\nName: ");
	switch (id) {
	case 1: printf("Coca-cola;"); break;
	case 2: printf("Coconuts;"); break;
	case 3: printf("Dragon fruit;"); break;
	case 4: printf("Farm apples;"); break;
	case 5: printf("Fresh berries of cherry;"); break;
	case 6: printf("Fresh berries of strawberry;"); break;
	case 7: printf("Fresh tomatoes;"); break;
	case 8: printf("Mango;"); break;
	case 9: printf("Pepsi;");	break;
	case 10: printf("Water (non - carbonated);"); break;
	}
	printf("\nID: %d;\nPrice: %d;\nSale: %d percent;\n", id, price[id - 1], sasalele[id - 1]);
}
void prodList() { // ves` chek: sena tovara, ego tip i kolisestvo
	double itog = 0;
	printf("\nYour cheque:\n");
	for (int id = 0; id < 10; id++)
		if (quantity[id] != 0) {
			prodListDop(id);
			double priceWithSale = quantity[id] * price[id] * (sasalele[id] != 0 ? (price[id] - sasalele[id] * 0.01) : 1);
			printf("%d; Price - %.2lf;\n", quantity[id], priceWithSale);
			itog += priceWithSale;
		}
	printf("Total: %.2lf\n", itog);
}
void bue() { // sostovlenie cheka
	int pr = -1;
	do {
		printf("\nEnter the ID of product or '0' for cheque: ");
		pr = proverka(0, 10, 'p');
		int col;
		if (pr != 0) {
			printf("Quantity: "); col = proverka(0, 1000, 'q'); // colitestvo tovara	
			quantity[pr - 1] += col;
		}
	} while (pr != 0);
}
char shop() { // magazin
	int com;
	commands();
	do {
		printf("\nPlease, enter a command: ");
		com = proverka(0, 5, 'c');
		if (com == 1) products(); // +
		if (com == 2) bue();		// +
		if (com == 3) prodList(); // +
		if (com == 4) prodInf(); //
		if (com == 5) commands(); // +
		else
			rewind(stdin);
	} while (com != 0);
	return 0;
}
int main() {
	printf("Welcome to the shop!\n");
	int ch;
	int flag = 0;
	do {
		printf("Action menu:\n");
		printf("1. Shop menu: '1'\n");
		printf("2. Exit: '0'\n");
		printf("command: ");
		scanf_s("%d", &ch); // vvod deistvia
		if (ch == 1)
			ch = shop();
		if (ch == 0) {
			printf("We hope to see you again!\n");
			return 0;
		}
		else {
			printf("Wrong simbol! Try again!\n\n");
			rewind(stdin);
			flag = 1;
		}
	} while (flag); // vvod do teh por poka ne poluchim klutivie komandi: e / p
	return 0;
}