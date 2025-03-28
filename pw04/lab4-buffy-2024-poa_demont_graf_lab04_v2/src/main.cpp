#include <iostream>
#include "Controller/Controller.hpp"

int main(int argc, char* argv[]) {
	const int NB_ARGS = 5;

	if (argc != NB_ARGS) {
		std::cerr << "Please enter a valid number of parameters : " << argv[0]
					 << "<width> <height> <number of humans> <number of vampires>"
					 << std::endl;
		return 1;
	}

	size_t width, height, nbHumans, nbVampires;
	try {
		for (int i = 1; i < argc; ++i) {
			if (std::stoi(argv[i]) < 0) {
				std::cerr << "Values should be positives." << std::endl;
				return 1;
			}
		}
		width = static_cast<size_t>(std::stoul(argv[1]));
		height = static_cast<size_t>(std::stoul(argv[2]));
		nbHumans = static_cast<size_t>(std::stoul(argv[3]));
		nbVampires = static_cast<size_t>(std::stoul(argv[4]));
	} catch (const std::invalid_argument& e) {
		return 1;
	} catch (const std::out_of_range& e) {
		std::cerr << "An argument is out of range." << std::endl;
		return 1;
	}

	Controller controller(width, height, nbHumans, nbVampires);
	controller.run();

	return 0;
}