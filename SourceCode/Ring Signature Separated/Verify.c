//Ring signature based

//Algo: Verify

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{

int i,j;
//Read q, n, signature, filetext and other necessary parameters from the text file  
	
pairing_t pairing;
pbc_demo_pairing_init(pairing, argc, argv);
if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
	
element_t hom;
element_init_GT(hom, pairing);
element_from_hash(hom, filetext, strlen(filetext));

element_t temp1,temp2,temp3,temp4,temp5;
element_init_G1(ranA, pairing);
element_init_GT(temp1, pairing);
element_init_G1(temp2, pairing);
element_init_G1(temp3, pairing);
element_init_GT(temp4, pairing);
element_init_GT(temp5, pairing);
	
element_t c[n];
for(i=0;i<n;i++)
	{
		element_init_GT(c[i], pairing);
	}
	
for(i=0;i<n;i++)
{
element_pairing(temp1,t[i],P);
element_mul(temp3, c[i], QID[i]);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c[i+1], hom, temp5);
}

if (!element_cmp(c[0], c[n]))
    {
//Checking commitment for file at location i 
element_t commitver;
element_t temp096;
element_t divans;
element_t p1re,p2re;
element_init_G2(commitver, pairing);
element_init_G2(temp096, pairing);
element_init_G2(divans, pairing);
element_init_GT(p1re, pairing);
element_init_GT(p2re, pairing);

element_pow_zn(temp096,h[i],M[i]);
element_set(commitver,C[i]);
element_div(divans,commitver,temp096);
element_pairing(p1re,divans,h[i]);
element_pairing(p2re,proofi,g);
if (!element_cmp(p1re, p2re))
    {
        checksum=1;
    }
if(checksum==1)
        printf("Proof valid\n");
else
		printf("proof invalid\n");
  
	}
else
    {
		printf("Verification failed\n");
	}

}