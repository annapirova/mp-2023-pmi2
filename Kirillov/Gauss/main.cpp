#include "gauss.h"

int main() {
    Matrix A(3, 3);
    A.Generate(10.0,50.0);
    /*std::cout << "Enter the elements of the matrix A (3x3):" << std::endl;
    std::cin >> A;*/

    Vector b(3);
    b.Generate(10.0, 50.0);
    /*std::cout << "Enter the elements of the vector b (size 3):" << std::endl;
    std::cin >> b;*/

    Gauss gauss(A, b);
    std::cout << "Original matrix A:" << std::endl;
    std::cout << A << std::endl;

    std::cout << "Modified solution vector:" << std::endl;
    std::cout << gauss.getAnswer2() << std::endl;

    gauss.solve();

    Vector answer = gauss.getAnswer();

    std::cout << "Solution vector:\n" << answer << std::endl;
    double accuracy;
    std::cout << "Enter accuracy answer:";
    std::cin >> accuracy;
    if (gauss.Check(b, accuracy) == 1) {
        cout << endl << "Answer within the specified accuracy";
    }
    else { cout << endl << "The answer is not within the specified accuracy"; }
    return 0;
}
