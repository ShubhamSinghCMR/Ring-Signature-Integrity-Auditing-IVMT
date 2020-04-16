#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv)
{
int i,j;
int q=20;
int n=4;
int tmp=0;
int temp=0;
int fileval=0;
int line=35;
FILE *file;
char filetext[line][9000];
char* filetext1[10000];
char* filename[10000];
char line1[10000];
double time1, time2;
pairing_t pairing;
pbc_demo_pairing_init(pairing, argc, argv);
if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
file = fopen("E:\Segmentaa.txt","r");
if (file== NULL)
        {
        printf("can not open file \n");
        return 1;
        }
while(fgets(filetext[fileval], sizeof filetext[fileval], file)!= NULL)
    {
		fileval++;
		tmp++;
    }
fclose(file);
//File read
element_t g,A[n],X[n],gsk[n][2],grt[n],gpk[3],Y,W,temp2,temp3;
element_t teop1,teop2,teop4,teop5,teop6,teop7,teop8,teop9,teop10,teop11;
element_t h[q+1],z[q+1];
element_t hij[q+1][q+1];
element_t temp1;
element_t g1,g2;
element_t M[q+1];
element_t C[q+1];
element_t Aux[q+1];
element_t tempn;
element_t r,ucap,vcap,c;
element_t u,v;
element_t alpha;
element_t T1,T2;
element_t tempnew;
element_t delsym;
element_t ralpha,rx,rdel;
element_t R1,R2,R3,p1,p2,p3,p4,p5,p6,te1,te2,te3,te4,te5,te6,te7;
element_t revn;
element_t revn2;
element_t mktemp;
element_t nte1,nte2;
element_t nte3,nte4,nte5,salpha,sx,sdel;
element_t Rs1,Rs2,Rs3;
element_t proofi;
element_t tempvar;
element_t premul;
element_t tempn1,tempn2,tempn3,tempn4,tempn5,tempn6;
element_init_G1(g, pairing);
for(i = 0; i < q+1; i++)
			{
				element_init_Zr(z[i], pairing);
				element_init_G1(h[i], pairing);
			}
for(i = 0; i < q+1; i++)
			{
				for(j = 0; j < q+1; j++)
                    {
						element_init_G1(hij[i][j], pairing);
                    }
			}
element_init_Zr(temp1, pairing);
element_init_G2(g2, pairing);
element_init_G1(g1, pairing);
element_init_Zr(Y, pairing);
element_init_G2(W, pairing);
for(i=0;i<n;i++)
		{
			element_init_G1(X[i], pairing);
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
element_init_GT(tempn, pairing);
for(i=0;i<q+1;i++)
	{
		element_init_G2(M[i], pairing);
		element_init_G2(C[i], pairing);
		element_init_G2(Aux[i], pairing);
	}
element_init_G1(r, pairing);
element_init_G2(ucap, pairing);
element_init_G2(vcap, pairing);
element_init_Zr(alpha, pairing);
element_init_G2(T1, pairing);
element_init_G2(T2, pairing);
element_init_G2(tempnew, pairing);
element_init_G2(delsym, pairing);
element_init_G1(ralpha, pairing);
element_init_G1(rx, pairing);
element_init_G1(rdel, pairing);
element_init_G2(R1, pairing);
element_init_G2(R2, pairing);
element_init_G2(R3, pairing);
element_init_GT(p1, pairing);
element_init_GT(p2, pairing);
element_init_GT(p3, pairing);
element_init_GT(p4, pairing);
element_init_GT(p5, pairing);
element_init_GT(p6, pairing);
element_init_G2(te1, pairing);
element_init_G2(te2, pairing);
element_init_G2(te3, pairing);
element_init_G2(te4, pairing);
element_init_G2(te5, pairing);
element_init_G2(te6, pairing);
element_init_G2(te7, pairing);
element_init_G2(revn, pairing);
element_init_G2(revn2, pairing);
element_init_G2(mktemp, pairing);
element_init_G2(nte1, pairing);
element_init_G2(nte2, pairing);
element_init_G1(c, pairing);
element_init_G2(nte3, pairing);
element_init_G2(nte4, pairing);
element_init_G2(nte5, pairing);
element_init_G2(salpha, pairing);
element_init_G2(sx, pairing);
element_init_G2(sdel, pairing);
element_init_G1(teop2, pairing);
element_init_G1(teop4, pairing);
element_init_G1(teop5, pairing);
element_init_G1(teop7, pairing);
element_init_Zr(teop1, pairing);
element_init_GT(teop6, pairing);
element_init_GT(teop8, pairing);
element_init_GT(teop9, pairing);
element_init_GT(teop10, pairing);
element_init_GT(teop11, pairing);
element_init_G2(Rs1, pairing);
element_init_G2(Rs2, pairing);
element_init_G2(Rs3, pairing);
element_init_G1(proofi, pairing);
element_init_G1(tempvar, pairing);
element_init_G1(premul, pairing);
element_init_G2(tempn1, pairing);
element_init_G2(tempn2, pairing);
element_init_G2(tempn3, pairing);
element_init_G2(tempn4, pairing);
element_init_G2(tempn5, pairing);
element_init_G2(tempn6, pairing);
element_init_G2(te6, pairing);
element_init_G2(te7, pairing);
element_random(g);
for(i = 0; i < q+1; i++)
			{
			    element_random(z[i]);
			    element_pow_zn(h[i],g,z[i]);
			}
for(i = 0; i < q+1; i++)
			{
				for(j = 0; j < q+1; j++)
                    {
						if(i!=j)
                            {
								element_mul(temp1,z[i],z[j]);
								element_pow_zn(hij[i][j],g,temp1);
                             }
                    }
            }
element_random(g2);
element_init_same_as(g1,g2);
element_random(g1);
element_random(Y);
element_pow_zn(W,g2,Y);
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
for(i=0;i<q;i++)
	{
	element_random(M[i]);
	element_pow_zn(tempn,h[i],M[i]);
	element_set(C[i],tempn);
	element_set(Aux[i],M[i]);
	}
/*
i=0;
j=0;
file = fopen("E:\filenames.txt", "r");
while(fgets(line1, sizeof line1, file)!=NULL)
    {
        filename[i]=line;
        i++;
    }
fclose(file);
for(int ti=0;ti<q;ti++)
    {
        i=0;
        j=0;
        file = fopen(filename[ti], "r");
        while(fgets(line1, sizeof line1, file)!=NULL)
            {
            filetext1[i]=line;
            i++;
            }
        fclose(file);
        element_from_hash(M[ti], filetext1, strlen(filetext1));
    }

    element_t tempn;
    element_init_GT(tempn, pairing);

    for(i=0;i<q;i++)
        {
        element_pow_zn(tempn,h[i],M[i]);
        element_set(C[i],tempn);
        element_set(Aux[i],M[i]);
        }
	*/
element_from_hash(M[q], filetext, strlen(filetext));
element_pow_zn(tempn,h[q],M[q]);
element_set(C[q],tempn);
element_set(Aux[q],M[q]);
i=3; //current modifier
time1 = pbc_get_time();
element_random(r);
element_random(ucap);
element_random(vcap);
element_init_same_as(u,ucap);
element_init_same_as(v,vcap);
element_random(u);
element_random(v);
element_random(alpha);
element_pow_zn(T1,u,alpha);
element_pow_zn(tempnew,v,alpha);
element_mul(T2,A[i],tempnew);
element_mul(delsym,X[i],alpha);
element_random(ralpha);
element_random(rx);
element_random(rdel);
element_pow_zn(R1,u,ralpha);
element_pairing(p1,T2,g2);
element_pow_zn(te1,p1,rx);
element_pairing(p2,v,W);
element_neg(revn,ralpha);
element_pow_zn(te2,p2,revn);
element_pairing(p3,v,g2);
element_neg(revn2,rdel);
element_pow_zn(te3,p3,revn2);
element_mul(mktemp,te1,te2);
element_mul(R2,mktemp,te3);
element_pow_zn(nte1,T1,rx);
element_pow_zn(nte2,u,revn2);
element_mul(R3,nte1,nte2);
element_random(c);
element_mul(nte3,c,alpha);
element_mul(nte4,c,delsym);
element_mul(nte5,c,X[i]);
element_add(salpha,ralpha,nte3);
element_add(sx,rx,nte5);
element_add(sdel,rdel,nte4);
element_set(Rs1,R1);
element_set(Rs2,R2);
element_set(Rs3,R3);
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
time2 = pbc_get_time();
printf("Signature generation time = %fs\n", time2 - time1);
i=q;
j=0;
element_set1(premul);
for(j=0;j<q+1;j++)
	{
	    if(j!=i)
            {
                element_pow_zn(tempvar,h[j],M[j]);
                element_mul(premul,premul,tempvar);
                }
	}
element_pow_zn(proofi,premul,z[i]);
i=0;
j=0;
time1 = pbc_get_time();
element_set(c, Sig[3]);
element_set(r, Sig[0]);
element_set(salpha, Sig[4]);
element_set(sx, Sig[5]);
element_set(sdel, Sig[6]);
element_set(T1, Sig[1]);
element_set(T2, Sig[2]);
element_init_same_as(u,ucap);
element_init_same_as(v,vcap);
element_random(u);
element_random(v);
element_pow_zn(tempn1,u,salpha);
element_pow_zn(tempn2,T1,c);
element_div(R1,tempn1,tempn2);
element_pairing(p1,T2,g2);
element_pow_zn(te1,p1,sx);
element_pairing(p2,v,W);
element_neg(revn,salpha);
element_pow_zn(te2,p2,revn);
element_pairing(p3,v,g2);
element_neg(revn2,sdel);
element_pow_zn(te3,p3,revn2);
element_pairing(p4,T2,W);
element_pairing(p5,g1,g2);
element_div(te4,p4,p5);
element_pow_zn(te5,te4,c);
element_mul(tempn1,te1,te2);
element_mul(tempn2,te3,te5);
element_mul(R2,tempn1,tempn2);
element_pairing(p6,v,W);
element_pow_zn(te3,T1,sx);
element_neg(revn2,sdel);
element_pow_zn(te4,u,revn2);
element_mul(R3,te3,te4);
if (!element_cmp(R1, Rs1))
    {
		if (!element_cmp(R2, Rs2))
			{
				if (!element_cmp(R3, Rs3))
					{
						tmp=1;
					}
            }
	}
if(tmp==1)
{
element_t commitver;
element_t temp096;
element_t divans;
element_t p1re,p2re;
element_init_G1(commitver, pairing);
element_init_G1(temp096, pairing);
element_init_G1(divans, pairing);
element_init_GT(p1re, pairing);
element_init_GT(p2re, pairing);
element_pow_zn(temp096,h[i],M[i]);
element_set(commitver,C[i]);
element_div(divans,commitver,temp096);
element_pairing(p1re,divans,h[i]);
element_pairing(p2re,proofi,g);
if (!element_cmp(p1re, p2re))
    {
        temp=5;
    }
if(temp==5)
        printf("valid\n");
else
        printf("invalid\n");
}
else
	{
	    printf("fail");
	}
time2 = pbc_get_time();
printf("Verification time = %fs\n", time2 - time1);
}
