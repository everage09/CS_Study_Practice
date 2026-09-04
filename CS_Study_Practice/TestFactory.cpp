#include "Factory.h"

int main()
{
	std::unique_ptr<CoffeeFactory> factory1 = std::make_unique<AmericanoFactory>();
	std::unique_ptr<CoffeeFactory> factory2 = std::make_unique<LatteFactory>();

	std::unique_ptr<Coffee> coffee1 = factory1->MakeCoffee();
	if (coffee1 == nullptr) {
		std::cout << "진짜로 비어있습니다!\n";
	}
	else {
		std::cout << "실제로는 잘 들어있습니다. 출력해볼게요:\n";
		std::cout << *coffee1;
	}

	std::unique_ptr<Coffee> coffee2 = factory2->MakeCoffee();
	if (coffee2 == nullptr) {
		std::cout << "진짜로 비어있습니다!\n";
	}
	else {
		std::cout << "실제로는 잘 들어있습니다. 출력해볼게요:\n";
		std::cout << *coffee2;
	}
	return 0;
}