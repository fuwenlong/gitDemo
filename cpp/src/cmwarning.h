/*
 * File:cmwarning.h
 * Data: 1 - Jan - 2014
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
 *  o Add
 *  o Merge
 *  o OutputMsg
 */

#ifndef CM_WARNING_H
#define CM_WARNING_H

#include <ostream> // std::ostream* pOutF
#include <list>   // list< std::string >
#include <string> 

namespace Common_Util
{

// container   
typedef std::list< std::string > ListMsg;
typedef ListMsg::iterator ListMsgItr;
  
/*
 * record warning messages. 
 */  
class CMWarning
{
public:
  /*
   * Construct
   */
  CMWarning( );
  CMWarning( const CMWarning& one );
  
  /*
   *  Destruct
   */
  virtual ~CMWarning();
  
  /*
   * Add one warning message
   * 
   * @param msg The warning infomation will be added. 
   */ 
  void Add( const char* msg );

  /*
   * add all warning messages from another instance (called one). 
   * 
   * @param one An existing <tt>CMWarning</tt> instance.   
   */ 
  void Merge( const CMWarning& one );
  
  /*
   * Output all messages into an output stream. 
   * 
   * @param pOutF (out) The output stream records all messages.  
   */
  void OutputMsg( std::ostream* const pOutF ) const; 
  
private:
  // container includes all warning messages.  
  ListMsg mvStrMsgs;
  
};
  
}

#endif
