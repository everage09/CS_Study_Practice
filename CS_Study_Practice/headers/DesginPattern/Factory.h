#pragma once
#include <iostream>
#include <string>
#include <memory>

class Coffee {
public:
	Coffee() = default;
	Coffee(const Coffee& _rhs) = default;
	virtual ~Coffee() = default;

	virtual int getPrice() const = 0;
	virtual void print(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Coffee& coffee)
{
	coffee.print(os);
	return os;
}

class Americano : public Coffee {
public:
	Americano() { price = 2500; }
	int getPrice() const override
	{
		return price;
	}
	void print(std::ostream& os) const override
	{
		os << "Americano is : " << getPrice() << "won.\n";
	}
	int price;
};

class Latte : public Coffee {
public:
	Latte() { price = 4000; }
	int getPrice() const override
	{
		return price;
	}
	void print(std::ostream& os) const override
	{
		os << "Latte is : " << getPrice() << "won.\n";
	}
	int price;
};

class CoffeeFactory {
public:
	virtual std::unique_ptr<Coffee> MakeCoffee() = 0;
	virtual ~CoffeeFactory() = default;
};

class AmericanoFactory : public CoffeeFactory {
public:
	std::unique_ptr<Coffee> MakeCoffee() override
	{
		return std::make_unique<Americano>();
	}
};

class LatteFactory : public CoffeeFactory {
public:
	std::unique_ptr<Coffee> MakeCoffee() override
	{
		return std::make_unique<Latte>();
	}
};