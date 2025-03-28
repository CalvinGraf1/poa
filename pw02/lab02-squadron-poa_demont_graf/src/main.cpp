/**
 * @file main.cpp
 * @brief A program to test the functionality of various classes
 * related to a squadron of ships.
 * @authors Demont Kilian & Graf Calvin
 */

#include <iostream>
#include <cassert>
#include <sstream>
#include "ships/TIE.hpp"
#include "ships/Interceptor.hpp"
#include "ships/cargo/Destroyer.hpp"
#include "ships/cargo/Shuttle.hpp"
#include "Squadron.hpp"
#include "Constants.hpp"

/**
 * Ships displaying test
 */
void testShipPrinting() {
    std::cout << "TEST : Affichage correcte des vaisseaux" <<
              std::endl;

    // Create an Interceptor with nickname "Red One"
    Interceptor interceptor1("Red One");
    // Create an Interceptor with nickname "Red Two"
    Interceptor interceptor2("Red Two");
    // Create a TIE with nickname "Black One"
    TIE tie("Black One");
    // Create a Destroyer with nickname "Star Destroyer" and cargo 150,000 tons
    Destroyer destroyer(150000, "Star Destroyer");
    // Create a Shuttle with nickname "Lambda Shuttle" and cargo 50 tons
    Shuttle shuttle(50, "Lambda Shuttle");

    // Expected output strings for each ship
    std::string expectedInterceptor1Output = "Red One [TIE/IN #1]\nweight : 5.00 tons\nmax speed : 110 MGLT";
    std::string expectedInterceptor2Output = "Red Two [TIE/IN #2]\nweight : 5.00 tons\nmax speed : 110 MGLT";
    std::string expectedTieOutput = "Black One [TIE/LN #1]\nweight : 6.00 tons\nmax speed : 100 MGLT";
    std::string expectedDestroyerOutput = "Star Destroyer [Super-class Star Destroyer #1]\nweight : 9000150000.00 tons\nmax speed : 40 MGLT\ncargo : 150000.0 tons (max : 250000.0)";
    std::string expectedShuttleOutput = "Lambda Shuttle [Lambda-class shuttle #1]\nweight : 410.00 tons\nmax speed : 54 MGLT\ncargo : 50.0 tons (max : 80.0)";

    try {
        // Check if the actual output matches the expected output for each ship
        std::ostringstream interceptor1Output;
        interceptor1Output << interceptor1;
        assert(interceptor1Output.str() ==
               expectedInterceptor1Output);

        std::ostringstream interceptor2Output;
        interceptor2Output << interceptor2;
        assert(interceptor2Output.str() ==
               expectedInterceptor2Output);

        std::ostringstream tieOutput;
        tieOutput << tie;
        assert(tieOutput.str() == expectedTieOutput);

        std::ostringstream destroyerOutput;
        destroyerOutput << destroyer;
        assert(destroyerOutput.str() == expectedDestroyerOutput);

        std::ostringstream shuttleOutput;
        shuttleOutput << shuttle;
        assert(shuttleOutput.str() == expectedShuttleOutput);
    } catch (const std::exception& e) {
        std::cout << "ERROR | TEST KO" << std::endl << std::endl;
    }

    std::cout << "TEST OK" << std::endl << std::endl;
}

/**
 * Invalid ship creation and modification test
 */
void testInvalidCargo() {
	std::cout << "TEST : Creation d'un vaisseau avec une cargaison invalide" <<
	std::endl;
	try {
		Shuttle shuttle = Shuttle(-12);
		std::cout << "ERROR | TEST KO" << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout << "TEST OK | Erreur levee : " << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "TEST : Creation d'un vaisseau avec une cargaison trop grande" <<
	std::endl;
	try {
		Shuttle shuttle = Shuttle(100);
		std::cout << "ERROR | TEST KO" << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout << "TEST OK | Erreur levee : " << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "TEST : Modification d'un vaisseau avec un cargaison invalide" <<
				 std::endl;
	Shuttle shuttle2 = Shuttle(40);
	try {
		shuttle2.setCargo(-12);
		std::cout << "ERROR | TEST KO" << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout << "TEST OK | Erreur levee : " << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "TEST : Modification d'un vaisseau avec un cargaison trop grande" <<
	std::endl;
	Shuttle shuttle = Shuttle(40);
	try {
		shuttle.setCargo(100);
		std::cout << "ERROR | TEST KO" << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout << "TEST OK | Erreur levee : " << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}
}

/**
 * Test the fuel consumption calculation of a ship
 */
void testComputeSingleConsumption() {
	TIE interceptor = TIE();

	std::cout << "TEST : Calcul de la consommation basique" << std::endl;
	double conso = 0;
	try {
		conso = interceptor.consumption(100, 50);
		if (conso == 0)
			throw std::exception();
	} catch (const std::exception& e) {
		std::cout << "ERROR | TEST KO" << std::endl;
		std::cout << e.what() << std::endl << std::endl;
		return;
	}
	std::cout << "TEST OK" << std::endl;
	std::cout << "Valeur de la consommation : " << conso << " " << CONSUMPTION_UNIT
	<< std::endl << std::endl;

	std::cout << "TEST : Calcul de la consommation avec vitesse trop rapide pour le "
					 "vaisseau"	<< std::endl;

	try {
		interceptor.consumption(100, 300);
		std::cout << "ERROR | TEST KO" << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout << "TEST OK | Erreur levee : " << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}
}

/**
 * Test the creation and copying of constant ships
 */
void testConstantShips() {
	const Shuttle ship1(12.2);

	std::cout << "TEST : Creation et affichage d'un vaisseau constant" << std::endl;
	std::cout << ship1 << std::endl << std::endl;

	std::cout << "TEST : Acceder aux valeurs d'un vaisseau constant" << std::endl;
	std::cout << "Max speed: " << ship1.speed() << " " << SPEED_UNIT << std::endl;
	std::cout << "Cargaison: " << ship1.speed() << " " << SPEED_UNIT << std::endl;
	std::cout << "Poids: " << ship1.weight() << " " << WEIGHT_UNIT << std::endl << std::endl;
}

/**
 * Test ship adding in different ways
 */
void testAddShips() {
	/*
	 * /!\ Attention : Le compilateur peut utiliser l'affectation par mouvement
	 * plutôt que par copie pour une question d'optimisation des performances.
	 *
	 * Pour être sûr de tester l'opérateur d'affectation par copie, veuillez mettre
	 * en commentaire l'opérateur d'affectation par mouvement.
	 */

	Squadron squad = Squadron("Escadrille de test");
	TIE ship1;
	TIE ship2;
	TIE ship3;
	TIE ship4;

	std::cout << "TEST : Ajout de vaisseaux de differentes manieres" << std::endl <<
	std::endl;
	squad += ship1;
	squad = squad + ship2;
	squad.addShip(ship3);

	Squadron squadCopy = squad.addShipCopy(ship4);

	std::cout << "Les 3 vaisseaux doivent figurer dans le squadron" << std::endl << std::endl;
	std::cout << squad << std::endl;

	std::cout << "La 2eme escadrille doit contenir 4 vaisseaux" << std::endl <<
	std::endl;
	std::cout << squadCopy << std::endl;

	std::cout << "TEST : Ajout de vaisseaux qui sont deja dans l'escadrille" << std::endl;
	squad += ship1;

	std::cout << "Il n'y a pas de doublons dans la liste des vaisseaux" << std::endl << std::endl;
	std::cout << squad << std::endl;

	Squadron moveSquad("Escadrille de mouvement");
	moveSquad = std::move(squad);

	std::cout << "La 1ere escadrille est desormais vide" << std::endl << std::endl;
	std::cout << squad << std::endl;

	std::cout << "La 3eme escadrille contient le contenu de la 1ere" << std::endl <<
				 std::endl;
	std::cout << moveSquad << std::endl;
}

/**
 * Test ship removal in different ways
 */
void testRemoveShips() {
	Squadron squad = Squadron("Escadrille de test");
	TIE ship1;
	TIE ship2;
	TIE ship3;
	TIE ship4;
	squad += ship1;
	squad += ship2;
	squad += ship3;
	squad += ship4;

	std::cout << "TEST : Suppression de vaisseaux de differentes manieres" <<
	std::endl;
	squad -= ship1;
	squad = squad - ship2;
	squad.removeShip(ship3);
	squad = squad.removeShipCopy(ship4);
	std::cout << "L'escadrille doit etre vide" << std::endl << std::endl;
	std::cout << squad << std::endl;

	std::cout << "TEST : Suppression de vaisseaux d'une escadrille vide" << std::endl;
	squad -= ship1;
	std::cout << "Il ne se passe rien. L'escadrille reste vide" << std::endl <<
	std::endl;
	std::cout << squad << std::endl;

	squad += ship1;
	squad += ship2;
	squad += ship3;
	squad += ship4;

	std::cout << "TEST : Suppression d'un vaisseau au milieu" << std::endl;
	squad -= ship3;
	std::cout << squad << std::endl;

	std::cout << "TEST : Suppression du premier vaisseau" << std::endl;
	squad -= ship1;
	std::cout << squad << std::endl;

	std::cout << "TEST : Suppression du dernier vaisseau" << std::endl;
	squad -= ship4;
	std::cout << squad << std::endl;
}

/**
 * Test access to a squadron ship in different ways
 */
void testAccessShip() {
	Squadron squad = Squadron("Escadrille de test");
	TIE ship1;
	TIE ship2;
	TIE ship3;
	TIE ship4;
	squad += ship1;
	squad += ship2;
	squad += ship3;
	squad += ship4;

	std::cout << "TEST : Acces au 1er vaisseau" << std::endl;
	std::cout << squad[0] << std::endl << std::endl;

	std::cout << "TEST : Acces au vaisseau au milieu de l'escadrille" << std::endl;
	std::cout << squad.getShip(2) << std::endl << std::endl;

	squad.getShip(0).setNickname("Je suis un test");
	std::cout << "TEST : Modification du premier vaisseau via getShip" << std::endl;
	std::cout << squad.getShip(0) << std::endl << std::endl;

	std::cout << "TEST : Acces au dernier ship" << std::endl;
	std::cout << squad[3] << std::endl << std::endl;

	std::cout << "TEST : Index invalide" << std::endl;
	try {
		squad.getShip(5);
		std::cout << "ERROR | TEST KO" << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout << "TEST OK | Erreur levee : " << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}

	const Squadron squad2(squad);
	std::cout << "TEST : Acces dans une escadrille constante" << std::endl;
	std::cout << squad2[3] << std::endl << std::endl;
}

/**
 * Test the addition of the squadron leader
 */
void testAddLeader() {
	Squadron squad = Squadron("Escadrille de test");
	TIE ship1;
	TIE ship2;
	TIE ship3;
	squad += ship1;
	squad += ship2;

	std::cout << "TEST : Promouvoir un vaisseau comme leader ne doit pas provoquer "
					 "de doublon (plus visible dans membre)" <<
					 std::endl;
	squad.setLeader(ship1);
	std::cout << squad << std::endl << std::endl;

	std::cout << "TEST : Remplacer un vaisseau comme leader d'une escadrille sans "
					 "que celui-ci soit prealablement membre de celle-ci (l'ancien "
					 "leader doit toujours etre membre)" << std::endl;
	squad.setLeader(ship3);
	std::cout << squad << std::endl;

	std::cout << "TEST : Attribuer comme leader un vaisseau qui est deja leader" <<
	std::endl;
	squad.setLeader(ship3);
	std::cout << squad << std::endl;
}

/**
 * Test the deletion of the squadron leader
 */
void testRemoveLeader() {
	Squadron squad = Squadron("Escadrille de test");
	TIE ship1;
	TIE ship2;
	squad += ship1;
	squad += ship2;
	squad.setLeader(ship1);

	std::cout << "TEST : Suppression du leader ne l'enleve pas de l'escadrille" << std::endl;
	squad.removeLeader();
	std::cout << squad << std::endl;

	std::cout << "TEST : Supprimer le leader lorsqu'il n'y en a pas ne fait rien" <<
	std::endl;
	squad.removeLeader();
	std::cout << squad << std::endl;
}

/**
 * Test the squadron copy
 */
void testCopySquadron() {
	Squadron squad = Squadron("Escadrille de test");
	TIE ship1;
	TIE ship2;
	TIE ship3;
	TIE ship4;
	squad += ship1;
	squad += ship2;
	squad += ship3;
	squad += ship4;
	squad.setLeader(ship1);

	std::cout << "TEST : La copie d'une escadrille copie bien les vaisseaux" <<
	std::endl << std::endl;
	Squadron squad2(squad);

	std::cout << "Escadrille originale : " << std::endl;
	std::cout << squad << std::endl;
	std::cout << "Escadrille copiee : " << std::endl;
	std::cout << squad2 << std::endl;

	std::cout << "TEST : Modification du nom de la copie" << std::endl;
	squad2.setName("Copie de l'escadrille");
	std::cout << "Escadrille originale : " << squad.getName() << std::endl;
	std::cout << "Escadrille copiee : " << squad2.getName() << std::endl << std::endl;

	std::cout << "TEST : Modification du leader de la copie" << std::endl;
	squad2.setLeader(ship2);
	std::cout << "Escadrille originale : " << std::endl;
	std::cout << squad << std::endl;
	std::cout << "Escadrille copiee : " << std::endl;
	std::cout << squad2 << std::endl;

	std::cout << "TEST : Suppression de vaisseau dans l'escadrille originale" << std::endl;
	squad -= ship1;
	std::cout << "Escadrille originale : " << std::endl;
	std::cout << squad << std::endl;
	std::cout << "Escadrille copiee : " << std::endl;
	std::cout << squad2 << std::endl;

	std::cout << "TEST : Suppression de vaisseau  dans l'escadrille copiee" << std::endl;
	squad2 -= ship3;
	std::cout << "Escadrille originale : " << std::endl;
	std::cout << squad << std::endl;
	std::cout << "Escadrille copiee : " << std::endl;
	std::cout << squad2 << std::endl;

	std::cout << "TEST : Copie dans une escadrille constante" << std::endl;
	const Squadron squad3 = Squadron(squad2);
	std::cout << "Escadrille originale : " << std::endl;
	std::cout << squad2 << std::endl;
	std::cout << "Escadrille copiee (constante) : " << std::endl;
	std::cout << squad3 << std::endl;
}

/**
 * Test the fuel consumption calculation of a squadron
 */
void testSquadronConsumption() {
	Squadron squad = Squadron("Squadron de test");
	Shuttle ship1(42);
	TIE ship2;
	squad += ship1;
	squad += ship2;
	double km = 200.5;
	size_t speed = 15;

	std::cout << "TEST : Verification du calcul de la consommation d'une escadrille"
		  << std::endl;
	double totalConsumption = squad.computeConsumption(km, speed);
	double oneByOneConsumption = 0;
	oneByOneConsumption += ship1.consumption(km, speed);
	oneByOneConsumption += ship2.consumption(km, speed);
	std::cout << "Consommation totale de l'escadrille : " << totalConsumption <<
	std::endl;
	std::cout << "Consommation additionnee vaisseau par vaisseau : "
	<< oneByOneConsumption<< std::endl << std::endl;

	std::cout << "TEST : Verification si la vitesse max de l'operation est trop grande "
			  "pour l'un des vaisseaux de l'escadrille" << std::endl;

	double tooBigSpeed = 100;
	try {
		squad.computeConsumption(km, tooBigSpeed);
	} catch (const std::exception& e) {
		std::cout << "TEST OK | Erreur levee : " << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}
}

/**
 * Runs all advanced tests
 */
void advancedTest() {
	testShipPrinting();
	testInvalidCargo();
	testComputeSingleConsumption();
	testConstantShips();
	testAddShips();
	testRemoveShips();
	testAccessShip();
	testCopySquadron();
	testAddLeader();
	testRemoveLeader();
	testSquadronConsumption();
}

/**
 * Run the test protocol provided
 */
void testProtocol() {
	TIE blackLeader;
	blackLeader.setNickname("Black leader");
	TIE blackTwo;
	Shuttle shuttle(23.4); // 23.4 tonnes de marchandises
	Squadron squad("Black Squadron");
	squad += blackLeader;
	squad += blackTwo;
	squad += shuttle;
	squad.setLeader(blackLeader);
	std::cout << squad << std::endl;
}

int main()
{
	advancedTest();
	//testProtocol();
}