#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Método que recibe como parámetro 2 strings y devuelve un string ,resultado de concatenar a s1 s2
char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

//Método que recibe un número entero y devuelve un string, resultado de convertir n a un número romano
char* arabico_a_romano(int n)
{
	 char *Unidad[]={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	 char *Decena[]={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	 char *Centena[]= {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	
	 char *Miles[]= {"","M","MM","MMM","/IV","/V","/VI","/VII","/VIII","/IX"};
	 char *DecenaMiles[] ={"","/X","/XX","/XXX","/XXXX","/XXXXX","/XXXXXX","/XXXXXXX","/XXXXXXXX","/XXXXXXXXX"};
	 int CentenaMiles[] ={0,10,20,30,40,50,60,70,80,90};
	
	int Millon[] ={0,100,200,300,400,500,600,700,800,900};
	int DecenaMillon[] ={0,1000,2000,3000,4000,5000,6000,7000,8000,9000};
	int CentenaMillon[] ={0,10000,20000,30000,40000,50000,60000,70000,80000,90000};
	
	int MilMillon[] ={0,100000,200000,300000,400000,500000,600000,700000,800000,900000};
	
	
	
	//Variables que representan los dígitos del número de derecha a izquierda
	int a,b,c,d,e,f,g,h,i,j;
	
	
	a= (n-n/10*10);
    b= (n-n/100*100-a)/10;
    c= (n-n/1000*1000-a-b)/100;
    d= (n-n/10000*10000-a-b-c)/1000;
    e= (n-n/100000*100000-a-b-c-d)/10000;
    f= (n-n/1000000*1000000-a-b-c-d-e)/100000;
    g= (n-n/10000000*10000000-a-b-c-d-e-f)/1000000;
    h= (n-n/100000000*100000000-a-b-c-d-e-f-g)/10000000;
    i= (n-n/1000000000*1000000000-a-b-c-d-e-f-g-h)/100000000;
    
    j= n /1000000000;
	
	if(n>0 && n<10)
	{
	    //printf("El número arábico %d corresponde con el número romano %s",n,Unidad[a]);
	    return Unidad[a] ;
	    
	}
	
	else if(n<100)
	{
	    //printf("El número arábico %d corresponde con el número romano %s%s",n,Decena[b],Unidad[a]);
	    
	    
	    char*s1= Decena[b];
	    char*s0= Unidad[a];
	    
	    char* result= concat(s1,s0) ;
		
		return result;
    
	    
	}
	
	else if(n<1000)
	{
	    //printf("El número arábico %d corresponde con el número romano %s%s%s",n,Centena[c],Decena[b],Unidad[a]);
	    char*s2= Centena[c];
	    
	    char*s1= concat(Decena[b],Unidad[a]);
	    
	    return concat(s2,s1);
	    
	}
	else if(n<10000)
	{
		//printf("El número arábico %d corresponde con el número romano %s%s%s%s",n,Miles[d],Centena[c],Decena[b],Unidad[a]);
		char*s1= concat(Miles[d],Centena[c]);
		char*s2= concat(Decena[b],Unidad[a]);
		
		return concat(s1,s2);
		
	}
	else if(n<100000)
	{
		//printf("El número arábico %d corresponde con el número romano %s%s%s%s%s",n,DecenaMiles[e],Miles[d],Centena[c],Decena[b],Unidad[a]);
		char*s1= concat(Miles[d],Centena[c]);
		char*s2= concat(Decena[b],Unidad[a]);
		char*s3= concat(s1,s2);
		
		return concat(DecenaMiles[e],s3);
		
	}
	
	else if(n<1000000)
	{
		//printf("El número arábico %d corresponde con el número romano ",n);
		char*result="/";
		int cont=0;
		int aux= CentenaMiles[f];
		
		for(cont;cont<aux;cont++)
	    {
	    	result=concat(result,"X");
		}
		char*s1= concat(Miles[d],Centena[c]);
		char*s2= concat(Decena[b],Unidad[a]);
		char*s3= concat(s1,s2);
		char*s4= concat(DecenaMiles[e],s3);
		//printf("%s%s%s%s%s",n,DecenaMiles[e],Miles[d],Centena[c],Decena[b],Unidad[a]);
		return concat(result,s4);
		
	}
	
	else if(n<10000000)
	{
		//printf("El número arábico %d corresponde con el número romano ",n);
		
		char*result="/";
		
		int var1=0;
		int var2= Millon[g];
		
		for(var1;var1<var2;var1++)
	    {
	    	result=concat(result,"X");
		} 
		
		
		int cont=0;
		int aux= CentenaMiles[f];
		
		for(cont;cont<aux;cont++)
	    {
	    	result=concat(result,"X");
		}
		char*s1= concat(Miles[d],Centena[c]);
		char*s2= concat(Decena[b],Unidad[a]);
		char*s3= concat(s1,s2);
		char*s4= concat(DecenaMiles[e],s3);
		
		return concat(result,s4);
		
	}
	
	else if(n<100000000)
	{
		char*result="/";
		
		int con=0;
		int var= DecenaMillon[h];
		
		for(con;con<var;con++)
	    {
	    	result=concat(result,"X");
		} 
		
		int var1=0;
		int var2= Millon[g];
		
		for(var1;var1<var2;var1++)
	    {
	    	result=concat(result,"X");
		} 
		
		
		int cont=0;
		int aux= CentenaMiles[f];
		
		for(cont;cont<aux;cont++)
	    {
	    	result=concat(result,"X");
		}
		char*s1= concat(Miles[d],Centena[c]);
		char*s2= concat(Decena[b],Unidad[a]);
		char*s3= concat(s1,s2);
		char*s4= concat(DecenaMiles[e],s3);
		
		return concat(result,s4);	
	
	}
	
	else if(n<1000000000)
	{
		char*result="/";
		
		int c1=0;
		int c2= CentenaMillon[i];
		
		for(c1;c1<c2;c1++)
	    {
	    	result=concat(result,"X");
		} 
		
		int con=0;
		int var= DecenaMillon[h];
		
		for(con;con<var;con++)
	    {
	    	result=concat(result,"X");
		} 
		
		int var1=0;
		int var2= Millon[g];
		
		for(var1;var1<var2;var1++)
	    {
	    	result=concat(result,"X");
		} 
		
		
		int cont=0;
		int aux= CentenaMiles[f];
		
		for(cont;cont<aux;cont++)
	    {
	    	result=concat(result,"X");
		}
		char*s1= concat(Miles[d],Centena[c]);
		char*s2= concat(Decena[b],Unidad[a]);
		char*s3= concat(s1,s2);
		char*s4= concat(DecenaMiles[e],s3);
		
		return concat(result,s4);	
	}
	
	else if(n<1000000000)
	{
		char*result="/";
		
		int c3=0;
		int c4= MilMillon[j];
		
		for(c3;c3<c4;c3++)
	    {
	    	result=concat(result,"X");
		} 
		
		int c1=0;
		int c2= CentenaMillon[i];
		
		for(c1;c1<c2;c1++)
	    {
	    	result=concat(result,"X");
		} 
		
		int con=0;
		int var= DecenaMillon[h];
		
		for(con;con<var;con++)
	    {
	    	result=concat(result,"X");
		} 
		
		int var1=0;
		int var2= Millon[g];
		
		for(var1;var1<var2;var1++)
	    {
	    	result=concat(result,"X");
		} 
		
		
		int cont=0;
		int aux= CentenaMiles[f];
		
		for(cont;cont<aux;cont++)
	    {
	    	result=concat(result,"X");
		}
		char*s1= concat(Miles[d],Centena[c]);
		char*s2= concat(Decena[b],Unidad[a]);
		char*s3= concat(s1,s2);
		char*s4= concat(DecenaMiles[e],s3);
		
		return concat(result,s4);
	}
	
}

/*char* arabico_a_romano(int n)
{
	if (n>0 && n<=999999999)
	{
		return arabico_a_romano_aux(n);
	}
	else
	{
		char* error= "El numero debe ser >0 y <=9999999999";
		return error;
		
	}
	
}*/
