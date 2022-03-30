
#include "class.h"
#include "class_0.h"
#include "functions.h"
#include "operators.h"
#include "AT.h"

int main()
{
    if (AT() == 0) {
        cout << "Autotest failled!\n\n";
    }
    if (AT() == 1) {
        cout << "Autotest passed!\n\n";
    }

    int mode;
    int dim;
    std::cout << "Enter dimension:\n";
    std::cin >> dim;
    std::cout << "Read one vector and output:\n to the console - 1\n in file - 2\n"<< endl;
    std::cout << "Read array of vectors - 3\n\n";
    std::cout << "Arithmetic with vectors - 4\n\n\n";
    std::cin >> mode;
    if (mode == 1) {
        char name[20];
        std::cout << "Enter name of file\n";
        std::cin >> name;
        create_CCV(name, dim);
    }
    else if (mode == 2) {
        char name[20];
        std::cout << "Enter name of file\n";
        std::cin >> name;
        create_CCV_and_fout(name, dim);
    }
    else if (mode == 3) {
        CCompexVector** arr;
        char name[20];
        std::cout << "Enter name of file\n";
        std::cin >> name;
      //  create_CCV_and_fout(name, dim);
        arr = fscan_data_and_output(name, dim);
        delete[] arr;
    }
    else if (mode == 4) {
        CCompexVector** arr;
        CCompexVector1 A(dim);
        ComplexNumber a;
        char name[20];
        std::cout << "Enter name of file with two vectors\n";
        std::cin >> name;
        arr = fscan_data(name, dim);
        A += *arr[0];
        A += *arr[1];
        A.output();
        A -= *arr[1];
        A -= *arr[1];
        A.output();
        a = (*arr[0]) * (*arr[1]);
        a.file_otput(arr[0]->get_foutput());
    }
    else {
        cout << "Incorrect nuber\n";
    }

  
    return 1;
}
