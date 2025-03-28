//
// Created by calvi on 23.06.2024.
//

#ifndef BUFFY_RESUME_HPP
#define BUFFY_RESUME_HPP


class resume {

};

Si B hérite de A, B b -> A B ~B ~A
A &ref_b = b -> Rien
Appel méthode sur &ref_b, si virtual B, sinon A
Fonction : Si par ref -> Normal, sinon en fonction de la classe en paramètre

// Constructeur par copie
T(const T& other) { var = other.var; }
// Assignation par copie
T& operator=(const T& other) {auto-affect, Libérer mémoire, var = other.var, retourner *this}
// Constructeur par déplacement
T(T &&other) noexept : var(std::move(other.var)) {}
// Assignation par déplacement
&T operator=(T &&other) noexcept {auto-affect, var = std::move(other.var), retourner *this}
// Destructeur
~T() {Libérer mémoire}

Si déplacement de pointeur -> Libérer mémoire, move new pointer, ancien ptr = nullptr
Type de retour constant -> const type& methode() const {} <- Ne modifie pas attribut de la classe

// Fonction prend collection et foncteur
template<typename TCollection, typename TFunctor>
void fonction(const TCollection& collection, TFunctor functor) {
	for (const auto& element : collection) functor(element); }

// Exemple Foncteur / Prédicat
template <typename T>
class Nom {
public: // Ou 1 seul paramètre
	 bool operator()(const T& a, const T& b) const { return a < b } };

// Lambda (p. 137)
[] : [=] -> valeur | [&] -> référence
auto lambda = [](const T& a, const T& b) { return a < b; }

// Concept (p. 118)
template <typename T, typename F>
auto fonction(parametre)
requires std::floating_point<T> || requires MyConcept<T> || requires (T > F)
{ /* Code */ }

// Concept - Itérateur
template <typename TCollection>
concept MyConcept = requires (TCollection a)
	{ {a.begin()} -> typename TCollection::Iterator;
	  {a.end()} -> typename TCollection::Iterator;
	  requires AncienConcept<typename TCollection::value_type>;
	};

// Concept - Fonction retourne int
concept Fonction = requires(F f, T t) { {f(t)} -> int; };

// Pointeur intelligent
// Gére seule une donnée et supprime lorsque plus utilisé, ne peut pas être copié
std::unique_ptr<T> ptr = std::make_unique<T>{/*Constructeur*/};
// Gére plusieurs pointeurs sur la même donnée et supprime lorsque dernier ptr cesse de référencer
std::shared_ptr<T> ptr = std::make_shared<T>{/*Constructeur*/};
// Pointeur faible, n'empêche pas la suppression de la donnée, mais permet de vérifier si donnée existe encore
std::weak_ptr<T> ptr = std::weak_ptr<T>{ptr};

#endif //BUFFY_RESUME_HPP
