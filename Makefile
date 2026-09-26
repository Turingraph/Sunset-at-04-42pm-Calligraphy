CC = cc -Wall -Wextra -Werror
SRC_motif = $(wildcard improvise/motif/*.c)
SRC_wood = $(wildcard improvise/wood/*.c)
SRC_quantum_spirit = $(wildcard improvise/quantum_spirit/*.c)
SRC_non_euclidean = $(wildcard improvise/non_euclidean/*.c)
SRC_suisei = $(wildcard fanart/suisei/*.c)
SRC_zutomayo = $(wildcard fanart/zutomayo/*.c)
# SRC_3b1b = $(wildcard fanart/3b1b/*.c)
SRC_improvise = $(SRC_non_euclidean) $(SRC_wood) $(SRC_motif) $(SRC_quantum_spirit)
SRC_fanart = $(SRC_zutomayo) $(SRC_suisei)
SRC_artworks = $(SRC_fanart) $(SRC_improvise)

OBJ_artworks = $(patsubst %.c, obj/%.o, $(SRC_artworks))
OUT_artworks = $(patsubst %.c, out/%.out, $(SRC_artworks))

all: $(OUT_artworks)

$(OUT_artworks): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. include/sunset442pm.a include/libmlx42.a -ldl -lglfw -pthread -lm

# *** create object files. ***
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

clean:
	rm -r -f out/
	rm -r -f obj/

re: clean
	make all

.PHONY: all clean re
