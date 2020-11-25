#include <iostream>
#include <fstream>
#include <cmath>


int main() {
	std::ifstream fin ("datensumme.txt");
	std::ifstream fin2 ("datensumme.txt");
	//std::ofstream fout("datensumme.txt");
	double a;
	double summed=0;
	int i=0;
	double N=234;
	double mean;
	double summed_diff_sq=0;
	double b;
	int j=0;
	double var;
	double std_dev;
	
	while (fin >> a && i<234)
	{
		summed = a + summed;
		//std::cout << a  << "	" <<  b << "	sum = " << summed << std::endl;
		//fout << summed << std::endl;
		i++;
	}
	mean = summed/N;
	std::cout.precision(8);
	std::cout << mean << std::endl;
	
	while (fin2 >> b && j<234)
	{
		summed_diff_sq = (b - mean)*(b - mean) + summed_diff_sq;
		j++;
	}
	var = summed_diff_sq/N;
	std::cout.precision(8);
	std::cout << var << std::endl;
	
	std_dev = sqrt(var);
	std::cout << std_dev << std::endl;
	
	fin.close();
	fin2.close();
		
	return 0;
}
