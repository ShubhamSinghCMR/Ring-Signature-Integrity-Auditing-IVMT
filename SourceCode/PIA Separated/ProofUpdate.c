//Public integrity auditing for shared dynamic cloud data with group user revocation

//Algo: Update

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j;
	//Read q and other necessary parameters from the text file  
	
	pairing_t pairing;
	pbc_demo_pairing_init(pairing, argc, argv);
	if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
	
	//Read file
	i=0;
	j=0;
	file = fopen("Filepath", "r");
	while(fgets(line, sizeof line, file)!=NULL)
	{
	filetext[i]=line;
	i++;
	}
	fclose(file);
	
//User wants to update the file at location i
	
element_t newhashele;
element_init_G2(newhashele, pairing);
element_from_hash(newhashele, filetext, strlen(filetext));

element_t subtemp;
element_init_G2(subtemp, pairing);
element_sub(subtemp,newhashele,M[i]);

element_t R1yu;
element_init_G2(R1yu, pairing);
element_pow_zn(R1yu,h[i],subtemp);

element_t Cdash;
element_init_G2(Cdash, pairing);

element_mul(Cdash,C[i],R1yu);

element_set(C[i],Cdash);
element_set(M[i],newhashele);

element_t proofjdash;
element_init_G2(proofjdash, pairing);
    
element_t tempvar;
element_init_G2(tempvar, pairing);

element_pow_zn(tempvar,hij[j][i],subtemp);
element_mul(proofjdash,proofj,tempvar);
	
//Update file values
}