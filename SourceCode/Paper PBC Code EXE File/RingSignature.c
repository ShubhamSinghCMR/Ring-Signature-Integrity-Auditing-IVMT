#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) {
	int k,i;
    k=3;
    int n; // No of users in gp.
    pairing_t pairing;
	double time1, time2;
	element_t P;  // Generator of G
	element_t Ppub, s;    //s is the MASTER key of TA
	element_t QID0,QID1,QID2,QID3,QID4; //Public Key
	element_t SID0,SID1,SID2,SID3,SID4; //Secret Key
	element_t ID0,ID1,ID2,ID3,ID4;  //ID
	element_t ranA,temp1,temp2,temp3,temp4,temp5;
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

  printf("SETUP\n");
  element_random(P);
  element_random(s);
  element_mul_zn(Ppub, P, s);
  element_printf("P = %B\n", P);
  element_printf("Ppub = %B\n", Ppub);

  printf("EXTRACT\n");
  element_from_hash(QID1, "ID1", 3);
  element_mul_zn(SID1, QID1, s);
  element_printf("User 1 Public key QID = %B\n", QID1);
  element_printf("User 1 Private key SID = %B\n", SID1);
    element_from_hash(QID2, "ID2", 3);
  element_mul_zn(SID2, QID2, s);
  element_printf("User 2 Public key QID = %B\n", QID2);
  element_printf("User 2 Private key SID = %B\n", SID2);
    element_from_hash(QID3, "ID3", 3);
  element_mul_zn(SID3, QID3, s);
  element_printf("User 3 Public key QID = %B\n", QID3);
  element_printf("User 3 Private key SID = %B\n", SID3);
    element_from_hash(QID4, "ID4", 3);
  element_mul_zn(SID4, QID4, s);
  element_printf("User 4 Public key QID = %B\n", QID4);
  element_printf("User 4 Private key SID = %B\n", SID4);
    element_from_hash(QID0, "ID0", 3);
  element_mul_zn(SID0, QID0, s);
  element_printf("User 5 Public key QID = %B\n", QID0);
  element_printf("User 5 Private key SID = %B\n", SID0);

  printf("SIGNING\n");
  //Current signer user 3 means k=3;
  element_random(ranA);
  element_pairing(temp1,ranA,P);
  element_printf("Before= %B\n", temp1);
  element_from_hash(hom, "HashOfMessage", 13);
  element_printf("hash ele= %B\n", hom);
  element_mul_zn(c4, hom, temp1);
  element_printf("c4= %B\n", c4);

  printf("c4 done");
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
element_printf("t4 %B\n", t4);
element_random(t0);
element_printf("t0 %B\n", t0);
element_random(t1);
element_printf("t1 %B\n", t1);
element_random(t2);
element_printf("t2 %B\n", t2);
element_random(t3);
element_printf("t3 %B\n", t3);

element_pairing(temp1,t4,P);
element_printf("temp1 %B\n", temp1);
element_mul(temp3, c4, QID4);
element_printf("temp3 %B\n", temp3);
element_pairing(temp4,temp3,Ppub);
element_printf("temp4 = %B\n", temp4);
element_mul(temp5, temp1, temp4);
element_printf("temp5 = %B\n", temp5);
element_mul(c0, hom, temp5);
element_printf("c0 = %B\n", c0);

element_pairing(temp1,t0,P);
element_mul(temp3, c0, QID0);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c1, hom, temp5);
element_printf("c1 = %B\n", c1);

element_pairing(temp1,t1,P);
element_mul(temp3, c1, QID1);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c2, hom, temp5);
element_printf("c2 = %B\n", c2);

element_pairing(temp1,t2,P);
element_mul(temp3, c2, QID2);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c3, hom, temp5);
element_printf("c3 = %B\n", c3);


//Computation of Tk for k=3
element_mul(temp3, c3, SID3);
element_printf("temp3 = %B\n", temp3);
element_printf("ranA = %B\n", ranA);
element_sub(t3,ranA,temp3);
element_printf("Tk = %B\n", t3);

//Computation complete
//Verification

  element_random(ranA);
  element_pairing(temp1,ranA,P);
  element_printf("Before= %B\n", temp1);
  element_from_hash(hom, "HashOfMessage", 13);
  element_printf("hash ele= %B\n", hom);
  element_mul_zn(c4, hom, temp1);
  element_printf("c4= %B\n", c4);

  printf("c4 done");
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
printf("Verification\n");

element_pairing(temp1,t0,P);
element_mul(temp3, c0, QID0);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c1, hom, temp5);
element_printf("c1 = %B\n", c1);

element_pairing(temp1,t1,P);
element_mul(temp3, c1, QID1);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c2, hom, temp5);
element_printf("c2 = %B\n", c2);

element_pairing(temp1,t2,P);
element_mul(temp3, c2, QID2);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c3, hom, temp5);
element_printf("c3 = %B\n", c3);

element_pairing(temp1,t3,P);
element_mul(temp3, c3, QID3);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c4, hom, temp5);
element_printf("c4 = %B\n", c4);

element_pairing(temp1,t4,P);
element_mul(temp3, c4, QID4);
element_pairing(temp4,temp3,Ppub);
element_mul(temp5, temp1, temp4);
element_mul(c0, hom, temp5);
element_printf("c0 = %B\n", c0);



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
