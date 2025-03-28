/*
 -----------------------------------------------------------------------------------
 Nom du fichier : Utils.cpp
 Auteur(s)      : Demont Kilian et Graf Calvin
 Date creation  : 20.03.2024

 Description    : Défintion des fonctions utilitaires, telles que mathModulo,
                  pour fournir des fonctionnalités générales.

 Compilateur    : Mingw-w64 gcc 13.2.0
 -----------------------------------------------------------------------------------
*/

int mathModulo(const int& a, const int& b)
{
    return (a % b + b) % b;
}