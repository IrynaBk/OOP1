#pragma once
#include <string>
#include <stdlib.h>   
#include <time.h>  
#include <iostream>


	class Creature {
		protected:
			int health_;	
			std::string name_;
			int damage_;
			bool isAlive;
			virtual void Greeting() = 0;
			void ShowHP() {
				std::cout << name_ << " : " << health_ << " HP" << std::endl;
			}
		public:	
			void getDamage(int damage,Creature* creature) {
				health_ -= damage;
				std::cout << name_ <<" отримує  -"<<damage <<"HP!" << std::endl;
				if (health_ <= 0) {
					creature->health_ = 0;
					ShowHP();
					std::cout << name_ << " : " << " бл......" << std::endl;
					creature->isAlive = false;
					return;
				}
				ShowHP();
			}
			virtual void Attack(Creature *enemy,int damage) {
			 (*enemy).getDamage(damage, enemy);
			}
			int returnDamage() {
				return damage_;
			}
			bool liveStatus() {
				return this->isAlive;
			}
	};

