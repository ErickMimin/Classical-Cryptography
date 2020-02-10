#ifndef AFFINE_H_
#define AFFINE_H_

#include "Cipher.h"

    class AffineKey{
        public:
            int a, b;
    };

    class Affine: public Cipher{

        protected:
            AffineKey key;
            string file;            
        public:
            Affine(AffineKey, string, string);
            Affine(AffineKey, string);
            static int modInverse(int, int);
            static int gcdExtended(int, int, int*, int*);
            void encrypt();   
            void decrypt();     

    };

#endif