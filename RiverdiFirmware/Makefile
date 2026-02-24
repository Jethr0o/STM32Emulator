# Configurazione Compilatore
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 $(shell pkg-config --cflags sdl2)
LDFLAGS = $(shell pkg-config --libs sdl2)

# Nome dell'eseguibile finale
TARGET = mainFirm

# Trova automaticamente tutti i file .c nella cartella corrente
SRCS = $(wildcard *.c)
# Genera i nomi dei file .o a partire dai file .c
OBJS = $(SRCS:.c=.o)

# --- REGOLE ---

all: $(TARGET)

# Link finale: unisce tutti gli oggetti in un unico eseguibile
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compilazione: trasforma ogni .c in .o
# -MMD genera file .d per tracciare i cambiamenti negli header (.h)
%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Include le dipendenze degli header generate automaticamente
-include $(SRCS:.c=.d)

clean:
	rm -f $(TARGET) $(OBJS) *.d

.PHONY: all clean

