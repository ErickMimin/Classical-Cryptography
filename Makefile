MAIN=main.cpp
DEPENDENCIES=Models/Vigenere.cpp Models/Cipher.cpp Models/Affine.cpp
LIBRARIES= -I./Models 
ALPHABET=alphabet.txt
FILE=Menssages/m3

run_vig_en: main $(ALPHABET) $(FILE).txt
	./main $(ALPHABET) $(FILE).txt 1

run_vig_de: main $(ALPHABET) $(FILE).vig
	./main $(ALPHABET) $(FILE).vig 3

run_aff_en: main $(ALPHABET) $(FILE).txt
	./main $(ALPHABET) $(FILE).txt 2

run_aff_de: main $(ALPHABET) $(FILE).aff
	./main $(ALPHABET) $(FILE).aff 4

main: $(MAIN) $(DEPENDENCIES)
	g++ $(LIBRARIES) $(MAIN) $(DEPENDENCIES) -o main 
