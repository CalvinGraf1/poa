/*
 -----------------------------------------------------------------------------------
 Nom du fichier : MatrixOperations.cpp
 Auteur(s)      : Demont Kilian et Graf Calvin
 Date creation  : 20.03.2024

 Description    : Définition des opérations sur les matrices, telles que l'addition,
                  la soustraction et la multiplication, ainsi que les fonctions
                  utilitaires associées.

 Compilateur    : Mingw-w64 gcc 13.2.0
 -----------------------------------------------------------------------------------
*/

#include "MatrixOperations.hpp"

// Fonction pour ajouter deux matrices (version statique)
Matrix addStatic(const Matrix& matrix1, const Matrix& matrix2) {
    // Créer une copie de la matrice 1
    Matrix result(matrix1);

    // Ajouter la matrice 2 à la matrice résultante
    result.addItself(matrix2);

    return result;  // Retourner la nouvelle matrice résultat par valeur
}

// Fonction pour ajouter deux matrices (version dynamique)
Matrix* addDynamic(const Matrix& matrix1, const Matrix& matrix2) {
    // Créer une nouvelle matrice sur le tas en copiant la matrice 1
    Matrix* result = new Matrix(matrix1);

    // Ajouter la matrice 2 à la matrice résultante
    result->addItself(matrix2);

    return result;  // Retourner un pointeur vers la nouvelle matrice résultat allouée dynamiquement
}

// Fonction pour soustraire deux matrices (version statique)
Matrix subtractStatic(const Matrix& matrix1, const Matrix& matrix2) {
    // Créer une copie de la matrice 1
    Matrix result(matrix1);

    // Soustraire la matrice 2 de la matrice résultante
    result.subtractItself(matrix2);

    return result;  // Retourner la nouvelle matrice résultat par valeur
}

// Fonction pour soustraire deux matrices (version dynamique)
Matrix* subtractDynamic(const Matrix& matrix1, const Matrix& matrix2) {
    // Créer une nouvelle matrice sur le tas en copiant la matrice 1
    Matrix* result = new Matrix(matrix1);

    // Soustraire la matrice 2 de la matrice résultante
    result->subtractItself(matrix2);

    return result;  // Retourner un pointeur vers la nouvelle matrice résultat allouée dynamiquement
}

// Fonction pour multiplier deux matrices (version statique)
Matrix multiplyStatic(const Matrix& matrix1, const Matrix& matrix2) {
    // Créer une copie de la matrice 1
    Matrix result(matrix1);

    // Multiplier la matrice résultante par la matrice 2
    result.multiplyItself(matrix2);

    return result;  // Retourner la nouvelle matrice résultat par valeur
}

// Fonction pour multiplier deux matrices (version dynamique)
Matrix* multiplyDynamic(const Matrix& matrix1, const Matrix& matrix2) {
    // Créer une nouvelle matrice sur le tas en copiant la matrice 1
    Matrix* result = new Matrix(matrix1);

    // Multiplier la matrice résultante par la matrice 2
    result->multiplyItself(matrix2);

    return result;  // Retourner un pointeur vers la nouvelle matrice résultat allouée dynamiquement
}