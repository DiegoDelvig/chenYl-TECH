#Programme à créer
PROG = projet

#Sources
SRC = *.c

#Regle par defaut
all: $(PROG)
	./$(PROG)

#compilation
$(PROG): $(SRC)
	gcc -o $(PROG) $(SRC)

#Nettoyage
clean : 
	rm -f $(PROG)
