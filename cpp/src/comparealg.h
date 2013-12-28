/*
 * File:comparealg.h
 * Data: 28 - Dec - 2013
 * Author: Fuwenlong@126.com
 * 
 * Details:
 * Interface for comparing two datasets. 
 *
 * 
 * Functions:
 * CompareTo  
 */ 

#ifndef COMPARE_ALG_H
#define COMPARE_ALG_H

namespace Data_Common
{
  class DataHandler;
}

namespace Compare_Alg
{
  
/*
 * An interface for comparing two datasets. 
 * 
 */  
class CompareAlg
{
private:
  
  CompareAlg();
  CompareAlg( const CompareAlg& one );
  
  virtual ~CompareAlg();
  
  
public:
  
  
  /*
   * Compare two datasets 
   * @param  one The first datasets
   * @param  two The second datasets
   * 
   * @return True   one is logically equal to two.
   *         False  one is not logically equalt to two. 
   */
  virtual bool CompareTo( 
     const Data_Common::DataHandler* one,
     const Data_Common::DataHandler* two
			) const = 0;    
};
    
}

#endif
 