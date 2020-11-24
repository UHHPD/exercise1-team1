// Script to calculate the mean of the 26 means and variances from part a) and apply Bessel's correction
#include <iostream>
#include <fstream>
#include <cmath>

int main() {
	std::ifstream fin ("mittelwerte.txt");
	std::ifstream fin2 ("varianzen.txt");
	std::ifstream fin3 ("varianzen_bessel.txt");
	//std::ofstream fout("datensumme.txt");
	double a;
	double summed=0;
	int i=0;
	double N=26;
	double mean;
	double mean_2;
	double mean_2_Bessel;
	double summed_2=0;
	double summed_3=0;
	double b;
	int j=0;
	int k=0;
	double var;
	double std_dev;
	double c;
	
	while (fin >> a && i<26)
	{
		summed = a + summed;
		//std::cout << a  << "	" <<  b << "	sum = " << summed << std::endl;
		//fout << summed << std::endl;
		i++;
	}
	mean = summed/N;
	std::cout.precision(16);
	std::cout << "mean of the 26 means: " << mean << std::endl;
	
	
	
	while (fin2 >> b && j<26)
	{
		summed_2 = b + summed_2;
		//std::cout << a  << "	" <<  b << "	sum = " << summed << std::endl;
		//fout << summed << std::endl;
		j++;
	}
	mean_2 = summed_2/N;
	std::cout.precision(16);
	std::cout << "mean of the 26 variances: " << mean_2 << std::endl;
	
	
	while (fin3 >> c && k<26)
	{
		summed_3 = c + summed_3;
		//std::cout << a  << "	" <<  b << "	sum = " << summed << std::endl;
		//fout << summed << std::endl;
		k++;
	}
	mean_2_Bessel = summed_3/N;
	std::cout.precision(16);
	std::cout << "mean of the 26 variances with Bessel's correction: " << mean_2_Bessel<< std::endl;
	
	
	/*
	while (fin2 >> b && j<234)
	{
		summed_diff_sq = (b - mean)*(b - mean) + summed_diff_sq;
		j++;
	}
	var = summed_diff_sq/N;
	std::cout.precision(16);
	std::cout << "variance: " << var << std::endl;
	
	std_dev = sqrt(var);
	std::cout << "standard deviation: " << std_dev << std::endl;
	*/
	
	fin.close();
	fin2.close();
	fin3.close();
		
	return 0;
}
