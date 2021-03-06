        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y�>  (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Character Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright (C) 2014 Samuel Benton",
        "Comment": "Allows for counting of certain types of characters within strings and string maniuplation. Currently only available for the English alphabet.",
        "URL": "http://www.xable.us/xable-character-object.html",
        "Help": "http://www.xable.us/xable-character-object.html",
        "Identifier": "Prod",
    },
    "ActionMenu": [],
    "ConditionMenu": 
	[
		["Alphanumerical",
			["Alphabetical",
				[2,"Contains Letters Only"],
				[3,"Contains Any Letters"],

				"Separator",

				[6,"Contains Consonants Only"],
				[7,"Contains Any Consonants"],

				"Separator",

				[4,"Contains Vowels Only"],
				[5,"Contains Any Vowels"],
			],
			["Numerical",
				[0,"Contains Numbers Only"],
				[1,"Contains Any Numbers"],
			],
		],

		["Punctuation Marks",
			[8,"Contains Punctuation Only"],
			[9,"Contains Any Punctuation"],

			"Separator",

			[10,"Contains Whitespace Only"],
			[11,"Contains Any Whitespace"],

			"Separator",

			[12,"Starts With a Whitespace"],
			[13,"Ends With a Whitespace"],

			"Separator",

			[14,"Contains Any Invalid Filepath Characters"],
			
		],

		["Other",
			[15,"String is in an Email Format"],
		]
	],

    "ExpressionMenu":
	[
		"Separator",
    
		["Alphanumerical",
			["Alphabetical",
				[3,"Letter Count"],
				
				"Separator",
				
				[2,"Consonant Count"],
				[1,"Vowel Count"],
				
				"Separator",
				
				[6,"Uppercase Count"],
				[7,"Lowercase Count"],
			],

			["Numerical",
				[4,"Number Count"],
			],
		],
		
		["Punctuation",
			[8,"Whitespace Count"],
			[9,"UNICODE Count"],	
			[10,"Punctuation Count"],
			[12,"Invalid File Character Count"],
		],

		["Trimming",
			
			["Whitespace",
				[13,"Trim Leading Whitespace Characters"],
				[14,"Trim Trailing Whitespace Characters"],
				[15,"Trim Leading and Trailing Whitespace Characters"],
				[16,"Trim All Whitespace Characters"],
			],
			
			["Punctuation",
				[17,"Trim Leading Punctuation Marks"],
				[18,"Trim Trailing Punctuation Marks"],
				[19,"Trim Leading and Trailing Punctuation Marks"],
				[20,"Trim All Punctuation Marks"],
			],
			
			["Numbers",
				[21,"Trim Leading Numbers"],
				[22,"Trim Trailing Numbers"],
				[23,"Trim Leading and Trailing Numbers"],
				[24,"Trim All Numbers"],
			],
			
			["Letters",
				[25,"Trim Leading Letters"],
				[26,"Trim Trailing Letters"],
				[27,"Trim Leading and Trailing Letters"],
				[28,"Trim All Letters"],
			],
			
			["Consonants",
				[29,"Trim Leading Consonants"],
				[30,"Trim Trailing Consonants"],
				[31,"Trim Leading and Trailing Consonants"],
				[32,"Trim All Consonants"],
			],
			
			["Vowels",
				[33,"Trim Leading Vowels"],
				[34,"Trim Trailing Vowels"],
				[35,"Trim Leading and Trailing Vowels"],
				[36,"Trim All Vowels"],
			],
			
			["Uppercase Letters",
				[37,"Trim Leading Uppercase Letters"],
				[38,"Trim Trailing Uppercase Letters"],
				[39,"Trim Leading and Trailing Uppercase Letters"],
				[40,"Trim All Uppercase Letters"],
			],
			
			["Lowercase Letters",
				[41,"Trim Leading Lowercase Letters"],
				[42,"Trim Trailing Lowercase Letters"],
				[43,"Trim Leading and Trailing Lowercase Letters"],
				[44,"Trim All Lowercase Letters"],
			],
		],

		["Padding",
			[45, "Left Pad String"],
			[46, "Right Pad String"],
		],

		["String Functions",
			[47, "Reverse String"],
		],


		["Other",
		   	[0,"Character Count"],
			[5,"Count the Number of a Specific Character"],
			[11, "Return Value of a Character"],
		],

		"Separator",
		
		
    ],
    "Actions": [],
    "Conditions": 
	[
		  {"Title": "%o : Does %0 contain only numbers?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 have at least one number?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 contain only letters?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 have at least one letter?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 contain only vowels?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 have at least one vowel?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 contain only consonants?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 have at least one consonant?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 contain only punctuations?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 have at least one punctuation?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 contain only whitespace character",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 have at least one whitespace character?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 start with a whitespace character?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 end with a whitespace character?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Does %0 contain any invalid filepath characters?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },
		{"Title": "%o : Is %0 in an email format?",
            "Parameters":
			[
				["Text","Message"],
            ],
            "Triggered": false
        },

	],
    "Expressions": [
       
		 {
            "Title": "CharCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text", "Enter the Message Here"],
            ]
        },

		 {
            "Title": "VowelCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },

		 {
            "Title": "ConsonantCount(",
            "Returns": "Integer",
            "Parameters":
			 [
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "LetterCount(",
            "Returns": "Integer",
            "Parameters":
			 [
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "NumberCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "FindCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
				["Text","Enter the Character to be Found"],
            ]
        },
		
		{
            "Title": "UpperCount(",
            "Returns": "Integer",
            "Parameters":
			 [
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "LowerCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "WhiteCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "UnicodeCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "PunctuationCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "ReturnValue(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here (only the first character will be analyzed)"],
            ]
        },

		{
            "Title": "InvalidFileCount(",
            "Returns": "Integer",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },

		{
            "Title": "TrimLeadingWhiteSpaces$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimTrailingWhiteSpaces$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimWhiteSpaces$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimAllWhiteSpaces$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLeadingPunct$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimTrailingPunct$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimPunct$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimAllPunct$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLeadingNum$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimTrailingNum$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimNum$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimAllNum$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLeadingLetters$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimTrailingLetters$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLetters$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimAllLetters$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLeadingConso$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimTrailingConso$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimConso$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimAllConso$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLeadingVow$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimTrailingVow$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimVow$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimAllVow$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLeadingUpper$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimTrailingUpper$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimUpper$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimAllUpper$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLeadingLower$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimTrailingLower$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimLower$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "TrimAllLower$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Enter the Message Here"],
            ]
        },
		{
            "Title": "LeftPad$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Message"],
				["Text","Padding Phrase"],
				["Integer","Repetition Count"],
            ]
        },
		{
            "Title": "RightPad$(",
            "Returns": "Text",
            "Parameters": 
			[
                ["Text","Message"],
				["Text","Padding Phrase"],
				["Integer","Repetition Count"],
            ]
        },
		{	
			"Title": "ReverseString$(",
			"Returns":	"Text",
			"Parameters":
			[
				["Text", "Message"],
			],
		},
    ]
}   &       �� ��     0	           M F 2                               