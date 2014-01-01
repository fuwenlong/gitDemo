/*
 * File:bucketcmp.h
 * Data: 1 - Jan - 2014
 * Author: fuwenlong@126.com
 * 
 * Details:
 * Using a fixed bucket to store all letters from two strings, then checking 
 * whether all values in the bucket are equal to 0. If all values are equal to 0, 
 * two strings are considered as an anagram.
 * 
 * 
 * Complexity:  
 * O(n) + O(M), where, n is the length of one or two ( assuming one.length = two.length),
 * and M is the size of the range of all letters after encoding.
 * + Space O(M), required by the bucket. 
 * 
 * Advantage:
 * After one pass over two strings, only a constant bucket is needed to check. For large strings,
 * the bucket can be used to effectively reduce the computational cost. 
 * 
 * Disadvantage:
 * A buffer with the size of M is required.  
 * 
 * ToDo:
 * Find the minumum leghth of a string to choose bucket sort or a fast sort algorithm.  
 * 
 * CopyRights (2014):  
 * fuwenlong@126.com
 */ 

#ifndef FAST_STAT_CMP_H
#define FAST_STAT_CMP_H

#include "comparealg.h"

namespace Data_Common
{
  class DataHandler;
}

namespace Compare_Alg
{
  
/*
 * Comparing two strings based on their statistical information. 
 * 
 */  
class BucketCmp: public Compare_Alg
{
  
public:
  
  BucketCmp();
  BucketCmp( const BucketCmp& one );
  
  virtual ~BucketCmp();
   
  
  /*
   * Compare two datasets 
   * @param  one The first datasets
   * @param  two The second datasets
   * 
   * @return True   one is logically equal to two.
   *         False  one is not logically equalt to two. 
   */
  virtual bool Compare( 
     const Data_Common::DataHandler* one,
     const Data_Common::DataHandler* two
			);    
    
};
    
}

#endif
 