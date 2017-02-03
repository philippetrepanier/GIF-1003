#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int x = 1;
	int total;

	while ( x <= 100 )
		total += x;
		++x;

	cout << "Le programme termine et le total est " << total << endl;
	return 0;
}