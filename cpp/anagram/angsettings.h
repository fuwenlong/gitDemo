 /*
 * File:angsettings.h
 * Data: 1 - Jan - 2014
 * Author: fuwenlong@126.com
 * 
 * Details:
 * Settings for Anagram. 
 * 
 * ToDo:
 * Might be driven from a basic setting class (including common settings for most algorithms).
 * 
 * CopyRights (2014):  
 * fuwenlong@126.com
 */ 
 
#ifndef Ang_Setting_H
#define Ang_Setting_H



namespace Anagram
{


/*
 * Provide different algorithm models to check two strings as anagram or not.  
 */  
class AngSettings
{

public:
  
  /*
   * Construct 
   * 
   */
  AngSettings( );

  /*
   * Destruct
   */
  virtual ~AngSettings();
  
  // ToDo: 
  // void SetAlg( AngAlgMethod );
  // 
  
private:
  
}  
  
}
