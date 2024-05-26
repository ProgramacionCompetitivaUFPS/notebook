import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    
    public static void main(String[] args) {
        // Tu código...
        int a = Integer.parseInt(in.next());
        int b = Integer.parseInt(in.next());
        double c = a + b;
        // Para imprimir con 6 decimales
        // Locale.setDefault(Locale.US);
        // out.printf("%.6f\n", c);
        out.println(c);
        out.close(); // Obligatorio al finalizar el programa
    }
}
