Realiza a^b y retorna el resultado módulo c

static long binaryExponentiation(long a, long b, long c){
	    if (b == 0){
	    	return 1;
	    } 
	    if (b % 2 == 0){
	        long temp = binaryExponentiation(a,b/2, c);
	        return (temp * temp) % c;
	    }else{
	        long temp = binaryExponentiation(a, b-1, c);
	        return (temp * a) % c;
	    }
	}
