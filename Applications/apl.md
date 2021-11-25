> __[Braille EAN13](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Braille EAN13)__
__[ final application]__, __[trivial]__, __[cross-platform]__
>> Consists of 2 seperate applications that were sent to the same contest.





> __[Brightly](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Brightly)__
__[ final application]__, __[linux]__, __[visible]__
>> - modifies the screen brightness
- offers the following options:
  1. Modify Bright - able to adjust the brightness up and down
                   - use [ and ] to dim up and down, type "done" to mention that you are done
  2. Bright Choices - presets for screen brightness ( 1. Bright  2. Default  3. Really bright  4. Normal )
  3. Continous slow - preset for unstoppable slow flicker ( only stoppable if you exit the application )
  4. Continous flicker - preset for unstoppable fast flicker ( only stoppable if you exit the application )
  more. More Birghties - executes a user-defined series of flickers, which stops when completed ( does not repeat like the 'continous' presets )
                       - users are asked to 
  reset. Reset Bright - resets brightness to default





> __[Clmns](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Clmns)__
__[ final application]__, __[cross-platform]__, __[needs rnd]__, __[visible]__, __[code generation]__
>> - makes data for tables, either sql or plain data with column names
- has 3 datatypes for the columns: int, string and double
- able to include self-oteration column





> __[Cpp Class string brackets](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Cpp Class string brackets)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> - makes classes when given the properties
- able to both define each data-type and recognise when given example data
- able to recognise table / array sizes or fill them in when they do not appear ( even if partial data if provided, only a size out of 7 for example )
- besides the class, the user receives arrays with the variable names provided, in case they need them for automating the generated code ...
- class is provided with:
	- private parameters
	- constructors ( one empty with initialisations and one with all paramaters )
	- getters and setters - multiple verifications available ( if you want to set a value at a position that exceeds the table size ... )
	- for tables, multiple intermediary functions are provided ( length, copy, ...  ) as well as multiple getters and setters
	- for tables ( with size >= 2 ) an array containing their data is provided to take care of operations such as copying data and others
	- a function to output information about the class parameter values
- available data-types for parameters: 1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom
- all gerenated classes use a boolean variable to determine if they are empty or not
- each generated class is fully commented
- has function fo generation clss out of code - not sure if it does
Improvements:
- when you use the constructor that takes values, make is_empty = 0, not true





> __[Cpp Class multiple items string folders linux cpp](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Cpp Class multiple items string folders linux cpp)__
__[ final application]__, __[linux]__, __[visible]__, __[code generation]__
>> - database application able to make table connections
- available options ( database ):
	- make. Make class file - makes tables
	- edit. Edit / Show a class file - edit / show a table and its data
	- simmilar. Enter simmilar files - makes table connections ( add, remove and show connections )
	- delete. Delete a class file - delete a table
	- exit. Exit - exits the application
- available options ( table ):
	- 1. Add entry - add a table row
	- 2. Show entry - show a table row ( and the rows of other tables that are connected to it, when the values coincide, same for all show functions )
	- 3. Show entries - complete - shows all entries and numerotates them
	- 4. Show entries - shows multiple entries as you enter their id ( which is >= 1 )
	- 5. Remove entry - removes a table row
	- 6. Remove entries - removes multiple entries as you enter their id ( which is >= 1 )
	- 7. Clear entries - deletes all entries
	- 8. Sort ( show / save ) - sort by any column ( asc / desc ) and decide to just show the result, or also save it
	- 9. Move - move a certain entry up and down how many rows you want
	- 10. Swap - swaps 2 table rows
	- item. Show entries that have [item] - search though the table data for a certain string ( also available for other data types, converstions are made )
	- save. Save - saves the table ( table is saved anyway, only to make the user feel safe )
	- exit. Exit - exits to the database options
Improvements:
- failed to save sorted rows - added 0 instead of 1 when swapping or such





> __[Css Atribs](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Css Atribs)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> - converts css attributes, attribute values and classes amongst each other
- many times, css classes are made to style applications, however using attributes instead of classes can prove easier and more visible. So, conversions are needed. 
- even after conversion, both the initial data and the result are kept ( both classes and attributes for example, when converting class to attribute )
- attribute values can be converted to classes as such: [ atrib = "val" ] becomes .atrib-val
Improvements:
- / convert attribute values to attributes, like with classes [ atrib-val ] 





> __[Css File 1](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Css File 1)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - using a header, the application can replace strings of the file to output multiple distinct variants of replacement ( for every result you replace what you want with what you need )
- the application orders the strings that need to be replaced, so that conflicts between replacement strings do not appear ( the result of the one replacement needs not be replaced by another replacement )
- even if made with css themes in mind, the application is versatile, meaning that it can replace any given strings
Css File: application version, cross-platform
- only outputs 1 specified file





> __[File Counter](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/File Counter)__
__[ library version]__, __[remake]__, __[cross-platform]__
>> - uses the same file





> __[Format text](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Format text)__
__[ trivial]__, __[cross-platform]__
>> - use only default templates to make letters of:
1. apology
2. thanks
3. invitation
4. congratulations
5. request
6. angry
7. trip
- uses a file counter to numerotate the output files





> __[Git Readme Maker folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Git Readme Maker folder)__
__[ final application]__, __[trivial]__, __[cross-platform]__, __[code generation]__
>> - keep your project details in your code file, with every compilation the actual separate file gets updated
) Git Readme Maker: application version, trivial, cross-platform, code generation
- without separate folder





> __[application](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/application)__
__[ trivial]____[final application]____[cross-platform]__, 
>> - adds variables to a file to make code





> __[choice](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/choice)__
__[ final application]____[cross-platform]____[code generation]__, 
>> - makes a c choices application using your features





> __[desktop maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/desktop maker)__
__[ application version]____[cross-platform]____[code generation]__, 
>> 




> __[desktop maker folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/desktop maker folder)__
__[ final application]____[cross-platform]____[code generation]__, 
>> - makes desktop file with every compilation





> __[maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/maker)__
__[ application version]____[cross-platform]____[code generation]__, 
>> 




> __[maker folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/maker folder)__
__[ final application]____[cross-platform]____[code generation]__, 
>> - makes makefile with every compilation





> __[readme](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/readme)__
__[ application version]____[cross-platform]____[code generation]__, 
>> 




> __[readme folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/readme folder)__
__[ final application]____[cross-platform]____[code generation]__, 
>> - makes it with every compilation





> __[rndm](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/rndm)__
__[ final application]____[cross-platform]__, 
>> - makes rndm nums, between a max and a min





> __[struct](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/struct)__
__[ final application]____[cross-platform]____[code generation]__, 
>> - makes a struct
- makes function for adding values to every struct field
- makes function for shoowing the struct values





> __[Inheritance file virtual](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Inheritance file virtual)__
__[ final application]__, __[cross-platform]__
>> - application that helps you keep track of your class inherintances
- makes it easy to understand what are the interitances, inheritors and virtual functions of every class
- options offered:
    1. Add Class     2. Add Inheritance     3. Add Inheritor     
    4. Remove Class  5. Remove Inheritance  6. Remove Inheritor  
    7. Show Classes  8. Add Virtual         9. Remove Virtual    
  exit. Exits
- the application does not use any of the provided classes, it only helps you keep the details you need





> __[Inheritance file](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Inheritance file)__
__[ application version]__, __[cross-platform]__
>> 




> __[Inheritance](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Inheritance)__
__[ application version]__, __[cross-platform]__
>> 




> __[Interface](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Interface)__
__[ final application]__, __[trivial]__, __[cross-platform]__
>> - makes interfaces, requesting names of functions and their parameters and data-types
- uses the data-types:
1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom ( enter now ) - void is considered custom
- able to make virtual functions
- asks you what to add to the file, so you do not have to ( only purpose )





> __[Interval](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Interval)__
__[ final application]__, __[trivial]__, __[cross-platform]__
>> - generates intervals with either even, odd, prime or square numbers
- outputs to a user-specified file
- leaves new line for every 5 entries





> __[Linux list Maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Linux list Maker)__
__[ final application]__, __[example]__, __[trivial]__, __[cross-platform]__
>> - adds entries to a list using linux commands ( example for using linux commands )





> __[Linux operations](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Linux operations)__
__[ not completed]__, __[linux]__
>> - execute linux commands ( spares you typing them if you use them a lot )
Improvements:
- add more operations





> __[Server](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Server)__
__[ final application]__, __[linux]__, __[visible]__
>> - server for databases of "Cpp Class multiple items string folders linux cpp"
- able to add and remove databases, as well as edit their names





> __[Slce](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Slce)__
__[ final application]__, __[trivial]__, __[cross-platform]__, __[code generation]__
>> - separates any cpp application into what is before the main function and the main function ( using  files that are correlated to compile )





> __[Sql Maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/Sql Maker)__
__[ final application]__, __[trivial]__, __[cross-platform]__, __[code generation]__
>> - makes sql commands to create a table nased on the user-defined column names and data-types
- only uses int and char data-types
- adds self-iterating on its own, no need to add it yourself
- could be used for automating with other applications





> __[align](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/align)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - alignes text in a .txt file
- options available: 1. Left  2. Center  3. Right  4. Middle  5. table
Improvements:
- / add other features: Upper, Lower, numerorate lines, wrd / line spacing ... - added, however it keeps outputting non-english alphabet letters





> __[application](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/application)__
__[ final application]__, __[trivial]__, __[cross-platform]__, __[code generation]__
>> - makes an application layout
- able to add:
  1. variable   2. subprogram   3. class   4. struct
  5. variables  exit. Exit
- just adds them





> __[are in files](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/are in files)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - searches one or many files for multiple queries ( strings )
- results of the search are shown in a result file for all the searched files
- able to keep your search queries in another file, one on each line
- able to keep the filepaths for the files that need to be searched in another file, one on each line
- the line where each result if found is shown in the result file
- results are grouped in the result file by the file that was searched and by search query





> __[are in](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/are in)__
__[ application version]__, __[cross-platform]__
>> - only searches in one file





> __[blar](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/blar)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - array of bool made into class
- for bool arrays, there is a constant need to adjust the length of the array in a separate variable. So, the data-type has a good reason to become a class.
- there are 2 paramaters for the primitive bool array and for its length
- functions to:
	- add a bool to the end of the array
	- add a bool at a certain position
	- modify ( set ) a bool a certain position
	- remove a bool at a certain position
	- output information about the class
	- get the length
	- get bool at a certain position
Improvements:
- add string of 1 and 0 to the array ( for binary output )
- add constructor that takes a primitive bool array and its length





> __[chars](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/chars)__
__[ example]__, __[cross-platform]__, __[visible]__, __[common words]__
>> - encodes common words with uncommon characters
- able to both encode and decode files
Improvements:
- ) omit wrds that only have 1 letter ( why encode them ) - not needed, hrdcoded fle done





> __[choices 1](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/choices 1)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> - makes an application with numerotated choices
- asks for the application name and its features = options = choices, and makes an application that is able to:
	- keep showing choices until the user wants to exit
	- checks if the choice the user entered is available
	- spatiates the choices to align them
	- adds option for exiting the application on its own
	- able to search through the features both by number and by string 
	- able to adapt the user input to the available features ( reduce extra spaces, ... )
Improvements:
- if the user enters a feature called "exit" that has to not appear twice





> __[choices](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/choices)__
__[ application version]__, __[cross-platform]__, __[code generation]__
>> 




> __[choices lnux](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/choices lnux)__
__[ final application]__, __[trivial]__, __[cross-platform]__, __[code generation]__
>> - makes a choices application for the linux command line ( takes application features and makes an application layout with them using only linux commands )





> __[cmb file](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/cmb file)__
__[ final application]__, __[cross-platform]__, __[needs rnd]__, __[visible]__
>> - outputs a combination of file lines
- can be used to generated human names, item names ...
- uses files that the user mentions ( also stores them )
- able to add, remove and show the files being used





> __[cmb](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/cmb)__
__[ final application]__, __[cross-platform]__, __[needs rnd]__
>> - outputs a combination of file lines
- can be used to generated human names, item names ...
- only uses 1 file ( which it remembers )
- able to generate combinaions of no matter how many items 





> __[codes](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/codes)__
__[ final application]__, __[example]__, __[cross-platform]__, __[code generation]__
>> - example of guided self-generated code
- able to:
    1. Make an if    2. Make an if / else  3. Make a for      4. Make a struct  
    5. Make a class  6. Make a var.        7. Make a comment  
- all the aforementioned are added to a function of the file being complied





> __[colors](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/colors)__
__[ final application]__, __[linux]__, __[visible]__
>> - able to output colored text to the linux terminal
- bold / italic / strike-though / udnerline and dim also avaialble for formatting
- 9 colors available ( all the available ones )





> __[commit linux same folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/commit linux same folder)__
__[ application version]__, __[linux]__
>> 




> __[commit same folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/commit same folder)__
__[ application version]__, __[linux]__
>> 




> __[commit your file](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/commit your file)__
__[ final application]__, __[cross-platform]__
>> - uses separate folder to make a copy of your code every 10 compilations
- can be set to ask for commit at every compilation 
- can be set to commit at a specified number of compilation
- able to reset the iterator used to numerotate the copies of your file ( the commits )





> __[common frev multiple](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/common frev multiple)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[common word]__
>> - used to determine the most common words by topic
- when a file is added ( to a topic or not ), the freqvency for each of its words is calculated and added next to the word in a file. After adding the words of the file with their freqvencies to a file that stores the most common words without regard to any topic, the user is asked if they want to add the file to a topic too. The process is repeated for the specified topic file.
- available options:
	- 1. Add File - adds the words of a file and their freqvencies to the "most common words" file. If needed, they are also added to a "most common words" file of a topic.
	- 2. Add topic - adds a topic ( adds and stores a topic name )
	- 3. Remove topic - removes a topic
	- 4. Show topics - shows all available topics
	- 5. Show topic - shows a topic and its top 5 most common words with their freqvencies
	- files. Remake files - if the user has at least 900 words stored in the general "most common words" file, they can remake the topic files to use the freqvencies of the general file, keeping the same words ( which are sorted, leading to the top most common words of that topic to change )
	- exit. Exits - exits the application
- the application checks for the same topic to not get added twice





> __[common frev](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/common frev)__
__[ application version]__, __[cross-platform]__, __[common word]__
>> - only uses 1 file to store the most common words ( does not have topics )





> __[common](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/common)__
__[ not completed]__, __[cross-platform]__
>> - stores applications names and their description 
- has a search feature that gives exact results and also makes suggestions for applications that are simmilar with the applications found. In order to determine that 2 applications are simmilar, their descriptions and names are compared. Usual words are excluded when it comes to searching, since the user might want to store only applications that belong to a certain topic, for example "history" the word "history" needs not be searched and is therefore excluded at seatch. So, the user can exclude certain words.
Improvements
- make the usual words not be taken into consideration at search
- make it able to install an application ( copy the executable )
- make subcategory for adding usual words ( do not show it as a primary function, make another interface for that )





> __[compare files](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/compare files)__
__[ not completed]__, __[linux]__, __[visible]__, __[common word]__
>> - compare sentances of multiple files to determine if they were plagiated
- the application separates the files into lowercased sentances. In order to compare the files, each sentance of 1 file compared with every sentance of the other files to determine how simmilar they are. Simmilarity is determined by the number of common words in the sentances.
Improvements:
- / the common words and the lines they appear on are not counted correctly, only need to increment in 1 for, not in both  ( lines 290 )
- delete the "lines" files





> __[compare](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/compare)__
__[ application version]__, __[cross-platform]__, __[common word]__
>> 




> __[convert file](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/convert file)__
__[ example]__, __[cross-platform]__, __[visible]__
>> - shows how conversions can be done using an external file ( output a data-type and read another )





> __[convert](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/convert)__
__[ not completed]__, __[cross-platform]__, __[visible]__
>> - converts between any 2 units of measurement ( for now it can only multiply one unit by a constant to get another, nneds to be done with rules )
- stores the conversions
- available options: 1. Convert  2. Add Convert  3. Edit Convert  4. Remove Convert  5. Show Converts
Improvements:
- add rules ( format an expression, then compile that expression in cpp to get the result and get the conversion )





> __[cpp sh](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/cpp sh)__
__[ library]__, __[linux]__
>> - uses scripts in separate files to communicate with the cpp functions ( to get parameters for the scripts and send results )
Improvements:
- add other scripts





> __[datatype](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/datatype)__
__[ final application]__, __[cross-platform]__
>> - separates file data into files for: integers, doubles and strings
Improvements:
- could add char, bool





> __[deb folders maker desktop my_debs](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/deb folders maker desktop my_debs)__
__[ final application]__, __[linux]__, __[code generation]__
>> - makes a deb for an application and saves in a special folder for all your applications
- adds a desktop file
Improvement:
- make a deb at every compilation





> __[deb folders maker desktop](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/deb folders maker desktop)__
__[ application verion]__, __[linux]__, __[code generation]__
>> - adds a desktop file





> __[deb folders maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/deb folders maker)__
__[ application verion]__, __[linux]__, __[code generation]__
>> 




> __[desktop maker folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/desktop maker folder)__
__[ final application]__, __[linux]__, __[code generation]__
>> - makes desktop file for linux
- for every compilation, a desktop file is made





> __[desktop maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/desktop maker)__
__[ application versions]__, __[linux]__, __[code generation]__
>> 




> __[details](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/details)__
__[ trivial]__, __[example]__, __[cross-platform]__
>> - example of how you can store names and their details in 1 file
- available options: 1. Add  2. Remove  3. Edit  show. Show  exit. Exits





> __[double](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/double)__
__[ trivial]__, __[final application]__, __[cross-platform]__
>> - given any numbers, the application determines their properties and calculates their average
- for integers it determines: pos / neg, parity, divisors, prime divisors
- for double it determines: 
Improvements:
- do not stop input with 0
- for 1, do not show prime divisors ( shows only empty paranthesis )
- for double numbers, show at least is they are positive, approximations to every decimal and to integer, num. of decimals ( does not show )
- identify if any of teh numbers is pi or other constants





> __[dplma](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/dplma)__
__[ not completed]__, __[linux]__, __[visible]__, __[code generation]__
>> - used to make diplomas
- enter the occasion, then either type or add a file with the names of the recipients
Improvements:
- add latex code
- ouput each diploma separately in a folder





> __[errors](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/errors)__
__[ example]__, __[trivial]__, __[library version]__, __[cross-platform]__, __[visible]__
>> - correlate error codes with their actual text
- defining your error is only done manually
Improvements:
- make errors that take parameters
- make errors show when you compile other applications
- predefine certain errors: division by 0, ...





> __[file browser](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/file browser)__
__[ final application]__, __[linux]__, __[visible]__
>> - uses only linux commands to move around the files
- available options: / 1. Home  / 2. Return / 3. Move Upwards / 4. Details / exit. Exits
- there is also a cpp version, not complete





> __[file choices](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/file choices)__
__[ final application]__, __[trivial]__, __[cross-platform]__
>> - provides with 2 templates to make either an application that uses 1 or multiple files ( just copies the files into your specified filename )





> __[file counter](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/file counter)__
__[ library version]__, __[remake]__, __[trivial]__, __[cross-platform]__
>> - uses 1 predefined file to count





> __[file lines](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/file lines)__
__[ trivial]__, __[example]__, __[application version]__, __[cross-platform]__
>> - monitors a file ( keeps on reloading the contents of a file to the terminal, to monitor any changes )





> __[file string](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/file string)__
__[ final application]__, __[cross-platform]__
>> - converts the contents of a file to a string ( replaces new lines with \n and adds "" )
- able to add \n instead of spaces, of new lines or instead of sentances delimitated by any string
- also able to output an array of strings, with [ "", "" ] or just with ,
- able to merge multiple files into the same string
Improvements:
- add custom char instead of just ,





> __[file type](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/file type)__
__[ not completed]__, __[final application]__, __[cross-platform]__, __[visible]__
>> - file format that is very easy to use to make paragraphs with titles
- when considering a document, it is usually observable that it is made only out of paragraphs with titles. So, in order to format a document, thet is the only vital information that the user needs to provide. Documents need to be formated in multiple formats ( using latex, ... ), so there should be a base format for all of them.
Improvements:
- add file formats
- outputs non-english letters to file, solve that





> __[files lines](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/files lines)__
__[ final application]__, __[trivial]__, __[cross-platform]__
>> - able to monitor any file for changes ( showing its contents in the terminal )





> __[files path](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/files path)__
__[ example]__, __[not completed]__, __[library version]__, __[trivial]__, __[linux]__
>> - gets all the filenames of a folder in cpp
Improvements
- uses wrong command, use "ls -p > file", not try to remake the filename
- could be part of "cpp sh", which could be part of a library





> __[filesize](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/filesize)__
__[ final application]__, __[linux]__, __[visible]__
>> - able to determine the filesize for every file-type in a folder, as well as show a percentage of each filesize out of total filesize





> __[form](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/form)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> - able to make forms that can be completed in the terminal
- provides with:
	- multiple choices
	- 1 line field of text
	- numeric interval field
- makes a cpp application that collects the specified data, which then formats the data into its very own file format 
Improvements:
- outputs forever for certain inputs
- determine what the 4th option does





> __[format file](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/format file)__
__[ trivial]__, __[example]__, __[cross-platform]__, __[code generation]__
>> - you give it a title and details and it formats them, only to add a few new lines and welcome the user to the application
- intended to make application details
Improvements:
- could add user details after every application





> __[format](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/format)__
__[ application version]__, __[cross-platform]__
>> - for "file string"





> __[formats](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/formats)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - adds style to a plain text file by adding user-defined strings before and after: words, lines or chatacters





> __[frev](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/frev)__
__[ final application]__, __[cross-platform]__, __[common word]__, __[statistics]__
>> - counts the freqvence of each word used in multiple specified files
- outputs the results in a file





> __[gap](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/gap)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - given a file with gaps defined by [], the user can replace each of the gaps with their input to make a file they can name





> __[get files](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/get files)__
__[ library version]__, __[cross-platform ]__
>> - functions for getting and setting multiple files at once





> __[get length](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/get length)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - gets words of certain files based only on their length
- available options: 1. Larger  2. Fewer  3. Equal
- shows results in a separate file, also mentioning the line number where they were found
Improvement:
- add option for interval





> __[get paths](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/get paths)__
__[ final application]__, __[library version]__, __[linux]__
>> - able to go through all folders in a folder to show what is in each of them ( does so for folder it finds, until there are no more )
- outputs the result in a file
- the output can be used to represent the file structure in a format that takes up the least memory possible
Improvement
- convert the result to filepaths





> __[header folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/header folder)__
__[ final application]__, __[linux]__, __[visible]__, __[code generation]__
>> - converts a cpp application to a header file that uses every function it has besides main ( the functions are stored separately, onlt the function names are in the header file )





> __[html website](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/html website)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> - makes a website
- enter a title and a small description, choose 1 of 5 available themes
- enter the text for your website in the terminal ( for both About and Contact )





> __[invalid](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/invalid)__
__[ final application]__, __[trivial]__, __[cross-platform]__
>> - given an array of integer, it determines the ones that are missing ( between the max and min values )





> __[linux commands](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/linux commands)__
__[ remake]__, __[final application]__, __[linux]__, __[visible]__
>> - use choices to execute linux commands
- could be used for repiring the system





> __[lng](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/lng)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> - given a list of language-specific symbols and their replacements, the application converts code written in the language that uses the replacements to cpp, then compiles it
- does not need a main function
- code can exist outside any other functions





> __[maker folder](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/maker folder)__
__[ final appliation]__, __[cross-platform]__, __[code generation]__
>> - makes a makefile with every compilation





> __[maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/maker)__
__[ application version]__, __[cross-platform]__, __[code generation]__
>> 




> __[measure](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/measure)__
__[ final application]__, __[trivial]__, __[cross-platform]__
>> - measure distances by measuring the time it takes for you to walk
- has a  variation where you inpu the number of steps you walked to measure





> __[mesur file](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/mesur file)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[statistics]__
>> - given a set of numeric data, the application calculates the average, errors for every entry, and an average error
- it also saves every file with measurements
- able to remove large errors by comparing with the average error
- able to add data to any of the saved measurements file ( either type it, or add it with a file )
- able to also reomve data, and measurement files
- shows the measurement filenames and their content
- computes the reults for any measurement and saves them in a separate file





> __[mesur](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/mesur)__
__[ application version]__, __[cross-platform]__
>> - takes data either by typing or with file and computes results in a file





> __[more](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/more)__
__[ not completed]__, __[linux]__
>> - meant to make classes and have them interract to change their parameter value (  )
- parameters have a range = interval in which they can fluctuate





> __[nums](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/nums)__
__[ final application]__, __[cross-paltform]__, __[visible]__, __[common word]__, __[statistics]__
>> - able to separate the data by int, string and double and group it
- for string:
	- counts them, both total and distinct
	- determine average freqvence by calculating it ( and approximating it to an integer ) and by determning how much the most of them repeat themselves ( usually they only appear once )
	- show each string and their freqvency ( unless the freqvency is 1 )
	- determine average length of strings in the file by calculating it ( and approximating it to an integer ) and by determning the length of most of the strings
	- do all the above separately for:
		- large first letter
		- small first letter
		- all uppercase
		- all lowercas
	- calculate max and min ( both alphabetically and by length ) 
- for any data-type considered to be a string:
	- calculates total - word count
	- count total length of teh data without whitespace
	- determine average length by calculating it ( and approximating it to an integer ) and by determning the length of most of the words
	- count total length of both data and whitespace
	- count total whitespace ( coincides with its length )
	- calculates data / whitespace
	- counts file lines
	- datermine average length of lines in the file by calculating it ( and approximating it to an integer ) and by determning the length of most of the lines
	- determine average freqvence by calculating it ( and approximating it to an integer ) and by determning how much the most of them repeat themselves ( usually they only appear once )
	- determine common and uncommon words total and distinct total
	- calculate uncommon word freqvency / uncommon word count for every uncommon word and show only the top 5
	- calculate:
		- uncommon words / total ( count )
		- uncommon words / total words ( count )
		- uncommon words / total and wh-space ( length )
		- numerical data: total and how many ints and doubles
		- uncommon words and nmerical data / total ( count )
		- uncommon words and numerical data / total and wh-space ( length )
- for integers:
 	- counts them, both total and distinct
	- determine average freqvence by calculating it ( and approximating it to an integer ) and by determning how much the most of them repeat themselves ( usually they only appear once )
	- show each string and their freqvency ( unless the freqvency is 1 )
	- do all the above separately for:
		- even
		- odd
		- pos
		- neg
		- prime
		- square
	- determine the missing integers in the interval determined by the smallest and the largest integer
	- determine max and min
- for doubles:
 	- counts them, both total and distinct
	- determine average freqvence by calculating it ( and approximating it to an integer ) and by determning how much the most of them repeat themselves ( usually they only appear once )
	- show each string and their freqvency ( unless the freqvency is 1 )
	- do all the above separately for:
		- pos
		- neg
	- determine max and min 
- for both ints and doubles:
	- show each string and their freqvency ( unless the freqvency is 1 )
	- do all the above separately only for:
		- pos
		- neg
Improvements:
- for any data-type considered to be a string also add:
	- totat of distinct
	- do not do just for neg and pos separately, also both
 	- counts them, both total and distinct
	- determine average freqvence by calculating it ( and approximating it to an integer ) and by determning how much the most of them repeat themselves ( usually they only appear once )
	- determine max and min
- calculate lengths of ints and doubles too ( both separately and taken together )





> __[organise](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/organise)__
__[ final application]__, __[linux]__
>> - make and edit files, add them to categories
- available options:
  1. Make a file   2. Ctg a file   3. !Ctg a file    4. Edit a file   5. Rename file
  6. Add ctg       7. Show ctgs    8. Remove ctg     9. Rename ctg
  delete. Delete file                 exit. Exit





> __[parts](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/parts)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[common word]__
>> - uses parts of speech to make sentances
available options:  1. Add File  2. Get Sentance  3. Sentances and words  4. Subjects  5. Exits
- add a file and it asks you what part of speech the word is, and if it is common or not
- memorises both the parts of speech in separate files, as well as the sentance ( the sentance is used as a template that uses the parts of speech you mentioned )





> __[pattern](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/pattern)__
__[ final application]__, __[cross-platform]__, __[common word]__
>> - memorises order of common words in a sentance ( could be used to determine if a sentance is gramatically valid )





> __[percision](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/percision)__
__[ final application]__, __[library version]__, __[trivial]__
>> - replicates the functionality of a cpp library that outputs decimals with a certain precision and spatiates the output
- has 2 identical files - why
Improvements:
- make into library





> __[phrse common](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/phrse common)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[common word]__
>> - eliminates phrases that have mostly common words ( that do not mean much )
- could be used to extract meaning on a text





> __[prcns](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/prcns)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[statistics]__
>> - given a text that has numeric data, the application extracts the numeric data and calculates how much each of the numbers is out of the total
- if a number is preceded by a string, the value represents it ( the string is the name of what that number represents )





> __[prgrph](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/prgrph)__
__[ final application]__, __[cross-paltform]__
>> - slices a paragraph into smaller paragraphs, when given a maximum sentance count
- only separates when sentances end





> __[remove](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/remove)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[common word]__
>> - given files on a certain topic, the application determines common words and makes a file consisting of the most used uncommon words in order.
- if the application realises that the file that was added belongs to a topic that was added before by another file, the "most used uncommon words" of the files are merged
- available options:
  add. Add usual word          adds. Add usual words - add 1 or multiple usual words
  remove.  Remove usual word   removes. Remove usual words - remove 1 or multiple usual words
  [help].  Enter text, enter which words make sense to improve - you improve the application by adding text and mentioning afterwards which if the words are uncommon ( to determine which are common )
  [enter]. Enter text and get words that make sense - type text and get the uncommon words 
  [sense]. Enter a word and get correlated words - using the "most used uncommon words" files, the application gives you words related to a word you enter
  files.   Show save file filenames - show filenames for the files with most used uncommon words
  show. Show usual words - shows common words
  copy. Make a copy of "usual_words" file - copies the usual words file, in case you need it
  save. Save usual words ( done anyways ) - save feature, just to make the user feel safe
  exit. Exit - exits the application
- the application does not crash when the user enters wrong data ( data is takes as a string, then converted if needed )
- other available options for editing save files:
  add. Add save word          adds. Add save words - add 1 or multiple unusual words for a "most used uncommon words" file
  remove.  Remove save word   removes. Remove save words - remove 1 or multiple unusual words out of a "most used uncommon words" file
  show. Show words of a save file - shows uncommon words of a "most used uncommon words" file
  files. Consider / Do not consider a save file for correlations - help by excluding files that seem to not have words that correlate with each other
  copy. Make a copy of a save file - copy a save file for the user
- able to identify plurals - even irregular
Improvements:
- keep freqvency too
- add data to the application
- fle





> __[rename](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/rename)__
__[ final application]__, __[linux]__
>> - renames all files ina  folder to numerotate them ( just numbers for filenames )
Improvements:
- detete the generated commands file





> __[repeat string](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/repeat string)__
__[ final application]__, __[cross-platform]__
>> - repeats the text in a file by replacing one word with other words multiple times





> __[repeat](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/repeat)__
__[ final application]__, __[cross-platform]__, __[statistics]__
>> - shows a top of the 10 most used words in the file
- able to identify plurals
Improvement:
- identify irregular plurals





> __[repeat_files](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/repeat_files)__
__[ final application]__, __[cross-paltform]__, __[common word]__
>> - after you type your text, the application removes commmon words and plurals to let you know which uncommon words you use the most
- memorises which uncommon words you used a their freqvence of use - shows you your most used words now and until now





> __[replace filename](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/replace filename)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - given a file that contains a list of filenames ( one on each row ), the application is able to replace strings in their filenames
- able to replace multiple strings at once without causing replacement conflicts





> __[replace](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/replace)__
__[ trivial]__, __[final application]__, __[cross-platform]__
>> - replaces multiples strings in a file
- able to replace multiple strings at once without causing replacement conflicts





> __[response](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/response)__
__[ example]__, __[trivial]__, __[cross-paltform]__
>> - example of how cpp files can communicate like they were client and server





> __[rhthm notes](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/rhthm notes)__
__[ trivial]__, __[example]__, __[cross-platform]__
>> - generates all combinations of 10 taken 4





> __[rhthm](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/rhthm)__
__[ application version]__, __[trivial]__, __[example]__, __[cross-platform]__
>> - generates all combinations of 10 taken 8





> __[scrpts](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/scrpts)__
__[ final application]__, __[linux]__, __[visible]__
>> - keeps your scripts
- able to copy the script files you give it into its own folder, add a title and details for them
- numerortates your scripts and executes them





> __[set time](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/set time)__
__[ example]__, __[trivial]__, __[linux]__
>> - changes the time





> __[sh in cpp](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/sh in cpp)__
__[ frinal application]__, __[example]__, __[trivial]__, __[linux]__, __[code generation]__
>> - adds: if / if else / for / while to a sh file ( only adds them, so you do not have to type them )





> __[site maker 1](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/site maker 1)__
__[ application version]__, __[cross-platform]__, __[code generation]__
>> 




> __[site maker linux](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/site maker linux)__
__[ final application]__, __[remake]__, __[linux]__, __[visible]__
>> - given a file that uses the "file format" application format, the application is able to make a website
- uses custom styling
- saves the file and its style in a separate folder





> __[site maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/site maker)__
__[ application version]__, __[cross-platform]__, __[code generation]__
>> 




> __[size more common](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/size more common)__
__[ final application]__, __[cross-paltform]__, __[visible]__, __[statistics]__
>> - able to determine the average word length for every topic you give it
- available options: 1. Add File  2. Add topic  3. Remove topic  4. Show topics and sizes  5. Exits
- when you add a file you have to add it to a topic
- able to add a new topic when you add a file





> __[size more](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/size more)__
__[ application version]__, __[cross-platform]__, __[statistics]__
>> 




> __[size sh](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/size sh)__
__[ example]__, __[trivial]__, __[remake]__, __[linux]__
>> - tells you a filesize for a certain filepath





> __[size](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/size)__
__[ final application]__, __[cross-platform]__, __[statistics]__
>> - calculates average word length, shows you the previous result when you execute ( add another file )





> __[slc file 1](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/slc file 1)__
__[ final application]__, __[cross-paltform]__
>> - able to separate files with lots of text into multiple smaller files that only have a specified maximum size





> __[slc file](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/slc file)__
__[ application version]__, __[cross-platform]__
>> - slices files





> __[sldn](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/sldn)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> - given a string the application makes you a terminal text animation 
- offers 4 default presets for inserting strings between letters, and 1 custom ( you decide what comes befor and after each of the letters )





> __[slid](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/slid)__
__[ trivial]__, __[fianl application]__, __[cross-platform]__, __[code generation]__
>> - it types a strings letter by letter ( repeats until you stop it )





> __[sntce](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/sntce)__
__[ final application]__, __[cross-paltform]__
>> - given a text that lacks proper formatting ( there are tabls and speaces everywhere ), the application is able to identify sentances, reduce whitespace and list all sentances on rows, lowercased





> __[sort](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/sort)__
__[ final application]__, __[cross-platform]__
>> - given a file, the application sorts strings or numerics ( ehich are either on lines or separated by a ' ' ), asc or desc, showing the result in a separate file, either on each line, or separated by a space





> __[speak](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/speak)__
__[ final application]__, __[linux]__
>> - able to use linux commands to speak sentances written in a file
- adapts the rate at which the words are said, to make the speech inteligeble





> __[strys](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/strys)__
__[ not completed]__, __[cross-platform]__, __[needs rnd]__, __[visible]__
>> - given a file with [], the application is able to use data files to fill in the missing words, which could be any of the words of a certain file mentioned between the []





> __[sure](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/sure)__
__[ final application]__, __[linux]__, __[needs rnd]__, __[visible]__, __[code generation]__
>> - given a function in a file, the application is able to conduct a series of tests to make sure that the results are the ones you would expect





> __[swap](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/swap)__
__[ final application]__, __[cross-platform]__
>> - able to swap any number of words in a certain given file
Improvements:
- add swapping for multiple files





> __[syllab](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/syllab)__
__[ trivial]__, __[final application]__, __[cross-paltform]__
>> - separates a word into its syllabels





> __[tale](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/tale)__
__[ example]__, __[remake]__, __[trivial]__, __[cross-paltform]__
>> - aims to make a stry by prplacing the progagonist ...





> __[theme](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/theme)__
__[ final applications]__, __[cross-platform]__, __[visible]__, __[common word]__
>> - aims to determine the theme of a text by identifying in how sentances each uncommon word appears
- shows multiple theme options if there are 





> __[thread](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/thread)__
__[ example]__, __[cross-platform]__
>> - shows how threads can be used in cpp





> __[type lnux details](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/type lnux details)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> - makes a text animation in the terminsl, to show the application name and the details ( which apprar line by line )
- able to add a file, or type in the details





> __[type lnux](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/type lnux)__
__[ application version]__, __[cross-platform]__, __[code generation]__
>> 




> __[type](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/type)__
__[ final application]__, __[cross-platform]__, __[visible]__, __[code generation]__
>> -types the text of a file in the terminal, letter by letter





> __[types](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/types)__
__[ library version]__, __[trivial]__, __[cross-platform]__
>> - given a string, the application determines the data-type that the data could be stored in ( double, int, bool, long, char or string )





> __[unrar](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/unrar)__
__[ final application]__, __[linux]__, __[visible]__
>> - unzip / unrar all the files in a certain folder ( also in the folders of that folder and so on )





> __[unzip](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/unzip)__
__[ library version]__, __[linux]__
>> - unzip / unrar a certain file using a cpp function





> __[verify](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/verify)__
__[ final application]__, __[cross-paltform]__, __[visible]__
>> - checks a cpp file to identify if the last character in a line is a valid cpp character, which takes care of:
	- forgotten ;
	- paranthesis left unclosed
	- quotes left unclosed
- does not consider comments, since they need not confirm to any cpp formatting ( checks for last character before comments )





> __[whitespace](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/whitespace)__
__[ final application]__, __[cross-platform]__, __[statistics]__
>> - determines how much whitespace there is in a file ( both how many charachers and how much of the total whitespace and non-whitespace represent )
- shows the filesize





> __[strings](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Ai/strings)__
__[ final application]____[example]____[cross-paltform]__, 
>> - search in a string[]
- demo that shows in how many iterations the search gets to a result
- efficient because:
	- uses sorted data
	- approximates the initial search position by the first letter of the searched string
} ai: final application, cross-paltform, common word
- give it statements, and say if they are true or not. When the application comes across a a statement that resambles what you told it, it can decide on its own.
- eliminates common words to make the comparison with its database effecitve, to offer answers for as many statements as possible
- improvement tends to be visible





> __[Dev maker](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Libraries/Dev maker)__
__[ not completed]____[linux]____[code generation]__, 
>> - ide, makes projects





> __[most used letters](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/most used letters)__
__[ not completed]__, __[cross-platform]__, __[visible]__, __[statistics]__
>> - knows what the most used letters are
- add file / sentance
Improvements:
- keeps outputting non-english alphabet letters





> __[typo](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/typo)__
__[ final application]__, __[cross-platform]__, __[visible]__
>> - has a set of typos that it can replce to modify text
- Options:
	- 1. Add file: modifies a file replcing typos
	- 2. Add typo: add a typo ( a well-spelled word and its mispellings )
	- 3. Remove typo: remove a typo
	- 4. Show typos: show available typos





> __[chars file](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/chars file)__
__[ final application]__, __[linux]__, __[visible]__
>> - able to determine the most used words of a file and encode them with chrchrs that are not commonly used for words ( , , ,  ... )
- reduces lots of storage space
- encodes and decodes a zip file with: the encoded file and its encoding file ( converted file and word-chrctr correlations )
- words that only have 1 char are not encoded
- can convert a maximum of 129 words
error formatted: final application, library version, linux, visible
- shows formatted error for linux terminal





