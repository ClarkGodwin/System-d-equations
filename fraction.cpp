#include"fraction.hpp"

using namespace std;

Fraction::Fraction(double a, double b):num(a), denum(b)
{
	reduit();
}

Fraction::Fraction(double a):num(a), denum(1){}

Fraction::Fraction(int a):num(a), denum(1){}

Fraction::Fraction(string nombre)
{
	*this = nombre;
	reduit();
}

Fraction::Fraction():num(1), denum(1){}

Fraction::Fraction(Fraction const& b):num(b.num), denum(b.denum){}

string Fraction::ftos()
{
	reduit();
	string answer, answer_num(to_string(num)), answer_denum(to_string(denum)), subn, subd;
	int in(0), id(0),tn(0), td(0), x(0), y(0);
	tn = answer_num.size();
	td = answer_denum.size();
	in = answer_num.find('.');
	id = answer_denum.find('.');
	bool r(true);
	
	if(denum == 1)
	{
		if(num == int(num))
		{
			for(int i=0; i < in; i++)
			{
				subn += " ";
				subn[i] = answer_num[i];
			}
			
			answer = subn;
		}
			
		else
		{
			x = answer_num.size();
			
			for(int i=in; i < tn; i++)
			{
				 if(answer_num[i] == '0')
				 {
				 	for(int j=i; j < tn; j++)
				 	{
						if(answer_num[j] != '0')
							break;
				 			
						else if(answer_num[j] == '0' && j == answer_num.size()-1)
							x = i;
				 	}
				 }
				 
				 if(x == i)
				 	break; 
			}
			
			for(int i=0; i < x; i++)
			{
				subn += " ";
				subn[i] = answer_num[i];
			}
			
			answer = subn;
		}
	}
		
	else
	{
		if(num == int(num))
		{
			for(int i=0; i < in; i++)
			{
				subn += " ";
				subn[i] = answer_num[i];
			}
			
			answer_num = subn;
	
				
			if(denum == int(denum))
			{
				for(int i=0; i < id; i++)
				{
					subd += " ";
					subd[i] = answer_denum[i];
				}
			
				answer_denum = subd;
			}
				
			else
			{
				y = answer_denum.size();
				
				for(int i=id; i < td; i++)
				{
					 if(answer_denum[i] == '0')
					 {
					 	for(int j=i; j < td; j++)
					 	{
							if(answer_denum[j] != '0')
								break;
					 			
							else if(answer_denum[j] == '0' && j == answer_denum.size()-1)
								y = i;
					 	}
					 }
					 
					 if(y == i)
					 	break;
				}
			
				for(int i=0; i < y; i++)
				{
					subd += " ";
					subd[i] = answer_denum[i];
				}
			
				answer_denum = subd;
			}
		}
			
		else
		{
			x = answer_num.size();
			
			for(int i=in; i < tn; i++)
			{
				 if(answer_num[i] == '0')
				 {
				 	for(int j=i; j < tn; j++)
				 	{
			 			if(answer_num[j] != '0')
			 				break;
				 			
			 			else if(answer_num[j] == '0' && j == answer_num.size()-1)
			 				x = i;
				 	}
				 }
				 
				 if(x == i)
				 	break;
			}
			
			for(int i=0; i < x; i++)
			{
				subn += " ";
				subn[i] = answer_num[i];
			}
			
			answer_num = subn;
			
			if(denum == int(denum))
			{
				for(int i=0; i < id; i++)
				{
					subd += " ";
					subd[i] = answer_denum[i];
				}
			
				answer_denum = subd;
			}
				
			else
			{
				y = answer_denum.size();
				
				for(int i=id; i < td; i++)
				{
					 if(answer_denum[i] == '0')
					 {
					 	for(int j=i; j < td; j++)
					 	{
				 			if(answer_denum[j] != '0')
				 				break;
					 			
				 			else if(answer_denum[j] == '0' && j == answer_denum.size()-1)
				 				y = i;
					 	}
					 }
					 
					 if(y == i)
					 	break;
				}
			
				for(int i=0; i < y; i++)
				{
					subd += " ";
					subd[i] = answer_denum[i];
				}
			
				answer_denum = subd;
			}
		}
		
		answer = answer_num + "/" + answer_denum;
	}
		
	return answer;
}

Fraction Fraction::lire(istream& flux)
{
	string nombre, num_str, denum_str;
	flux>>nombre;
	*this = nombre;
	return *this;
}

Fraction operator>>(istream& flux, Fraction& a)
{
	a.lire(flux);
	return a;
}

void Fraction::afficher(ostream& flux) const
{
	if(denum == 1)
		cout<<num;
		
	else
		flux<<num<<"/"<<denum;
}

ostream& operator<<(ostream& flux, Fraction a)
{
	Fraction m(a);
	m.afficher(flux);
	return flux;
}

double Fraction::get_num() const
{
	return num;
}

double Fraction::get_denum() const
{
	return denum;
}

double Fraction::ppcm(double a, double b)
{
	double x(a), y(b);
	if(x >= 0 && y >= 0)
	{
		while(x != y)
		{
			if(x > y)
				y = y+b;
			
			else if(x < y)
				x = x+a;
		}
	}
	
	else if(x < 0 || y < 0)
	{
		if(x < 0)
		{
			x *= -1;
			x = ppcm(x, y);
		}
		
		else
		{
			y *= -1;
			x = ppcm(x, y);
		}
	}
	
	else if(x < 0 && y < 0)
	{
		x *= -1;
		y *= -1;
		x = ppcm(x, y);
	}
	
	return x;
}

int Fraction::pgcd(int a, int b)
{
	int x(a), y(b), r(0);
	
	if(x >= 0 && y >= 0)
	{
		r = x%y;
	
		while(r != 0)
		{
			x = y;
			y = r;
			r = x%y;
		}
	}
	
	else if(x < 0 || y < 0)
	{
		if(x < 0)
		{
			x *= -1;
			y = pgcd(x, y);
		}
		
		else
		{
			y *= -1;
			y = pgcd(x, y);
		}
	}
	
	else if(x < 0 && y < 0)
	{
		x *= -1;
		y *= -1;
		y = pgcd(x, y);
	}
	
	return y;
}

Fraction Fraction::inverse()
{
	double a(num);
	num = denum;
	denum = a;
	return *this;
}

Fraction Fraction::reduit()
{
	string num_str, denum_str;
	int in(0), id(0);
	num_str = to_string(num);
	in = num_str.find('.');
	denum_str = to_string(denum);
	id = denum_str.find('.');
	
	if(in != string::npos && id != string::npos)
	{
		if(denum == 1)
			return *this;
		
		else if(num == 0 || denum == 0)
		{
			if(denum == 0)
				cout<<"Erreur, denominateur = 0, correction automatique, denominateur = 1"<<endl;
			denum = 1;
		}
	
		else if(num*denum < 0)
		{
			if(num < 0)
			{
				double nbr(0);
				nbr = pgcd(num, denum);
				num /= nbr;
				denum /= nbr;
			}
			
			else
			{
				num *= -1;
				denum *= -1;
				reduit();
			}
		}
		
		else if(num*denum > 0) 
		{
			if(num > 0)
			{
				double nbr(0);
				nbr = pgcd(num, denum);
				num /= nbr;
				denum /= nbr;
			}
			
			else
			{
				num *= -1;
				denum *= -1;
				reduit();
			}
		}
	}
		
	else
	{
		if(num == 0)
			denum = 1;
			
		else if(num == denum)
		{
			num = 1;
			denum = 1;
		}
			
		else if(num*denum > 0) 
		{
			if(num > 0)
			{
				num /= denum;
				denum = 1;
			}
			
			else
			{
				num *= -1;
				denum *= -1;
				reduit();
			}
		}
		
		else
		{
			if(num < 0)
			{
				num /= denum;
				denum = 1;
			}
			
			else
			{
				num *= -1;
				denum *= -1;
				reduit();
			}
		}
	}
	
	return *this;
}

Fraction Fraction::operator=(Fraction b)
{
	num = b.num;
	denum = b.denum;
	return *this;
}

Fraction Fraction::operator=(int b)
{
	num = b;
	denum = 1;
	return *this;
}

Fraction Fraction::operator=(double b)
{
	num = b;
	denum = 1;
	return *this;
}

Fraction Fraction::operator=(string nombre)
{
	int i(0);
	i = nombre.find('/');
	
	if(i == string::npos)
	{
		num = stod(nombre);
		denum = 1;
	}
	
	else
	{
		string num_str, denum_str;
		num_str = nombre.substr(0, i);
		denum_str = nombre.substr(i+1);
		num = stod(num_str);
		denum = stod(denum_str);
		reduit();
	}
	
	return *this;
}

bool Fraction::operator>=(Fraction b) const
{
	return ((num >= b.num) && (denum >= b.denum));
}

bool Fraction::operator<=(Fraction b) const
{
	return ((num <= b.num) && (denum <= b.denum));
}

bool Fraction::operator>=(int b) const
{
	return ((num >= b) && (denum >= 1));
}

bool Fraction::operator<=(int b) const
{
	return ((num <= b) && (denum <= 1));
}

bool Fraction::operator>=(double b) const
{
	return ((num >= b) && (denum >= 1));
}

bool Fraction::operator<=(double b) const
{
	return ((num <= b) && (denum <= 1));
}

bool operator>(Fraction a, Fraction b)
{
	return ((a.get_num() > b.get_num()) && (a.get_denum() > b.get_denum()));
}

bool operator<(Fraction a, Fraction b)
{
	return ((a.get_num() < b.get_num()) && (a.get_denum() < b.get_denum()));
}

bool operator==(Fraction a, Fraction b)
{
	return ((a.get_num() == b.get_num()) && (a.get_denum() == b.get_denum()));
}

bool operator!=(Fraction a, Fraction b)
{
	return !(a == b);
}

bool operator>(Fraction a, int b)
{
	return ((a.get_num() > b) && (a.get_denum() > 1));
}

bool operator<(Fraction a, int b)
{
	return ((a.get_num() < b) && (a.get_denum() < 1));
}

bool operator==(Fraction a, int b)
{
	return ((a.get_num() == b) && (a.get_denum() == 1));
}

bool operator!=(Fraction a, int b)
{
	return !(a == b);
}

bool operator>(Fraction a, double b)
{
	return ((a.get_num() > b) && (a.get_denum() > 1));
}

bool operator<(Fraction a, double b)
{
	return ((a.get_num() < b) && (a.get_denum() < 1));
}

bool operator==(Fraction a, double b)
{
	return ((a.get_num() == b) && (a.get_denum() == 1));
}

bool operator!=(Fraction a, double b)
{
	return !(a == b);
}

Fraction Fraction::operator+=(Fraction b)
{
	double nbr(ppcm(denum, b.denum));
	num = num*(nbr/denum) + b.num*(nbr/b.denum);
	denum = nbr;
	reduit();
	return *this;
}

Fraction Fraction::operator-=(Fraction b)
{
	double nbr(ppcm(denum, b.denum));
	num = num*(nbr/denum) - b.num*(nbr/b.denum);
	denum = nbr;
	reduit();
	return *this;
}

Fraction Fraction::operator*=(Fraction b)
{
	num = num*b.num;
	denum = denum*b.denum;
	reduit();
	return *this;
}

Fraction Fraction::operator/=(Fraction b)
{
	Fraction m(b);
	*this *= m.inverse();
	return *this;
}

Fraction Fraction::operator+=(int b)
{
	double nbr(ppcm(denum, 1));
	num = num*(nbr/denum) + b*nbr;
	denum = nbr;
	reduit();
	return *this;
}

Fraction Fraction::operator-=(int b)
{
	double nbr(ppcm(denum, 1));
	num = num*(nbr/denum) - b*nbr;
	denum = nbr;
	reduit();
	return *this;
}

Fraction Fraction::operator*=(int b)
{
	num = num*b;
	reduit();
	return *this;
}

Fraction Fraction::operator/=(int b)
{
	Fraction m(b);
	*this *= m.inverse();
	return *this;
}

Fraction Fraction::operator+=(double b)
{
	double nbr(ppcm(denum, 1));
	num = num*(nbr/denum) + b*nbr;
	denum = nbr;
	reduit();
	return *this;
}

Fraction Fraction::operator-=(double b)
{
	double nbr(ppcm(denum, 1));
	num = num*(nbr/denum) - b*nbr;
	denum = nbr;
	reduit();
	return *this;
}

Fraction Fraction::operator*=(double b)
{
	num = num*b;
	reduit();
	return *this;
}

Fraction Fraction::operator/=(double b)
{
	Fraction m(b);
	*this *= m.inverse();
	return *this;
}

int Fraction::operator%(int b)
{
	double nbr(num/denum);
	int a(0);
	
	if(int(nbr) != nbr)
		cout<<"Erreur, ce nombre n'est pas un entier"<<endl;
		
	else
	{
		a = nbr;
		return a%b;
	}
}

Fraction operator+(Fraction a, Fraction b)
{
	Fraction m(a);
	m += b;
	return m;
}

Fraction operator-(Fraction a, Fraction b)
{
	Fraction m(a);
	m -= b;
	return m;
}

Fraction operator*(Fraction a, Fraction b)
{
	Fraction m(a);
	m *= b;
	return m;
}

Fraction operator/(Fraction a, Fraction b)
{
	Fraction m(a);
	m /= b;
	return m;
}

Fraction operator+(Fraction a, int b)
{
	Fraction m(a);
	m += b;
	return m;
}

Fraction operator-(Fraction a, int b)
{
	Fraction m(a);
	m -= b;
	return m;
}

Fraction operator*(Fraction a, int b)
{
	Fraction m(a);
	m *= b;
	return m;
}

Fraction operator/(Fraction a, int b)
{
	Fraction m(a);
	m /= b;
	return m;
}

Fraction operator+(Fraction a, double b)
{
	Fraction m(a);
	m += b;
	return m;
}

Fraction operator-(Fraction a, double b)
{
	Fraction m(a);
	m -= b;
	return m;
}

Fraction operator*(Fraction a, double b)
{
	Fraction m(a);
	m *= b;
	return m;
}

Fraction operator/(Fraction a, double b)
{
	Fraction m(a);
	m /= b;
	return m;
}

Fraction Fraction::puissance(int a)
{
	Fraction m1, m2, m3;
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
	}
	
	*this = m1;
	reduit();
	
	return *this;
}
