#include "Common.h"

// Returns the length of a string in a given message
int Extension::CharCount(TCHAR * Message)
{

	unsigned int charCount = 0;

	for (unsigned int x = 0; x < _tcslen(Message); ++x)
	{
		if(_totlower(Message[x] != _T('\r')))
		{
			++charCount;
		}
	}
	return charCount;
}

// Returns the number of english vowels in a string (a,e,i,o,u) in both cases, in a given message
int Extension::VowelCount(TCHAR * Message)
{
	unsigned int vowel = 0, length = _tcslen(Message);

	for (unsigned int x = 0; x < length; ++x)
	{
		if (
			_totlower(Message[x]) == _T('a') || 
			_totlower(Message[x]) == _T('e') ||
			_totlower(Message[x]) == _T('i') || 
			_totlower(Message[x]) == _T('o') ||
			_totlower(Message[x]) == _T('u'))
		{
			++vowel;
		}
	}
	return vowel;
}

// Returns the number of english consonants in a string (b,c,d,f,g,h,j,k,l,m,n,p,q,r,s,t,v,w,x,y,z) in both cases, in a given message
int Extension::ConsonantCount(TCHAR * Message)
{
	unsigned int consonant = 0, length = _tcslen(Message);

	for (unsigned int x = 0; x < length; ++x)
	{
		if(Message[x] >= 0)
		{
			if(_istalpha(Message[x]))
			{
				if (
					_totlower(Message[x]) != _T('a') && 
					_totlower(Message[x]) != _T('e') &&
					_totlower(Message[x]) != _T('i') && 
					_totlower(Message[x]) != _T('o') &&
					_totlower(Message[x]) != _T('u'))
				{
					++consonant;
				}
			}
		}
	}
	return consonant;

}

// Returns the number of english letters in a string (a-z)(A-Z), in a given message
int Extension::LetterCount(TCHAR * Message)
{
	unsigned int length = _tcslen(Message), letter = 0;
	
	for (unsigned int x = 0; x < length; ++x)
		{
			if(Message[x] >= 0)
			{
				if(_istalpha(Message[x]))
				{
					letter++;
				}
			}
		}

	return letter;
}

// Returns the number of base 10 numbers (0-9), in a given message
int Extension::NumberCount(TCHAR * Message)
{
	unsigned int length = _tcslen(Message), number = 0;

	for(unsigned int x = 0 ; x < length ; ++x)
	{
		if(Message[x] >= 0)
		{
			if(_istdigit(Message[x]))
			{
				if(!_istalpha(Message[x]))
				{
					++number;
				}
			}
		}
	}
	return number;
}

// Returns the number of a specified character in a given message
int Extension::FindCount(TCHAR * Message, TCHAR * Letter)
{
	unsigned int length = _tcslen(Message), length2 = _tcslen(Letter), charcount = 0;

	for(unsigned int x = 0; x < length; ++x)
	{
		if(length2 > 0)
		{
			if(Message[x] == Letter[0])
				{
					++charcount;
				}
		}

		else
		{
			return 0;
		}
		
	}

	return charcount;
}

// Returns the number of uppercase letters in a message, based on the standard english alphabet
int Extension::UpperCount(TCHAR * Message)
{

	unsigned int length = _tcslen(Message), upper = 0;

	for (unsigned int x = 0; x < length; ++x)
	{
		if(Message[x] >= 0)
		{
			if(_istalpha(Message[x]))
			{
				if(_istupper(Message[x]))
				{
					upper++;
				}
			}
		}
	}
	return upper;
}

// Returns the number of lowercase letters in a message, based on the standard english alphabet
int Extension::LowerCount(TCHAR * Message)
{

	unsigned int length = _tcslen(Message), lower = 0;

		for (unsigned int x = 0; x < length; ++x)
		{
			if(Message[x] >= 0)
			{
				if(_istalpha(Message[x]))
				{
					if(_istlower(Message[x]))
					{
						lower++;
					}
				}
				
			}
		}
	return lower;
}

// Returns the number of whitespace characters in a message (newlines,tabs,spaces,enter key presses, etc)
int Extension::WhiteCount(TCHAR * Message)
{

	unsigned int length = _tcslen(Message), blank = 0;

	for (unsigned int x = 0; x < length; ++x)
	{

		if(Message[x] >= 0)
		{
			if(_istspace(Message[x]))
			{
				if(Message[x] != '\r')
				{
					++blank;
				}
			}
		}
	}

	return blank;
}

// Returns the number of unicode characters in a message 
// ** Note ** Returned numbers may be inaccurated
int Extension::UnicodeCount(TCHAR * Message)
{
	unsigned int length = _tcslen(Message), unicode = 0;

	for(unsigned int x = 0; x < length; ++x)
	{
		if(Message[x] < 0)
		{
			++unicode;
		}
	}
	
	return unicode;
}

// Returns the number of punctuation characters in a message
int Extension::PunctuationCount(TCHAR * Message)
{
	unsigned int length = _tcslen(Message), punctuation = 0;

	for(unsigned int x = 0; x < length; ++x)
	{
		if(Message[x] > 0)
		{
			if(_istpunct(Message[x]))
			{
				++punctuation;
			}
		}
	}
	return punctuation;
}

// Returns the ASCII id of the first character in a message
int Extension::ReturnCharValue(TCHAR * Message)
{
	unsigned int length =_tcslen(Message), value = 0;

	return Message[0];
}

// Returns the number of invalid file characters in a message (characters that cannot be in a filename
int Extension::InvalidFileCharacters(TCHAR * Message)
{
	unsigned int length = _tcslen(Message), invalid = 0;

	for(unsigned int x = 0; x < length; ++x)
	{
		if( Message[x] == '/' || Message[x] == '\\' || Message[x] == '?' || Message[x] == '*' || Message[x] == '>' || Message[x] == '<' || 
			Message[x] == '"' || Message[x] == ':' || Message[x] == '|' )
		{
			++invalid;
		}
	}

	return invalid;

}

// Removes leading whitespaces from a message
TCHAR * Extension::RemoveLeadingWhiteSpaces(TCHAR * Message)
{
	unsigned int length = _tcslen(Message) + 1;

	TCHAR * New = NULL;
	   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		// Space characters skip this portion
		if(!_istspace(Message[index]))
		{
			New = (TCHAR *) Runtime.Allocate(1 + length - index);

			for(; index < length; index++, internal_index++)
			{
				New[internal_index] = Message[index];
			}

				New[_tcslen(New)] = '\0';
				return New;
		}

		index++;
	}

	return Message;
}

// Removes trailing whitespaces from a message
TCHAR * Extension::RemoveTrailingWhiteSpaces(TCHAR * Message)
{
	return Runtime.CopyString(ReverseString(RemoveLeadingWhiteSpaces(ReverseString(Message))));
}

// Removes leading and trailing whitespaces from a message
TCHAR * Extension::RemoveLeadingAndTrailingWhiteSpaces(TCHAR * Message)
{

	return Runtime.CopyString(RemoveTrailingWhiteSpaces(RemoveLeadingWhiteSpaces(Message)));

}

// Removes all whitespaces from a message
TCHAR * Extension::RemoveAllWhiteSpaces(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(_istspace(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	New[internal_index] = '\0';

	return Runtime.CopyString(New);
}

// Removes leading punctuation marks in a message
TCHAR * Extension::RemoveLeadingPunctuation(TCHAR * Message)
{
	unsigned int length = _tcslen(Message) + 1;

	TCHAR * New = NULL;
	   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		// Punctuation characters skip this portion
		if(!_istpunct(Message[index]))
		{
			New = (TCHAR *) Runtime.Allocate(1 + length - index);

			for(; index < length; index++, internal_index++)
			{
				New[internal_index] = Message[index];
			}

				New[_tcslen(New)] = '\0';
				return Runtime.CopyString(New);
		}

		index++;
	}

	return Runtime.CopyString(Message);
}

// Removes trailing punctuaion marks in a message
TCHAR * Extension::RemoveTrailingPunctuation(TCHAR * Message)
{
	return Runtime.CopyString(ReverseString(RemoveLeadingPunctuation(ReverseString(Message))));
}

// Removes leading and trailing punctuation marks in a message 
TCHAR * Extension::RemoveLeadingAndTrailingPunctuation(TCHAR * Message)
{
	return Runtime.CopyString(RemoveTrailingPunctuation(RemoveLeadingPunctuation(Message)));
}

// Removes all punctuation marks in a message
TCHAR * Extension::RemoveAllPunctuation(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(_istpunct(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	New[internal_index] = '\0';
	
	return Runtime.CopyString(New);
}

// Removes leading numbers from a message (0-9)
TCHAR * Extension::RemoveLeadingNumbers(TCHAR * Message)
{	unsigned int length = _tcslen(Message) + 1;

	TCHAR * New = NULL;
	   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		// Number characters skip this portion
		if(!_istdigit(Message[index]))
		{
			New = (TCHAR *) Runtime.Allocate(1 + length - index);

			for(; index < length; index++, internal_index++)
			{
				New[internal_index] = Message[index];
			}

				New[_tcslen(New)] = '\0';
				return Runtime.CopyString(New);
		}

		index++;
	}

	return Runtime.CopyString(Message);
}

// Removes trailing numbers from a message (0-9)
TCHAR * Extension::RemoveTrailingNumbers(TCHAR * Message)
{
	return Runtime.CopyString(ReverseString(RemoveLeadingNumbers(ReverseString(Message))));
}

// Removes leading and trailing numbers from a message (0-9)
TCHAR * Extension::RemoveLeadingAndTrailingNumbers(TCHAR * Message)
{
	return Runtime.CopyString(RemoveTrailingNumbers(RemoveLeadingNumbers(Message)));
}

// Removes all numbers from a message (0-9)
TCHAR * Extension::RemoveAllNumbers(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(_istdigit(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	New[internal_index] = '\0';
	
	return Runtime.CopyString(New);
}

// Removes leading letters from a message (vowels and consonants) (a-z) (A-Z)
TCHAR * Extension::RemoveLeadingLetters(TCHAR * Message)
{	
	unsigned int length = _tcslen(Message) + 1;

	TCHAR * New = NULL;
	   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		// Letter characters skip this portion
		if(!_istalpha(Message[index]))
		{
			New = (TCHAR *) Runtime.Allocate(1 + length - index);

			for(; index < length; index++, internal_index++)
			{
				New[internal_index] = Message[index];
			}

				New[_tcslen(New)] = '\0';
				return Runtime.CopyString(New);
		}

		index++;
	}

	return Runtime.CopyString(Message);
}

// Removes trailing letters from a message (vowels and consonants) (a-z) (A-Z)
TCHAR * Extension::RemoveTrailingLetters(TCHAR * Message)
{
	return Runtime.CopyString(ReverseString(RemoveLeadingLetters(ReverseString(Message))));
}

// Removes leading and trailing letters from a message (vowels and consonants) (a-z) (A-Z)
TCHAR * Extension::RemoveLeadingAndTrailingLetters(TCHAR * Message)
{
	return Runtime.CopyString(RemoveTrailingLetters(RemoveLeadingLetters(Message)));
}

// Removes all letters from a message (vowels and consonants) (a-z) (A-Z)
TCHAR * Extension::RemoveAllLetters(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(_istalpha(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}

		index++;
	}
	
	New[internal_index] = '\0';

	return Runtime.CopyString(New);
}

// Removes leading consonants from a message 
TCHAR * Extension::RemoveLeadingConsonants(TCHAR * Message)
{
	unsigned int length = _tcslen(Message) + 1;

	TCHAR * New = NULL;
	   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		// Consonants characters skip this portion
		if(_istalpha(Message[index]) && !(_totlower(Message[index]) != 'a' && _totlower(Message[index]) != 'e' && _totlower(Message[index]) != 'i' && _totlower(Message[index]) != 'o' && _totlower(Message[index]) != 'u'))
		{
			New = (TCHAR *) Runtime.Allocate(1 + length - index);

			for(; index < length; index++, internal_index++)
			{
				New[internal_index] = Message[index];
			}

				New[_tcslen(New)] = '\0';
				return Runtime.CopyString(New);
		}

		index++;
	}

	return Runtime.CopyString(Message);
}

// Removes trailing consonants from a message
TCHAR * Extension::RemoveTrailingConsonants(TCHAR * Message)
{
	return Runtime.CopyString(ReverseString(RemoveLeadingConsonants(ReverseString(Message))));
}

// Removes leading and trailing consonants from a message
TCHAR * Extension::RemoveLeadingAndTrailingConsonants(TCHAR * Message)
{
	return Runtime.CopyString(RemoveTrailingConsonants(RemoveLeadingConsonants(Message)));
}

// Removes all consonants from a message
TCHAR * Extension::RemoveAllConsonants(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(_istalpha(Message[index]) && (_totlower(Message[index]) != 'a' && _totlower(Message[index]) !=	'e' && _totlower(Message[index]) != 'i' && _totlower(Message[index]) != 'o' && _totlower(Message[index]) != 'u')))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	New[internal_index] = '\0';

	return Runtime.CopyString(New);
}

// Removes leading vowels from a message
TCHAR * Extension::RemoveLeadingVowels(TCHAR * Message)
{
	unsigned int length = _tcslen(Message) + 1;

	TCHAR * New = NULL;
	   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		// Vowel characters skip this portion
		if(_istalpha(Message[index]) && !(_totlower(Message[index]) == 'a' || _totlower(Message[index]) == 'e' || _totlower(Message[index]) == 'i' || _totlower(Message[index]) == 'o' || _totlower(Message[index]) == 'u'))
		{
			New = (TCHAR *) Runtime.Allocate(1 + length - index);

			for(; index < length; index++, internal_index++)
			{
				New[internal_index] = Message[index];
			}

				New[_tcslen(New)] = '\0';
				return Runtime.CopyString(New);
		}

		index++;
	}

	return Runtime.CopyString(Message);
}

// Removes trailing vowels from a message
TCHAR * Extension::RemoveTrailingVowels(TCHAR * Message)
{
	return Runtime.CopyString(ReverseString(RemoveLeadingVowels(ReverseString(Message))));
}

// Removes leading and trailing vowels from a message
TCHAR * Extension::RemoveLeadingAndTrailingVowels(TCHAR * Message)
{
	return Runtime.CopyString(RemoveTrailingVowels(RemoveLeadingVowels(Message)));
}

// Removes all vowels from a message
TCHAR * Extension::RemoveAllVowels(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(_istalpha(Message[index]) && (tolower(Message[index]) == 'a' || tolower(Message[index]) ==	'e' || tolower(Message[index]) == 'i' || tolower(Message[index]) == 'o' || tolower(Message[index]) == 'u')))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}

		index++;
	}

	New[internal_index] = '\0';
	
	return Runtime.CopyString(New);
}

// Removes leading uppercase letters from a message
TCHAR * Extension::RemoveLeadingUppercaseLetters(TCHAR * Message)
{
	unsigned int length = _tcslen(Message) + 1;

	TCHAR * New = NULL;
	   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		// Uppercase characters skip this portion
		if(!_istupper(Message[index]))
		{
			New = (TCHAR *) Runtime.Allocate(1 + length - index);

			for(; index < length; index++, internal_index++)
			{
				New[internal_index] = Message[index];
			}

				New[_tcslen(New)] = '\0';
				return Runtime.CopyString(New);
		}

		index++;
	}

	return Runtime.CopyString(Message);
}

// Removes trailing uppercase letters from a message
TCHAR * Extension::RemoveTrailingUppercaseLetters(TCHAR * Message)
{
	return Runtime.CopyString(ReverseString(RemoveLeadingUppercaseLetters(ReverseString(Message))));
}

// Removes leading and trailing uppercase letters from a message
TCHAR * Extension::RemoveLeadingAndTrailingUppercaseLetters(TCHAR * Message)
{
	return Runtime.CopyString(RemoveTrailingUppercaseLetters(RemoveLeadingUppercaseLetters(Message)));
}

// Removes all uppercase letters from a message
TCHAR * Extension::RemoveAllUppercaseLetters(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(_istupper(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}

		index++;
	}

	New[internal_index] = '\0';
	
	return Runtime.CopyString(New);
}

// Removes leading lowercase letters from a message
TCHAR * Extension::RemoveLeadingLowercaseLetters(TCHAR * Message)
{
		unsigned int length = _tcslen(Message) + 1;

	TCHAR * New = NULL;
	   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		// Lowercase characters skip this portion
		if(!_istlower(Message[index]))
		{
			New = (TCHAR *) Runtime.Allocate(1 + length - index);

			for(; index < length; index++, internal_index++)
			{
				New[internal_index] = Message[index];
			}

				New[_tcslen(New)] = '\0';
				return Runtime.CopyString(New);
		}

		index++;
	}

	return Runtime.CopyString(Message);
}

// Removes trailing lowercase letters from a message
TCHAR * Extension::RemoveTrailingLowercaseLetters(TCHAR * Message)
{
	return Runtime.CopyString(ReverseString(RemoveLeadingLowercaseLetters(ReverseString(Message))));
}

// Removes leading and trailing lowercase letters from a message
TCHAR * Extension::RemoveLeadingAndTrailingLowercaseLetters(TCHAR * Message)
{
	return RemoveTrailingLowercaseLetters(RemoveLeadingLowercaseLetters(Message));
}

// Removes all lowercase letters from a message
TCHAR * Extension::RemoveAllLowercaseLetters(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(_istlower(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	New[internal_index] = '\0';
	
	return Runtime.CopyString(New);
}

// Repeats a phrase x amount of times before a specified message
TCHAR * Extension::PadLeftPhrase(TCHAR * Message, TCHAR * Phrase, int repeats)
{
	repeats = max(repeats, 0);
	
	string PhraseMessage = "";

	for(int index = 0; index < repeats; index++)
	{
		PhraseMessage.append((char *) Phrase);
	}

	string FinalMessage = "";

	// Adds the repeating message first
	FinalMessage.append(PhraseMessage);

	// Adds the 'fixed' message last
	FinalMessage.append((char *) Message);


	return Runtime.CopyString((TCHAR *)FinalMessage.c_str());
}

// Repeats a phrase x amount of times after a specified message
TCHAR * Extension::PadRightPhrase(TCHAR * Message, TCHAR * Phrase, int repeats)
{
	repeats = max(repeats, 0);
	
	string PhraseMessage = "";

	for(int index = 0; index < repeats; index++)
	{
		PhraseMessage.append((char *)Phrase);
	}

	string FinalMessage = "";

	// Adds the 'fixed' message first
	FinalMessage.append((char *)Message);

	// Adds the repeating message last
	FinalMessage.append(PhraseMessage);

	return Runtime.CopyString((TCHAR *)FinalMessage.c_str());
}

// Reverse a given string
TCHAR * Extension::ReverseString(TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * MessageArray = (TCHAR *)Runtime.Allocate(length);

	for(int index = 0; index < length; index++)
	{
		MessageArray[length - index - 1] = Message[index];
	}

	MessageArray[length] = '\0';

	return Runtime.CopyString(MessageArray);

}