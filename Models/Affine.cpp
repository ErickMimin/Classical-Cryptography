#include "Affine.h"

Affine::Affine(AffineKey k, string a, string m): Cipher(a, m), key(k){} 

Affine::Affine(AffineKey k, string a): Cipher(a), key(k){}

void Affine::encrypt(){
    for(int i = 0; i < menssage.length(); i++){
        if(alphabet.find(menssage[i]) < alphabet.length())
            cMenssage.push_back(alphabet[mod(((alphabet.find_first_of(menssage[i]) * key.a) + key.b), alphabet.length())]);    
        else 
            cMenssage.push_back(menssage[i]);
    }
    
}

void Affine::decrypt(){
    for(int i = 0; i < cMenssage.length(); i++){
        if(alphabet.find(cMenssage[i]) < alphabet.length())
            menssage.push_back(alphabet[mod(((alphabet.find_first_of(cMenssage[i]) - key.b) * modInverse(key.a, alphabet.length())), alphabet.length())]);
        else
            menssage.push_back(cMenssage[i]);        
    }
}

int Affine::modInverse(int a, int m){ 
    a = mod(a, m);
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1;
    else
        // m is added to handle negative x 
        return (x % m + m) % m; 
} 
  
int Affine::gcdExtended(int a, int b, int *x, int *y){ 

    if (a == 0){ 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1); 
   
    *x = y1 - (b / a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
