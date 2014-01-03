#!/usr/bin/python
# File: DA.py 
# Author: fuwenlong@126.com
# Data: 7 - Dec - 2013
#
# Details:
#   discriminant analysis 
#   Just a demo
#   real module needs to be inherited from abstract class
#   fisher's discriminant analysis
#   (x - mu ) sig.I (x-mu).T 
# Copyrights (2014): 
#    fuwenlong@126.com
#
from numpy import matrix;

class DA:
  __vars__ = matrix( [] ); #matrix; # last index for target 
  # __targetLabel__ = 0;
  __weightFlag__ = [];
  __mu__ = [];
  __std__ = []; 
  __indexTarget__ = -1;
  __classLabel__ = {} ;
  __nLabels__ = [];
  __nTotlcase = 0;
  
  def __init__( self, varbuf, weightFlag, classLabel = { } ) :
    self.__vars__ = varbuf;
    #self.targetLabel__ = targetLable;
    self.__weightFlag__ = weightFlag;
    self.__nTotlcase,width = self.__vars__.shape;
    self.__indexTarget__ = width - 1;
    self.__classLabel__ = classLabel;
    
    
  def run( self ):
   # save codes, use matrix operation 
   # for casex in self.__vars__ :
   #   for attx in xrange( len(casex) ) :
   X = matrix( self.__vars__ );
   #print X;
   XT = X.T;
   # parsing class labels?
   if self.__classLabel__ == {} :
     #print 'get label',len( X );
     for xCase in xrange( len( X ) ):
       #print xCase, self.__weightFlag__[ xCase ], self.__indexTarget__;
       if self.__weightFlag__[ xCase ] >= 0 :
	 tmpL = X[ xCase, self.__indexTarget__] ;
         if (self.__classLabel__).has_key( tmpL ) :
	    self.__classLabel__[ tmpL ] += 1;
	 else: 
	    self.__classLabel__[ tmpL ] = 1;
  # get different class labels 
   self.__nLabels__ = (self.__classLabel__).keys( );
   print self.__nLabels__,self.__classLabel__;
   oneCIndex = matrix( [[ True ]* (self.__indexTarget__ + 1) ] );
   oneCIndex = oneCIndex.T;
   #SelectVars = matrix( [[ True ]* (self.__indexTarget__ + 1) ] );
   #SelectVars[ 0, self.__indexTarget__ ] = False;
   #print self.__nTotlcase, oneCIndex;
   for iclass in xrange( len( self.__classLabel__ ) ):
    tmp1 = matrix( self.__weightFlag__ ) >= 0;
    #print tmp1;
    tmp2 = XT[ self.__indexTarget__, :] == self.__nLabels__[ iclass ];
    Index = tmp1  & tmp2;
    Index = oneCIndex * Index;
    Index = Index.T;
    Index[:,self.__indexTarget__ ] = False;
    #print X.shape, Index.shape;
    nX = X[ Index ];
    nX = nX.reshape( -1,self.__indexTarget__ );
    #print nX;
    nXT = nX.T;
    nEx = nX.mean( 0 );
    #print nX, nEx; 
    self.__mu__.append( nEx );
    #sig = e(xx) - e(x)e(x)
    EXX = nXT*nX/ self.__nTotlcase ;
    tmpT = EXX - nEx.T*nEx;
    #print EXX, tmpT;
    self.__std__.append( tmpT ); 
   
   # finished to obtain mu and sig 
  
 # return test acc.  
  def predicatoin( self ) :
   dSumR = 0; 
   nClasses = len( self.__classLabel__  ); 
   nCases = len( self.__weightFlag__ );
   #nScore = [ matrix( [ ]*nCases ) ]* nClasses;
   ## all scores 
   nP = [0]*nCases;
   # hard to get each max, so only based on case by case 
   #for indexC in xrange( nClasses ): 
      #nScore[ indexC ] = ( self.__vars__ - self.__mu__[ indexC ] )*(self.__std__).I*( self.__vars__ - self.__mu__[ indexC ] ).T ; 
   # get index 
   varI = [ 0 ]*(self.__indexTarget__);
   for xi in xrange( len( varI ) ) :
     varI[ xi ] = xi;
  # based on case by case
   aTest = 0;
   istC = 0
   print self.__mu__,self.__std__;
   for xi in self.__vars__:
    indexMax = 0;
    maxDensity = float('inf') ;
    tmpX = xi.take( varI ) + 1;
    #print tmpX;
    for ci in xrange( nClasses ):
      tmpDensity = ( tmpX - self.__mu__[ ci ] )*(self.__std__[ ci ]).I*( tmpX - self.__mu__[ ci ] ).T ;
      #tmpDensity = ( tmpX - self.__mu__[ ci ] )*( tmpX - self.__mu__[ ci ] ).T ;
      #print ci,tmpDensity;
      if maxDensity > tmpDensity :
	maxDensity = tmpDensity;
	indexMax = ci;
    # end if
    # end for 
    nP[ istC ] = self.__nLabels__[ indexMax ] ;
    #print istC, nP[ istC ], xi;
    if self.__weightFlag__[ istC ] < 0 :
     aTest += 1.0;
     if nP[ istC ] == xi.take( [ self.__indexTarget__ ] )[ 0 ] :
       dSumR += 1.0; 
     if aTest== 0 :
      aTest = 1;
    istC += 1;
   return dSumR/aTest;
  