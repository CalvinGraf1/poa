/*
 -----------------------------------------------------------------------------------
 Nom du fichier : Matrix.cpp
 Auteur(s)      : Demont Kilian et Graf Calvin
 Date creation  : 29.02.2024

 Description    : Définition de la classe Matrix et des méthodes associées
                  pour modéliser son comportement.

 Compilateur    : Mingw-w64 gcc 13.2.0
 -----------------------------------------------------------------------------------
*/

#include "Matrix.hpp"
#include "Utils.hpp"

#include <random>
#include <ostream>
#include <utility>

Matrix::Matrix(int rows, int columns, int modulo) {
    checkValuesIntegrity(rows, columns, modulo);

   this->rows = rows;
	this->columns = columns;
	this->modulo = modulo;

	// Allocation de la mémoire pour le tableau de tableau
	values = new int *[rows];
	for (int i = 0; i < rows; ++i) values[i] = new int[columns];

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, modulo - 1);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			values[i][j] = distrib(gen);
		}
	}
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), columns(other.columns),
												  modulo(other.modulo) {
	values = new int *[rows];

	for (int i = 0; i < rows; ++i) {
		values[i] = new int[columns];
		std::copy(other.values[i], other.values[i] + columns, values[i]);
	}

}

Matrix::Matrix(Matrix &&other) noexcept:
        values(std::exchange(other.values, nullptr)),
        rows(std::exchange(other.rows, 0)),
        columns(std::exchange(other.columns, 0)),
        modulo(std::exchange(other.modulo, 0))
{ }

Matrix::~Matrix() {
	freeMemory();
}

void Matrix::freeMemory() {
	if (values != nullptr) {
		for (int i = 0; i < rows; ++i) {
			delete[] values[i];
		}
		delete[] values;
		values = nullptr;
	}
}

Matrix& Matrix::operator=(const Matrix &other) {
	if (this != &other) {
		freeMemory();

        rows = other.rows;
		columns = other.columns;
		modulo = other.modulo;

		values = new int *[rows];
		for (int i = 0; i < rows; ++i) {
			values[i] = new int[columns];
			for (int j = 0; j < columns; ++j) values[i][j] = other.values[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator=(Matrix &&other) noexcept {
	if(this == &other) return *this;

	// Il faut peut-être factoriser car utilisé 3-4 fois
	// Libérer les ressources existantes
	freeMemory();

	// Appropriation des valeurs
	this->values = other.values;
    this->rows = other.rows = 0;
	this->columns = other.columns;
	this->modulo = other.modulo;

	// S'assurer qu'on laisse "other" dans un état valide
	other.values = nullptr;
	other.rows = 0;
	other.columns = 0;
	other.modulo = 0;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	for (int i = 0; i < matrix.rows; ++i) {
		for (int j = 0; j < matrix.columns; ++j)
			os << std::to_string(matrix.values[i][j]) << " ";
		os << "\n";
	}
	return os;
}


Matrix& Matrix::addItself(const Matrix &other) {
    performOperation(other, MatrixAddition());

    return *this;
}

Matrix &Matrix::subtractItself(const Matrix &other) {
    performOperation(other, MatrixSubtraction());

    return *this;
}

Matrix &Matrix::multiplyItself(const Matrix &other) {
    performOperation(other, MatrixMultiplication());

    return *this;
}

void Matrix::checkMatrixDimensions(const Matrix &other) const {
    if (modulo != other.modulo) throw std::invalid_argument("Two modulos"
											" don't match.");
}

void Matrix::checkValuesIntegrity(const int &m, const int &n, const int &mod) const {
    if (m < 0 || n < 0) throw std::runtime_error(std::string("Matrix size"
								  " must be positive and non-null.\n"));

    if (mod <= 0) throw std::runtime_error(std::string("Modulo must"
						 " be positive and non-null.\n"));
}


void Matrix::performOperation(const Matrix &other, const MatrixOperation &operation) {
    checkMatrixDimensions(other);

    // Sauvegarde des dimensions de la matrice courante
    int currentRows = rows;
    int currentColumns = columns;

    // Calcul des nouvelles dimensions de la matrice résultante
    int newRows = std::max(rows, other.rows);
    int newColumns = std::max(columns, other.columns);

    // Allocation de mémoire pour la nouvelle matrice résultante
    int **newValues = new int *[newRows];
    for (int i = 0; i < newRows; ++i) {
        newValues[i] = new int[newColumns];
    }

    // Initialisation des valeurs à 0
    for (int i = 0; i < newRows; ++i) {
        for (int j = 0; j < newColumns; ++j) {
            newValues[i][j] = 0;
        }
    }

    // Copie des valeurs de la matrice courante dans la nouvelle matrice résultante
    for (int i = 0; i < currentRows; ++i) {
        for (int j = 0; j < currentColumns; ++j) {
            newValues[i][j] = values[i][j];
        }
    }

    // Application de l'opération avec les valeurs de la matrice 'other'
    for (int i = 0; i < other.rows; ++i) {
        for (int j = 0; j < other.columns; ++j) {
            newValues[i][j] = mathModulo(operation.perform(getValue(i,j), other.getValue(i,j)), modulo);
        }
    }

    // Suppression de l'ancien contenu et mise à jour des attributs
    freeMemory();

    rows = newRows;
    columns = newColumns;
    values = newValues;
}

int Matrix::getValue(int row, int col) const{
    if(row >= this->rows || col >= this->columns){
        return 0;
    }
    return values[row][col];
}

int Matrix::MatrixAddition::perform(int a, int b) const {
    return (a + b);
}

int Matrix::MatrixSubtraction::perform(int a, int b) const {
    return (a - b);
}

int Matrix::MatrixMultiplication::perform(int a, int b) const {
    return (a * b);
}


