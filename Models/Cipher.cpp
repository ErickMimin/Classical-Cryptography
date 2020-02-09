#include "Cipher.h"

Cipher::Cipher(string a, string m): menssage(m), alphabet(a){
    /* Verificacion */
}

Cipher::Cipher(string a): alphabet(a){
    /* Verificacion */
}


Cipher::~Cipher(){
}

string Cipher::getCipherMenssage(){
    return cMenssage;
}

void Cipher::setCipherMenssage(string m){
    cMenssage = m;
}

string Cipher::getMenssage(){
    return menssage;
}

int Cipher::mod(int a, int n){
    int r = a % n;
    return r < 0 ? r + n : r;
}