#pragma once
#include <iostream>
#include "Creature.h"


class Enemy : public Creature {
	public:
		virtual void Greeting() {
			std::cout <<name_<<" : "<< " � � �� ����� ������" << std::endl;
		}
		Enemy(int heath, int damage, std::string name) {
			name_ = name;
			health_ = heath;
			damage_ = damage;
			isAlive = true;
			Greeting();
		}
		Enemy() {

		}
};

class Boss : public Enemy {
	public:
		virtual void Greeting() {
			std::cout << name_ << " : " << "���������, ������ ���������! " << std::endl;
		}
		Boss(int heath, int damage, std::string name) {
			name_ = name;
			health_ = heath;
			damage_ = damage;
			isAlive = true;
			Greeting();
		}
		void SpecialAttack(Creature* enemy, int damage) {
			std::cout << "��� �����! �� ���� ������ ������� ����, ��������� �� �����..." << std:: endl;
			(*enemy).getDamage(damage+5, enemy);
		}
		virtual void Attack(Creature* enemy, int damage) {
			if (this->health_ <= 5) {
				this->SpecialAttack(enemy, damage);
			}
			else {
				(*enemy).getDamage(damage, enemy);
			}
		}

};
