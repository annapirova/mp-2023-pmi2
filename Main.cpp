//#include <iostream>
#include "Class.h"


int main() {
	Field f(8, 8);
	f.FieldZeroFill();
	f.fieldOut();
	f.FieldPlayerFill();
	f.fieldOut();
	return 0;
}