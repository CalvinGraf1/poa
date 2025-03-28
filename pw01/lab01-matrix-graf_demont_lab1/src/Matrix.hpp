/*
 -----------------------------------------------------------------------------------
 Nom du fichier : Matrix.hpp
 Auteur(s)      : Demont Kilian et Graf Calvin
 Date creation  : 29.02.2024

 Description    : Déclaration de la classe Matrix et des méthodes associées
                  pour modéliser son comportement.

 Remarque(s)    : Les opérations statiques et dynamiques sont déclarées dans le
                  fichier MatrixOperations.hpp

 Compilateur    : Mingw-w64 gcc 13.2.0
 -----------------------------------------------------------------------------------
*/

#pragma once

#include <cstddef>
#include <iosfwd>

/*!
 * \brief La classe Matrix représente une matrice d'entiers avec des opérations arithmétiques de base.
 */
class Matrix {
private:
    int** values; ///< Tableau bidimensionnel contenant les valeurs de la matrice
    int rows, columns; ///< Nombre de lignes et de colonnes de la matrice
    int modulo; ///< Valeur du modulo pour les opérations arithmétiques

    void freeMemory(); ///< Libère la mémoire allouée pour les valeurs de la matrice
    void checkValuesIntegrity(const int& m, const int& n, const int& mod) const; ///< Vérifie l'intégrité des valeurs de la matrice
    void checkMatrixDimensions(const Matrix& other) const; ///< Vérifie la compatibilité des dimensions avec une autre matrice

    /*!
     * \brief La classe interne MatrixOperation est une classe de base abstraite pour les opérations matricielles.
     */
    class MatrixOperation {
    public:
        /*!
         * \brief Performe l'opération matricielle.
         * \param a Premier opérande de l'opération.
         * \param b Deuxième opérande de l'opération.
         * \return Résultat de l'opération.
         */
        [[nodiscard]] virtual int perform(int a, int b) const = 0;
    };

    /*!
     * \brief La classe interne MatrixAddition implémente l'opération d'addition pour les matrices.
     */
    class MatrixAddition : public MatrixOperation {
    public:
        /*!
         * \brief Effectue l'addition de deux nombres.
         * \param a Premier nombre.
         * \param b Deuxième nombre.
         * \return Résultat de l'addition.
         */
        [[nodiscard]] int perform(int a, int b) const override;
    };

    /*!
     * \brief La classe interne MatrixSubtraction implémente l'opération de soustraction pour les matrices.
     */
    class MatrixSubtraction : public MatrixOperation {
    public:
        /*!
         * \brief Effectue la soustraction de deux nombres.
         * \param a Premier nombre.
         * \param b Deuxième nombre.
         * \return Résultat de la soustraction.
         */
        [[nodiscard]] int perform(int a, int b) const override;
    };

    /*!
     * \brief La classe interne MatrixMultiplication implémente l'opération de multiplication pour les matrices.
     */
    class MatrixMultiplication : public MatrixOperation {
    public:
        /*!
         * \brief Effectue la multiplication de deux nombres.
         * \param a Premier nombre.
         * \param b Deuxième nombre.
         * \return Résultat de la multiplication.
         */
        [[nodiscard]] int perform(int a, int b) const override;
    };

    /*!
     * \brief Effectue une opération matricielle avec une autre matrice en utilisant une opération spécifique.
     * \param other L'autre matrice avec laquelle effectuer l'opération.
     * \param operation L'opération matricielle à effectuer.
     */
    void performOperation(const Matrix& other, const MatrixOperation &operation);

    /*!
     * \brief Obtient la valeur de la matrice à la position spécifiée.
     * \param row L'indice de ligne.
     * \param col L'indice de colonne.
     * \return La valeur de la matrice à la position spécifiée.
     */
    [[nodiscard]] int getValue(int row, int col) const;

public:
    /*!
     * \brief Constructeur de la classe Matrix.
     * \param rows Le nombre de lignes de la matrice.
     * \param columns Le nombre de colonnes de la matrice.
     * \param modulo La valeur du modulo pour les opérations arithmétiques.
     */
     Matrix(int rows, int columns, int modulo);

    /*!
     * \brief Constructeur de copie de la classe Matrix.
     * \param other La matrice à copier.
     */
	 Matrix(const Matrix& other);

    /*!
     * \brief Constructeur de déplacement de la classe Matrix.
     * \param other La matrice à déplacer.
     */
	 Matrix(Matrix&& other) noexcept;

    /*!
     * \brief Destructeur de la classe Matrix.
     */
    ~Matrix();

    /*!
     * \brief Opérateur d'affectation par copie de la classe Matrix.
     * \param other La matrice à copier.
     * \return Une référence sur la matrice modifiée.
     */
	 [[nodiscard]] Matrix& operator=(const Matrix& other);

    /*!
     * \brief Opérateur d'affectation par déplacement de la classe Matrix.
     * \param other La matrice à déplacer.
     * \return Une référence sur la matrice modifiée.
     */
	 [[nodiscard]] Matrix& operator=(Matrix&& other) noexcept;

    /*!
     * \brief Ajoute une autre matrice à la matrice actuelle.
     * \param other La matrice à ajouter.
     * \return Une référence sur la matrice actuelle après l'addition.
     */
	 Matrix& addItself(const Matrix& other);

    /*!
     * \brief Soustrait une autre matrice de la matrice actuelle.
     * \param other La matrice à soustraire.
     * \return Une référence sur la matrice actuelle après la soustraction.
     */
	 Matrix& subtractItself(const Matrix& other);

    /*!
     * \brief Multiplie la matrice actuelle par une autre matrice.
     * \param other La matrice à multiplier.
     * \return Une référence sur la matrice actuelle après la multiplication.
     */
	 Matrix& multiplyItself(const Matrix& other);

    /*!
     * \brief Opérateur de flux de sortie pour l'affichage de la matrice.
     * \param os Le flux de sortie.
     * \param matrix La matrice à afficher.
     * \return Une référence sur le flux de sortie modifié.
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};
