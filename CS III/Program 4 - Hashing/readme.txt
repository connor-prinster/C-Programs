Three Facts:
------------
	1) Periods mean the end of the sentence. In this specific program we remove all periods, but the computer doesn't even 
	have that knowledge. Because of this, a word that was originally the end of the sentence registers the beginning word
	of the next sentence as one of its SecondWordInfo objects.

	2) The computer doesn't know definitions. Some words just won't make sense if put next to each other. In my most 
	recent run through the Poe.txt file I got the super fun phrase "this maiden whome the nausea the angels name in". These
	words don't make sense next to each other, but because the program doesn't know definitions, it just spits out words 
	that were, at one point, valid.

	3) Some of these words are used multiple times in various places throughout the .txt file. In green.txt there are 18 
	"new" words. A good majority of these words can be used in a ton of different places next to a bunch of totally 
	different words with various definitions (e.g. "and", "or", "like", etc).

Comparing Poems:
----------------
	The more words in a poem the more coherent it becomes. Poe.txt has more "unique-ish" words than green.txt does. Green.txt
	has 18 different words while Poe.txt has over 50. These unique words have fewer options for the words following it. For
	example, the word "late" is only said once in the whole poem so the only word it knows that can follow it is "visiter" and 
	since "visitor" is followed 2/3 times by "entreating" and 2/2 times by "entrance" and 2/2 times by "at" the three words will most likely spit out a coherent sentence: "late 
	visiter entreating entrance at" 
	Basically: longer poems with a greater variation of words = greater coherency