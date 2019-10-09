Divide el string s por espacios. Devuelve un vector<> con los substrings resultantes.
* Tambien puede dividir el string s por cada ocurrencia de un char c. (Para esto quitar los "//")

vector<string> split(string &s/*, char c*/) {
    vector<string> v;
    istringstream iss(s);
    string sub;
    while (iss >> sub) {
    //while (getline(iss, sub, c)) {
        v.push_back(sub);
    }
    return v;
}
