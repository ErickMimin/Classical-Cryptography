#include "Vigenere.h"

Vigenere::Vigenere(string k, string a, string m): Cipher(a, m), key(k){} 

Vigenere::Vigenere(string k, string a): Cipher(a), key(k){}

void Vigenere::encrypt(){
    for(int i = 0; i < menssage.length(); i++)
        cMenssage.push_back(alphabet[(alphabet.find_first_of(menssage[i]) + alphabet.find_first_of(key[i % key.length()])) % alphabet.length()]);    
}

void Vigenere::decrypt(){
    for(int i = 0; i < cMenssage.length(); i++)
        menssage.push_back(alphabet[mod(alphabet.find_first_of(cMenssage[i]) - alphabet.find_first_of(key[i % key.length()]), alphabet.length())]);    
}