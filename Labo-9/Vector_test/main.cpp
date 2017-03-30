/**
 * \file main.cpp
 * \brief
 * \author etudiant
 * \date 2017-03-24
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> tableau1;
	tableau1.push_back(10);
	tableau1.push_back(12);
	tableau1.push_back(11);
	for (size_t i = 0; i < tableau1.size(); ++i)
	{
		cout << tableau1[i] << " ";
	}
}
