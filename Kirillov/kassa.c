#include "stdio.h"
#include <stdbool.h>

unsigned int globalBarcode = 1000;


struct Product
{
	char name[50];
	char description[200];
	int price;
	unsigned int discount;
	unsigned int barcode;


	int count;
};
struct Product store[5];

struct Receipt 
{
	struct Product products[100];
	int itemCount;
};

struct Receipt addToReceipt(struct Receipt myreceipt, struct Product myproduct) {
	int index = productIndex(myreceipt, myproduct);
	if (index != -1) {
		myreceipt.products[index].count += 1;
	}
	else myreceipt.products[myreceipt.itemCount++] = myproduct;
	return myreceipt;
}

int productIndex(struct Receipt myreceipt, struct Product myproduct) {
	for (int i = 0; i < myreceipt.itemCount; i++) {
		if (myreceipt.products[i].barcode == myproduct.barcode) {
			return i;
		}
	}
	return -1;
}

void printProduct(struct Product p) {
	printf("\nName: %s\n", p.name);
	printf("Description: %s\n", p.description);
	printf("price: %d\n", p.price);
	printf("discount: %d\n", p.discount);
	printf("barcode: %d\n\n", p.barcode);
}
void printReceipt(struct Receipt receipt) {
	for (int i = 0; i < receipt.itemCount; i++) {
		printf("\nName: %s\n", receipt.products[i].name);
		printf("price: %d * %d\n", receipt.products[i].price * (100 - receipt.products[i].discount) / 100, receipt.products[i].count);

	}
}

bool checkProduct(unsigned int brcode) {
	for (int i = 0;i < 5;i++) {
		if (store[i].barcode == brcode) {
			
			return true;
		}

	}
	return false;
}


void createStore() {
	

	

	strcpy(store[0].name, "milk");
	strcpy(store[0].description, "1 l , 2.5% fat ");
	store[0].price = 100;
	store[0].discount = 30;
	store[0].barcode = globalBarcode++;
	store[0].count = 1;

	printProduct(store[0]);


	

	strcpy(store[1].name, "bread");
	strcpy(store[1].description, "description for bread");
	store[1].price = 25;
	store[1].discount = 20;
	store[1].barcode = globalBarcode++;
	store[1].count = 1;

	printProduct(store[1]);

	strcpy(store[2].name, "juice");
	strcpy(store[2].description, "description for juice");
	store[2].price = 100;
	store[2].discount = 20;
	store[2].barcode = globalBarcode++;
	store[2].count = 1;

	printProduct(store[2]);

	strcpy(store[3].name, "pasta");
	strcpy(store[3].description, "description for pasta");
	store[3].price = 110;
	store[3].discount = 0;
	store[3].barcode = globalBarcode++;
	store[3].count = 1;

	printProduct(store[3]);

	strcpy(store[4].name, "chocolate");
	strcpy(store[4].description, "description for chocolate");
	store[4].price = 50;
	store[4].discount = 20;
	store[4].barcode = globalBarcode++;
	store[4].count = 1;

	printProduct(store[4]);
}

void findByBarcode(unsigned int brcode) {
	for (int i = 0;i < 5;i++) {
		if (store[i].barcode == brcode) {
			printProduct(store[i]);
			return;
		}

	}
	printf("Product #%d didn't find\n", brcode);
}

struct Product returnByBarcode(unsigned int brcode) {
	for (int i = 0;i < 5;i++) {
		if (store[i].barcode == brcode) {
			return store[i];
		}

	}
	printf("Product #%d didn't find\n", brcode);
	
}

void addReceiptToArray(struct Receipt myR,int rba[],int cpa[]) {
	int counter = 0;
	for (int i = 0;i < myR.itemCount;i++) {
		rba[i] = myR.products[i].barcode;
		cpa[i] = myR.products[i].count;
		
	}
	
}
void receiptSum(int rba[], int cpa[], struct Product str[],struct Receipt myR) {
	int result = 0;
	for (int i = 0;i < myR.itemCount;i++) {
		result += ((returnByBarcode(rba[i]).price * (100 - returnByBarcode(rba[i]).discount)) / 100) * cpa[i];
	}
	printf("Sum: %d \n", result);
}



int main() {
	int userbrcode;
	createStore();
	int k = 0;
	int receiptBarcodeArray[5], countProductsArray[5];

	struct Receipt myReceipt;
	myReceipt.itemCount = 0;
	int operation;
	printf("Enter 1 to scan barcode,2 to get product info,3 to add item to receipt ,4 generate a purchase receipt,5 to get sum of receipt\n");
	printf("Enter any number to close the purchase: ");
	do
	{
		printf("Select the command: ");
		scanf_s("%d", &operation);
		switch (operation)
		{
		case 1: 
			printf("Scan barcode for find: ");
			scanf_s("%d", &userbrcode);
			if (checkProduct(userbrcode) == 0) { 
				printf("Product #%d didn't find\n", userbrcode); 
			}
			break;
			

		case 2: 
			if (checkProduct(userbrcode)) { 
				findByBarcode(userbrcode); 
			}
			break;
			
			
			
		case 3: 
			myReceipt = addToReceipt(myReceipt, returnByBarcode(userbrcode));
			printf("Product was added successfully \n");
			break;
			

		case 4: 
			printf("\nAll list of products: \n");
			printReceipt(myReceipt);
			break;
			
			
		case 5:
			addReceiptToArray(myReceipt, receiptBarcodeArray, countProductsArray );
			receiptSum(receiptBarcodeArray,countProductsArray, store, myReceipt); 
			break;
			
		
		}

	} while ((operation>0)&&(operation<6));
	
	return 0;

}