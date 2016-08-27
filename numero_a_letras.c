#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>


//Método que recibe como parámetro 2 strings y devuelve un string ,resultado de concatenar a s1 s2
char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcat(result, s2);
    return result;
}


//Método que recibe como parámetro un número entero n y devuelve un string, representación en texto del número ingresado
char* getCentenas(int n){

	//Variables que representan los dígitos del numero de derecha a izquierda
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
    
    
    
    
    char *unidades[] = 
    {"cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez"};
    
    char *decenas[] =
    {"veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};
    
    char *especiales[] =
    {"once","doce","trece","catorce","quince","dieciseis","diecisiete","dieciocho","diecinueve"};
    
    char *centenas[] =
    {"","cien","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"};
    
    if (n>=0 && n<11)
	{
		//printf("%s",unidades[n]);
		return unidades[n];
	}
	else if (n<20)
	{
		//printf("%s",especiales[n-11]);
		return especiales[n-11];
	}
	else if (n<100)
	{
		if (a==0)
		{
			//printf("%s",decenas[b-2]);
			return decenas[b-2];
		}
		else if(a!=0 && b== 2)
		{
			//printf("veinti%s",unidades[a]);
			return concat("veinti",unidades[a]);
		}
		else
		{
			//printf("%s y %s",decenas[b-2],unidades[a]);
			char*s1= concat(decenas[b-2]," y ");
			char*s2= concat(s1,unidades[a]);
			return s2;
		}
	}
	else if (n<1000)
	{
		if (a==0 && b==0)
		{
			//printf("%s",centenas[c]);
			return 	centenas[c];
		}
		else if (a==0 && b!=0)
		{
			if (c==1 && b==1)
			{
				//printf("ciento diez");
				return "ciento diez";
			}
			else if (c!=1 && b==1)
			{
				//printf("%s diez",centenas[c]);
				return concat(centenas[c]," diez");
			}
			else if (c==1 && b!=1)
			{
				//printf("ciento %s",decenas[b-2]);
				return concat("ciento ",decenas[b-2]);
			}
			else
			{
				//printf("%s %s",centenas[c],decenas[b-2]);
				char*s1= concat(centenas[c]," ");
				return concat(s1,decenas[b-2]);
			}
		}
		else if(a!=0 && b==0)
		{
			if (c==1)
			{
				//printf("ciento %s",unidades[a]);
				return concat("ciento ",unidades[a]);
			}
			else
			{
				//printf("%s %s",centenas[c],unidades[a]);
				char*s1= concat(centenas[c]," ");
				return concat(s1,unidades[a]);
			}
		}
		else if(b!=0 && a!=0)
		{
			if (c==1 && b==1)
			{
				//printf("ciento %s",especiales[a-1]);
				return concat("ciento ",especiales[a-1]);
			}
			else if(c!=1 && b==1)
			{
				//printf("%s %s",centenas[c],especiales[a-1]);
				char*s1= concat(centenas[c]," ");
				return concat(s1,especiales[a-1]);
			}
			else if(c==1 && b==2)
			{
				//printf("ciento veinti%s",unidades[a]);
				return concat("ciento veinti",unidades[a]);
			}
			else if(c==1 && b!=1)
			{
				//printf("ciento %s y %s",decenas[b-2],unidades[a]);
				char*s1= concat("ciento ",decenas[b-2]);
				char*s2= concat(s1," y ");
				return concat(s2,unidades[a]);
			}
			else if(c!=1 && b==2)
			{
				//printf("%s veinti%s",centenas[c],unidades[a]);
				
				char*s1= concat(centenas[c]," veinti");
				return concat(s1,unidades[a]);
			}
			else
			{
				//printf("%s %s y %s",centenas[c],decenas[b-2],unidades[a]);
				char*s1= concat(centenas[c]," ");
				char*s2= concat(s1,decenas[b-2]);
				char*s3=(s2," y ");
				return concat(s3,unidades[a]);
			}
			
		}
	}
   
    
}

char* getMiles(int n)
{
	int a,b,c,d,e,f,g,h,i,j;
	
	
	a= (n-n/10*10);
    b= (n-n/100*100-a)/10;
    c= (n-n/1000*1000-a-b)/100;
    d= (n-n/10000*10000-a-b-c)/1000;
    e= (n-n/100000*100000-a-b-c-d)/10000;
    f= (n-n/1000000*1000000-a-b-c-d-e)/100000;
    
    int miles,cent;
    cent = a*pow(10,0) + b*pow(10,1) + c*pow(10,2) ; 
    
    miles = d*pow(10,0)  + e*pow(10,1) + f*pow(10,2) ;
    
    
    if (miles>0)
	{
		
		char* s1= getCentenas(miles);
		char* s2= concat(s1," mil ");
		return concat(s2,getCentenas(cent));
	}
    else
	{
		return getCentenas(cent);
	}
    
	
}


char* getMillones(int n)
{
	int a,b,c,d,e,f,g,h,i;
	
	
	a= (n-n/10*10);
    b= (n-n/100*100-a)/10;
    c= (n-n/1000*1000-a-b)/100;
    d= (n-n/10000*10000-a-b-c)/1000;
    e= (n-n/100000*100000-a-b-c-d)/10000;
    f= (n-n/1000000*1000000-a-b-c-d-e)/100000;
    g= (n-n/10000000*10000000-a-b-c-d-e-f)/1000000;
    h= (n-n/100000000*100000000-a-b-c-d-e-f-g)/10000000;
    i= (n-n/1000000000*1000000000-a-b-c-d-e-f-g-h)/100000000;
    
    
    int miles,millon;
    
    miles = a*pow(10,0) + b*pow(10,1) + c*pow(10,2) +d*pow(10,3) + e*pow(10,4) + f*pow(10,5);
    
    millon = g*pow(10,0) + h*pow(10,1) + i*pow(10,2) ;
    
    char* result="";
    
    if (millon>1)
	{
		
		result=concat(getCentenas(millon)," millones ");
    	
	}
	else
	{
		
		result= concat(getCentenas(millon)," millon ");
    	
	}
	//getMiles(miles);
	
	result= concat(result,getMiles(miles));
	return result;
}


char* getMilesMillones(int n)
{
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
    
    char *cantidades[] = 
    {"mil","dos mil","tres mil","cuatro mil","cinco mil","seis mil","siete mil","ocho mil","nueve mil"};
    
    int millones;
    millones = a*pow(10,0) + b*pow(10,1) + c*pow(10,2) + d*pow(10,3) + e*pow(10,4) +f*pow(10,5) + g*pow(10,6) +h*pow(10,7) +i*pow(10,8);
    
    /*printf("%s ",cantidades[j-1]);
    getMillones(millones);*/
    
    char*result= concat(cantidades[j-1]," ");
    
    return concat(result,getMillones(millones));
    
    
    
    
	
}


char* numero_Letra(int num)
{
	if (num>=0 && num<9999999999)
	{
		if (num>=0 && num<1000)
		{
			return getCentenas(num);
		}
		else if(num<1000000)
		{
			return getMiles(num);
		}
		else if(num<1000000000)
		{
			return getMillones(num);
		}
		else
		{
			return getMilesMillones(num);
		}
	}
	else
	{
		char*error= "el numero debe ser >0 y < 9999999999";
		return error;
	}
	
}

