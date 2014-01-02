/*
 * File:cmmessage.h
 * Data: 3 - Jan - 2014
 * Author: fuwenlong@126.com
 * 
 * Details:
 * Common warning container.  
 *
 * CopyRights (2014):  
 * fuwenlong@126.com
 * 
 * 
 * Functions:
 *  o AddWarning
 *  o Merge
 *  o OutputMsg
 *  o IsGood
 *  o GetError
 */

#ifndef CM_MESSAGE_H
#define CM_MESSAGE_H

#include <ostream> // std::ostream* pOutF
#include <string> 

#include "cmwarning.h"  // CMWarning, ListMsg

namespace Common_Util
{
  
/*
 * record warning messages. 
 */  
class CMMessage
{
public:
  /*
   * Construct
   */
  CMMessage( );
  CMMessage( const CMMessage& one );
  
  /*
   *  Destruct
   */
  virtual ~CMMessage();
  
  /*
   * Add one warning message
   * 
   * @param msg The warning infomation will be added. 
   */ 
  void AddWarning( const char* msg );

  /*
   * add all warning messages from another instance (called one). 
   * 
   * @param one An existing <tt>CMMessage</tt> instance.   
   */ 
  void Merge( const CMMessage& one );
  
  /*
   * Output all messages into an output stream. 
   * 
   * @param pOutF (out) The output stream records all messages.  
   */
  void OutputMsg( std::ostream* const pOutF ) const; 
  
  /*
   * Check whether the current status is good or not.
   * 
   * @return False  An error must occur. 
   *         True   No errors. 
   */
  bool IsGood( ) const;
  
  /*
   * The current error messages. 
   * 
   * @return The current error messages. 
   * Note that "NA" will be returned if there are no error messages. 
   */ 
  std::string GetError() const; 
  
  
private:
  // error message records.
  ListMsg mvStrErr;
  
  CMWarning mxWarning;
};
  
}

#endif
