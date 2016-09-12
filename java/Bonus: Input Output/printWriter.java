Utilizar en lugar del System.out.println para mejorar la eficiencia.

import java.io.PrintWriter;

PrintWriter so = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
so.print("Imprime sin salto de linea");
so.println("Imprime con salto de linea");

//Al finalizar
so.close();
