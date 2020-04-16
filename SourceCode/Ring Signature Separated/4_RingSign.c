//Ring signature based

//Algo: RingSign

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j,min;
	//Read q, n and public parameters from the text file  
	
	pairing_t pairing;
	pbc_demo_pairing_init(pairing, argc, argv);
	if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
	
	//Let user k be the signer
	//This means that the user k will run the RingSign algorithm
	//Read required keys from the text file in which user keys are stored

	element_t ranA,temp1,temp2,temp3,temp4,temp5;
	element_init_G1(ranA, pairing);
    element_init_GT(temp1, pairing);
	element_init_G1(temp2, pairing);
	element_init_G1(temp3, pairing);
	element_init_GT(temp4, pairing);
	element_init_GT(temp5, pairing);
	
	element_t hom;
	element_init_GT(hom, pairing);
	
	element_t c[n],t[n];
	for(i=0;i<n;i++)
	{
		element_init_GT(c[i], pairing);
		element_init_GT(t[i], pairing);
	}
	
	element_random(ranA);
	element_pairing(temp1,ranA,P);
	element_from_hash(hom, filetext, strlen(filetext));
	element_mul_zn(c[k+1], hom, temp1);
	
	i=k+1;
	while(i!=k)
	{
		if(i==n)
			i=0;
		if(i+1==n)
			min=0;
		else 
			min=i;
		element_random(t[i]);
		element_pairing(temp1,t[i],P);
		element_mul(temp3, c[i], QID[i]);
		element_pairing(temp4,temp3,Ppub);
		element_mul(temp5, temp1, temp4);
		element_mul(c[min], hom, temp5);
		i++;
	}
element_mul(temp3, c[k], SID[k]);
element_sub(t[k],ranA,temp3);
	
//Signature is (co,t0,t1,..tn-1)
//Store the generated signature in a text file

}