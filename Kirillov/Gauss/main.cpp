#include "gauss.h"

int main() {

    Matrix A(3, 3);
    std::cout << "Enter the elements of the matrix A (3x3):" << std::endl;
    std::cin >> A;


    Vector b(3);
    std::cout << "Enter the elements of the vector b (size 3):" << std::endl;
    std::cin >> b;

    Gauss gauss(A,b);
    std::cout << "Original matrix A:" << std::endl;
    std::cout << A << std::endl;

    //cout << "answer vector:" << endl;
    //cout << gauss.getAnswer2() << endl;
    gauss.transformToUpperTriangular();
    std::cout << "Matrix A after transforming to upper triangular form:" << std::endl;
    std::cout << gauss.getMCopy() << std::endl;
    
    
    std::cout << "Modified solution vector:" << std::endl;
    std::cout << gauss.getAnswer2() << std::endl;

    gauss.solve();


    Vector answer = gauss.getAnswer();


    std::cout << "Solution vector:\n" << answer << std::endl;

    return 0;
}