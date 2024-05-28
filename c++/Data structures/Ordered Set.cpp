> Funciona como un set<> que además cuenta con dos funciones adicionales.

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

ordered_set<int> st;
st.find_by_order(k) // Retorna iterador al k-ésimo elemento más pequeño
                    // Si k >= st.size() entonces retorna st.end()
st.order_of_key(x)  // Retorna cuántos elementos hay menores que x
