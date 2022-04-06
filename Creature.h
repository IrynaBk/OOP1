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
			// takeDamage() would be a better description, 
			// get misleads the reader to think its a getter function
			void getDamage(int damage,Creature* creature) {		
				health_ -= damage;
				std::cout << name_ <<" отримує  -"<<damage <<"HP!" << std::endl;
				if (health_ <= 0) {
					// is there a reason for passing another pointer of Creature type?
					// it seems that you're always passing a pointer to the calling object itself anyway
					// but I'm guessing you're trying to mess with pointers to see how they work
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
			// getDamage()
			int returnDamage() {	
				return damage_;
			}
			// isAlive(), this is the naming convention when returning booleans
			bool liveStatus() {
				return this->isAlive;
			}
	};

