#include "Common.h"


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
int Extension::ReturnCharValue(const TCHAR * Message)
{
	unsigned int length =_tcslen(Message), value = 0;

	return Message[0];
}
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
TCHAR * Extension::RemoveLeadingAndTrailingWhiteSpaces(const TCHAR * Message)
{

	return RemoveLeadingWhiteSpaces(RemoveTrailingWhiteSpaces(Message));

}
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
TCHAR * Extension::RemoveLeadingAndTrailingPunctuation(const TCHAR * Message)
{
	return RemoveLeadingPunctuation(RemoveTrailingPunctuation(Message));
}
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
TCHAR * Extension::RemoveLeadingAndTrailingNumbers(const TCHAR * Message)
{
	return RemoveLeadingNumbers(RemoveTrailingNumbers(Message));
}
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
TCHAR * Extension::RemoveLeadingAndTrailingLetters(const TCHAR * Message)
{
	return RemoveLeadingLetters(RemoveTrailingLetters(Message));
}
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
TCHAR * Extension::RemoveLeadingAndTrailingConsonants(const TCHAR * Message)
{
	return RemoveLeadingConsonants(RemoveTrailingConsonants(Message));
}
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
TCHAR * Extension::RemoveLeadingAndTrailingVowels(const TCHAR * Message)
{
	return RemoveLeadingVowels(RemoveTrailingVowels(Message));
}
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
TCHAR * Extension::RemoveLeadingAndTrailingUppercaseLetters(const TCHAR * Message)
{
	return RemoveLeadingUppercaseLetters(RemoveTrailingUppercaseLetters(Message));
}
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
TCHAR * Extension::RemoveLeadingAndTrailingLowercaseLetters(const TCHAR * Message)
{
	return RemoveLeadingLowercaseLetters(RemoveTrailingLowercaseLetters(Message));
}
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
TCHAR * Extension::PadLeftPhrase(const TCHAR * Message, const TCHAR * Phrase, int repeats)
{
	repeats = max(repeats, 0);
	
	string PhraseMessage = "";

	for(int index = 0; index < repeats; index++)
	{
		PhraseMessage.append((char *) Phrase);
	}

	string FinalMessage = "";

	FinalMessage.append(PhraseMessage);
	FinalMessage.append((char *) Message);


	return Runtime.CopyString((TCHAR *)FinalMessage.c_str());
}
TCHAR * Extension::PadRightPhrase(const TCHAR * Message, const TCHAR * Phrase, int repeats)
{
	repeats = max(repeats, 0);
	
	string PhraseMessage = "";

	string copy_of_phrase = "";



	for(int index = 0; index < repeats; index++)
	{
		PhraseMessage.append((char *)Phrase);
	}

	string FinalMessage = "";

	FinalMessage.append((char *)Message);
	FinalMessage.append(PhraseMessage);

	return Runtime.CopyString((TCHAR *)FinalMessage.c_str());
}
TCHAR * Extension::ReverseString(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	string Message_String = "";

	Message_String.append( (char *) Message);
	Message_String = string( Message_String.rbegin(), Message_String.rend());

	return Runtime.CopyString( (TCHAR *)Message_String.c_str());

}

