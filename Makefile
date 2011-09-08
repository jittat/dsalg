all: dsalg.html

clean:
	rm *.html recursion.txt intro.txt

dsalg.html: dsalg.txt intro.txt recursion.txt
	asciidoc -a latexmath -a pygments dsalg.txt

recursion.txt: recursion.tx
	python scripts/compile-math.py recursion.tx

intro.txt: intro.tx
	python scripts/compile-math.py intro.tx

