// SimulacaoUrna.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include<conio.h>

#include <Mmsystem.h>
#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")

//configuração do SFML https://www.sfml-dev.org/tutorials/2.5/start-vc.php
#include "../SFML-2.5.1/include/SFML/Audio.hpp"

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

using namespace  std;
int main()
{
	int Bolsonaro = 0;
	int Lula = 0;
	int NuloBranco = 0;
	int Numero = 0;
	int totalEleitores = 0;

	char key_press;
	int ascii_value;

	//Cenario Voto Impresso
	while (totalEleitores < 10)
	{
		std::cout << "\n";
		std::cout << "Digite Numero do Candidato:" << "\n";
		std::cin >> Numero;

		std::cout << "\n";


		std::cout << "Confirmar: " << Numero << " Sim [s] ou [n] Nao \n";
		key_press = _getch();
		ascii_value = key_press;

		if (ascii_value == 115)
		{
			if (Numero == 13)
			{
				Lula++;
				std::cout << "Seu voto foi Lula \n";
			}

			//if (Numero == 0)
			//{
			//	Lula++;
			//	std::cout << "Seu voto foi Lula \n";
			//}

			if (Numero == 0)
			{
				NuloBranco++;
				std::cout << "Seu voto foi Nulo \n";
			}


			if (Numero == 17)
			{
				if (Bolsonaro < Lula)
				{
					Bolsonaro++;
					std::cout << "Seu voto foi Bolsonaro \n";
				}
				else
				{
					std::cout << "Seu voto foi Lula \n";
					Lula++;
				}


			}

			std::cout << "Voto Confirmado. \n";
			PlaySound("urna.wav", NULL, SND_SYNC);

		}
		else if (ascii_value == 110)
		{
			continue;
		}
		else {
			std::cout << " Tecla incorreta \n";
			continue;
		}

		totalEleitores++;
		clear();
		std::cout << "Total Votos: " << totalEleitores << " \n";

		std::cout << "\n";

		std::cout << "Lula: " << Lula << "\n";
		std::cout << "Bolsonaro: " << Bolsonaro << "\n";
		std::cout << "Nulo ou Branco: " << NuloBranco << "\n";
	}
	
	std::cout << "\n";

	if (Lula > Bolsonaro)
		std::cout << "Novo Presidente foi Lula \n";

	if (Bolsonaro > Lula)
		std::cout << "Novo Presidente foi Bolsonaro \n";

	if (Bolsonaro == Bolsonaro)
		std::cout << "Empate, Segundo turno... \n";

	std::cout << "\n";

	std::cout << "Total Votos:" << totalEleitores << "\n";
	std::cout << "Total Votos Bolsonaro:" << Bolsonaro << "\n";
	std::cout << "Total Votos Lula:" << Lula << "\n";

	system("pause");
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
