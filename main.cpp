#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

int calculate_omega(int local_hour);
double calculate_delta(int day);
double calculate_alfa(int omega, double delta, float phi);
double calculate_psi(double alfa, double delta ,float phi);

int main() {
	
	// Inputs
	float phi = -15.02; // value of latitude in degrees
	int day = 284; // day julian (value between 1 and 365)  11 de outubro = 284 link: https://www.calendarr.com/brasil
	int local_hour = 16; //Hora local GM
	
	double omega = calculate_omega(local_hour);
	double delta = calculate_delta(day);
	double alfa = calculate_alfa(omega, delta, phi);
	double psi = calculate_psi(alfa, delta, phi);

	//Logs
	std::cout << "Omega: " << omega << std::endl;
	std::cout << "Delta: " << delta << std::endl;
	std::cout << "Alfa: "  << alfa  << std::endl;
	std::cout << "PSI: "   << psi   << std::endl;

	return 0;
}

int calculate_omega(int local_hour) {
	int omega = (12 - local_hour) * 15;
	return omega;
}

double calculate_delta(int day) {
	double delta = 23.45 * sin(360 * (day - 80) / 365);
	return delta;
}

double calculate_alfa(int omega, double delta, float phi) {
	double alfa =  sin(delta) * sin(phi) + cos(delta) * cos(phi)*cos(omega);
	return alfa;
}

double calculate_psi(double alfa, double delta ,float phi) {
	double psi = (-sin(alfa) * sin(phi) + sin(delta)) /	 cos(alfa) * cos(phi);
	return psi; 
}