#include <iostream>
#include "Matrix.hpp"
#include "MatrixOperations.hpp"

int main(int argc, char *argv[]) {
	int m1Lines, m1Columns, m2Lines, m2Columns, mod;

	if (argc == 6) {
		try {
			m1Lines = std::stoi(argv[1]);
			m1Columns = std::stoi(argv[2]);
			m2Lines = std::stoi(argv[3]);
			m2Columns = std::stoi(argv[4]);
			mod = std::stoi(argv[5]);
		} catch (std::runtime_error &e) {
			throw std::runtime_error(std::string("Please enter valid numbers "
															 "in the parameters.\n") +
											 e.what());
		} catch (std::out_of_range &e) {
			throw std::runtime_error("Please enter parameters between 0 (or 1 for "
											 "modulo) and 2147483647.\n");
		}
	} else throw std::runtime_error("Please enter 5 parameters.\n");

	// Basic test
	printf("The modulus is %u\n\n", mod);

	Matrix m1Basic(m1Lines, m1Columns, mod);
	Matrix m2Basic(m2Lines, m2Columns, mod);
	std::cout << "one" << "\n" << m1Basic << "\n";
	std::cout << "two" << "\n" << m2Basic << "\n";
	std::cout << "one + two" << "\n" << addStatic(m1Basic, m2Basic) << "\n";
	std::cout << "one - two" << "\n" << subtractStatic(m1Basic, m2Basic) << "\n";
	std::cout << "one * two" << "\n" << multiplyStatic(m1Basic, m2Basic) << "\n\n";



	// Advanced test
    std::cout << "======== ADVANCED TEST PROGRAM ========\n\n";
    printf("The modulus is %u\n\n", mod);

    {
        std::cout << "======== RULES OF FIVE ========\n\n";
        std::cout << "----- Constructor with random values & Flux operator -----\n";
        Matrix m1(m1Lines, m1Columns, mod);
        Matrix m2(m2Lines, m2Columns, mod);
        std::cout << "Matrix m1 address: " << &m1 << "\n";
        std::cout << "m1 \n" << m1 << "\n";
        std::cout << "Matrix m2 address: " << &m2 << "\n";
        std::cout << "m2 \n" << m2 << "\n";

        std::cout << "----- Duplication par constructeur -----\n";
        Matrix m1Copy(m1);
        std::cout << "original \n" << m1 << "\n";
        std::cout << "copy \n" << m1Copy << "\n";

        std::cout << "----- Duplication par assignation -----\n";
        Matrix m2Copy = m2;
        std::cout << "original \n" << m2 << "\n";
        std::cout << "copy \n" << m2Copy << "\n";

        std::cout << "----- Deplacement par constructeur -----\n";
        Matrix m1Move(std::move(m1));
        std::cout << "original \n" << m1; // Note: m1 est valide mais indéterminée
        std::cout << "move \n" << m1Move << "\n";

        std::cout << "----- Deplacement par assignation -----\n";
        Matrix m2Move = std::move(m2);
        std::cout << "original \n" << m2; // Note: m2 est valide mais indéterminée
        std::cout << "move \n" << m2Move << "\n";
    }

    {
        Matrix m1Add(m1Lines, m1Columns, mod);
        Matrix m2Add(m2Lines, m2Columns, mod);
        Matrix m1Sub = m1Add;
        Matrix m2Sub = m2Add;
        Matrix m1Mul = m1Add;
        Matrix m2Mul = m2Add;

        std::cout << "\n======== OPERATOR MATHEMATIC ========\n\n";
        std::cout << "m1 \n" << m1Add << "\n";
        std::cout << "m2 \n" << m2Add << "\n";

		 std::cout << "Matrix m1 address: " << &m1Add << "\n";
		 std::cout << "Matrix m2 address: " << &m2Add << "\n\n";

        std::cout << "----- Addition -----\n";

        Matrix m3Add = addStatic(m1Add, m2Add);
        std::cout << "Matrix m3 address: " << &m3Add << "\n";
        std::cout << "Addition static : m3 = m1 + m2\n" << m3Add << "\n";

        Matrix* m4Add = addDynamic(m1Add, m2Add);
        std::cout << "Matrix m4 address: " << m4Add << "\n";
        std::cout << "Addition dynamic : m4 = m1 + m2\n" << *m4Add << "\n";
        delete m4Add;

        std::cout << "Method addItself : m1 += m2 \n" <<
		  					m1Add.addItself(m2Add) << "\n";


        std::cout << "----- Subtraction -----\n";

        Matrix m3Sub = subtractStatic(m1Sub, m2Sub);
        std::cout << "Matrix m3 address: " << &m3Sub << "\n";
        std::cout << "Subtraction static : m3 = m1 - m2\n" << m3Sub << "\n";

        Matrix* m4Sub = subtractDynamic(m1Sub, m2Sub);
        std::cout << "Matrix m4 address: " << m4Sub << "\n";
        std::cout << "Subtraction dynamic : m4 = m1 - m2'\n" << *m4Sub << "\n\n";
        delete m4Sub;

        std::cout << "Method subtractItself : m1 -= m2\n" <<
		  				m1Sub.subtractItself(m2Sub) << "\n\n";


        std::cout << "----- Multiplication -----\n";

        Matrix m3Mul = multiplyStatic( m1Mul, m2Mul);
        std::cout << "Matrix m3 address: " << &m3Mul << "\n";
        std::cout << "Multiplication static : m3 = m1 * m2\n" << m3Mul << "\n";

        Matrix* m4Mul = multiplyDynamic( m1Mul, m2Mul);
        std::cout << "Matrix m4 address: " << m4Mul << "\n";
        std::cout << "Multiplication dynamic : m4 = m1 * m2\n" << *m4Mul << "\n\n";
        delete m4Mul;

        std::cout << "Method multiplyItself : m1 *= m2\n" <<
		  				m1Mul.multiplyItself(m2Mul) << "\n";

		 std::cout << "\nMatrix with size of 0" << "\n";
		 Matrix m0(0, 0, mod);
		 std::cout << "Matrix of 0x0 : \n" << m0 << "\n";

    }

	{
		std::cout << "\n======== ERROR ========\n\n";

		//std::cout << "Matrix with different dimensions" << "\n";

		std::cout << "Please, uncomment errors to see the result in this part.\n";

		std::cout << "\nMatrix with null or negative size" << "\n";
		//Matrix m1(-1, m1Columns, mod);
		//Matrix m2(m1Lines, -1, mod);

		std::cout << "\nMatrix with null or negative modulo" << "\n";
		//Matrix m3(m1Lines, m1Columns, 0);
		//Matrix m4(m1Lines, m1Columns, -1);

		std::cout << "\nMatrix with two different modulos" << "\n";
		//Matrix m5(m1Lines, m1Columns, mod);
		//Matrix m6(m2Lines, m2Columns, mod + 1);
		//std::cout << "m5 + m6 \n" << m5.addItself(m6) << "\n";
	}

	std::cout << "\nPlease check with different size of matrix and modulo.\n\n";
	std::cout << "======== END OF TEST PROGRAM ========\n\n";


	return 0;
}
