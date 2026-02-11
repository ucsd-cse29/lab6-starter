
default: cse100

cse8a:
	touch cse8a

cse11:
	touch cse11

cse12: cse11
	touch cse12

cse29: cse11
	echo 'Taking CSE 29... (you right now!)'
	touch cse29

cse30: cse29
	touch cse30

cse20: cse11
	touch cse20

cse21: cse20
	touch cse21

cse100: cse21 cse12 cse29
	touch cse100

.PHONY: clean

clean:
	rm -f cse*
