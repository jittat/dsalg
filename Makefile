all: dsalg.dvi

LANG=cpp

clean:
	rm *.tex dsalg.dvi

dsalg.dvi: dsalg.tex recursion.tex intro.tex
	latex dsalg

%.tex : %.tx
	./scripts/compile $< $(LANG)