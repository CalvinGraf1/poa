/*
 -----------------------------------------------------------------------------------
 Nom du fichier : MatrixOperations.hpp
 Auteur(s)      : Demont Kilian et Graf Calvin
 Date creation  : 20.03.2024

 Description    : Déclaration des opérations sur les matrices, telles que l'addition,
                  la soustraction et la multiplication, ainsi que les fonctions
                  utilitaires associées.

 Remarque(s)    : Ce fichier contient les déclarations des opérations sur les matrices
                  implémentées dans la classe Matrix.

 Compilateur    : Mingw-w64 gcc 13.2.0
 -----------------------------------------------------------------------------------
*/
#ifndef LABMATRIX_MATRIXOPERATIONS_HPP
#define LABMATRIX_MATRIXOPERATIONS_HPP

#pragma once

#include "Matrix.hpp"

/*!
 * \brief
 * Effectue une opération d'addition de deux matrices (version statique).
 * \param matrix1 La première matrice.
 * \param matrix2 La deuxième matrice.
 * \return La matrice résultante de l'addition.
 */
Matrix addStatic(const Matrix& matrix1, const Matrix& matrix2);

/*!
 * \brief Effectue une opération d'addition de deux matrices (version dynamique).
 * \param matrix1 La première matrice.
 * \param matrix2 La deuxième matrice.
 * \return Un pointeur vers la matrice résultante de l'addition allouée dynamiquement.
 */
Matrix* addDynamic(const Matrix& matrix1, const Matrix& matrix2);

/*!
 * \brief Effectue une opération de soustraction de deux matrices (version statique).
 * \param matrix1 La première matrice.
 * \param matrix2 La deuxième matrice.
 * \return La matrice résultante de la soustraction.
 */
Matrix subtractStatic(const Matrix& matrix1, const Matrix& matrix2);

/*!
 * \brief Effectue une opération de soustraction de deux matrices (version dynamique).
 * \param matrix1 La première matrice.
 * \param matrix2 La deuxième matrice.
 * \return Un pointeur vers la matrice résultante de la soustraction allouée dynamiquement.
 */
Matrix* subtractDynamic(const Matrix& matrix1, const Matrix& matrix2);

/*!
 * \brief Effectue une opération de multiplication de deux matrices (version statique).
 * \param matrix1 La première matrice.
 * \param matrix2 La deuxième matrice.
 * \return La matrice résultante de la multiplication.
 */
Matrix multiplyStatic(const Matrix& matrix1, const Matrix& matrix2);

/*!
 * \brief Effectue une opération de multiplication de deux matrices (version dynamique).
 * \param matrix1 La première matrice.
 * \param matrix2 La deuxième matrice.
 * \return Un pointeur vers la matrice résultante de la multiplication allouée dynamiquement.
 */
Matrix* multiplyDynamic(const Matrix& matrix1, const Matrix& matrix2);

#endif //LABMATRIX_MATRIXOPERATIONS_HPP
