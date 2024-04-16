#ifndef header_hpp
#define header_hpp

#include"matrice.hpp"

class System
{
	private:
		int eq, inc;
		Matrice MB, M, B;
		std::vector<std::string> name_inc;
		std::vector<std::string> name_ind;
		std::vector<std::string> name_elt;
		
	public:
		System(int a, int b);
		System(int a);
		System();
		System lire(std::istream& flux);
		void afficher(std::ostream& flux) const; 
		Matrice solution();
};

System operator>>(std::istream& flux, System& a);
std::ostream& operator<<(std::ostream& flux, System const& m);

#endif
