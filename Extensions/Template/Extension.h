
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

		bool NumbersOnly(const TCHAR * Message);
		bool AnyNumbers(const TCHAR * Message);
		bool LettersOnly(const TCHAR * Message);
		bool AnyLetters(const TCHAR * Message);
		bool VowelsOnly(const TCHAR * Message);
		bool AnyVowels(const TCHAR * Message);
		bool ConsonantsOnly(const TCHAR * Message);
		bool AnyConsonants(const TCHAR * Message);
		bool PunctuationOnly(const TCHAR * Message);
		bool AnyPunctuation(const TCHAR * Message);
		bool WhiteSpaceOnly(const TCHAR * Message);
		bool AnyWhiteSpace(const TCHAR * Message);
		bool StartsWhiteSpace(const TCHAR * Message);
		bool EndsWhiteSpace(const TCHAR * Message);
		bool ContainsInvalidFileCharacters(const TCHAR * Message);
		bool EmailFormat(const TCHAR * Message);

    /// Expressions
        
      	int CharCount(const TCHAR * Message);
		int VowelCount(const TCHAR * Message);
		int ConsonantCount(const TCHAR * Message);
		int LetterCount(const TCHAR * Message);
		int NumberCount(const TCHAR * Message);
		int FindCount(const TCHAR * Message, const TCHAR * Letter);
		int UpperCount(const TCHAR * Message);
		int LowerCount(const TCHAR * Message);
		int WhiteCount(const TCHAR * Message);
		int UnicodeCount(const TCHAR * Message);
		int PunctuationCount(const TCHAR * Message);
		int ReturnCharValue(const TCHAR * Message);
		int InvalidFileCharacters(const TCHAR * Message);

		TCHAR * RemoveLeadingWhiteSpaces(const TCHAR * Message);
		TCHAR * RemoveTrailingWhiteSpaces(const TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingWhiteSpaces(const TCHAR * Message);
		TCHAR * RemoveAllWhiteSpaces(const TCHAR * Message);

		TCHAR * RemoveLeadingPunctuation(const TCHAR * Message);
		TCHAR * RemoveTrailingPunctuation(const TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingPunctuation(const TCHAR * Message);
		TCHAR * RemoveAllPunctuation(const TCHAR * Message);

		TCHAR * RemoveLeadingNumbers(const TCHAR * Message);
		TCHAR * RemoveTrailingNumbers(const TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingNumbers(const TCHAR * Message);
		TCHAR * RemoveAllNumbers(const TCHAR * Message);

		TCHAR * RemoveLeadingLetters(const TCHAR * Message);
		TCHAR * RemoveTrailingLetters(const TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingLetters(const TCHAR * Message);
		TCHAR * RemoveAllLetters(const TCHAR * Message);

		TCHAR * RemoveLeadingConsonants(const TCHAR * Message);
		TCHAR * RemoveTrailingConsonants(const TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingConsonants(const TCHAR * Message);
		TCHAR * RemoveAllConsonants(const TCHAR * Message);

		TCHAR * RemoveLeadingVowels(const TCHAR * Message);
		TCHAR * RemoveTrailingVowels(const TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingVowels(const TCHAR * Message);
		TCHAR * RemoveAllVowels(const TCHAR * Message);

		TCHAR * RemoveLeadingUppercaseLetters(const TCHAR * Message);
		TCHAR * RemoveTrailingUppercaseLetters(const TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingUppercaseLetters(const TCHAR * Message);
		TCHAR * RemoveAllUppercaseLetters(const TCHAR * Message);

		TCHAR * RemoveLeadingLowercaseLetters(const TCHAR * Message);
		TCHAR * RemoveTrailingLowercaseLetters(const TCHAR * Message);
		TCHAR * RemoveLeadingAndTrailingLowercaseLetters(const TCHAR * Message);
		TCHAR * RemoveAllLowercaseLetters(const TCHAR * Message);

		TCHAR * PadLeftPhrase(const TCHAR * Message, const TCHAR * Phrase, int repeats);
		TCHAR * PadRightPhrase(const TCHAR * Message, const TCHAR * Phrase, int repeats);

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