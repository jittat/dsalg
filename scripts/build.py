#!/usr/bin/env python
import glob
import os
import markdown
import time

def get_output_filename(filename):
    items = os.path.splitext(filename)
    return items[0] + '.txt'

def compile():
    os.system("make")

files = glob.glob("*.tx") + glob.glob("*/*.tx") + glob.glob("*/*/*.tx")

if len(files)==0:
    print "no file to track.  (only look at 3 levels)"
    quit()
else:
    print "tracking", len(files), "files"

while True:
    for f in files:
        oname = get_output_filename(f)
        if (not os.path.exists(oname) or
            (os.path.exists(f) and 
             (os.path.getmtime(f) > os.path.getmtime(oname)))):
            compile()
            print "Built"
    time.sleep(1)
