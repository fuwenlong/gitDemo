/**
 * File:BucketSingleton.java
 * Author:fuwenlong@126.com
 * Data: 3 - Jan - 2014
 *
 * Details:
 *  Create BucketSingleton to check two strings as an anagram or not.
 **/

import java.io.*;

public enum BucketSingleton
{
INSTANCE;

public static void main(String[ ] args) throws Exception
{
    // a demoe to use a singleton model.
	// note that BucketSingleton (enum) only shows a singleton model.
	// if two tasks call BucketSingleton at the same time, the results
	// might be wrong because mxIndicators would mix strings from two tasks together.
	// A modified version will be done in AnagramSingleton.
	INSTANCE.Reset();

    // first input
    System.out.println(" input first string");

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();

    for( int i = 0, n = line.length(); i < n; i ++ )
    	INSTANCE.IncreaseOne( line.charAt( i ) );


    System.out.println(" input another string");
    line = br.readLine();
    ;
    for( int i = 0, n = line.length(); i < n; i ++ )
    	INSTANCE.DecreaseOne( line.charAt( i ) );

    boolean brslt = INSTANCE.IsanAngaram( );
    System.out.println(" Angnam?");
    if( brslt ) System.out.println("Yes");
    else System.out.println("no");

    // Demo uses an instance (class) (not singlton).
	/*
	BucketSingleton one = new BucketSingleton();
    one.Reset();

    // first input
    System.out.println(" input first string");

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();

    for( int i = 0, n = line.length(); i < n; i ++ )
    one.IncreaseOne( line.charAt( i ) );


    System.out.println(" input another string");
    line = br.readLine();
    ;
    for( int i = 0, n = line.length(); i < n; i ++ )
    one.DecreaseOne( line.charAt( i ) );

    boolean brslt = one.IsanAngaram( );
    System.out.println(" Angnam?");
    if( brslt ) System.out.println("Yes");
    else System.out.println("no"); */
}


//public BucketSingleton()
//{
//
//}

// reset
public void Reset( )
{
	// get all value
  int len = 'Z' - 'A' + 1 + 'z' - 'a' + 1;
  // do we need check 'new'?
  mxIndicators = new int[ len ];
}

public void IncreaseOne( char one )
{
	if( one >= 'a' && one <= 'z' )
	 mxIndicators[ one - 'a' ] ++;
	else if( one >= 'A'&& one<= 'Z' )
     mxIndicators[ one - 'A' ] ++;
}
public void DecreaseOne( char one )
{
	if( one >= 'a' && one <= 'z' )
		 mxIndicators[ one - 'a' ] --;
	else if( one >= 'A'&& one<= 'Z' )
	     mxIndicators[ one - 'A' ] --;
}

public boolean IsanAngaram()
{
  for( int i= 0; i < mxIndicators.length; i ++ )
  {
	 if( mxIndicators[ i ] != 0 ) return false;
  }
  return true;
}
// A fixed array for fixed buffer (from a to z. )
// ArrayList is not used in here.
private int[ ] mxIndicators;
}

