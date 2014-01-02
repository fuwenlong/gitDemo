/*
 * File:anagrambuilder.h
 * Data: 1 - Jan - 2014
 * Author: fuwenlong@126.com
 * 
 * Details:
 * Build a algorithm to check whether two strings are an anagram.  
 *
 * CopyRights (2014):  
 * fuwenlong@126.com
 */ 
#ifndef ANAGRAM_BUILDER_H
#define ANAGRAM_BUILDER_H

namespace Common_Util
{
  class CMMessage;
}

namespace Compare_Alg
{
  class Compare_Alg;
}


namespace Anagram
{

class AngSettings;

/*
 * Provide different algorithm models to check two strings as anagram or not.  
 */  
class AnagramBuilder
{

public:
  
  /*
   * Construct 
   * 
   * @param pMsg (out) Record all warning and error messages when building a model and calling the model. 
   * @param pSetting  Settings for building a model. 
   * 
   */
  AnagramBuilder( 
    Common_Util::CMMessage* const pMsg, 
    const Anagram::AngSettings* pSetting );
  
  virtual ~AnagramBuilder();
  
  
 /*
  * Create a new comparison instance using fast sort. 
  * 
  * @retrun an instantiated comparion algorithm model. 
  */
  Compare_Alg::CompareAlg* BuildOne( ) const;  

private:
  /*
   * Construct
   */
  AnagramBuilder( );
  
  
private:
  
}  
  
}