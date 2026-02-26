CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -DLV_CONF_INCLUDE_SIMPLE -I. -I$(LVGL_DIR) $(shell pkg-config --cflags sdl2)
LDFLAGS = -L. -llvgl $(shell pkg-config --libs sdl2) -lm

LVGL_DIR_NAME ?= lvgl
LVGL_DIR ?= $(shell pwd)
include $(LVGL_DIR)/$(LVGL_DIR_NAME)/lvgl.mk

TARGET = mainFirm

# Sorgenti del TUO progetto (escludiamo $(CSRCS) di LVGL)
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Oggetti di LVGL (derivati da $(CSRCS) definito in lvgl.mk)
LVGL_OBJS = $(CSRCS:.c=.o)
LVGL_LIB = liblvgl.a

all: $(LVGL_LIB) $(TARGET)

# Compila il tuo eseguibile linkando la libreria statica
$(TARGET): $(OBJS) $(LVGL_LIB)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Crea la libreria statica SOLO se non esiste o se i sorgenti LVGL cambiano
$(LVGL_LIB): $(LVGL_OBJS)
	ar rcs $@ $(LVGL_OBJS)
	@echo "Libreria LVGL creata con successo."

# Regola generica per i file .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Il tuo CLEAN non tocca più liblvgl.a né gli oggetti dentro la cartella lvgl/
clean:
	rm -f $(TARGET) $(OBJS) *.d
	@echo "Puliti solo i file del progetto. LVGL rimane compilato."

# Se vuoi cancellare TUTTO, inclusa la libreria LVGL
distclean: clean
	rm -f $(LVGL_LIB)
	find $(LVGL_DIR_NAME) -name "*.o" -type f -delete
	find $(LVGL_DIR_NAME) -name "*.d" -type f -delete
	@echo "Tutto rimosso, inclusa la libreria LVGL."

.PHONY: all clean distclean

