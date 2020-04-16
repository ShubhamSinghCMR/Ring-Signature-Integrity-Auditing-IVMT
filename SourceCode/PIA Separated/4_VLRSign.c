//Public integrity auditing for shared dynamic cloud data with group user revocation

//Algo# 4: VLRSign

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j;
	//Read q, n and public parameters from the text file  
	
	pairing_t pairing;
	pbc_demo_pairing_init(pairing, argc, argv);
	if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
	
	//Let user i be the signer
	//This means that the user i will run the VLRSign algorithm
	//gsk of user i will be needed during the signing process
	//Read required keys from the text file in which user keys are stored

	element_t r,ucap,vcap,c;
	element_init_Zr(r, pairing);
	element_random(r);
	
    element_init_G2(ucap, pairing);
	element_init_G2(vcap, pairing);

	element_random(ucap);
    element_random(vcap);

    element_t u,v;
	element_init_same_as(u,ucap);
	element_init_same_as(v,vcap);

	element_random(u);
    element_random(v);

	element_t alpha;
	element_init_Zr(alpha, pairing);
	element_random(alpha);

	element_t T1,T2;
	element_init_G2(T1, pairing);
	element_init_G2(T2, pairing);

	element_t tempnew;
	element_init_G2(tempnew, pairing);

	element_pow_zn(T1,u,alpha);
	element_pow_zn(tempnew,v,alpha);
	element_mul(T2,A[i],tempnew);

	element_t delsym;
	element_init_G2(delsym, pairing);

	element_mul(delsym,X[i],alpha);
	
	element_t ralpha,rx,rdel;
	element_init_Zr(ralpha, pairing);
	element_init_Zr(rx, pairing);
	element_init_Zr(rdel, pairing);
	
	element_random(ralpha);
	element_random(rx);
	element_random(rdel);
	
	element_t R1,R2,R3,p1,p2,p3,te1,te2,te3;
	element_init_G2(R1, pairing);
	element_init_G2(R2, pairing);
	element_init_G2(R3, pairing);
	element_init_GT(p1, pairing);
	element_init_GT(p2, pairing);
	element_init_GT(p3, pairing);
	element_init_G2(te1, pairing);
	element_init_G2(te2, pairing);
	element_init_G2(te3, pairing);
    
	element_pow_zn(R1,u,ralpha);
	
	element_pairing(p1,T2,g2);
	element_pow_zn(te1,p1,rx);
	
	element_pairing(p2,v,W);
	element_t revn;
	element_init_G2(revn, pairing);
	element_neg(revn,ralpha);
	element_pow_zn(te2,p2,revn);
	
	element_pairing(p3,v,g2);
	element_t revn2;
	element_init_G2(revn2, pairing);
	element_neg(revn2,rdel);
	element_pow_zn(te3,p3,revn2);
	
	element_t mktemp;
	element_init_G2(mktemp, pairing);
	element_mul(mktemp,te1,te2);
	element_mul(R2,mktemp,te3);
	
	element_t nte1,nte2;
	element_init_G2(nte1, pairing);
	element_init_G2(nte2, pairing);
    element_pow_zn(nte1,T1,rx);
	element_pow_zn(nte2,u,revn2);
	element_mul(R3,nte1,nte2);
    
	element_t c;
	element_init_Zr(c, pairing);
	element_random(c);
	
	element_t nte3,nte4,nte5,salpha,sx,sdel;
	element_init_G2(nte3, pairing);
	element_init_G2(nte4, pairing);
	element_init_G2(nte5, pairing);
	element_init_G2(salpha, pairing);
	element_init_G2(sx, pairing);
	element_init_G2(sdel, pairing);
	
	element_mul(nte3,c,alpha);
	element_mul(nte4,c,delsym);
	element_mul(nte5,c,X[i]);
	element_add(salpha,ralpha,nte3);
	element_add(sx,rx,nte5);
	element_add(sdel,rdel,nte4);

	element_t Sig[7];
	for(i = 0; i < 7; i++)
			{
				element_init_GT(Sig[i], pairing);
			}
	element_set(Sig[0], r);
	element_set(Sig[1], T1);
	element_set(Sig[2], T2);
	element_set(Sig[3], c);
	element_set(Sig[4], salpha);
	element_set(Sig[5], sx);
	element_set(Sig[6], sdel);

//Store the generated signature in a text file
//ucap, vcap, u, v, ralpha, rx, rdel, alpha, del, R1, R2, R3 is the metadata for this signature. Store it in a file    	
//Send the signature to the cloud server where cloud server process ttakes place

//Now the public key parameter is gpk and this file which is signed

}