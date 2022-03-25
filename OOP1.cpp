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
        cout << "������ ������� ����..." << endl;
        cin >> q;
    }
    return q;
}


 bool Fight(Hero* player, Creature* enemy) {
    while (1) {
        cout << "ճ� ����������" << endl;
        (*enemy).Attack(player, (*enemy).returnDamage()); 
        if (!(player->liveStatus())) {
            cout << "����� �����..." << endl;
            delete player;
            player = nullptr;
            return true;
        }
        int sum = player->throwDices();
        if (sum <  6) {
            cout << "���� �� �� ������ �'��, ������� ����� �������� �����!" << endl; 
            (*player).Attack(enemy, (*player).returnDamage() / 2);
        }
        else {
            (*player).Attack(enemy, (*player).returnDamage());
        }
        if (!(enemy->liveStatus())) {
            cout << "��� ��������!" << endl;
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
    cout << "³��� � ��� ��, ������� ������?" << endl;
    cout << "��������, ����� ��� ��'� : " << endl;
    string name;
    cin >> name;
    Hero *player = new Hero(50, 10, name);

    cout << "�� ���� ��� �� ���, �� ������� ���������. ���� ����?  " << endl;
    cout << "1) �����" << endl;
    cout << "2) �������" << endl;
    cout << "3) ����� " << endl;
    
    int choice = Choice(3);
    if (choice == 1) {
        cout << "㳳�, �� ������ ���� � �� ���� ������!" << endl;
        Enemy* cmonia = new Enemy(10, 5, "�����");
        if (Fight(player, cmonia)) 
            return 0;
    }
    else if (choice == 2) {
        cout << "�� �������� ��������� ������ ����������� ���, �� ���� � ���....���� �����, ��� ������" << endl;
        (*player).getDamage(3, player);
        if (player->throwDices() < 8) {
            cout << " ������� � ���� �����, ����� ���������� ���� ����� :) ";
            cout << " ���� ����� ���������? ";
            switch (Choice(2))
            {
            default:
                break;
            case 1:
                while ((*player).setOfDices[1].ShowNumber() + (*player).setOfDices[0].ShowNumber() <= 8) {
                    (*player).setOfDices[0].generateNumber();
                }
                cout << "�� ����� " << (*player).setOfDices[0].ShowNumber() << endl;
                cout << "����, �� �������� � ���!" << endl;
                break;
            case 2:
                while ((*player).setOfDices[1].ShowNumber() + (*player).setOfDices[0].ShowNumber() <= 8) {
                    (*player).setOfDices[1].generateNumber();
                }
                cout << "������ ����� " << (*player).setOfDices[1].ShowNumber() << endl;
                cout << "����, �� �������� � ���!" << endl;
                break;

            }

        }
    }
    else {
        cout << "�� ����-���� ��� ���, �� ��� �����, �� � ���� ������ �����! � ���� �� � ��� ���������!!" << endl;
        if (player->throwDices() <= 7) {
            cout << "���, �� �� �����..." << endl;
            (*player).getDamage(5, player);
        }
        else {
            cout << "��� �����������!! �� �� ������� ����." << endl;
        }
        cout << "���� �� �����, ����� ������� �����, �� ���� ��������� 2 ����!!! ���������� ����!" << endl;
        Enemy* ork1 = new Enemy(15, 5, "�����");
        Enemy* ork2 = new Enemy(10, 5, "���� ����");
        cout << "������, ���� ����� ���� ������." << endl;
        cout << "1) �����" << endl;
        cout << "2) ���� ���� " << endl;
        switch (Choice(2))
        {
        default:
            break;
        case 1:
            if (Fight(player, ork1))
                return 0;
            cout << "�������� ��...����� �����..." << endl;
            if (Fight(player, ork2))
                return 0;
            break;
        case 2:
            if (Fight(player, ork2))
                return 0;
            cout << "�� ��� � �������, ����� �� ����" << endl;
            if (Fight(player, ork1))
                return 0;
            break;
        }
    }


    cout << "ϳ��� ������ ��������� ��� �� ������ ��������, ��� �����.. ������ ��� ���� � �����. " << endl;
    cout << "³� ������� �������... �� � ���! " << endl;
    Boss* boss = new Boss(25, 10, "������");
    if (Fight(player, boss)) {
        return 0;
    }
    cout << "���� �������." << endl;
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
