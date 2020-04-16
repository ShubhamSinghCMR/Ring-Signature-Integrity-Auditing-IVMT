#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) {
	int k,i,j;
    k=3;
    int q=70;
    int n=4; // n is the number of users in the group
    pairing_t pairing;
	double time1, time2;
	element_t P;  // Generator of G
	element_t Ppub, s;    //s is the MASTER key of TA
	element_t QID0,QID1,QID2,QID3,QID4; //Public Key
	element_t SID0,SID1,SID2,SID3,SID4; //Secret Key
	element_t ID0,ID1,ID2,ID3,ID4;  //ID
	element_t ranA,temp1,temp2,temp3,temp4,temp5;
	element_t newrt3, t56y, yval0, t57y, templ09, wer1, wer2, wer3, wer4;
	element_t t0,t1,t2,t3,t4;
	element_t c0,c1,c2,c3,c4;
    element_t hom;
    mpz_t t4s;
  pbc_demo_pairing_init(pairing, argc, argv);
  if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
  element_init_G1(P, pairing);
  element_init_G1(Ppub, pairing);
  element_init_Zr(s, pairing);
  element_init_G1(QID1, pairing);
  element_init_G1(SID1, pairing);
  element_init_G1(ID1, pairing);
  element_init_G1(QID2, pairing);
  element_init_G1(SID2, pairing);
  element_init_G1(ID2, pairing);
  element_init_G1(QID3, pairing);
  element_init_G1(SID3, pairing);
  element_init_G1(ID3, pairing);
  element_init_G1(QID4, pairing);
  element_init_G1(SID4, pairing);
  element_init_G1(ID4, pairing);
  element_init_G1(QID0, pairing);
  element_init_G1(SID0, pairing);
  element_init_G1(ID0, pairing);
  element_init_G1(ranA, pairing);
  element_init_GT(temp1, pairing);
  element_init_GT(hom, pairing);
  element_init_G1(temp2, pairing);
  element_init_G1(temp3, pairing);
  element_init_GT(temp4, pairing);
  element_init_GT(temp5, pairing);
  element_init_GT(c0, pairing);
  element_init_GT(c1, pairing);
  element_init_GT(c2, pairing);
  element_init_GT(c3, pairing);
  element_init_GT(c4, pairing);
  element_init_G1(t0, pairing);
  element_init_G1(t1, pairing);
  element_init_G1(t2, pairing);
  element_init_G1(t3, pairing);
  element_init_G1(t4, pairing);
  element_init_Zr(yval0, pairing);
  element_init_Zr(templ09, pairing);
  element_init_Zr(wer1, pairing);
  element_init_G1(t57y, pairing);
  element_init_G1(newrt3, pairing);
  element_init_G1(t56y, pairing);
  element_init_G1(wer2, pairing);
  element_init_GT(wer3, pairing);
  element_init_GT(wer4, pairing);
//Reading file in array
i=0;
j=0;
char* filetext[100];
char line[100];
FILE *file;
file = fopen("E:\mytext.txt", "r");
while(fgets(line, sizeof line, file)!=NULL)
{//printf("%s", line);
filetext[i]=line;
i++;
}
//for (i=0 ; i<j; i++)
  //  {
//printf("\n%s", filetext[i]);
//}
fclose(file);

//File read

element_t g;
element_init_G1(g, pairing);
element_random(g);
element_random(yval0);
element_random(newrt3);
element_t h[q],z[q];
element_t h1new,z1new;
for(i = 0; i < q; i++)
			{
				element_init_Zr(z[i], pairing);
				element_init_G1(h[i], pairing);
			}
element_init_Zr(z1new, pairing);
element_init_G2(h1new, pairing);
//Selection of z[i] and computation of h[i]
for(i = 0; i < q; i++)
			{
			    element_random(z[i]);
			//    element_printf("ZVAL %B\n",z[i] );
			    element_pow_zn(h[i],g,z[i]);
	//			element_printf("hval %B\n", h[i]);
			}
element_random(z1new);
element_pow_zn(h1new,g,z1new);
element_mul_zn(t56y, newrt3, yval0);
//hij computaion

element_t hij[q][q];
for(i = 0; i < q; i++)
			{
				for(j = 0; j < q; j++)
                    {
						element_init_G1(hij[i][j], pairing);
                    }

			}
element_t tem1p1;
element_init_Zr(tem1p1, pairing);
for(i = 0; i < q; i++)
			{
				for(j = 0; j < q; j++)
                    {
						if(i!=j)
                            {
								element_mul(tem1p1,z[i],z[j]);
								element_pow_zn(hij[i][j],g,tem1p1);
					//			element_printf("hij %B\n", hij[i][j]);
                            }
                    }
            }
       //     element_printf("\nVCKeyGen Done\n");



//Keygen
  element_random(P);
  element_random(s);
  element_mul_zn(Ppub, P, s);
//  element_printf("P = %B\n", P);
//  element_printf("Ppub = %B\n", Ppub);


  element_from_hash(QID1, "ID1", 3);
  element_mul_zn(SID1, QID1, s);
//  element_printf("User 1 Public key QID = %B\n", QID1);
//  element_printf("User 1 Private key SID = %B\n", SID1);
    element_from_hash(QID2, "ID2", 3);
  element_mul_zn(SID2, QID2, s);
//  element_printf("User 2 Public key QID = %B\n", QID2);
 // element_printf("User 2 Private key SID = %B\n", SID2);
    element_from_hash(QID3, "ID3", 3);
  element_mul_zn(SID3, QID3, s);
//  element_printf("User 3 Public key QID = %B\n", QID3);
//  element_printf("User 3 Private key SID = %B\n", SID3);
    element_from_hash(QID4, "ID4", 3);
  element_mul_zn(SID4, QID4, s);
 // element_printf("User 4 Public key QID = %B\n", QID4);
//  element_printf("User 4 Private key SID = %B\n", SID4);
    element_from_hash(QID0, "ID0", 3);
  element_mul_zn(SID0, QID0, s);
//  element_printf("User 5 Public key QID = %B\n", QID0);
 // element_printf("User 5 Private key SID = %B\n", SID0);
//keygenerated
//commit
//VCCom Compute commitment
element_t M[q];
element_t C[q];
element_t Aux[q];
element_t tempn;
element_init_GT(tempn, pairing);
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
//	element_printf("Aux %B\n", Aux[i]);
//	element_printf("M %B\n", M[i]);
	}

//	element_printf("\nVCCom Done\n");
//Hash
	element_t hashele;
	element_init_G2(hashele, pairing);
	element_from_hash(hashele, filetext, strlen(filetext));
	element_add(wer1, hashele, yval0);
    element_invert(wer1, wer1);
    element_mul_zn(t57y, newrt3, wer1);
//	element_printf("\nComputed\n");
 //   element_printf("Hashele %B\n", hashele);

//
element_t Cnew;
element_init_G2(Cnew, pairing);
	element_t Auxnew;
element_init_G2(Auxnew, pairing);
	element_t tempn1;
element_init_G2(tempn1, pairing);
//	element_printf("h1new %B\n", h1new);
	element_pow_zn(tempn1,h1new,hashele);
	element_t tempv;
	element_init_G2(tempv, pairing);
	element_set(tempv,tempn1);
	element_random(tempn1);
//	element_printf("empnew %B\n", tempn1);
	element_set(Cnew,tempn1);
	element_set(Auxnew,hashele);

//	element_printf("Auxnew %B\n", Auxnew);
//	element_printf("Cnew %B\n", Cnew);


	//VCCom Done
element_from_hash(hom, filetext, strlen(filetext));
//  element_printf("hash ele= %B\n", hom);
//commitdone
//Siggenewa
  //Current signer user 3 means k=3;
  element_random(ranA);
  element_pairing(temp1,ranA,P);
//  element_printf("Before= %B\n", temp1);
  element_mul_zn(c4, hom, temp1);
//  element_printf("c4= %B\n", c4);
//  printf("c4 done");
  //Genrating forward ring sequence
 /* element_printf("Generating sequence");
  k=3;
  n=5;
  i=k+1;
  while(i!=k)
  {
	  if(i==n)
		  i=0;
	//Working
 printf("%d",i);
	  i++;
  }
printf("%d",i);
*/
//Mannual for five users
element_random(t4);
//element_printf("t4 %B\n", t4);
element_random(t0);
//element_printf("t0 %B\n", t0);
element_random(t1);
//element_printf("t1 %B\n", t1);
element_random(t2);
//element_printf("t2 %B\n", t2);
element_random(t3);
//element_printf("t3 %B\n", t3);
 time1 = pbc_get_time();

element_pairing(temp1,t4,P);
//element_printf("temp1 %B\n", temp1);
element_mul(temp3, c4, QID4);
//element_printf("temp3 %B\n", temp3);
element_pairing(temp4,temp3,Ppub);
//element_printf("temp4 = %B\n", temp4);
element_mul(temp5, temp1, temp4);
//element_printf("temp5 = %B\n", temp5);
element_mul(c0, hom, temp5);
//element_printf("c0 = %B\n", c0);

element_pairing(temp1,t0,P);
element_mul(temp3, c0, QID0);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c1, hom, temp5);
//element_printf("c1 = %B\n", c1);
element_pairing(temp1,t1,P);
element_mul(temp3, c1, QID1);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c2, hom, temp5);
//element_printf("c2 = %B\n", c2);
element_pairing(temp1,t2,P);
element_mul(temp3, c2, QID2);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c3, hom, temp5);
//element_printf("c3 = %B\n", c3);
//Computation of Tk for k=3
element_mul(temp3, c3, SID3);
//element_printf("temp3 = %B\n", temp3);
//element_printf("ranA = %B\n", ranA);
element_sub(t3,ranA,temp3);
//element_printf("Tk = %B\n", t3);
//Computation complete
time2 = pbc_get_time();
  printf("Signature generation time = %fs\n", time2 - time1);

  //proof generation

//Computing proof for file at i=4
i=4;
j=0;
element_t proofi;
element_t tempvar;
element_t premul;
element_init_GT(proofi, pairing);
element_init_GT(tempvar, pairing);
element_init_GT(premul, pairing);
element_set1(premul);
element_from_hash(templ09, filetext, strlen(filetext));
element_mul_zn(wer2, newrt3, templ09);
element_add(wer2, wer2, t56y);
element_pairing(wer3, wer2, t57y);
element_pairing(wer4, newrt3, newrt3);
time1 = pbc_get_time();
for(j=0;j<q;j++)
	{
	    if(j!=i)
            {
                element_pow_zn(tempvar,h[j],M[j]);
                element_mul(premul,premul,tempvar);
                }
	}
element_pow_zn(proofi,premul,z[i]);
time2 = pbc_get_time();
printf("Proof generation time = %fs\n", time2 - time1);

//VCOpen Done

  //.pgenr


//Verification

i=4;
int checksum=0;
element_t commitver;
element_t temp096;
element_t divans;
 element_t teop1,teop2,teop4,teop5,teop6,teop7,teop8,teop9,teop10,teop11;
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
element_from_hash(teop1, filetext, strlen(filetext));
element_from_hash(hom, filetext, strlen(filetext));
//element_printf("hash ele= %B\n", hom);
time1 = pbc_get_time();
element_random(ranA);
element_pairing(temp1,ranA,P);
//element_printf("Before= %B\n", temp1);
element_mul_zn(c4, hom, temp1);
// element_printf("c4= %B\n", c4);

//  printf("c4 done");
  //Genrating forward ring sequence
 // element_printf("Generating sequence");
/*int  v=3;
 int n1=5;
 int il=k+1;
  while(il!=v)
  {
	  if(il==n1)
		  il=0;
	//Working
// printf("%d",i);
	  il++;
  }
  */
//printf("%d",i);

//Mannual for five users
time1 = pbc_get_time();
element_pairing(temp1,t0,P);
element_mul(temp3, c0, QID0);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c1, hom, temp5);
//element_printf("c1 = %B\n", c1);

element_pairing(temp1,t1,P);
element_mul(temp3, c1, QID1);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c2, hom, temp5);
//element_printf("c2 = %B\n", c2);

element_pairing(temp1,t2,P);
element_mul(temp3, c2, QID2);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c3, hom, temp5);
//element_printf("c3 = %B\n", c3);


element_pairing(temp1,t3,P);
element_mul(temp3, c3, QID3);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c4, hom, temp5);
//element_printf("c4 = %B\n", c4);

element_pairing(temp1,t4,P);
element_mul(temp3, c4, QID4);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c0, hom, temp5);
//element_printf("c0 = %B\n", c0);

// printf("Hahs genera5\n");
element_t p1re,p2re;
if (element_cmp(c0, c4))
    {
  //  printf("valid sig\n");
    element_init_G2(commitver, pairing);
  //  printf("valid sig2\n");
    element_set(commitver,Cnew);
   // printf("valid sig3\n");
    element_init_G2(temp096, pairing);
  //  printf("valid sig4\n");
    element_pow_zn(temp096,h[i],hashele);
    element_init_G2(divans, pairing);
   // printf("valid sig5\n");
    element_div(divans,commitver,temp096);
   // printf("valid sig6\n");
    element_init_GT(p1re, pairing);
	element_init_GT(p2re, pairing);
//	printf("valid sig006\n");
    element_pairing(p1re,divans,h[i]);
  //  printf("valid sig5526\n");
	element_pairing(p2re,proofi,g);
//	printf("valid sig6\n");
	if (element_cmp(p1re, p2re))
    {
        checksum=1;
        if (!element_cmp(wer3, wer4))
            checksum=0;
    }

  //  printf("%d",checksum);
    if(checksum==0)
        printf("proof valid\n");
    else
    printf("proof invalid\n");

  }
else
    {
    printf("signot valid\n");
  }
time2 = pbc_get_time();
  printf("TPA Verification time = %fs\n", time2 - time1);


//Veridone
//Updateing dta
printf("Enter new data:\n");
char sentence[1000];
FILE *fptr;
fptr = fopen("E:\mytext.txt", "w");
if(fptr == NULL)
   {
      printf("Error!");
   }
printf("Enter data:\n");
gets(sentence);
fprintf(fptr,"%s", sentence);
fclose(fptr);
//Read file to compute commit
i=0;
j=0;
file = fopen("E:\mytext.txt", "r");
while(fgets(line, sizeof line, file)!=NULL)
{
//printf("%s", line);
filetext[i]=line;
i++;
}
fclose(file);
//Hash
i=4;
element_t newhashele;
element_init_G2(newhashele, pairing);
element_from_hash(newhashele, filetext, strlen(filetext));
element_t proofj;
element_init_GT(proofj, pairing);
element_set1(premul);
time1 = pbc_get_time();
for(j=0;j<q;j++)
	{
	    if(j!=i)
            {
                element_pow_zn(tempvar,h[j],newhashele);
                element_mul(premul,premul,tempvar);
                }
	}
j=4;
time1 = pbc_get_time();
element_pow_zn(proofj,premul,z[i]);
element_t subtemp;
element_init_G2(subtemp, pairing);
element_sub(subtemp,newhashele,hashele);
element_t R1yu;
element_init_G2(R1yu, pairing);
element_pow_zn(R1yu,h[i],subtemp);
element_t Cdash;
element_init_G2(Cdash, pairing);
element_mul(Cdash,C[i],R1yu);
element_t proofjdash;
element_init_G2(proofjdash, pairing);
if(i!=j)
	{
        element_pow_zn(tempvar,hij[j][i],subtemp);
		element_mul(proofjdash,proofj,tempvar);
	}
else
	{
	element_set(proofjdash,proofj);
	}

time2 = pbc_get_time();
  printf("proof update time = %fs\n", time2 - time1);





////
  element_clear(P);
  element_clear(Ppub);
  element_clear(QID1);
  element_clear(SID1);
  element_clear(ID1);
  element_clear(QID2);
  element_clear(SID2);
  element_clear(ID2);
  element_clear(QID3);
  element_clear(SID3);
  element_clear(ID3);
  element_clear(QID4);
  element_clear(SID4);
  element_clear(ID4);
  element_clear(QID0);
  element_clear(SID0);
  element_clear(ID0);
 element_clear(s);
pairing_clear(pairing);

  return 0;
}
