/**
 * File:AnagramSingleton.java
 * Author:fuwenlong@126.com
 * Data: 3 - Jan - 2014
 *
 * Details:
 *  Create Anagram Singleton to check two strings as an anagram or not.
 **/

import java.io.*;


/*
 * Modify from BucketSingleton so that different tasks can return right results at the same time.
 */
public enum AnagramSingleton
{
INSTANCE;

// ToDo: 
// change INSTANCE to three different algorithms.
// Bucket, FastSort, StatInfo;
// private abstract boolean CompareAlg( String one, String two ); 
// then Compare calls CompareAlg.
// or change Compare to 
// public abstract boolean Compare( String one, String two );

public static void main(String[ ] args) throws Exception
{
    // first input
    System.out.println(" input first string");

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String strOne = br.readLine();
    System.out.println(" input another string");
    String strTwo = br.readLine();

    boolean brslt = INSTANCE.Compare( strOne,  strTwo );

    System.out.println(" Angnam?");
    if( brslt ) System.out.println("Yes");
    else System.out.println("no");
}
/*
 * Copmare two strings whether they include the same distribution on
 * letters (non-letters are not considered).
 *
 * @param one A string will be used to compare
 * @param two Another string
 *
 * @return True  Strings one and two have the same distribution on letters.
 *         False String one and two have different distribution on letters.
 */
public boolean Compare( String one, String two )
{
  final int len = 'Z' - 'A' + 1 + 'z' - 'a' + 1;
  int[] Indicators = new int[ len ]; // default as 0
  for( int i =0; i < len; i ++ ) Indicators[ i ] = 0;
  char ctmp;
  for( int i =0, n = one.length(); i < n; i ++ )
  {
	ctmp = one.charAt( i );
	if( ctmp >= 'a' && ctmp <= 'z' )
		Indicators[ ctmp - 'a' ] ++;
	else if( ctmp >= 'A'&& ctmp<= 'Z' )
		Indicators[ ctmp - 'A' ] ++;
  }
  for( int i =0, n = two.length(); i < n; i ++ )
  {
	ctmp = two.charAt( i );
	if( ctmp >= 'a' && ctmp <= 'z' )
		Indicators[ ctmp - 'a' ] --;
	else if( ctmp >= 'A'&& ctmp<= 'Z' )
		Indicators[ ctmp - 'A' ] --;
  }

  for( int i= 0; i < len; i ++ )
  {
    if( Indicators[ i ] != 0 ) return false;
  }
  return true;
}

}

