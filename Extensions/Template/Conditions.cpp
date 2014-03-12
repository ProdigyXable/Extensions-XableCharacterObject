
#include "Common.h"


// Returns true if a message contains only numbers (0-9)
bool Extension::NumbersOnly(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if(!(isdigit(Message[index])))
		{
			return false;
		}
	}

	return true;

}

// Returns true if a message contains any numbers (0-9)
bool Extension::AnyNumbers(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if((isdigit(Message[index])))
		{
			return true;
		}
	}

	return false;

}

// Returns true if a message contains only letters (vowels and consonants)
bool Extension::LettersOnly(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if(!(isalpha(Message[index])))
		{
			return false;
		}
	}

	return true;

}

// Returns true if a message contains any letter (vowels and consonants)
bool Extension::AnyLetters(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if((isalpha(Message[index])))
		{
			return true;
		}
	}

	return false;

}

// Returns true if a message contains only vowels (a,e,i,o,u)
bool Extension::VowelsOnly(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if(_totlower(Message[index]) != 'a' && _totlower(Message[index]) != 'e' && _totlower(Message[index]) != 'i' && _totlower(Message[index]) != 'o' && _totlower(Message[index]) != 'u')
		{
			return false;
		}
	}

	return true;

}

// Returns true if a message contains any vowels (a,e,i,o,u)
bool Extension::AnyVowels(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if(_totlower(Message[index]) == 'a' || _totlower(Message[index]) == 'e' || _totlower(Message[index]) == 'i' || _totlower(Message[index]) == 'o' || _totlower(Message[index]) == 'u')
		{
			return true;
		}
	}

	return false;

}

// Returns true if a message contains only consonants
bool Extension::ConsonantsOnly(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if(isalpha(Message[index]))
		{
			if(_totlower(Message[index]) == 'a' || _totlower(Message[index]) == 'e' || _totlower(Message[index]) == 'i' || _totlower(Message[index]) == 'o' || _totlower(Message[index]) == 'u')
			{
				return false;
			}
		}
	}

	return true;

}

// Returns true if a message contains any consonants
bool Extension::AnyConsonants(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if(isalpha(Message[index]))
		{

			if(_totlower(Message[index]) != 'a' && _totlower(Message[index]) != 'e' && _totlower(Message[index]) != 'i' && _totlower(Message[index]) != 'o' && _totlower(Message[index]) != 'u')
			{
				return true;
			}
		}
	}

	return false;

}

// Returns true if a message contains only punctuation marks
bool Extension::PunctuationOnly(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if(!(ispunct(Message[index])))
		{
			return false;			
		}
	}

	return true;
}

// Returns true if a message contains any punctuation mark
bool Extension::AnyPunctuation(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if((ispunct(Message[index])))
		{
			return true;			
		}
	}

	return false;
}

// Returns true if a message contains only whitespace characters
bool Extension::WhiteSpaceOnly(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if(!(isspace(Message[index])))
		{
			return false;			
		}
	}

	return true;

}

// Returns true if a message contains only whitespace characters
bool Extension::AnyWhiteSpace(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned index = 0; index < length; index++)
	{
		if((isspace(Message[index])))
		{
			return true;			
		}
	}

	return false;

}

// Returns true if a message starts wtih a whitespace character
bool Extension::StartsWhiteSpace(const TCHAR * Message)
{
	if(isspace(Message[0]))
	{
		return true;
	}
	return false;

}

// Returns true if a message ends with a whitespace character
bool Extension::EndsWhiteSpace(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	if(isspace(Message[length-1]))
	{
		return true;
	}
	return false;

}

// Returns true if a message contains any invalid file characters
bool Extension::ContainsInvalidFileCharacters(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	for(unsigned int index = 0; index < length; index++)
	{
		if(Message[index] == '\\' || Message[index] == '/' || Message[index] == ':' || Message[index] == '*' || Message[index] == '?' || Message[index] == '"' || Message[index] == '>' || Message[index] == '<' || Message[index] == '|')
		{
			return true;
		}
	}

	return false;
}

// Returns true if a message is in email format (mydomain@email.address)
// One '@' in the message
// One '.' after the @ in the message
bool Extension::EmailFormat(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);
	

	bool at_detected = false;
	bool dot_detected = false;
	bool after_characters = false;

	const TCHAR At_Symbol = '@';
	const TCHAR * At_Symbol_Pointer = &At_Symbol;
	
	for(unsigned int while_loop_index = 0; while_loop_index < length; ++while_loop_index)
	{
		if(Message[while_loop_index] == '@' && at_detected == false && Extension::FindCount(Message,At_Symbol_Pointer) == 1)
		{
			if(Message[while_loop_index + 1] != '.' && isalpha(Message[0]))
			{
				at_detected = true;
			}
		}

		if(Message[while_loop_index] == '.' && at_detected == true)
		{
			if(Message[while_loop_index + 1] != NULL)
			{
				dot_detected = true;
			}
		}

	}

	return dot_detected;

}
