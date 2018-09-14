#include<iostream>
#include<string>
#include"Guess.h"


int main(){
	std::shared_ptr<Guessnode < std::string >> gues = std::make_shared<Guessnode < std::string >>("panda");
	std::shared_ptr<Guessnode < std::string >> door = gues;
	std::shared_ptr<Guessnode<std::string>> parent = nullptr;
	std::shared_ptr<Guessnode<std::string>> root = nullptr;
	std::string answer;
	std::string answer1;
	std::string answer2;

	while (true){

		std::cout << "Think of something." << std::endl;

		while (door != nullptr){


			answer2 = door->data;
			if (door->left !=nullptr && door->right != nullptr){
				std::cout << door->data << std::endl;
				std::getline(std::cin, answer);
				if (answer == "no"){
					parent = door;
					door = door->right;

				}
				else{
					parent = door;
					door = door->left;

				}
			}
			else{
			
				std::cout << "Are you thinking of a " << door->data << " ?" << std::endl;

				std::getline(std::cin, answer);
				if (answer == "no"){
					parent = door;
					door = door->right;

				}
				else{
					parent = door;
					door = door->left;
					std::cout << "I win. want to play again?" << std::endl;
					std::getline(std::cin, answer);
					if (answer == "no"){
						return 0;
					}
					else{
						door = root;
					}

				}
			}
		}

		std::cout << "what are you think of?" << std::endl;
		std::getline(std::cin, answer1);

		std::cout << "What could I have asked to know you were thinking of " << answer1 << " and not a " << answer2 << "? " << std::endl;

		std::getline(std::cin, answer);

		door = std::make_shared<Guessnode < std::string >>(answer);
		door->left = std::make_shared<Guessnode < std::string >>(answer1);
		if (parent->data == gues->data){
			door->right = gues;

			gues->left = door;
			zag<std::string >(gues);
		}
		else {

			door->right = gues;
			parent->right = door;

			zig<std::string >(parent);
		}
		door = gues;
			if (root == nullptr){
				root = door;
			}

		std::cout << "Want to play again? " << std::endl;
		std::getline(std::cin, answer);
		if (answer == "no"){
			return 0;
		}
	}








	return 0;
}

