//Ring signature based

//Algo: RingKeyGen

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j;
//Read q, n and public parameters from the text file  

pairing_t pairing;
pbc_demo_pairing_init(pairing, argc, argv);
if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");

//RingKeyGen

	element_t P;  			
	element_t Ppub, s;      //s is the MASTER key of TA
	element_init_G1(P, pairing);
	element_init_G1(Ppub, pairing);
	element_init_Zr(s, pairing);
  
	element_random(P);
	element_random(s);
	element_mul_zn(Ppub, P, s);

	element_t QID[n]; //Public Key
	element_t SID[n]; //Secret Key
	for(i=0;i<n;i++)
		{
			element_init_G1(QID[i], pairing);
			element_init_G1(SID[i], pairing);
		}
		
	//Read User ID's from a textfile in the array ID
	i=0;
	j=0;
	char line[10000];
	char* ID[n];  //User ID's
	FILE *file;
	file = fopen("User ID File Path", "r");	
	while(fgets(line, sizeof line, file)!=NULL)
		{
			ID[i]=line;
			i++;
		}
	fclose(file);
	
	for(i=0;i<n;i++)
		{
			element_from_hash(QID[i], ID[i], strlen(ID[i]));
			element_mul_zn(SID[i], QID[i], s);
		}
	
//Store P, Ppub, s in a file. They are a part of required parameters	
//Store the generated keys in a text file    	
		
}