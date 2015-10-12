Utilizar en lugar del System.out.println para mejorar la eficiencia.

import java.io.PrintWriter;

PrintWriter so = new PrintWriter(System.out);
so.print("Imprime sin salto de linea");
so.println("Imprime con salto de linea");

//Al finalizar
bw.flush();
