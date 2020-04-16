//Public integrity auditing for shared dynamic cloud data with group user revocation

//Algo# 3: VCCom

#include <pbc.h>
#include <pbc_test.h>

int main(int argc, char **argv) 
{
	int i,j;
//Read q, n and public parameters from the text file  

pairing_t pairing;
pbc_demo_pairing_init(pairing, argc, argv);
if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");

element_t M[q];		//Holds the hash value of files stored in the database
element_t C[q];		//Holds the commiment value for the files
element_t Aux[q];	//Holds auxiliary information

for(i=0;i<q;i++)
	{
		element_init_G2(M[i], pairing);
		element_init_G2(C[i], pairing);
		element_init_G2(Aux[i], pairing);
	}

//Read q no. of files and store their hash value in the array M[i]

char* filetext[10000];		//Array which contains the file data
char* filename[10000];		//Array which contains the file name
char line[10000];
FILE *file;

//Reading filenames from a filename text file
i=0;
j=0;
file = fopen("E:\filenames.txt", "r");	
while(fgets(line, sizeof line, file)!=NULL)
{
filename[i]=line;
i++;
}
fclose(file);

for(int ti=0;ti<q;ti++)
{
//Reading filedata
i=0;
j=0;
file = fopen(filename[ti], "r");	
while(fgets(line, sizeof line, file)!=NULL)
{
filetext[i]=line;
i++;
}
fclose(file);
element_from_hash(M[ti], filetext, strlen(filetext));
}
	
element_t tempn;
element_init_GT(tempn, pairing);

for(i=0;i<q;i++)
	{
	element_pow_zn(tempn,h[i],M[i]);
	element_set(C[i],tempn);
	element_set(Aux[i],M[i]);
	}

//Store the generated commitment in a text file    	
		
}