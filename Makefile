all: dsalg.dvi

clean:
	rm *.tex

dsalg.dvi: dsalg.tex recursion.tex intro.tex
	latex dsalg

%.tex : %.tx
	./scripts/compile $<