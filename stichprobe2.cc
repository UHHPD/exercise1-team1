#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

int main() {

double a;
double summed;
int i;
double N=9;
double mean;
double summed_diff_sq;
double b;
int j;
int c;
int k1;
int k2;
double var;
double var_bessel;
double std_dev;
std::vector<double> mean_vec(26);


	//for(int c = 0; c<26; ++c) 
	//{
		std::ifstream fin ("datensumme.txt");
		std::ifstream fin2 ("datensumme.txt");
		std::ofstream fout1("mittelwerte.txt");
		std::ofstream fout2("varianzen.txt");
		std::ofstream fout3("varianzen_bessel.txt");
		summed=0;
		i=0;
		summed_diff_sq=0;
		j=0;
		c=0;
		k1=0;
		
		while (fin >> a && i<234)
		{
			summed = a + summed;
			//std::cout << a  << "	" <<  b << "	sum = " << summed << std::endl;
			//fout << summed << std::endl;
			c++;
			
			// should produce an output of 26 numbers
			if (c == 9)
			{
				mean = summed/N;
				mean_vec[k1] = mean;
				std::cout.precision(8);
				//std::cout << "mean: " << mean << std::endl;
				fout1.precision(8);
				fout1 << mean << std::endl;
				summed=0;
				c=0;
				k1++;
			}

			i++;
		}
		
		c=0;
		k2=0;
	
		while (fin2 >> b && j<234)
		{
			summed_diff_sq = (b - mean_vec[k2])*(b - mean_vec[k2]) + summed_diff_sq;
			c++;
			
			// should produce an output of 26 numbers
			if (c == 9)
			{
				var = summed_diff_sq/N;
				var_bessel = var*(N/(N-1));	// with Bessel's correction
				std::cout.precision(8);
				//std::cout << "variance: " << var << std::endl;
				fout2.precision(8);
				fout2 << var << std::endl;
				fout3.precision(8);
				fout3 << var_bessel << std::endl;
				summed_diff_sq=0;
				c=0;
				k2++;
			}
			
			j++;
		}
		
	
		//std_dev = sqrt(var);
		//std::cout << "standard deviation: " << std_dev << std::endl;
	
		fin.close();
		fin2.close();
		fout1.close();
		fout2.close();
		fout3.close();
	//}
		
	return 0;
}
