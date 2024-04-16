#include"header.hpp"

using namespace std;

int main()
{
	System sys;
	string reponse;
	cout<<"  ********************************************"<<endl<<endl;
	cout<<"       Clark Godwin Niyonzima : System        "<<endl<<endl;
	cout<<"  ********************************************"<<endl<<endl;
	
	do{
		cout<<" Entrer les informations du systeme: "<<endl;
		cin>>sys;
		cout<<endl<<sys<<endl<<endl<<sys.solution()<<endl<<" Souhaitez-vous recommencer(oui ou non): ";
		
		do{
			cin>>reponse;
			
			if(reponse != "oui" && reponse != "Oui" && reponse != "OUI" && reponse != "non" && reponse != "Non" && reponse != "NON")
				cout<<endl<<" Erreur, choisissez entre oui et non: ";
				
		}while(reponse != "oui" && reponse != "Oui" && reponse != "OUI" && reponse != "non" && reponse != "Non" && reponse != "NON");
		
	}while(reponse == "oui" || reponse == "Oui" || reponse == "OUI");
	return 0;
}
