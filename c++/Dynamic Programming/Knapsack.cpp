Dados N articulos, cada uno con su propio valor y peso y un tamaño maximo de una mochila, se debe calcular el valor maximo de los elementos que es posible llevar.
Debe seleccionarse un subconjunto de objetos, de tal manera que quepan en la mochila y representen el mayor valor posible.

#include <algorithm>

const int MAX_WEIGHT = 40;//Peso maximo de la mochila
const int MAX_N = 1000; //Numero maximo de objetos
int N;//Numero de objetos 
int prices[MAX_N];//precios de cada producto
int weights[MAX_N];//pesos de cada producto
int memo[MAX_N][MAX_WEIGHT];//tabla dp

//El metodo debe llamarse con 0 en el id, y la capacidad de la mochila en w
int knapsack(int id, int w) {
  	if (id == N || w == 0) {
  		return 0;
  	}
  	if (memo[id][w] != -1) {
  		return memo[id][w];
  	}
  	if (weights[id] > w){
  		memo[id][w] = knapsack(id + 1, w);
  	}else{
  		memo[id][w] = max(knapsack(id + 1, w), prices[id] + knapsack(id + 1, w - weights[id]));
  	}
  	
  	return memo[id][w];
}

//La tabla memo debe iniciar en -1
memset(memo, -1, sizeof(memo[0][0]) * MAX_N * MAX_WEIGHT );
