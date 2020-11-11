#include <iostream>
#include <fstream>


int main() {
	std::ifstream fin ("daten.txt");
	std::ofstream fout("datensumme.txt");
	int a, b;
	int summed;
	int i=0;
	while (fin >> a >> b && i<234)
	{
		summed = a + b;
		//std::cout << a  << "	" <<  b << "	sum = " << summed << std::endl;
		fout << summed << std::endl;
		i++;
	}
	fin.close();
		
	return 0;
}
