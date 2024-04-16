#include"header.hpp"

using namespace std;

System::System(int a, int b): eq(a), inc(b)
{
	vector<vector<Fraction>> sub1, sub2, sub3;
	int c(0);
	
	for(int i=0; i < eq; i++)
	{
		sub1.push_back(vector<Fraction>());
		sub2.push_back(vector<Fraction>());
		sub3.push_back(vector<Fraction>());
		string m, n;
		n = "b" + to_string(i+1);
		name_ind.push_back(n);
		
		for(int j=0; j <= inc; j++)
		{
			sub1[i].push_back(0);
			
			if(j != inc)
			{
				if(i == 0)
				{
					string n = "x" + to_string(j+1);
					name_inc.push_back(n);
				}
				
				sub2[i].push_back(0);
				name_elt.push_back("");
				m = "a";
				m += to_string(c+1);
				name_elt[c] = m;
				c++;
			}
			
			else
				sub3[i].push_back(0);
		}
	}
	
	MB = sub1;
	M = sub2;
	B = sub3;
}

System::System(int a): System(a, a) {}

System::System(): eq(0), inc(0){}

System System::lire(istream& flux)
{
	int c(0);
	
	if(eq != 0)
	{
		Fraction s;
		cout<<endl<<" Les xi etant des inconnues, le systeme est de la forme: "<<endl<<endl;
		
		for(int i=0; i < eq; i++)
		{		
			for(int j=0; j <= inc; j++)
			{
				if(j != inc)
				{
					cout<<" "<<name_elt[c]<<"*"<<name_inc[j];
					
					if(j != inc-1)
						cout<<" + ";
						
					c++;
				}
				
				else
					cout<<" = "<<name_ind[i];
			}
			
			cout<<endl;
		}
		
		cout<<endl<<" Entrer les elements: "<<endl<<endl;
		c = 0;
		
		for(int i=0; i < eq; i++)
		{		
			for(int j=0; j <= inc; j++)
			{
				if(j != inc)
				{
					cout<<" "<<name_elt[c]<<": ";
					flux>>s;
					MB.set_matrice(i, j, s);
					M.set_matrice(i, j, s);
					cout<<endl;
					c++;
				}
			
				else
				{
					cout<<" "<<name_ind[i]<<": ";
					flux>>s;
					MB.set_matrice(i, j, s);
					B.set_matrice(i, 0, s);
				}
			}
			
			cout<<endl;
		}
	}
	
	else
	{
		vector<vector<Fraction>> sub1, sub2, sub3;
		cout<<endl<<" Nombres d'equations: ";
		flux>>eq;
		inc = eq;
		cout<<endl<<" Les xi etant des inconnues, le systeme est de la forme: "<<endl<<endl;
		
		for(int i=0; i < eq; i++)
		{
			sub1.push_back(vector<Fraction>());
			sub2.push_back(vector<Fraction>());
			sub3.push_back(vector<Fraction>());
			string m, n;
			n = "b" + to_string(i+1);
			name_ind.push_back(n);
			
			for(int j=0; j <= inc; j++)
			{
				sub1[i].push_back(0);
				if(j != inc)
				{
					if(i == 0)
					{
						string n = "x" + to_string(j+1);
						name_inc.push_back(n);
					}
					
					sub2[i].push_back(0);
					name_elt.push_back("");
					m = "a";
					m += to_string(c+1);
					name_elt[c] = m;
					c++;
				}
				
				else
					sub3[i].push_back(0);
			}
		}
		
		c = 0;
		
		for(int i=0; i < eq; i++)
		{
			for(int j=0; j <= inc; j++)
			{
				if(j != inc)
				{
					cout<<" "<<name_elt[c]<<"*"<<name_inc[j];
					
					if(j != inc-1)
						cout<<" + ";
						
					c++;
				}
				
				else
					cout<<" = "<<name_ind[i];
			}
			
			cout<<endl;
		}
		
		cout<<endl<<" Entrer les elements: "<<endl<<endl;
		c = 0;
		
		for(int i=0; i < eq; i++)
		{		
			for(int j=0; j <= inc; j++)
			{
				if(j != inc)
				{
					cout<<" "<<name_elt[c]<<": ";
					flux>>sub1[i][j];
					sub2[i][j] = sub1[i][j];
					cout<<endl;
					c++;
				}
			
				else
				{
					cout<<" "<<name_ind[i]<<": ";
					flux>>sub1[i][j];
					sub3[i][0] = sub1[i][j];
				}
			}
			
			cout<<endl;
		}
		
		MB = sub1;
		M = sub2;
		B = sub3;
	}
	
	return *this;
}

System operator>>(istream& flux, System& m)
{
	m.lire(flux);
	return m;
}

void System::afficher(ostream& flux) const
{
	cout<<" L'equation est: "<<endl<<endl;
		
	for(int i=0; i < eq; i++)
	{		
		for(int j=0; j <= inc; j++)
		{
			if(j != inc)
			{
				if(j == 0)
					flux<<" ";
					
				flux<<M.get_matrice(i, j)<<"*"<<name_inc[j];
				
				if(j != inc-1)
					flux<<" + ";
			}
				
			else
				flux<<" = "<<B.get_matrice(i, 0);
		}
			
		flux<<endl;
	}
}

ostream& operator<<(ostream& flux, System const& m)
{
	m.afficher(flux);
	return flux;
}

Matrice System::solution()
{
	int r(0);
	Fraction sub(M.rang());
	r = sub.get_num();
	
	if(M.calc_det() != 0)
	{
		Matrice S(B);
		S.set_name("S");
		S = B/M;
		return S;
	}
		
	else
	{
		if(MB.rang() != M.rang())
		{
			Matrice S("System Impossible",0 ,0);
			return S;
		}
		
		else
		{
			Matrice S("System Indetermine",0 ,0);
			cout<<" Rang du systeme = "<<M.rang()<<endl<<endl;
			return S;
		}
	}
}
