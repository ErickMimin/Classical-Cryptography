#ifndef VIGENERE_H_
#define VIGENERE_H_

#include "Cipher.h"

    class Vigenere: public Cipher{

        protected:
            string key;
            string file;
        public:
            Vigenere(string, string, string);
            Vigenere(string, string);
            void encrypt();   
            void decrypt();     

    };
    

#endif