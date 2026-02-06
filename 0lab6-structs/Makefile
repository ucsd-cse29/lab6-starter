default: sizes alignment

sizes: sizes.c structs.h
	gcc sizes.c structs.h -o sizes

alignment: structs.h alignment.c
	gcc alignment.c structs.h -o alignment

clean:
	rm alignment sizes
