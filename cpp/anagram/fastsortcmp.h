/*
 * File:fastsortcmp.h
 * Data: 1 - Jan - 2014
 * Author: fuwenlong@126.com
 * 
 * Details:
 * Sort two strings (one and two) based on fast sort algorithm, then compare each letter from the begin, 
 * string one -> sort -> Sone 
 * string two -> sort -> Stwo 
 * 
 * Complexity:
 * O(nlog(n)), where n is the length of one or two ( assuming one.length = two.length)
 * 
 * Advantage:
 * No more space is required. 
 * 
 * Disadvantage:
 * The sort algorithm is not cheap.  
 * 
 * CopyRights (2014):  
 * fuwenlong@126.com
 */ 

#ifndef FAST_SORT_CMP_H
#define FAST_SORT_CMP_H

#include "comparealg.h"

namespace Common_Util
{
  class CMMessage;
}

namespace Data_Common
{
  class DataHandler;
}

namespace Compare_Alg
{
  
/*
 * Comparing two strings based on fast sort. 
 * 
 */  
class FastSortCmp: public Compare_Alg
{
  
public:
    /*
   * Construct
   * 
   * @param pMsg (out) Record all warning and error messages when building a model and calling the model. 
   */
  FastSortCmp( Common_Util::CMMessage* const pMsg  );
  FastSortCmp( const FastSortCmp& one );
  
  virtual ~FastSortCmp();
   
  
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
			) const;  
private:
  FastSortCmp( );
    
};
    
}

#endif
 