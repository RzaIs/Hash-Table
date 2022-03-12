COMPILER = gcc
EX = .c

OBJdir = bin
HDRdir = include
SRCdir = src

FLAGS = -Wall

obj = $(patsubst $(SRCdir)/%$(EX), $(OBJdir)/%.o, $(wildcard $(SRCdir)/*))
hdr = $(wildcard $(HDRdir)/*)

build: $(OBJdir)/run

run: $(OBJdir)/run
	./$^

clean:
	@if find $(OBJdir) -mindepth 1 -maxdepth 1 | read; then rm $(OBJdir)/*; fi

$(OBJdir)/run: $(obj)
	$(COMPILER) $^ -o $@

$(OBJdir)/%.o: $(SRCdir)/%$(EX) $(hdr)
	$(COMPILER) -c $< -o $@ -I "$(HDRdir)/" $(FLAGS)
