#include"matrice.hpp"

using namespace std;

Matrice::Matrice(): name(""), line(0), column(0){}

Matrice::Matrice(string nom, int ligne, int colonne):name(nom), line(ligne), column(colonne)
{		
	for(int i=0; i < line; i++)
	{
		matrice.push_back(vector<Fraction>());
		for(int j=0; j < column; j++)
		{
			matrice[i].push_back(0);
		}
	}
}

Matrice::Matrice(string nom, int ordre):name(nom), line(ordre), column(ordre)
{
	for(int i=0; i < line; i++)
	{
		matrice.push_back(vector<Fraction>());
		for(int j=0; j < column; j++)
		{
			matrice[i].push_back(0);
		}
	}
}

Matrice::Matrice(int ligne, int colonne):name(""), line(ligne), column(colonne)
{		
	for(int i=0; i < line; i++)
	{
		matrice.push_back(vector<Fraction>());
		for(int j=0; j < column; j++)
		{
			matrice[i].push_back(0);
		}
	}
}

Matrice::Matrice(int ordre):name(""), line(ordre), column(ordre)
{
	for(int i=0; i < line; i++)
	{
		matrice.push_back(vector<Fraction>());
		for(int j=0; j < column; j++)
		{
			matrice[i].push_back(0);
		}
	}
}

Matrice::Matrice(Matrice const& b):name(b.name), line(b.line), column(b.column)
{
	Fraction nbr(0);
	for(int i=0; i < line; i++)
	{
		matrice.push_back(vector<Fraction>());
		for(int j=0; j < column; j++)
		{
			nbr = b.matrice[i][j];
			matrice[i].push_back(nbr);
		}
	}
}

Fraction Matrice::rang()
{
	if(line == 1)
	{
		if(matrice[0][0] == 0)
			return 0;
		else
			return 1;
	}
	
	else if(condition_det())
	{
		if(calc_det() != 0)
			return line;
			
		else
		{
			for(int i=0; i < line; i++)
			{
				for(int j=0; j < column; j++)
				{
					if(mineur(i, j) != 0)
						return line-1;
				}
			}
			
			Matrice substitute(line-1);
			vector<Fraction> nbr(pow(line, 2), 0);
			int it(0);
			Fraction r(0);
			
			for(int i=0; i < line; i++)
			{
				for(int j=0; j < column; j++)
				{
					substitute = mineur_matrice(i, j);
					nbr[it] = substitute.rang();
					it++;
				}
			}
			
			r = highest(nbr);
			return r;
		}
	}
	
	else if(condition_det() == false)
	{
		if(line == 1)
		{
			vector<Fraction> nbr(column);
			int it(0);
			Fraction r(0);
			for(int j=0; j < column; j++)
			{
				nbr[it] = matrice[0][j];
				it++;
			}
			
			r = highest(nbr);
			
			if(r == 0)
				return 0;
			else
				return 1;
		}
		
		if(column == 1)
		{
			vector<Fraction> nbr(line);
			int it(0);
			Fraction r(0);
			for(int i=0; i < line; i++)
			{
				nbr[it] = matrice[i][0];
				it++;
			}
			
			r = highest(nbr);
			
			if(r == 0)
				return 0;
			else
				return 1;
		}
		
		else
		{
			int taille(0), it(0);
			Fraction r(0);
			taille = line*column*2;
			vector<Fraction> nbr(taille, 0);
			Matrice substitute_line(line-1, column), substitute_column(line, column-1);
			for(int i=0; i < line; i++)
			{
				for(int j=0; j < column; j++)
				{
					substitute_line = sous_matrice_line(i);
					nbr[it] = substitute_line.rang();
					it++;
					substitute_column = sous_matrice_column(j);
					nbr[it] = substitute_column.rang();
					it++;
				}
			}
			
			r = highest(nbr);
			return r;
		}
	}
}

bool Matrice::condition_det() const
{
	return (line == column);
}

bool Matrice::condition_inverse() const
{
	if(condition_det())
	{
		Fraction det(calc_det());
		if(det == 0)
			return false;
		else
			return true;
	}
	
	else
		return false;
}


bool Matrice::condition_product(Matrice const& b) const
{
	return (column == b.line);
}

Matrice Matrice::sous_matrice_column(int a) const
{
	Matrice substitute(line, column-1);
	int x(0), y(0);
	for(int i=0; i < line; i++)
	{
		for(int j=0; j < column; j++)
		{
			if(j != a)
			{
				substitute.matrice[x][y] = matrice[i][j];
				y++;
			}
		}
		
		y = 0;
		x++;
	}
	
	return substitute;
}

Matrice Matrice::sous_matrice_line(int a) const
{
	Matrice substitute(line-1, column);
	int x(0), y(0);
	for(int i=0; i < line; i++)
	{
		if(i != a)
		{
			for(int j=0; j < column; j++)
			{
				substitute.matrice[x][y] = matrice[i][j];
				y++;
			}
			
			y = 0;
			x++;
		}
	}
	
	return substitute;
}

Matrice Matrice::mineur_matrice(int a, int b) const
{
	int x(0), y(0);
	Matrice matrice_mineur(line-1);
	
	for(int i=0; i < line; i++)
	{
		if(i != a)
		{
			for(int j=0; j < line; j++)
			{
				if(j != b)
				{
					matrice_mineur.matrice[x][y] = matrice[i][j];
					y++;
				}
			}
			x++;
			y = 0;
		}
	}
	
	return matrice_mineur;
}

Fraction Matrice::mineur(int a, int b) const
{
	int x(0), y(0);
	Matrice matrice_mineur(line-1);
	
	for(int i=0; i < line; i++)
	{
		if(i != a)
		{
			for(int j=0; j < line; j++)
			{
				if(j != b)
				{
					matrice_mineur.matrice[x][y] = matrice[i][j];
					y++;
				}
			}
			x++;
			y = 0;
		}
	}
	
	return matrice_mineur.calc_det();
}

Fraction Matrice::cofacteur(int a, int b) const
{
	int coeff(0), nbr(0);
	nbr = (a+b)%2;
	
	if(nbr == 0)
		coeff = 1;
	else
		coeff = -1;
	
	return coeff*mineur(a ,b);
}

Fraction Matrice::cofxelt(int a, int b) const
{
	return matrice[a][b]*cofacteur(a, b);
}

Fraction Matrice::calc_det() const
{
	Fraction determinant(0);
	if(line == 2)
		return matrice[0][0]*matrice[1][1] - matrice[1][0]*matrice[0][1];
			
	else if(line == 1)
		return matrice[0][0];
		   
	else if(line > 2)
	{
		for(int j=0; j < column; j++)
		{
			determinant += cofxelt(0, j);
		}
		
		return determinant;
	}
}

Matrice Matrice::det_pr()
{
	Matrice M, sub, a[line*column];
	bool r(false);
	Fraction e(rang());
	int ref(0), it(0);
	ref = e.get_num();
	
	if(condition_det())
	{
		for(int i=0; i < line; i++)
		{
			for(int j=0; j < column; j++)
			{
				sub = mineur_matrice(i, j);
				
				if(sub.calc_det() != 0 && ref == sub.line)
				{
					M = sub;
					r = true;
					break;
				}
					
				else if(sub.calc_det() == 0)
				{
					a[it] = sub.det_pr();
					
					if(ref == a[it].line)
					{
						M = a[it];
						r = true;
						break;
					}
					
					else
					{
						it++;
						continue;
					}
				}
			}
			
			if(r)
				break;
		}
	}
	
	return M;
}

int Matrice::get_line() const
{
	return line;
}

int Matrice::get_column() const
{
	return column;
}

Fraction Matrice::get_matrice(int i, int j) const
{
	return matrice[i][j];
}

Matrice Matrice::set_matrice(int i, int j, Fraction nbr)
{
	matrice[i][j] = nbr;
	return *this;
}

string Matrice::get_name() const
{
	return name;
}

Matrice Matrice::set_name(string nom)
{
	name = nom;
	return *this;
}

Matrice Matrice::transposed()
{
	Matrice substitute(line, column);
	substitute = *this;
	
	for(int i=0; i < line; i++)
	{
		for(int j=0; j < column; j++)
		{
			matrice[i][j] = substitute.matrice[j][i];
		}
	}
	
	return *this;
}

Matrice Matrice::inverse() const
{
	if(condition_inverse())
	{
		Matrice m("reverse_"+name, line);
		Fraction reverse_det(1/calc_det());
		for(int i=0; i < line; i++)
		{
			for(int j=0; j < column; j++)
			{
				Fraction nbr(cofacteur(i, j));
				m.matrice[i][j]= nbr;
			}
		}
		
		m.transposed();
		m *= reverse_det;
	
		return m;
	}
	
	else
		cout<<"Cette matrice est singuliere."<<endl;
}

Matrice Matrice::lire(istream& flux)
{
	cout<<" Nom de la matrice: ";
	flux>>name;
	cout<<endl;
	
	if(line == 0)
	{
		cout<<" Nombre de lignes: ";
		flux>>line;
		cout<<endl<<" Nombre de colonnes: ";
		flux>>column;
		cout<<endl;
		
		for(int i=0; i < line; i++)
		{
			matrice.push_back(vector<Fraction>());
			for(int j=0; j < column; j++)
			{
				matrice[i].push_back(0);
			}
		}
	}
	
	Fraction nbr;
	
	for(int i=0; i < line; i++)
	{
		for(int j=0; j < column; j++)
		{
			cout<<" "<<name<<"["<<i+1<<"]["<<j+1<<"]: ";
			flux>>nbr;
			matrice[i][j] = nbr;
			cout<<endl;
		}
	}
	return *this;
}

Matrice operator>>(istream& flux, Matrice& m)
{
	m.lire(flux);
	return m;
}

void Matrice::afficher(ostream& flux) const
{
	int r(0);
	Fraction a;
	vector<int> column_size(column, 0);
	vector<vector<string>> elt_str;
	vector<vector<int>> space;
	
	if(line != 0)
	{
		for(int i=0; i < line; i++)
		{
			elt_str.push_back(vector<string>());
			space.push_back(vector<int>());
			
			for(int j=0; j < column; j++)
			{
				elt_str[i].push_back(" ");
				space[i].push_back(0);
			}
		}
	
		for(int j=0; j < column; j++)
		{
			for(int i=0; i < line; i++)
			{
				a = matrice[i][j];
				elt_str[i][j] = a.ftos();
				r = elt_str[i][j].size();
			
				if(column_size[j] < r)
					column_size[j] = r;
			}
				
			for(int i=0; i < line; i++)
			{
				space[i][j] = column_size[j] - elt_str[i][j].size();
			}
		}
	
		cout<<" "<<name<<" = ";
		
		for(int i=0; i < line; i++)
		{
			cout<<"| ";
		
			for(int j=0; j < column; j++)
			{
				for(int y=0; y < space[i][j]; y++)
				{
					cout<<" ";
				}
				
				cout<<matrice[i][j];
				cout<<"  ";
			}
		
			cout<<"|"<<endl;
			
			for(int x=0; x < name.size()+4; x++)
			{
				cout<<" ";
			}
		}
	
		cout<<endl;
	}
	
	else
		cout<<" "<<name<<endl;
}

ostream& operator<<(ostream& flux, Matrice const& m)
{
	m.afficher(flux);
	return flux;
}

Matrice Matrice::operator=(Matrice const& sub)
{
	if(line == 0 && column == 0)
	{
		line = sub.line;
		column = sub.column;
		
		for(int i=0; i < line; i++)
		{
			matrice.push_back(vector<Fraction>());
			
			for(int j=0; j < column; j++)
			{
				matrice[i].push_back(0);
				matrice[i][j] = sub.matrice[i][j];
			}
		}
	}	
		
	else
	{
		if(line != sub.line || column != sub.column)
			cout<<"Erreur, types differents."<<endl;
		
		else
		{
			for(int i=0; i < line; i++)
			{
				for(int j=0; j < column; j++)
				{
					matrice[i][j] = sub.matrice[i][j];
				}
			}
		}
	}
	
	return *this;
}

Matrice Matrice::operator=(vector<vector<Fraction>>& sub)
{
	if(line == 0)
	{
		line = sub.size();
		column = sub[0].size();
	
		for(int i=0; i < line; i++)
		{
			matrice.push_back(vector<Fraction>());
		
			for(int j=0; j < column; j++)
			{
				matrice[i].push_back(0);
				matrice[i][j] = sub[i][j];
			}
		}
	}
	
	else
	{
		for(int i=0; i < line; i++)
		{	
			for(int j=0; j < column; j++)
			{
				matrice[i][j] = sub[i][j];
			}
		}
	}
	
	return *this;
}

Matrice Matrice::operator*=(Fraction nbr)
{
	for(int i=0; i < line; i++)
	{
		for(int j=0; j < column; j++)
		{
			matrice[i][j] *= nbr;
		}
	}
	
	return *this;
}

bool operator==(Matrice const& a, Matrice const& b)
{
	if(a.get_line() == b.get_line() && a.get_column() == b.get_column())
	{
		for(int i=0; i < a.get_line(); i++)
		{
			for(int j=0; j < a.get_column(); j++)
			{
				if(a.get_matrice(i, j) != b.get_matrice(i, j))
					return false;
					
				else if(i == a.get_line()-1 && j == a.get_column()-1 && a.get_matrice(i, j) == b.get_matrice(i, j))
					return true;
			}
		}
	}
	
	else
		return false;		
}

Matrice Matrice::operator+=(Matrice const& b)
{
	if(line == b.line && column == b.column)
	{
		for(int i=0; i < line; i++)
		{
			for(int j=0; j < column; j++)
			{
				matrice[i][j] += b.matrice[i][j];
			}
		}
	
		return *this;
	}
	
	else
		cout<<"Operation impossible car les 2 matrices sont de dimensions differentes"<<endl;
}

Matrice Matrice::operator-=(Matrice const& b)
{
	if(line == b.line && column == b.column)
	{
		for(int i=0; i < line; i++)
		{
			for(int j=0; j < column; j++)
			{
				matrice[i][j] -= b.matrice[i][j];
			}
		}
	
		return *this;
	}
	
	else
		cout<<"Operation impossible car les 2 matrices sont de dimensions differentes"<<endl;
}

Matrice operator+(Matrice const& m1, Matrice const& m2)
{
	Matrice m3(m1);
	m3 += m2;
	m3.set_name(m1.get_name() + " + " + m2.get_name());
	return m3;
}

Matrice operator-(Matrice const& m1, Matrice const& m2)
{
	Matrice m3(m1);
	m3 -= m2;
	m3.set_name(m1.get_name() + " - " + m2.get_name());
	return m3;
}

Matrice operator*(Matrice& m1, Matrice& m2)
{
	if(m1.condition_product(m2))
	{
		int line_m3(m1.get_line()), column_m3(m2.get_column()), it(m1.get_column());
		Fraction sum(0);
		string name_m3(m1.get_name()+" * "+m2.get_name());
		Matrice m3(name_m3, line_m3, column_m3);
		for(int i=0; i < line_m3; i++)
		{
			for(int j=0; j < column_m3; j++)
			{
				for(int k=0; k < it; k++)
				{
					sum += m1.get_matrice(i, k)*m2.get_matrice(k, j);
				}
				
				m3.set_matrice(i, j, sum);
				sum = 0;
			}
		}
	
		return m3;
	}
	
	else
		cout<<"Multiplication impossible car le nombre de colonnes de la premiere est different du nombre de lignes de la deuxieme."<<endl;
}

Matrice operator/(Matrice& m1, Matrice& m2)
{
	Matrice m(m2);
	m = m2.inverse();
	return m*m1;
}

Matrice Matrice::puissance(int a)
{
	Matrice m1(line, column), m2(line, column), m3(line, column);
	m1 = *this;
	m2 = *this;
	m3 = *this;
	
	if(a > 1)
	{
		for(int i=1; i < a; i++)
		{
			m1 = m2*m3;
			m2 = m1;
		}
	
		set_name("(" + name + ")^" + to_string(a));
	}
	
	*this = m1;
	
	return *this;
}

Fraction high(Fraction a, Fraction b)
{
	if(a > b)
		return a;
	else
		return b;
}

Fraction highest(vector<Fraction> const& sub)
{
	Fraction nbr(0);
	for(int i=0; i < sub.size(); i++)
	{
		nbr = high(nbr, sub[i]);
	}
	
	return nbr;
}
