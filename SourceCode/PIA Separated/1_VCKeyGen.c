//Public integrity auditing for shared dynamic cloud data with group user revocation

//Algo# 1: VCKeyGen

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
int i,j;	
int q;		//No. of files present in the database which is shared by 'n' no. of users with only one data owner
int n; 		//No. of users in the group

//Input q and n 

pairing_t pairing;
pbc_demo_pairing_init(pairing, argc, argv);
if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");

//VCKeyGen

//Bilinear map is e : G X G-> GT

element_t g;			//g is the generator of group G
element_init_G1(g, pairing);
element_random(g);

element_t h[q],z[q];	//z[q] belongs to Zp which is the message space

for(i = 0; i < q; i++)
			{
				element_init_Zr(z[i], pairing);
				element_init_G1(h[i], pairing);
			}
			
for(i = 0; i < q; i++)
			{
			    element_random(z[i]);
			    element_pow_zn(h[i],g,z[i]);
			}

element_t hij[q][q];

for(i = 0; i < q; i++)
			{
				for(j = 0; j < q; j++)
                    {
						element_init_G1(hij[i][j], pairing);
                    }
			}
			
element_t temp1;
element_init_Zr(temp1, pairing);

for(i = 0; i < q; i++)
			{
				for(j = 0; j < q; j++)
                    {
						if(i!=j)
                            {
								element_mul(temp1,z[i],z[j]);
								element_pow_zn(hij[i][j],g,temp1);
			                }
                    }
            }
//(p,q,G,GT,H,g,hi,hij)are the public parameters
//Store q, n and public parameters in a text file    	
}