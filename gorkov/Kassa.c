#include "stdio.h"
#define MAX_NUMS 5
#include "stdbool.h"

int n = MAX_NUMS;

int i, kol, j = 0, z, st, dis, alldis, allprice, t = 0, pos = 0, k = 0, Qr;

int Sh[MAX_NUMS] = { 1111, 2222, 3333, 4444, 5555 };
int Price[MAX_NUMS] = { 100, 200, 300, 400, 500 };
int Disc[MAX_NUMS] = { 5, 8, 10, 15 , 3 };
int Count[MAX_NUMS], Pos[MAX_NUMS], NewQr[MAX_NUMS], x[MAX_NUMS];

void Menu()
{
	printf("1 - all products\n");
	printf("2 - scan product\n");
	printf("3 - print information of scanned products\n");
	printf("4 - print Total\n");
	printf("5 - print check\n");
	printf("6 - end\n");
}
void ListProd() {
	for (i = 0; i < n; i++)
	{
		printf("Sh=%d Price=%d Disc=%d\n", NewQr[i], Price[Pos[i]], Disc[Pos[i]]);
	}
}
void ScanPr()
{
	Qr = 0;
	printf("Enter sh and count\nEnter 10 to stop scan\n");
	while ((pos < 10) && (Qr != 10)) {
		scanf_s("%d", &Qr);
		if (Qr == 10) kol = -1;
		if (Qr != 10) scanf_s(" %d", &kol);
		k = 0;
		z = 0;
		for (i = 0; i < n; i++) {
			if (kol == 0) {
				printf("Entered 0 count\n");
				z++;
				break;
			}
			if (Qr == Sh[i]) {
				k++;
				NewQr[j] = Qr;
				Count[j] += kol;
				Pos[j] = i;
				j++;
			}
		}
		if (Qr == 10) { k = 1; printf("End of scan\n"); }
		if ((k == 0) && (z == 0)) printf("product out of list\n");
		pos++;

	}

}

void PrintCh()
{
	for (i = 0; i < n; i++) {
		if (Count[i] != 0) {
			dis = (Count[i] * Price[Pos[i]] * Disc[Pos[i]]) / 100;
			alldis += dis;
			st = (Count[i] * Price[Pos[i]]) - dis;
			allprice += st;
			printf("Pr.%d %d  %d*%d st=%d\n                   -%d\n", i + 1, NewQr[i], Price[Pos[i]], Count[i], st, dis);
		}
	}
	printf("\n\nDisc.=  %d\nTotal:    %d\n", alldis, allprice);
	allprice = 0;
	alldis = 0;
}
void Total()
{//same what in Check witout print
	for (i = 0; i < n; i++) {
		if (Count[i] != 0) {
			dis = (Count[i] * Price[i] * Disc[i]) / 100;
			alldis += dis;
			st = (Count[i] * Price[i]) - dis;
			allprice += st;
		}
	}
	printf("Total=%d\n", allprice);
	allprice = 0;
	alldis = 0;
}
void PrintMass(int x[]) {
	for (i = 0; i < n; i++)
	{
		printf("%d",x[i]);
	}
}
void PrintInf()
{
	i = 0;
	while (NewQr[i] != 0)

	{
		printf("%d price=%d dis=%d\n", NewQr[i], Price[Pos[i]], Disc[Pos[i]]);
		i++;
	}
	
	if (NewQr[0] == 0)printf("There is no scanned products\n");
}

int main()
{
	printf("Enter <0> to Menu\n");
	int choise;
	bool run = true;
	while (run) {
		scanf_s("%d", &choise);
		switch (choise)
		{
		case 0:
			Menu();
			break;
		case 1:
			ListProd();
			break;
		case 2:
			ScanPr();
			break;
		case 3:
			PrintInf();
			break;
		case 4:
			Total();
			break;
		case 5:
			PrintCh();
			break;
		case 6:
			printf("Thank you");
			run = false;
			break;
		case 7:
			PrintMass(NewQr);
			printf("\n");
			PrintMass(Count);
			printf("\n");
			PrintMass(Pos);
			break;
		default:
			printf("unknown operation --> tab <0> to Menu\n");
		}

	}
	return 0;
}
