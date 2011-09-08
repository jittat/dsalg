all: dsalg.html

clean:
	rm *.html recursion.txt

dsalg.html: dsalg.txt recursion.txt
	asciidoc -a latexmath dsalg.txt

recursion.txt: recursion.tx
	python scripts/compile-math.py recursion.tx

