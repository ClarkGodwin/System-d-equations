#ifndef matrice_hpp
#define matrice_hpp

#include"fraction.hpp"
#include<vector>
#include<cmath>

class Matrice
{
	private:
		int line, column;
		std::string name;
		std::vector<std::vector<Fraction>> matrice;
		
	public:
		Matrice();
		Matrice(std::string nom, int ligne, int colonne);
		Matrice(std::string nom, int ordre);
		Matrice(int ligne, int colonne);
		Matrice(int ordre);
		Matrice(Matrice const& b);
		Matrice det_pr();
		Matrice puissance(int a);
		Fraction rang();
		bool condition_det() const;
		bool condition_inverse() const;
		bool condition_product(Matrice const& b) const;
		Fraction mineur(int a, int b) const;
		Fraction cofacteur(int a, int b) const;
		Fraction cofxelt(int a, int b) const;
		Fraction calc_det() const;
		void afficher(std::ostream& flux) const;
		Matrice lire(std::istream& flux);
		int get_line() const;
		int get_column() const;
		Fraction get_matrice(int i, int j) const;
		Matrice set_matrice(int i, int j, Fraction nbr);
		std::string get_name() const;
		Matrice set_name(std::string nom);
		Matrice transposed();
		Matrice inverse() const;
		Matrice mineur_matrice(int a, int b) const;
		Matrice sous_matrice_column(int a) const;
		Matrice sous_matrice_line(int a) const;
		Matrice operator+=(Matrice const& b);
		Matrice operator-=(Matrice const& b);
		Matrice operator*=(Fraction nbr);
		Matrice operator=(Matrice const& sub);
		Matrice operator=(std::vector<std::vector<Fraction>>& sub);
};

Fraction high(Fraction& a, Fraction& b);
Fraction highest(std::vector<Fraction> const& sub);
bool operator==(Matrice const& a, Matrice const& b);
Matrice operator*(Matrice& m1, Matrice& m2);
Matrice operator/(Matrice& m1, Matrice& m2);
Matrice operator+(Matrice const& m1, Matrice const& m2);
Matrice operator-(Matrice const& m1, Matrice const& m2);
std::ostream& operator<<(std::ostream& flux, Matrice const& m);
Matrice operator>>(std::istream& flux, Matrice& m);

#endif 
