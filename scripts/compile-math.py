import sys
import re

def compile_math(input_filename, output_filename):
    f = open(output_filename,"w")
    lines = open(input_filename).read()
    output = re.sub(r'\$([^\$]+)\$',r'latexmath:[$\1$]',lines)
    f.write(output)
    f.close()

def main():
    for f in sys.argv[1:]:
        fout = f.replace("tx","txt")
        compile_math(f,fout)

if __name__=='__main__':
    main()
