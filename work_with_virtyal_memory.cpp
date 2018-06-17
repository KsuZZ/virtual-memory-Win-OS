#define _CRT_SECUSE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Windows.h"

using namespace std;
DWORD flag = PAGE_READONLY, Flag, old;
char *virt, *range, x;
int input = 1;
char mas[]="dvsdv";
BOOL tmp;

int main()
{
	//setlocale();
	cout << "1 - write" << endl;
	cout << "2 - read" << endl;
	cout << "3 - test" << endl;
	cout << "0 - exit" << endl;
	cout << endl;
	
	virt = (char*)VirtualAlloc(NULL, 5, MEM_COMMIT, PAGE_READWRITE);
	while (input != 0)
	{
		cin >> input;
		switch (input)
		{
		case 1:
			Flag = PAGE_READWRITE;
			cout << "Flag" << Flag << endl;
			VirtualProtect(virt, sizeof(virt), Flag, &old);
		    cout << "enter"<< endl;
			cin >> mas;
			cout << endl;
			strcpy(virt, mas);
			cout << "next action" << endl;
			break;
		case 2:
			Flag = PAGE_READONLY;
			cout << "Flag" << Flag << endl;
			VirtualProtect(virt, sizeof(virt), Flag, &old);
			cout << "Reverse order";
			for (int i = strlen(virt); i >= 0; i--)
			{
				range = &virt[i];
				x = *range;
				cout << x;
			}
			cout << endl;
			cout << "next action" << endl;
			break;
		case 3:
			Flag = PAGE_NOACCESS;
			cout << "Flag" << Flag << endl;
			tmp = VirtualProtect(virt, sizeof(virt), Flag, &old);
			cout << tmp << endl;
			try
			{
				for (int i = strlen(virt); i >= 0; i--)
				{
					range = &virt[i];
					x = *range;
					cout << x;
				}
			}
			catch (...)
			{
				cout << "Error" << endl;
			}
			cout << endl;
			cout << "next action" << endla;
			break;
		case 0:
			exit(0);
		}
	}
	system("pause");
} 
