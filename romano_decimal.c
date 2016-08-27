

//Metodo que recieb un string correspondiente al numero romano y el largo del string y devuelve la representacion del numero decimal

int romano_a_decimal(char numero_R[], int size){
    int numero_A[20];
    int i;
    int suma=0;

    for(i=0;i<20;i++){
        numero_A[i]=0;
    }
    for(i=0;i<size;i++){
        switch(numero_R[i])
        {
            case 'I': numero_A[i]=1;break;
            case 'V': numero_A[i]=5;break;
            case 'X': numero_A[i]=10;break;
            case 'L': numero_A[i]=50;break;
            case 'C': numero_A[i]=100; break;
            case 'D': numero_A[i]=500; break;
            case 'M': numero_A[i]=1000; break;
            default: break;
        }
    }
    for(i=0;i<size;i++){
        if(numero_A[i] < numero_A[i+1])
            suma -= numero_A[i];
        else
            suma += numero_A[i];
    }

    return suma;
}


