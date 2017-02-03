/**
 * \file puissance.cpp
 * \author FRM
 * \date 2013-10-09
 * \brief Programme démo calcul de x à la puissance y en langage C++
 */
#include <iostream>
using namespace std;
int main(void)
{
	int x;
	int y;
	int i = 0;
	int puissance;

	cout<<"Ce programme calcule x a la puissance y."<<endl;

	cout<<"Veuillez entrer la valeur entière de x (different de 0): "<<endl;
	cin >> x;
	/*A: x est différent de 0*/

	cout<<"\nVeuillez entre la valeur de y strictement positif: "<<endl;
	cin >> y;
	/*A: y > 0 */

	puissance = x;
	while (i < y - 1)
	{
		puissance = puissance * x;
		i++;
	}

	cout<<"x a la puissance y = "<<puissance<<endl;
	return 0;
}


