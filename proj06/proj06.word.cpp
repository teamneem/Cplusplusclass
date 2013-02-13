/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #6

****************************************************************************/

using namespace std;
#include <iostream>
#include "/user/cse232/Projects/project06.word.h"


Word::Word( const char check[] )
{
	//Determine length
	Length = 0;
	while (check[Length]!='\0' && Length <= Word::MAX)
	{
		Length++;
	}
	
	//check if too long
	if (Length > Word::MAX)
	{
		Length = Word::MAX;
		cerr << "Word is too long, truncating" << endl;
	}
	
	//if Length equal to zero, we can stop here
	if (Length == 0)
	{
		return;
	}
	
	//Does not begin with alphabetic character
	if ((check[0]  < 'a' || check[0] > 'z') && (check[0]  < 'A' || check[0] > 'Z'))
	{
		cerr << "Word does not begin with alphabetic character, resetting word" << endl;
		Length = 0;
		return;
	}

	
	//Has invalid characters
	for (int i = 0; i < Length; i++)
	{
		Mem[i] = check[i];
		if ((check[i]  < 'a' || check[i] > 'z') &&
			(check[i]  < 'A' || check[i] > 'Z') && 
			(check[i] != '\'') &&
			(check[i] != '-'))
		{
			cerr << "Word has an invalid character, stopping word" << endl;
			Length = i;
			return;
		}
	}	
	
	//copy characters in word into memory to make word
	for (int i = 0; i < Length; i++)
	{
		Mem[i] = check[i];
	}
}




/*-----------------------------------------------------------------------------
   Name:  copy operator for class "Word" 

   Purpose:  Copy the contents of one word into another.
   Receive:  The word which is to be copied
   Return:   The word on the righthand side
-----------------------------------------------------------------------------*/

Word& Word::operator=( const Word& copiedWord)
{
	Length = copiedWord.Length;
	
	for (int i = 0; i < Length; i++)
	{
		Mem[i] = copiedWord.Mem[i];
	}
	return *this;
}

/*-----------------------------------------------------------------------------
   Name:  append operator for class "Word" 

   Purpose:  Append one word to another.
   Receive:  The word which is to be appended
   Return:   The appended final word
-----------------------------------------------------------------------------*/

Word& Word::operator+=( const Word& appendWord)
{
	if (Length + appendWord.Length  > MAX)
	{
		cerr << "Word is too long after appending, truncating" << endl;
	}
	
	for (int i = 0; i < appendWord.Length; i++)
	{
		Mem[Length] = appendWord.Mem[i];
		Length ++;
		if (Length >= MAX) break;
	}
}

/*-----------------------------------------------------------------------------
   Name:  operator+

   Purpose:  Add a word and another word.
   Receive:  The word and word to be added
   Return:   The word which is the concatenation of two parameters
-----------------------------------------------------------------------------*/

Word operator+( const Word& word1, const Word& word2)
{
	Word newWord(word1);
	newWord += word2;
	return newWord;
}

/*-----------------------------------------------------------------------------
   Name:  operator==

   Purpose:  Compare two words for equality.
   Receive:  The two words to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/

bool operator==( const Word& word1, const Word& word2)
{
	if (word1.length() != word2.length()) return false;

	for (int i = 0; i < word1.length(); i++)
	{
		if (word1[i] != word2[i]) return false;
	}
	return true;
}

/*-----------------------------------------------------------------------------
   Name:  operator!=

   Purpose:  Compare two words for inequality.
   Receive:  The two words to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/

bool operator!=( const Word& word1, const Word& word2)
{
	return !(word1 == word2);
}

/*-----------------------------------------------------------------------------
   Name:  operator<

   Purpose:  Compare two words to see if the second is bigger
   Receive:  The two words to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/

bool operator<( const Word& word1, const Word& word2)
{
	int testLength = word1.length();
	if (testLength > word2.length()) testLength = word2.length();
	for (int i = 0; i < testLength; i++)
	{
		if (word1[i] < word2[i]) return true;
		if (word1[i] > word2[i]) return false;
	}
	if (word1.length() < word2.length()) return true;
	return false;
}


/*-----------------------------------------------------------------------------
   Name:  operator<=

   Purpose:  Compare two words to see if the second is bigger or equal
   			 to the first word
   Receive:  The two words to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/
bool operator<=( const Word& word1, const Word& word2)
{
	return ((word1 == word2)||(word1 < word2));
}

/*-----------------------------------------------------------------------------
   Name:  operator>

   Purpose:  Compare two words to see if the first word is bigger
   Receive:  The two words to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/

bool operator>( const Word& word1, const Word& word2 )
{
	return !(word1 <= word2);
}

/*-----------------------------------------------------------------------------
   Name:  operator>=

   Purpose:  Compare two words to see if the first is bigger or equal
   			 to the second word
   Receive:  The two words to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/
bool operator>=( const Word& word1, const Word& word2 )
{
	return !(word1 < word2);
}

 /*-----------------------------------------------------------------------------
   Name:  operator<<

   Purpose:  Put a Word object into an output stream.
   Receive:  A reference to an output stream
             A constant reference to a Word
   Return:   The output stream
   Output:   A word
-----------------------------------------------------------------------------*/

ostream& operator<<( ostream& Out, const Word& word1)
{
	for (int i = 0; i < word1.length(); i++)
	{
		Out << word1[i];
	}
	return Out;
}


/*-----------------------------------------------------------------------------
   Name:  operator>>

   Purpose:  Extract a word object from an input stream.
   Receive:  A reference to an input stream
             A reference to a word
   Return:   The input stream
   Input:    A word
-----------------------------------------------------------------------------*/


istream& operator>>( istream& In, Word& word1)
{
	char inWord[Word::MAX];
	
	In.width (Word::MAX);        // limit width of input
	In >> inWord;
    Word outWord(inWord);
	word1 = outWord;
	
	return In;
}







