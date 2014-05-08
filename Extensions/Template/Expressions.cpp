#include "Common.h"

// Returns the length of a string in a given message
int Extension::CharCount(const TCHAR * Message)
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
int Extension::VowelCount(const TCHAR * Message)
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
int Extension::ConsonantCount(const TCHAR * Message)
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
int Extension::LetterCount(const TCHAR * Message)
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
int Extension::NumberCount(const TCHAR * Message)
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
int Extension::FindCount(const TCHAR * Message, const TCHAR * Letter)
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
int Extension::UpperCount(const TCHAR * Message)
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
int Extension::LowerCount(const TCHAR * Message)
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
int Extension::WhiteCount(const TCHAR * Message)
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
int Extension::UnicodeCount(const TCHAR * Message)
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
int Extension::PunctuationCount(const TCHAR * Message)
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
int Extension::ReturnCharValue(const TCHAR * Message)
{
	unsigned int length =_tcslen(Message), value = 0;

	return Message[0];
}

// Returns the number of invalid file characters in a message (characters that cannot be in a filename
int Extension::InvalidFileCharacters(const TCHAR * Message)
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
TCHAR * Extension::RemoveLeadingWhiteSpaces(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(isspace(Message[index]))
	{
		index++;
	}

	for(; index < length; index++)
	{
		New[internal_index] = Message[index];
		internal_index++;
	}

	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(internal_index);
	_tcsncpy(RealNew, New, internal_index);
	

	return RealNew;
}

// Removes trailing whitespaces from a message
TCHAR * Extension::RemoveTrailingWhiteSpaces(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);
	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   

	unsigned int index = 0;
	unsigned int internal_index = 0;


	while(isspace(Message[(length-index)-1]))
	{
		index++;
	}



	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(length-index);
	_tcsncpy(RealNew, Message, length-index);
	RealNew[length-index] = '\0';

	return RealNew;
}

// Removes leading and trailing whitespaces from a message
TCHAR * Extension::RemoveLeadingAndTrailingWhiteSpaces(const TCHAR * Message)
{

	return RemoveLeadingWhiteSpaces(RemoveTrailingWhiteSpaces(Message));

}

// Removes all whitespaces from a message
TCHAR * Extension::RemoveAllWhiteSpaces(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(isspace(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	
	
	New[internal_index] = '\0';
	

	return New;
}

// Removes leading punctuation marks in a message
TCHAR * Extension::RemoveLeadingPunctuation(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(ispunct(Message[index]))
	{
		index++;
	}

	for(; index < length; index++)
	{
		New[internal_index] = Message[index];
		internal_index++;
	}

	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(internal_index);
	_tcsncpy(RealNew, New, internal_index);
	

	return RealNew;
}

// Removes trailing punctuaion marks in a message
TCHAR * Extension::RemoveTrailingPunctuation(const TCHAR * Message)
{
		unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   

	unsigned int index = 0;
	unsigned int internal_index = 0;


	while(ispunct(Message[(length-index)-1]))
	{
		index++;
	}



	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(length-index);
	_tcsncpy(RealNew, Message, length-index);
	RealNew[length-index] = '\0';

	return RealNew;
}

// Removes leading and trailing punctuation marks in a message 
TCHAR * Extension::RemoveLeadingAndTrailingPunctuation(const TCHAR * Message)
{
	return RemoveLeadingPunctuation(RemoveTrailingPunctuation(Message));
}

// Removes all punctuation marks in a message
TCHAR * Extension::RemoveAllPunctuation(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(ispunct(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	New[internal_index] = '\0';
	

	return New;
}

// Removes leading numbers from a message (0-9)
TCHAR * Extension::RemoveLeadingNumbers(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(isdigit(Message[index]))
	{
		index++;
	}

	for(; index < length; index++)
	{
		New[internal_index] = Message[index];
		internal_index++;
	}

	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(internal_index);
	_tcsncpy(RealNew, New, internal_index);
	

	return RealNew;
}

// Removes trailing numbers from a message (0-9)
TCHAR * Extension::RemoveTrailingNumbers(const TCHAR * Message)
{
		unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   

	unsigned int index = 0;
	unsigned int internal_index = 0;


	while(isdigit(Message[(length-index)-1]))
	{
		index++;
	}



	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(length-index);
	_tcsncpy(RealNew, Message, length-index);
	RealNew[length-index] = '\0';

	return RealNew;
}

// Removes leading and trailing numbers from a message (0-9)
TCHAR * Extension::RemoveLeadingAndTrailingNumbers(const TCHAR * Message)
{
	return RemoveLeadingNumbers(RemoveTrailingNumbers(Message));
}

// Removes all numbers from a message (0-9)
TCHAR * Extension::RemoveAllNumbers(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(isdigit(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	New[internal_index] = '\0';
	

	return New;
}

// Removes leading letters from a message (vowels and consonants) (a-z) (A-Z)
TCHAR * Extension::RemoveLeadingLetters(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(isalpha(Message[index]))
	{
		index++;
	}

	for(; index < length; index++)
	{
		New[internal_index] = Message[index];
		internal_index++;
	}

	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(internal_index);
	_tcsncpy(RealNew, New, internal_index);
	

	return RealNew;
}

// Removes trailing letters from a message (vowels and consonants) (a-z) (A-Z)
TCHAR * Extension::RemoveTrailingLetters(const TCHAR * Message)
{
		unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   

	unsigned int index = 0;
	unsigned int internal_index = 0;


	while(isalpha(Message[(length-index)-1]))
	{
		index++;
	}



	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(length-index);
	_tcsncpy(RealNew, Message, length-index);
	RealNew[length-index] = '\0';

	return RealNew;
}

// Removes leading and trailing letters from a message (vowels and consonants) (a-z) (A-Z)
TCHAR * Extension::RemoveLeadingAndTrailingLetters(const TCHAR * Message)
{
	return RemoveLeadingLetters(RemoveTrailingLetters(Message));
}

// Removes all letters from a message (vowels and consonants) (a-z) (A-Z)
TCHAR * Extension::RemoveAllLetters(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(isalpha(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	
	New[internal_index] = '\0';
	

	return New;
}

// Removes leading consonants from a message 
TCHAR * Extension::RemoveLeadingConsonants(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(isalpha(Message[index]) && (tolower(Message[index]) != 'a' && tolower(Message[index]) !=
		'e' && tolower(Message[index]) != 'i' && tolower(Message[index]) != 'o' && tolower(Message[index]) != 'u'))
	{
		index++;
	}

	for(; index < length; index++)
	{
		New[internal_index] = Message[index];
		internal_index++;
	}

	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(internal_index);
	_tcsncpy(RealNew, New, internal_index);
	

	return RealNew;
}

// Removes trailing consonants from a message
TCHAR * Extension::RemoveTrailingConsonants(const TCHAR * Message)
{
		unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   

	unsigned int index = 0;
	unsigned int internal_index = 0;


	while(isalpha(Message[(length - index)-1]) && (tolower(Message[(length - index)-1]) != 'a' &&
		tolower(Message[(length - index)-1]) != 'e' && tolower(Message[(length - index)-1]) != 'i' &&
		tolower(Message[(length - index)-1]) != 'o' && tolower(Message[(length - index)-1]) != 'u'))
	{
		index++;
	}



	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(length-index);
	_tcsncpy(RealNew, Message, length-index);
	RealNew[length-index] = '\0';

	return RealNew;
}

// Removes leading and trailing consonants from a message
TCHAR * Extension::RemoveLeadingAndTrailingConsonants(const TCHAR * Message)
{
	return RemoveLeadingConsonants(RemoveTrailingConsonants(Message));
}

// Removes all consonants from a message
TCHAR * Extension::RemoveAllConsonants(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(isalpha(Message[index]) && (tolower(Message[index]) != 'a' && tolower(Message[index]) !=
		'e' && tolower(Message[index]) != 'i' && tolower(Message[index]) != 'o' && tolower(Message[index]) != 'u')))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}


	New[internal_index] = '\0';
	

	return New;
}

// Removes leading vowels from a message
TCHAR * Extension::RemoveLeadingVowels(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(isalpha(Message[index]) && (tolower(Message[index]) == 'a' || tolower(Message[index]) ==
		'e' || tolower(Message[index]) == 'i' || tolower(Message[index]) == 'o' || tolower(Message[index]) == 'u'))
	{
		index++;
	}

	for(; index < length; index++)
	{
		New[internal_index] = Message[index];
		internal_index++;
	}

	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(internal_index);
	_tcsncpy(RealNew, New, internal_index);
	

	return RealNew;
}

// Removes trailing vowels from a message
TCHAR * Extension::RemoveTrailingVowels(const TCHAR * Message)
{
		unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   

	unsigned int index = 0;
	unsigned int internal_index = 0;


	while(isalpha(Message[(length-index)-1]) && (tolower(Message[(length-index)-1]) == 'a' || tolower(Message[(length-index)-1]) ==
		'e' || tolower(Message[(length-index)-1]) == 'i' || tolower(Message[(length-index)-1]) == 'o' || tolower(Message[(length-index)-1]) == 'u'))
	{
		index++;
	}



	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(length-index);
	_tcsncpy(RealNew, Message, length-index);
	RealNew[length-index] = '\0';

	return RealNew;
}

// Removes leading and trailing vowels from a message
TCHAR * Extension::RemoveLeadingAndTrailingVowels(const TCHAR * Message)
{
	return RemoveLeadingVowels(RemoveTrailingVowels(Message));
}

// Removes all vowels from a message
TCHAR * Extension::RemoveAllVowels(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(isalpha(Message[index]) && (tolower(Message[index]) == 'a' || tolower(Message[index]) ==
		'e' || tolower(Message[index]) == 'i' || tolower(Message[index]) == 'o' || tolower(Message[index]) == 'u')))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}


	New[internal_index] = '\0';
	

	return New;
}

// Removes leading uppercase letters from a message
TCHAR * Extension::RemoveLeadingUppercaseLetters(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(isupper(Message[index]))
	{
		index++;
	}

	for(; index < length; index++)
	{
		New[internal_index] = Message[index];
		internal_index++;
	}

	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(internal_index);
	_tcsncpy(RealNew, New, internal_index);
	

	return RealNew;
}

// Removes trailing uppercase letters from a message
TCHAR * Extension::RemoveTrailingUppercaseLetters(const TCHAR * Message)
{
		unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   

	unsigned int index = 0;
	unsigned int internal_index = 0;


	while(isupper(Message[(length-index)-1]))
	{
		index++;
	}


	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(length-index);
	_tcsncpy(RealNew, Message, length-index);
	RealNew[length-index] = '\0';

	return RealNew;
}

// Removes leading and trailing uppercase letters from a message
TCHAR * Extension::RemoveLeadingAndTrailingUppercaseLetters(const TCHAR * Message)
{
	return RemoveLeadingUppercaseLetters(RemoveTrailingUppercaseLetters(Message));
}

// Removes all uppercase letters from a message
TCHAR * Extension::RemoveAllUppercaseLetters(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(isupper(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}


	New[internal_index] = '\0';
	

	return New;
}

// Removes leading lowercase letters from a message
TCHAR * Extension::RemoveLeadingLowercaseLetters(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(islower(Message[index]))
	{
		index++;
	}

	for(; index < length; index++)
	{
		New[internal_index] = Message[index];
		internal_index++;
	}

	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(internal_index);
	_tcsncpy(RealNew, New, internal_index);
	

	return RealNew;
}

// Removes trailing lowercase letters from a message
TCHAR * Extension::RemoveTrailingLowercaseLetters(const TCHAR * Message)
{
		unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   

	unsigned int index = 0;
	unsigned int internal_index = 0;


	while(islower(Message[(length-index)-1]))
	{
		index++;
	}


	TCHAR * RealNew = (TCHAR *) Runtime.Allocate(length-index);
	_tcsncpy(RealNew, Message, length-index);
	RealNew[length-index] = '\0';

	return RealNew;
}

// Removes leading and trailing lowercase letters from a message
TCHAR * Extension::RemoveLeadingAndTrailingLowercaseLetters(const TCHAR * Message)
{
	return RemoveLeadingLowercaseLetters(RemoveTrailingLowercaseLetters(Message));
}

// Removes all lowercase letters from a message
TCHAR * Extension::RemoveAllLowercaseLetters(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	TCHAR * New = (TCHAR *) Runtime.Allocate(length);
   
	unsigned int index = 0;
	unsigned int internal_index = 0;

	while(index < length)
	{
		if(!(islower(Message[index])))
		{
			New[internal_index] = Message[index];
			internal_index++;
		}
		index++;
	}

	
	
	New[internal_index] = '\0';
	

	return New;
}

// Repeats a phrase x amount of times before a specified message
TCHAR * Extension::PadLeftPhrase(const TCHAR * Message, const TCHAR * Phrase, int repeats)
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
TCHAR * Extension::PadRightPhrase(const TCHAR * Message, const TCHAR * Phrase, int repeats)
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
TCHAR * Extension::ReverseString(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	string Message_String = "";

	Message_String.append( (char *) Message);
	Message_String = string( Message_String.rbegin(), Message_String.rend());

	return Runtime.CopyString( (TCHAR *)Message_String.c_str());

}

