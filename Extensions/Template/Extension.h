
class Extension
{
public:

    LPRDATA rdPtr;
    LPRH    rhPtr;

    Edif::Runtime Runtime;

    static const int MinimumBuild = 251;
    static const int Version = 1;

	static const int OEFLAGS = 0; 
    static const int OEPREFS = 0;
    
    static const int WindowProcPriority = 100;

    Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
    ~Extension();


    /*  Add any data you want to store in your extension to this class
        (eg. what you'd normally store in rdPtr)

        Unlike rdPtr, you can store real C++ objects with constructors
        and destructors, without having to call them manually or store
        a pointer.
    */

    // int MyVariable;




    /*  Add your actions, conditions and expressions as real class member
        functions here. The arguments (and return type for expressions) must
        match EXACTLY what you defined in the JSON.

        Remember to link the actions, conditions and expressions to their
        numeric IDs in the class constructor (Extension.cpp)
    */

	/// Actions



    /// Conditions

		bool NumbersOnly(TCHAR * Message);
		bool AnyNumbers(TCHAR * Message);
		bool LettersOnly(TCHAR * Message);
		bool AnyLetters(TCHAR * Message);
		bool VowelsOnly(TCHAR * Message);
		bool AnyVowels(TCHAR * Message);
		bool ConsonantsOnly(TCHAR * Message);
		bool AnyConsonants(TCHAR * Message);
		bool PunctuationOnly(TCHAR * Message);
		bool AnyPunctuation(TCHAR * Message);
		bool WhiteSpaceOnly(TCHAR * Message);
		bool AnyWhiteSpace(TCHAR * Message);
		bool StartsWhiteSpace(TCHAR * Message);
		bool EndsWhiteSpace(TCHAR * Message);
		bool ContainsInvalidFileCharacters(TCHAR * Message);
		bool EmailFormat(TCHAR * Message);

    /// Expressions
        
      	int CharCount(TCHAR * Message);
		int VowelCount(TCHAR * Message);
		int ConsonantCount(TCHAR * Message);
		int LetterCount(TCHAR * Message);
		int NumberCount(TCHAR * Message);
		int FindCount(TCHAR * Message, TCHAR * Letter);
		int UpperCount(TCHAR * Message);
		int LowerCount(TCHAR * Message);
		int WhiteCount(TCHAR * Message);
		int UnicodeCount(TCHAR * Message);
		int PunctuationCount(TCHAR * Message);
		int ReturnCharValue(TCHAR * Message);
		int InvalidFileCharacters(TCHAR * Message);

		TCHAR * RemoveLeadingWhiteSpaces(TCHAR * Message);
		TCHAR * RemoveTrailingWhiteSpaces(TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingWhiteSpaces(TCHAR * Message);
		TCHAR * RemoveAllWhiteSpaces(TCHAR * Message);

		TCHAR * RemoveLeadingPunctuation(TCHAR * Message);
		TCHAR * RemoveTrailingPunctuation(TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingPunctuation(TCHAR * Message);
		TCHAR * RemoveAllPunctuation(TCHAR * Message);

		TCHAR * RemoveLeadingNumbers(TCHAR * Message);
		TCHAR * RemoveTrailingNumbers(TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingNumbers(TCHAR * Message);
		TCHAR * RemoveAllNumbers(TCHAR * Message);

		TCHAR * RemoveLeadingLetters(TCHAR * Message);
		TCHAR * RemoveTrailingLetters(TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingLetters(TCHAR * Message);
		TCHAR * RemoveAllLetters(TCHAR * Message);

		TCHAR * RemoveLeadingConsonants(TCHAR * Message);
		TCHAR * RemoveTrailingConsonants(TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingConsonants(TCHAR * Message);
		TCHAR * RemoveAllConsonants(TCHAR * Message);

		TCHAR * RemoveLeadingVowels(TCHAR * Message);
		TCHAR * RemoveTrailingVowels(TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingVowels(TCHAR * Message);
		TCHAR * RemoveAllVowels(TCHAR * Message);

		TCHAR * RemoveLeadingUppercaseLetters(TCHAR * Message);
		TCHAR * RemoveTrailingUppercaseLetters(TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingUppercaseLetters(TCHAR * Message);
		TCHAR * RemoveAllUppercaseLetters(TCHAR * Message);

		TCHAR * RemoveLeadingLowercaseLetters(TCHAR * Message);
		TCHAR * RemoveTrailingLowercaseLetters(TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingLowercaseLetters(TCHAR * Message);
		TCHAR * RemoveAllLowercaseLetters(TCHAR * Message);

		TCHAR * PadLeftPhrase(TCHAR * Message, TCHAR * Phrase, int repeats);
		TCHAR * PadRightPhrase(TCHAR * Message, TCHAR * Phrase, int repeats);
		TCHAR * ReverseString(TCHAR * Message);

    /* These are called if there's no function linked to an ID */

    void Action(int ID, LPRDATA rdPtr, long param1, long param2);
    long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
    long Expression(int ID, LPRDATA rdPtr, long param);




    /*  These replace the functions like HandleRunObject that used to be
        implemented in Runtime.cpp. They work exactly the same, but they're
        inside the extension class.
    */

    short Handle();
    short Display();

    short Pause();
    short Continue();

    bool Save(HANDLE File);
    bool Load(HANDLE File);

};