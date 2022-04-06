#pragma once

#include <iostream>
#include "Creature.h"
#include "Enemy.h"
#include <utility>

using namespace std;

class Hero : public Creature { 
	public:
		class Dice {
			private:
				int number;
			public:
				void generateNumber() {
					number = 1+ rand() % 6;
				}
				// should be GetNumber since it's a getter
				int ShowNumber() {
					return number;
				}
				Dice() {
					generateNumber();
				}
		};
		Dice setOfDices[2];

		virtual void Greeting() override{
			std::cout <<name_<<" : " << "Я готовий до пригод!" << std::endl;
		}
		Hero(int heath, int damage, std::string name) {
			name_ = name;
			health_ = heath;
			damage_ = damage;
			isAlive = true;
			Greeting();
		}

		int throwDices() { // по людськи
			(setOfDices[0]).generateNumber();
			cout << "Перший кубик : " << (setOfDices[0]).ShowNumber() <<endl;
			(setOfDices[1]).generateNumber();
			cout << "Другий кубик : " << (setOfDices[1]).ShowNumber() <<endl;

			return (setOfDices[0]).ShowNumber() + (setOfDices[1]).ShowNumber();
		}
		~Hero(){
			cout << "Кінець гри. Герой спочиває...можливо, він ще повернеться в наступній лабці " << endl;
		}
};