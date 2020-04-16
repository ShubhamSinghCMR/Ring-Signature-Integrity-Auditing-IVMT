//Public integrity auditing for shared dynamic cloud data with group user revocation

//Algo: Update

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j;
	//Read q, gpk, signature and other necessary parameters from the text file  
	
	pairing_t pairing;
	pbc_demo_pairing_init(pairing, argc, argv);
	if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
	
	printf("Enter new file data:\n");
	char sentence[1000];
	FILE *fptr;
	char* filetext[10000];		//Array which contains the file data
	char line[10000];
	FILE *file;
	fptr = fopen("Filepath", "w");
	if(fptr == NULL)
		{
			printf("Error!");
		}
	gets(sentence);
	fprintf(fptr,"%s", sentence);
	fclose(fptr);

	//Read file
	i=0;
	j=0;
	file = fopen("Filepath", "r");
	while(fgets(line, sizeof line, file)!=NULL)
	{
	filetext[i]=line;
	i++;
	}
	fclose(file);
	
//User wants to update the file at location i
	
element_t newhashele;
element_init_G2(newhashele, pairing);
element_from_hash(newhashele, filetext, strlen(filetext));

element_t subtemp;
element_init_G2(subtemp, pairing);
element_sub(subtemp,newhashele,M[i]);

element_t R1yu;
element_init_G2(R1yu, pairing);
element_pow_zn(R1yu,h[i],subtemp);

element_t Cdash;
element_init_G2(Cdash, pairing);

element_mul(Cdash,C[i],R1yu);

element_set(C[i],Cdash);
element_set(M[i],newhashele);

//Update file values
}