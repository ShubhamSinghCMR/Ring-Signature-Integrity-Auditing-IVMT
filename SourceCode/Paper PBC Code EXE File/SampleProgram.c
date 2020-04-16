#include <pbc.h>
#include <pbc_test.h>
#include<string.h>

void VCKeyGen(int q)
{
	int i,j;
		//Type A Pairing setup
		pairing_t pairing;
		char param[1024]="param/a.param";
		size_t count = strlen(param);
		if (!count) pbc_die("input error");
		pairing_init_set_buf(pairing, param, count);

		//
		element_t g;
		element_init_G1(g, pairing);
		element_random(g);
		
		element_t h[q],z[q];
		
		 for(i = 0; i < q; i++) 
			{
				element_init_G1(h[i], pairing);
				element_init_Zr(z[i], pairing);
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
		element_init_G1(temp1,pairing);
		
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
}
void VLRKeyGen(int n)
{
		int i,j;
		element_t g1,g2;
		element_init_G2(g2, pairing);
		element_init_G1(g1, pairing);
		element_random(g2);
		element_set(g1,G1(g2));
		
		element_t Y;
		element_init_Zr(Y, pairing);
		element_random(Y);
		
		element_t W;
		element_init_G2(W, pairing);
		element_pow_zn(W,g2,Y);
		
		element_t A[n],X[n],gsk[n][2],grt[n],gpk[3];
		
		
		for(i=0;i<n;i++)
		{
			element_init_Zr(X[i], pairing);
			element_init_G1(A[i], pairing);
			element_init_G2(gsk[i][0], pairing);
			element_init_G2(gsk[i][1], pairing);
			element_init_G1(grt[i], pairing);
			element_init_G2(gpk[i][0], pairing);
			element_init_G2(gpk[i][1], pairing);
			element_init_G2(gpk[i][2], pairing);
		}
		
		element_t temp2,temp3;
		element_init_G2(temp2, pairing);
		element_init_G2(temp3, pairing);
		
		for(i=0;i<n;i++)
			{
				element_random(X[i]);
				element_add(temp2,Y,X[i]);
				while((element_is0(temp2)))
					{
						element_random(X[i]);
						element_add(temp2,Y,X[i]);
					}	
				element_invert(temp3,temp2);
				element_pow_zn(A[i],g1,temp3);
				element_set(gsk[i][0],A[i]);
				element_set(gsk[i][1],X[i]);
				element_set(grt[i],A[i]);
			}
		element_set(gpk[0],g1);
		element_set(gpk[1],g2);
		element_set(gpk[2],W);
}

void VCCom(int q)
{
	int i,j;
	element_t M[q];
	element_t C[q];
	element_t Aux[q];
	element_t tempn;

	element_init_G2(tempn, pairing);
	for(i=0;i<q;i++)
	{
		element_init_G2(M[i], pairing);
		element_init_G2(C[i], pairing);
		element_init_G2(Aux[i], pairing);
	}
	for(i=0;i<q;i++)
	{
	element_random(M[i]);
	element_pow_zn(tempn,h[i],M[i]);
	element_set(C[i],tempn);
	element_set(Aux[i],M[i]);
	}
	
}

void VLRSign(int n,int i)
{
	element_t r,ucap,vcap;
	element_init_Zr(r, pairing);
	element_random(r);
	
	element_init_G2(ucap, pairing);
	element_init_G2(vcap, pairing);
	
	element_t u,v;
	element_init_G2(u, pairing);
	element_init_G2(v, pairing);
	
	element_set(u,G1(ucap));
	element_set(v,G1(vcap));
	
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
	
	element_t delsym;
	element_init_G2(delsym, pairing);
	
	element_mul(T2,A[i],tempnew);
	element_mul(delsym,X[i],alpha);
	
	element_t raplha,rx,rdel;
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
	element_init_G2(p1, pairing);
	element_init_G2(p2, pairing);
	element_init_G2(p3, pairing);
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
	element_mul(nte5,c,x[i]);
	element_add(salpha,ralpha,nte3);
	element_add(sx,rx,nte5);
	element_add(sdel,rdel,nte4);

	element_t Sig[7];
	for(i = 0; i < 7; i++) 
			{
				element_init_G2(Sig[i], pairing);
			}
	
	element_set(Sig[0], r);
	element_set(Sig[1], T1);
	element_set(Sig[2], T2);
	element_set(Sig[3], c);
	element_set(Sig[4], salpha);
	element_set(Sig[5], sx);
	element_set(Sig[6], sdel);
	
	//Send to server. Server adds this to Commitment file
	element_t Ct;//Element form of inut message
	//write signature to end of file
	//Compute its hash using any hasing algo Let hash be msgh
	element_from_hash(Ct, msgh, strlen(msgh));
	//Store this file msgh at server database
	
}

void VCOpen(element_t M[i],int i,element_t Aux[i])
{
	element_t proofi;
	element_init_G2(proofi, pairing);
	
	element_t tempvar;
	element_init_G2(tempvar, pairing);
	
	element_t premul;
	element_init_G2(premul, pairing);
	element_set(premul);
	
	for(i=0;i<q;i++)
	{
		element_pow_zn(tempvar,h[j],M[j]);
		element_mul(premul,premul,tempvar);
	}
	
		element_pow_zn(proofi,premul,z[i]);
		
}

//TPA Verification Code

void VLRVerify(element_t grt[n],element_t gpk[3], element_t Sig[7])
{
	int checkvar=0;
	element_t Ct1;
	element_init_G2(Ct1, pairing);
	//Read file msgh	
		//compute hash 
		element_from_hash(Ct1, msgh, strlen(msgh));
		if(!(element_cmp(Ct1,Ct))
		{
			checkvar=1;
		}
		
	//Checking commitment
	//VCVer Algorithm
	//Find M[i] value for inpute file
	//Then
	element_t powervar,divans,p1re,p2re;
	element_init_G2(powervar, pairing);
	element_init_G2(divans, pairing);
	element_init_G2(p1re, pairing);
	element_init_G2(p2re, pairing);
	
	element_pow_zn(powervar,h[i],M[i]);
	element_div(divans,Ct1,powervar);
	element_pairing(p1re,divans,h[i]);
	element_pairing(p2re,proofi,g);
	if(!(element_cmp(p1re,p2re))
		{
			checkvar=1;
		}
	
}

void VCUpdate()
{
	//Call VC.Verify
	//Find original commitment of the file using fileid
	
	element_t Cdash;
	element_init_G2(Cdash, pairing);
	
	element mdash;
	element_init_G2(mdash, pairing);
	element_random(mdash);
	
	element subtemp;
	element_init_G2(subtemp, pairing);
	element_sub(subtemp,mdash,M[i])
	
	element powtemp;
	element_init_G2(powtemp, pairing);
	element_pow_zn(powtemp,h[i],subtemp);
	element_mul(Cdash,C[i],powtemp);
	
	
}

void VCProofUpdate(int i, int j)
{
	//proofj valid for message at position j
	//uses update info of message at i to compute updated commitment and updated proof j 
	if(i!=j)
	{
	element_t Cdash;
	element_init_G2(Cdash, pairing);
	
	element mdash;
	element_init_G2(mdash, pairing);
	element_random(mdash);
	
	element subtemp;
	element_init_G2(subtemp, pairing);
	element_sub(subtemp,mdash,M[i])
	
	element powtemp;
	element_init_G2(powtemp, pairing);
	element_pow_zn(powtemp,h[i],subtemp);
	element_mul(Cdash,C[i],powtemp);
	
	//
	element_t proofjdash;
	element_init_G2(proofjdash, pairing);
	
	
		element_pow_zn(tempvar,hij[j][i],subtemp);
		element_mul(proofjdash,proofj,tempvar);
	
		
	}
	else
	{
	element_t Cdash;
	element_init_G2(Cdash, pairing);
	
	element mdash;
	element_init_G2(mdash, pairing);
	element_random(mdash);
	
	element subtemp;
	element_init_G2(subtemp, pairing);
	element_sub(subtemp,mdash,M[i])
	
	element powtemp;
	element_init_G2(powtemp, pairing);
	element_pow_zn(powtemp,h[i],subtemp);
	element_mul(Cdash,C[i],powtemp);
	element_t proofjdash;
	element_init_G2(proofjdash, pairing);
	
	element_set(proofjdash,proofi);

	}
	
}

void RevokeUser()
{
	element_t ucap,vcap;
	element_init_G2(ucap, pairing);
	element_init_G2(vcap, pairing);
	
	element_t u,v;
	element_init_G2(u, pairing);
	element_init_G2(v, pairing);
	
	element_set(u,G1(ucap));
	element_set(v,G1(vcap));
	
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
	element_div(R1,tempn1,T1);
	
	//R2 Computation
	element_t p1,p2,p3,p4,p5,te1,te2,te3,te4,te5;
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
	
	//R3 Computation
	element_t te6,te7;
	element_init_G2(te6, pairing);
	element_init_G2(te7, pairing);
	
	element_pow_zn(te3,T1,sx);
	element_pow_zn(te4,u,revn2);
	element_mul(R3,te3,te4);
	
	element_t p6,p7,tmk1;
	element_init_G2(p6, pairing);
	element_init_G2(p7, pairing);
	element_init_G2(tmk1, pairing);
	element_pairing(p7,T1,vcap);
	
	
	for(=0;i<n;i++)
	{
	element_div(tmk1,T2,A[i]);
	element_pairing(p6,tmk1,ucap);
	if(!(element_cmp(p6,p7))
		{
			printf("Revoked");
		}
	
		
	}
	
	
}

int main(int argc, char **argv) 
	{
		
	 
	}
	
	
	