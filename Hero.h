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
				int ShowNumber() {
					return number;
				}
				Dice() {
					generateNumber();
				}
		};
		Dice setOfDices[2];

		virtual void Greeting() {
			std::cout <<name_<<" : " << "� ������� �� ������!" << std::endl;
		}
		Hero(int heath, int damage, std::string name) {
			name_ = name;
			health_ = heath;
			damage_ = damage;
			isAlive = true;
			Greeting();
		}

		int throwDices() { // �� �������
			(setOfDices[0]).generateNumber();
			cout << "������ ����� : " << (setOfDices[0]).ShowNumber() <<endl;
			(setOfDices[1]).generateNumber();
			cout << "������ ����� : " << (setOfDices[1]).ShowNumber() <<endl;

			return (setOfDices[0]).ShowNumber() + (setOfDices[1]).ShowNumber();
		}
		~Hero(){
			cout << "ʳ���� ���. ����� �������...�������, �� �� ����������� � �������� ����� " << endl;
		}
};