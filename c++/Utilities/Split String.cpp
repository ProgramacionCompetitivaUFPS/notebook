Divide el string s por cada espacio ' ' y devuelve un vector<> con los substrings resultantes.
Para dividir el string por un caracter especifico, agregar el parametro c y cambiar el while.

vector<string> split(const string &s/*, char c*/) {
    vector<string> v;
    stringstream ss(s);
    string sub;
    while (ss >> sub) v.pb(sub);
    // while (getline(ss, sub, c)) v.pb(sub);
    return v;
}
