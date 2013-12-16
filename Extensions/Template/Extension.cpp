
#include "Common.h"


///
/// EXTENSION CONSTRUCTOR/DESTRUCTOR
///

Extension::Extension(LPRDATA _rdPtr, LPEDATA edPtr, fpcob cobPtr)
    : rdPtr(_rdPtr), rhPtr(_rdPtr->rHo.hoAdRunHeader), Runtime(_rdPtr)
{
    /*
        Link all your action/condition/expression functions to their IDs to match the
        IDs in the JSON here
    */
	
	LinkExpression(0, CharCount);
	LinkExpression(1, VowelCount);
	LinkExpression(2, ConsonantCount);
	LinkExpression(3, LetterCount);
	LinkExpression(4, NumberCount);
	LinkExpression(5, FindCount);
	LinkExpression(6, UpperCount);
	LinkExpression(7, LowerCount);
	LinkExpression(8, WhiteCount);
	LinkExpression(9, UnicodeCount);
	LinkExpression(10, PunctuationCount);

   	LinkExpression(11, ReturnCharValue);

	LinkExpression(12, InvalidFileCharacters);

	LinkExpression(13, RemoveLeadingWhiteSpaces);
	LinkExpression(14, RemoveTrailingWhiteSpaces);
	LinkExpression(15, RemoveLeadingAndTrailingWhiteSpaces);
	LinkExpression(16, RemoveAllWhiteSpaces);
	
	LinkExpression(17, RemoveLeadingPunctuation);
	LinkExpression(18, RemoveTrailingPunctuation);
	LinkExpression(19, RemoveLeadingAndTrailingPunctuation);
	LinkExpression(20, RemoveAllPunctuation);
	
	LinkExpression(21, RemoveLeadingNumbers);
	LinkExpression(22, RemoveTrailingNumbers);
	LinkExpression(23, RemoveLeadingAndTrailingNumbers);
	LinkExpression(24, RemoveAllNumbers);
	
	LinkExpression(25, RemoveLeadingLetters);
	LinkExpression(26, RemoveTrailingLetters);
	LinkExpression(27, RemoveLeadingAndTrailingLetters);
	LinkExpression(28, RemoveAllLetters);
	
	LinkExpression(29, RemoveLeadingConsonants);
	LinkExpression(30, RemoveTrailingConsonants);
	LinkExpression(31, RemoveLeadingAndTrailingConsonants);
	LinkExpression(32, RemoveAllConsonants);
	
	LinkExpression(33, RemoveLeadingVowels);
	LinkExpression(34, RemoveTrailingVowels);
	LinkExpression(35, RemoveLeadingAndTrailingVowels);
	LinkExpression(36, RemoveAllVowels);
	
	LinkExpression(37, RemoveLeadingUppercaseLetters);
	LinkExpression(38, RemoveTrailingUppercaseLetters);
	LinkExpression(39, RemoveLeadingAndTrailingUppercaseLetters);
	LinkExpression(40, RemoveAllUppercaseLetters);
	
	LinkExpression(41, RemoveLeadingLowercaseLetters);
	LinkExpression(42, RemoveTrailingLowercaseLetters);
	LinkExpression(43, RemoveLeadingAndTrailingLowercaseLetters);
	LinkExpression(44, RemoveAllLowercaseLetters);

	LinkExpression(45, PadLeftPhrase);
	LinkExpression(46, PadRightPhrase);

	LinkCondition(0, NumbersOnly);
	LinkCondition(1, AnyNumbers);

	LinkCondition(2, LettersOnly);
	LinkCondition(3, AnyLetters);

	LinkCondition(4, VowelsOnly);
	LinkCondition(5, AnyVowels);

	LinkCondition(6, ConsonantsOnly);
	LinkCondition(7, AnyConsonants);

	LinkCondition(8, PunctuationOnly);
	LinkCondition(9, AnyPunctuation);

	LinkCondition(10, WhiteSpaceOnly);
	LinkCondition(11, AnyWhiteSpace);

	LinkCondition(12, StartsWhiteSpace);
	LinkCondition(13, EndsWhiteSpace);

	LinkCondition(14, ContainsInvalidFileCharacters);
    /*
        This is where you'd do anything you'd do in CreateRunObject in the original SDK

        It's the only place you'll get access to edPtr at runtime, so you should transfer
        anything from edPtr to the extension class here.
    
    */


    
}

Extension::~Extension()
{
    /*
        This is where you'd do anything you'd do in DestroyRunObject in the original SDK.
        (except calling destructors and other such atrocities, because that's automatic in Edif)
    */



}


short Extension::Handle()
{
    /*
       If your extension will draw to the MMF window you should first 
       check if anything about its display has changed :

           if (rdPtr->roc.rcChanged)
              return REFLAG_DISPLAY;
           else
              return 0;

       You will also need to make sure you change this flag yourself 
       to 1 whenever you want to redraw your object
     
       If your extension won't draw to the window, but it still needs 
       to do something every MMF loop use :

            return 0;

       If you don't need to do something every loop, use :

            return REFLAG_ONESHOT;

       This doesn't mean this function can never run again. If you want MMF
       to handle your object again (causing this code to run) use this function:

            Runtime.Rehandle();

       At the end of the loop this code will run

    */

	// Will not be called next loop	
	return REFLAG_ONESHOT;
}


short Extension::Display()
{
    /*
       If you return REFLAG_DISPLAY in Handle() this routine will run.
    */

    // Ok
    return 0;
}

short Extension::Pause()
{

    // Ok
    return 0;
}

short Extension::Continue()
{

    // Ok
    return 0;
}

bool Extension::Save(HANDLE File)
{
	bool OK = false;

    #ifndef VITALIZE

	    // Save the object's data here

	    OK = true;

    #endif

	return OK;
}

bool Extension::Load(HANDLE File)
{
	bool OK = false;

    #ifndef VITALIZE

	    // Load the object's data here

	    OK = true;

    #endif

	return OK;
}


// These are called if there's no function linked to an ID

void Extension::Action(int ID, LPRDATA rdPtr, long param1, long param2)
{

}

long Extension::Condition(int ID, LPRDATA rdPtr, long param1, long param2)
{

    return false;
}

long Extension::Expression(int ID, LPRDATA rdPtr, long param)
{

    return 0;
}

