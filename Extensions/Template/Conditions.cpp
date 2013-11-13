
#include "Common.h"

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

bool Extension::StartsWhiteSpace(const TCHAR * Message)
{
	if(isspace(Message[0]))
	{
		return true;
	}
	return false;

}


bool Extension::EndsWhiteSpace(const TCHAR * Message)
{
	unsigned int length = _tcslen(Message);

	if(isspace(Message[length-1]))
	{
		return true;
	}
	return false;

}

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
