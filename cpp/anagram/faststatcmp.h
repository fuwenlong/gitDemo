/*
 * File:faststatcmp.h
 * Data: 1 - Jan - 2014
 * Author: fuwenlong@126.com
 * 
 * Details:
 * Using statistical information from two strings to compare whether they are an anagram.
 * 
 * 
 * Complexity:  
 * O(n), where n is the length of one or two ( assuming one.length = two.length)
 * 
 * Advantage:
 * After one pass over two strings, the statistical information will be obtained immediately.
 * 
 * Disadvantage:
 * This algorithm allows a low probability to consider two strings (not a true 
 * anagram) as an anagram.  
 * 
 * ToDo:
 * Shift the statistical information to an effective hash code method so that two strings have the same 
 * hash value if they are considered as an anagram.
 * 
 * 
 * CopyRights (2014):  
 * fuwenlong@126.com
 */ 

#ifndef FAST_STAT_CMP_H
#define FAST_STAT_CMP_H

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
 * Comparing two strings based on their statistical information. 
 * 
 */  
class FastStatCmp: public Compare_Alg
{
  
public:
  /*
   * Construct
   * 
   * @param pMsg (out) Record all warning and error messages when building a model and calling the model. 
   */
  FastStatCmp( Common_Util::CMMessage* const pMsg );
  FastStatCmp( const FastStatCmp& one );
  
  virtual ~FastStatCmp();
   
  
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
private:
  /*
   * Construct
   */
  FastStatCmp();
  
    
};
    
}

#endif
 