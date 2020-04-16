//Public integrity auditing for shared dynamic cloud data with group user revocation

//Algo: Verify

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j;
	//Read q, gpk, signature and other necessary parameters from the text file  
	
	pairing_t pairing;
	pbc_demo_pairing_init(pairing, argc, argv);
	if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
	
	element_t c;
	element_init_Zr(c, pairing);
	element_set(c, Sig[3]);
	
	element_t r;
	element_init_Zr(r, pairing);
	element_set(r, Sig[0]);
	
	element_t salpha,sx,sdel;
	element_init_G2(salpha, pairing);
	element_init_G2(sx, pairing);
	element_init_G2(sdel, pairing);

	element_set(salpha, Sig[4]);
	element_set(sx, Sig[5]);
	element_set(sdel, Sig[6]);
	
	element_t T1,T2;
	element_init_G2(T1, pairing);
	element_init_G2(T2, pairing);
		
	element_set(T1, Sig[1]);
	element_set(T2, Sig[2]);
	
	element_t ucap,vcap;
    element_init_G2(ucap, pairing);
	element_init_G2(vcap, pairing);
	
    element_t u,v;
	element_init_same_as(u,ucap);
	element_init_same_as(v,vcap);
	
	element_t Rs1,Rs2,Rs3;
	element_init_G2(Rs1, pairing);
	element_init_G2(Rs2, pairing);
	element_init_G2(Rs3, pairing);
	
	//Read the metadata values
	
	element_t R1,R2,R3;
	element_init_G2(R1, pairing);
	element_init_G2(R2, pairing);
	element_init_G2(R3, pairing);

	element_t tempn1,tempn2,tempn3,tempn4,tempn5,tempn6;
	element_init_G2(tempn1, pairing);
	element_init_G2(tempn2, pairing);
	element_init_G2(tempn3, pairing);
	element_init_G2(tempn4, pairing);
	element_init_G2(tempn5, pairing);
	element_init_G2(tempn6, pairing);

	element_pow_zn(tempn1,u,salpha);
	element_pow_zn(tempn2,T1,c);
	element_div(R1,tempn1,tempn2);

	element_t p1,p2,p3,te1,te2,te3,te4,te5;
	element_init_G2(p1, pairing);
	element_init_G2(p2, pairing);
	element_init_G2(p3, pairing);
	element_init_G2(te1, pairing);
	element_init_G2(te2, pairing);
	element_init_G2(te3, pairing);
	element_init_G2(te4, pairing);
	element_init_G2(te5, pairing);

	element_pairing(p1,T2,g2);
	element_pow_zn(te1,p1,sx);

	element_pairing(p2,v,W);
	element_t revn;
	element_init_G2(revn, pairing);
	element_neg(revn,salpha);
	element_pow_zn(te2,p2,revn);

	element_pairing(p3,v,g2);
	element_t revn2;
	element_init_G2(revn2, pairing);
	element_neg(revn2,sdel);
	element_pow_zn(te3,p3,revn2);

	element_pairing(p4,T2,W);
	element_pairing(p5,g1,g2);
	element_div(te4,p4,p5);
	element_pow_zn(te5,te4,c);

	element_mul(tempn1,te1,te2);
	element_mul(tempn2,te3,te5);
	element_mul(R2,tempn1,tempn2);	

	element_init_G2(te6, pairing);
	element_init_G2(te7, pairing);
	element_pow_zn(te3,T1,sx);
	element_pow_zn(te4,u,revn2);
	element_mul(R3,te3,te4);
	
	int checkval=0;
	if (!element_cmp(R1, Rs1))
    {
		if (!element_cmp(R2, Rs2))
			{				
				if (!element_cmp(R3, Rs3))
					{	
						checkval=1;
					}
					
			}
	}
int checksum=0;
if(checkval!=1)
{
	printf("Signature is not valid. Verification failed");
}
else
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
        printf("proof valid\n");
else
    printf("proof invalid\n");
}

}