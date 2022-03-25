// OOP1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Creature.h"
#include "Hero.h"
#include "Enemy.h"

using namespace std;

int Choice(int n){ 

    int q=0;
    cin >> q;
    while (q > n || q < 1 || isalpha(q)) {
        cout << "Такого варіанту немає..." << endl;
        cin >> q;
    }
    return q;
}


 bool Fight(Hero* player, Creature* enemy) {
    while (1) {
        cout << "Хід противника" << endl;
        (*enemy).Attack(player, (*enemy).returnDamage()); 
        if (!(player->liveStatus())) {
            cout << "Герой помер..." << endl;
            delete player;
            player = nullptr;
            return true;
        }
        int sum = player->throwDices();
        if (sum <  6) {
            cout << "Щось ти не влучно б'єш, наносиш тільки половину урону!" << endl; 
            (*player).Attack(enemy, (*player).returnDamage() / 2);
        }
        else {
            (*player).Attack(enemy, (*player).returnDamage());
        }
        if (!(enemy->liveStatus())) {
            cout << "Ура перемога!" << endl;
            delete enemy;
            enemy = nullptr;
            return false;
        }
        
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE, "ukr");
    cout << "Вітаю в моїй грі, готовий почати?" << endl;
    cout << "Спочатку, скажи своє ім'я : " << endl;
    string name;
    cin >> name;
    Hero *player = new Hero(50, 10, name);

    cout << "Ти йшов собі по лісу, як побачив роздоріжжя. Куди підеш?  " << endl;
    cout << "1) Наліво" << endl;
    cout << "2) Направо" << endl;
    cout << "3) Прямо " << endl;
    
    int choice = Choice(3);
    if (choice == 1) {
        cout << "гіій, ти зустрів Орка і він тебе вдарив!" << endl;
        Enemy* cmonia = new Enemy(10, 5, "чмоня");
        if (Fight(player, cmonia)) 
            return 0;
    }
    else if (choice == 2) {
        cout << "Ти настільки захопився красою українського лісу, що впав в яму....кинь кубик, щоб вилізти" << endl;
        (*player).getDamage(3, player);
        if (player->throwDices() < 8) {
            cout << " поганий з тебе лазун, можеш перекинути один кубик :) ";
            cout << " Який кубик перекинеш? ";
            switch (Choice(2))
            {
            default:
                break;
            case 1:
                while ((*player).setOfDices[1].ShowNumber() + (*player).setOfDices[0].ShowNumber() <= 8) {
                    (*player).setOfDices[0].generateNumber();
                }
                cout << "Ти вибив " << (*player).setOfDices[0].ShowNumber() << endl;
                cout << "Ураа, ти вибрався з ями!" << endl;
                break;
            case 2:
                while ((*player).setOfDices[1].ShowNumber() + (*player).setOfDices[0].ShowNumber() <= 8) {
                    (*player).setOfDices[1].generateNumber();
                }
                cout << "Випало число " << (*player).setOfDices[1].ShowNumber() << endl;
                cout << "Ураа, ти вибрався з ями!" << endl;
                break;

            }

        }
    }
    else {
        cout << "Ти йшов-йшов собі далі, аж тут відчув, що в тебе летить стріла! В тебе ще є час ухилитись!!" << endl;
        if (player->throwDices() <= 7) {
            cout << "Ауч, ти не встиг..." << endl;
            (*player).getDamage(5, player);
        }
        else {
            cout << "Яка майстерність!! Ти не отримуєш урон." << endl;
        }
        cout << "Поки ти думав, звідки вилетіла стріла, до тебе підкралися 2 орки!!! Починається бійка!" << endl;
        Enemy* ork1 = new Enemy(15, 5, "чмоня");
        Enemy* ork2 = new Enemy(10, 5, "друг чмоні");
        cout << "Вибери, кого будеш бити першим." << endl;
        cout << "1) чмоня" << endl;
        cout << "2) друг чмоні " << endl;
        switch (Choice(2))
        {
        default:
            break;
        case 1:
            if (Fight(player, ork1))
                return 0;
            cout << "Складний бій...тепер інший..." << endl;
            if (Fight(player, ork2))
                return 0;
            break;
        case 2:
            if (Fight(player, ork2))
                return 0;
            cout << "Не так і складно, тепер ще один" << endl;
            if (Fight(player, ork1))
                return 0;
            break;
        }
    }


    cout << "Після такого складного дня ти вирішив відпочити, але опана.. якийсь орк виліз з кущів. " << endl;
    cout << "Він виглядає сильним... Це ж бос! " << endl;
    Boss* boss = new Boss(25, 10, "босяра");
    if (Fight(player, boss)) {
        return 0;
    }
    cout << "Було складно." << endl;
    delete player;
    player = nullptr;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
