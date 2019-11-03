#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s)
	: seed(s)
{
	if(seed==0){
		std::random_device rd;
		seed = rd();
	}
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& v, double lower, double upper){
	std::uniform_real_distribution<double> distribution(lower, upper);
	for(auto& value : v){
		value = distribution(rng);
	}
}

double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution<double> distribution(lower, upper);
	return distribution(rng);
}

void RandomNumbers::normal(std::vector<double>& v, double mean, double sd){
	std::normal_distribution<double> distribution(mean, sd);
	for(auto& value : v){
		value = distribution(rng);
	}
}

double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<double> distribution(mean, sd);
	return distribution(rng);
}

void RandomNumbers::poisson(std::vector<int>& v, double mean){
	std::poisson_distribution<int> distribution(mean);
	for(auto& value : v){
		value = distribution(rng);
	}
}

int RandomNumbers::poisson(double mean){
	std::poisson_distribution<int> distribution(mean);
	return distribution(rng);
}
