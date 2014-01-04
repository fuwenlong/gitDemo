#!/usr/bin/python
# File: demoDA.py 
# Author: fuwenlong@126.com
# Data: 7 - Dec - 2013
# Details:
#  a demo for discriminant analysis 
# Copyrights (2014): 
#    fuwenlong@126.com
#

from numpy import matrix,genfromtxt,random;
import DA;

import sys,getopt;

#import matplotlib.pyplot as plt

# read file 
fred = open( "iris.data", 'r' );
vars = [];
for line in fred:
  attone =  line.split(',');
  tmpv = [];
  for ai in attone:
    tmpv.append( float( ai ) );
  vars.append( tmpv )  ;
  #print float( line );
  #vars.append( float( line ) );
#print vars
  
# using numpy
## numpy.ndarray
#vars = genfromtxt("iris.data", delimiter="\n");
#print vars;
ncase = len( vars );
varsM = matrix( vars );
print ncase;
dweigtFlag = random.random_integers( 0, 3, ncase ) - 1;

#count, bins, ignored = plt.hist(dweigtFlag, 11, normed=True)
#plt.show()

da = DA.DA( varsM, dweigtFlag.tolist() );

da.run();

acc = da.predicatoin();

print acc;

