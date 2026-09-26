CC = cc -Wall -Wextra -Werror
SRC_suisei = $(wildcard fanart/suisei/*.c)
SRC_awake = $(wildcard fanart/awake/*.c)
SRC_zutomayo = $(wildcard fanart/zutomayo/*.c)
# SRC_3b1b = $(wildcard fanart/3b1b/*.c)
SRC_artworks = $(SRC_zutomayo) $(SRC_suisei) $(SRC_awake)
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
