#ifndef Fraction_hpp
#define Fraction_hpp

#include<iostream>
#include<string>

class Fraction
{
	private:
		double num, denum;
	public:
		Fraction(double a, double b);
		Fraction(double a);
		Fraction(int a);
		Fraction(std::string nombre);
		Fraction();
		Fraction(Fraction const& b);
		Fraction lire(std::istream& flux);
		Fraction puissance(int a);
		std::string ftos();
		void afficher(std::ostream& flux) const;
		double ppcm(double a, double b);
		int pgcd(int a, int b);
		Fraction inverse();
		Fraction reduit();
		double get_num() const;
		double get_denum() const;
		Fraction operator=(Fraction b);
		Fraction operator=(int b);
		Fraction operator=(double b);
		Fraction operator=(std::string nombre);
		bool operator>=(Fraction b) const;
		bool operator<=(Fraction b) const;
		bool operator>=(int b) const;
		bool operator<=(int b) const;
		bool operator>=(double b) const;
		bool operator<=(double b) const;
		Fraction operator+=(Fraction b);
		Fraction operator-=(Fraction b);
		Fraction operator*=(Fraction b);
		Fraction operator/=(Fraction b);
		Fraction operator+=(int b);
		Fraction operator-=(int b);
		Fraction operator*=(int b);
		Fraction operator/=(int b);
		Fraction operator+=(double b);
		Fraction operator-=(double b);
		Fraction operator*=(double b);
		Fraction operator/=(double b);
		int operator%(int b);
};

Fraction operator>>(std::istream& flux, Fraction& a);
std::ostream& operator<<(std::ostream& flux, Fraction a);
Fraction operator+(Fraction a, Fraction b);
Fraction operator-(Fraction a, Fraction b);
Fraction operator*(Fraction a, Fraction b);
Fraction operator/(Fraction a, Fraction b);
Fraction operator+(Fraction a, int b);
Fraction operator-(Fraction a, int b);
Fraction operator*(Fraction a, int b);
Fraction operator/(Fraction a, int b);
Fraction operator+(Fraction a, double b);
Fraction operator-(Fraction a, double b);
Fraction operator*(Fraction a, double b);
Fraction operator/(Fraction a, double b);
bool operator==(Fraction a, Fraction b);
bool operator!=(Fraction a, Fraction b);
bool operator>(Fraction a, Fraction b);
bool operator<(Fraction a, Fraction b);
bool operator==(Fraction a, int b);
bool operator!=(Fraction a, int b);
bool operator>(Fraction a, int b);
bool operator<(Fraction a, int b);
bool operator==(Fraction a, double b);
bool operator!=(Fraction a, double b);
bool operator>(Fraction a, double b);
bool operator<(Fraction a, double b);


#endif
