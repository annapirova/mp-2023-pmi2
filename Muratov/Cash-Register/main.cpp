#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include "Cash_Register.h"
#include "Check.h"
using namespace std;


int main() {
	setlocale(LC_CTYPE, "Rus");
	Cash_Register Cash;
	Check C;
	std::string input_file, output_file;
	input_file = "zakaz.txt";
	output_file = "check.txt";
	Cash.Delete_Product("Egg");
	File_Input(input_file, &Cash, &C);
	C.File_Output(output_file, &C, &Cash);
}
