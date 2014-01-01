/*
 * File:datahandler.h
 * Data: 1 - Jan - 2013
 * Author: fuwenlong@126.com
 * 
 * Details:
 * Basic data handler is used to read data.  
 * This provides encoded data. 
 * 
 * 
 * CopyRights (2014):  
 * fuwenlong@126.com
 * 
 * Functions:
 * o Load
 * o NextInt
 * o NextDouble
 * o NextRow
 * 
 */

#ifndef DATA_HANDLE_H
#define DATA_HANDLE_H

#include <fstream>
#include <istream>

namespace Common_Util
{
  class CMWarning;
}

namespace Data_Common
{

/*
 * Read data to process. 
 */  
class DataHandler
{
public:
  /*
   * Construct 
   * 
   */
  DataHandler();
  DataHandler( const DataHandler& one );
  /*
   * Construct 
   * 
   * @param  pone The loaded stream. 
   */
  DataHandler( std::istream* pone );
  /*
   * Construct 
   * 
   * @param  fName The loaded file name. 
   */
  DataHandler( const char* fName ); 
  
  /*
   * Destruct
   * 
   */
  virtual ~DataHandler();
  
  /*
   * Load file from fName, mStrFName (assinged by constructor)
   * or mFData (assinged by constructor).
   * 
   * @param fName The loaded file name.
   * 
   * @return True   Load successfully.
   *         False  Problems in reading the given file. 
   */
  virtual bool Load( const char* fName = 0 );
  
  /*
   *  Read an int value. 
   * 
   * @return A int value in the current row.  
   */
  virtual int NextInt();
  
  /*
   *  Read a double value. 
   * 
   * @return A double value in the current row.  
   */
  virtual double NextDouble();
  
  /*
   * Check whether Finished a pass.  
   * 
   * @return True    not finish a pass.
   *         False   finish a pass. 
   */
  virtual bool NextRow();
  
    
private: 
  // loaded file name 
  std::string mStrFName;
  // loaded file stream
  std::fstream mFData;
  
  // Todo: do we need buffer?
  // int ** 
  // double **
  
  CMWarning* mpxWarning;
  
};
  
  
  
}


#endif
