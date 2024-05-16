Estructura de datos basada en politicas. Funciona como un set<> pero es internamente indexado, cuenta con dos funciones adicionales.
.find_by_order(k) -> Retorna un iterador al k-esimo elemento, si k >= size() retona .end()
.order_of_key(x) -> Retorna cuantos elementos hay menores (<) que x

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;