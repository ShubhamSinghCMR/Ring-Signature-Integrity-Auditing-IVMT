//Ring signature based

//Algo: Query- VCOpen

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j;
	//Read q and other necessary parameters from the text file  
	
	pairing_t pairing;
	pbc_demo_pairing_init(pairing, argc, argv);
	if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");	
	
	//Computing proof for file at location i
	
element_t proofi;
element_t tempvar;
element_t premul;
element_init_GT(proofi, pairing);
element_init_GT(tempvar, pairing);
element_init_GT(premul, pairing);

element_set1(premul);
for(j=0;j<q;j++)
	{
	    if(j!=i)
            {
                element_pow_zn(tempvar,h[j],M[j]);
                element_mul(premul,premul,tempvar);
            }
	}
element_pow_zn(proofi,premul,z[i]);

//Store the generted proof

}