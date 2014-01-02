/*
 * File:anagram.cpp
 * Data: 28 - Dec - 2013
 * Author: Fuwenlong@126.com
 * 
 * Details:
 * Compare two strings to check whether they are anagram worlds. 
 *
 * ToDo:
 * Move the application to test directory, and create a class (API) to solve the problem. 
 * 
 * CopyRights (2014):  
 * fuwenlong@126.com
 */ 

#include <exception> 
#include <iostream>

#include "anagrambuilder.h" // Anagram::AnagramBuilder
#include "angsettings.h"   //  Anagram::AngSettings
#include "datahandler.h"   //  Data_Common::DataHandler
#include "cmmessage.h"     //  Common_Util::CMMessage
#include "comparealg.h"    // CompareAlg



int main( int argc, char** argv )
{
// 1. read parameters
Anagram::AngSettings aSet;
// ToDo, load parameters  

// 2. load two strings. 
// 
 Data_Common::DataHandler one;
 Data_Common::DataHandler two;
// ToDo: load files to store strings 
 
// 3. build a algorithm model 
 try{
   Common_Util::CMMessage msg; 
   Anagram::AnagramBuilder* pBuilder = 
   new Anagram::AnagramBuilder( &msg, &aSet );
 
   CompareAlg* palg( 0 );
 
   if( pBuilder )
   {
      palg = pBuilder->BuildOne();
   }
   else
   {
     // throw errors or directly print out error message. 
     std::cerr<< "Cannot new Anagram::AnagramBuilder " << std::endl;
     return -1;   
   }
   
// 4. check whether two strings have same letters. 
   bool bAna( false );
   if( palg )
   {
      bAna = palg->Compare(&one, &two);  
   }
   else
   {
      // throw errors or directly print out error message. 
      std::cerr<< "Cannot build an algorithm model" << std::endl;
      return -1; 
   }

// 5. give results.  here std::cout true or false. 
   if( msg.IsGood( ) )
   {
     std::cout<<" Answer: "<< ( bAna ? " Yes" : " No" )<<std::endl;
   }
   else
   {
      std::cout<<" Errors: "<< msg.GetError( ) <<std::endl;
   }
   
   // 6. release
   if( pBuilder )
   {
      delete pBuilder;
      pBuilder = 0;
   }
 
   if( palg )
   {
      delete palg;
      palg = 0;
   }
   
}
// ToDo: further process expections 
catch( std::exception& e )
{  
   std::cerr<< e.what() << std::endl;
   return -1;
}
  
return 0;
}
