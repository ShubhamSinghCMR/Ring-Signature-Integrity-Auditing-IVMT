//Public integrity auditing for shared dynamic cloud data with group user revocation

//Algo# 2: VLRKeyGen

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j;
//Read q, n and public parameters from the text file  

pairing_t pairing;
pbc_demo_pairing_init(pairing, argc, argv);
if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");

//Bilinear map is e : G1 X G2-> GT  	

//VLRKeyGen

        element_t g1,g2;		
		//g1: Generator of G1
		//g2: Generator of G2
    	
		element_init_G2(g2, pairing);
		element_init_G1(g1, pairing);
		element_random(g2);
		
		element_init_same_as(g1,g2);
		element_random(g1);
		
		element_t A[n],X[n],gsk[n][2],grt[n],gpk[3],Y,W,temp2,temp3;
		//(g1,g2,w): Group public key i.e. gpk
		//(A,x): Private key i.e gsk
		//(A): User revocation token i.e. grt
		
		element_init_Zr(Y, pairing);
		element_random(Y);
	
		element_init_G2(W, pairing);
		element_pow_zn(W,g2,Y);

		for(i=0;i<n;i++)
		{
			element_init_Zr(X[i], pairing);
			element_init_G1(A[i], pairing);
			element_init_G1(gsk[i][0], pairing);
			element_init_G1(gsk[i][1], pairing);
			element_init_G1(grt[i], pairing);
			element_init_G1(gpk[0], pairing);
			element_init_G1(gpk[1], pairing);
			element_init_G1(gpk[2], pairing);
		}

		element_init_Zr(temp2, pairing);
		element_init_Zr(temp3, pairing);

		for(i=0;i<n;i++)
			{
			    element_random(temp2);
				element_set(X[i],temp2);
				element_add(temp2,Y,temp2);
				while((element_is0(temp2)))
					{
						element_random(temp2);
						element_add(temp2,Y,temp2);
					}
				element_set(X[i],temp2);
				element_invert(temp3,temp2);
				element_pow_zn(A[i],g1,temp3);
				element_set(gsk[i][0],A[i]);
				element_set(gsk[i][1],X[i]);
				element_set(grt[i],A[i]);
			}
		element_set(gpk[0],g1);
		element_set(gpk[1],g2);
		element_set(gpk[2],W);

//Store the generated keys in a text file    	
		
}