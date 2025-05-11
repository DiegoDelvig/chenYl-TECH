# Nom de l'exécutable final
EXEC = projet

# Compilateur
CC = gcc

#Options de compilation
CFLAGS = -Wall -Wextra -std=c99

# Fichiers source
SRC = *c

# Fichiers d'objets (automatiquement déduits)
OBJ = $(SRC:.c=.o)

# Règle principale
all: $(EXEC)

# Génération de l'exécutable
$(EXEC): $(OBJ)
    $(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Nettoyage des fichiers objects et de l'exécutable
clean:
    rm -f $(EXEC) $(OBJ)

# Recompilation compète
rebuild: clean all
