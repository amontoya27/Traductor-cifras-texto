#import <stdio.h>
#import <string.h>
#import <stdbool.h>


const char *saludo1 = "-----------------------------------------------------------------\n";
const char *saludo2 = "          Salazar, Andres     Montoya, Daniel\n";
const char *saludo3 = "                       Traductor\n";

const char *palabras[] = {"cero","uno","un","dos","tres","cuatro",
                   "cinco","seis","siete","ocho","nueve","diez", "once","doce",
                   "trece","catorce","quince","dieciseis","diecisiete",
                   "dieciocho","diecinueve", "veinte", "veintiuno","veintidos","veintitres",
                   "veinticuatro","veinticinco","veintiseis","veintisiete",
                   "veintiocho", "veintinueve","treinta", "cuarenta",
                   "cincuenta","sesenta", "setenta", "ochenta", "noventa",
                   "ciento","cien","doscientos","trescientos","cuatrocientos",
                   "quinientos","seiscientos","setecientos","ochocientos",
                   "novecientos"};
                   
const char *especiales[] = {"mil", "millon","millones","billon","billones"};


int numeros[] = {0,1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
                 21,22,23,24,25,26,27,28,29,30,40,50,60,70,80,90,100,100,
                 200,300,400,500,600,700,800,900};
                 
int numerosEspeciales[] = {1000,1000000,1000000,
                 				1000000000,1000000000};


FILE *outputFile;
int temp = 0;
bool flag = false;
int resultado = 0;

void letra_numero(char* palabra, int size){

  //Traductor de letras a numeros
  int i;
  int bytes = size * sizeof(char);
  int numero = 0;
  

  for(i=0; i < 48; i++){
	 if(memcmp(palabra,palabras[i],bytes) == 0){
	 	temp += numeros[i];
		return;
 	 }
  }
  
  for(i=0; i < 5; i++){
	 if(memcmp(palabra,especiales[i],bytes) == 0){
	 
	 	if(temp == 0){
	 		resultado += numerosEspeciales[i];
	 	}
	 	else{
	 		temp = temp * numerosEspeciales[i];
	 		resultado += temp;
	 		temp = 0;
	 		return;
	 	}
	 	
	 }
  }
}


int aux_letra_numero(char* palabra, int n){

  char token[30];   //para almacenar cada token 
  int indice = 0;   //para marcar el indice actual del buffer

  int i;            //indice para recorrer la linea
  
  
  //Recorrer la linea
  for(i=0; i < n; i++){
    
  	 if(palabra[i] == ' '){ // si hay un espacio es un nuevo token
  	 	letra_numero(token,indice);
  	 	indice = 0;

  	 }
  	 else{ //se agrega caracter al buffer (token)
  	 	token[indice] = palabra[i];
  	 	indice++;

  	 }
  }
   token[indice] = palabra[i];
  	indice++;
  	letra_numero(token,indice);
	return reiniciar();
}


void output(int res){
	              
	
	char stringNum[255];
	sprintf(stringNum,"%d",res);
	fputs(stringNum,outputFile);
	fputc('\n',outputFile);

}

void outputString(char* cadena){
	fputs(cadena,outputFile);
	fputc('\n',outputFile);

}



int reiniciar(){
	int resultadoFinal = resultado + temp;
	resultado = 0;
	temp = 0;
	output(resultadoFinal);
	return resultadoFinal;
}

void analizarCadena(char * cadena, int size){
	//Analiza cada cadena para ver si es un romano, decimal o 
	//palabras
	int i;
	int numero;
	bool esNumero = false;
	bool romano = false;
	for(i = 0; i < size; i++)
   {
      if (isdigit(cadena[i])){
      	esNumero = true;
      }
      else{
			if(isupper(cadena[i])){
				romano = true;
			}
			else{
				romano = false;

			}
      }
   }
   
   if(!esNumero && !romano){
   	aux_letra_numero(cadena, size);
   	//hay que pasarlo a romano
   }
   
   else if(romano){
   
   	numero = romano_a_decimal(cadena,size+1);
   	outputString(numero_Letra(numero));
   }
   
   else if (esNumero && !romano){
   	char * final;
   	numero = strtol(cadena,&final,10);
   	outputString(numero_Letra(numero));
   	
   }

}

void fileHandler(char* fileName){		  //Funcion encargada de abrir archivos y enviar cadenas
								 // al analizador de cadenas
								 
	char c;               // para almacenar temporalmente cada caracter
	char EOL = '\n';      // marca el final de una linea
	char buffer[255];     // buffer en el que se almacena cada linea
	int indiceBuffer = 0;
	
	FILE *f;              //variable del archivo de texto
	
	f = fopen(fileName, "r" );//se abre el archivo solo para lectura
	
	if(f == NULL){ //manejo de errores
		printf("Error al abrir el archivo.\n");
		return;
	}
	
	//Recorrer el archivo hasta el EOF
	while( (c = fgetc(f)) != EOF){
		if(c == EOL){
			indiceBuffer--;
			analizarCadena(buffer,indiceBuffer); //nuevo token
			indiceBuffer = 0;
		}
		
		else{
			buffer[indiceBuffer] = c;
			indiceBuffer++;
		}
	}
	fclose(f);
}

void greet(){

	printf("%s",saludo1);
	printf("%s",saludo2);
	printf("%s",saludo3);
	printf("%s",saludo1);
}

void menu(){
	
	char file[100];
	printf("Digite el nombre del archivo: ");
	scanf("%s",file);
	printf("Abriendo el archivo: %s\n",file);
	fileHandler(file);

}

int main(){
	outputFile = fopen("output.txt", "w+" );
	greet();
	menu();
	printf("El resultado se encuentra en el archivo output.txt\n Adios!\n");
   fclose(outputFile);
}
