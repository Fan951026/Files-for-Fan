#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cstdlib>
#include <exception>
#include "Rational.h"
#include <sstream>
template <typename c, typename F>
void apply(c & container, F f){
	if (container.size() < 2){ throw std::runtime_error("NOt enough operands"); }
	auto second = container.back();
	container.pop_back();
	auto first = container.back();
	container.pop_back();
	auto result = f(first, second);
	std::cout << first << " op " << second << " = " << result << std::endl;
	container.push_back(result);

}
int main(){
	bool running = true;
	std::vector<Rational>stack;
	
	while (running){
		
		std::string input;
		try{
			std::getline(std::cin, input);
			if (input[0] == 'e'){ return EXIT_SUCCESS; }
			else if (input[0] == '+'){
				apply(stack, [](Rational a, Rational b){return a + b; });
			}
			else if (input[0] == '-'){
				apply(stack, [](Rational a, Rational b){return a - b; });
			}
			else if (input[0] == '*'){
				apply(stack, [](Rational a, Rational b){return a * b; });
			}
			else if (input[0] == '/'){
				apply(stack, [](Rational a, Rational b){return a / b; });
			}
			else if (input[0] == 'c'){
				stack.clear();
			}
			else {
				std::stringstream s;
			     s << input;
				Rational a;
				s >> a; 
				stack.push_back(a);
			}
		}


		catch (std::exception & e){
			std::cout << e.what();
			stack.clear();

		}

	}
}